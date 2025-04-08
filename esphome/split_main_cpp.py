import argparse
import os
import re
import yaml

def extract_parts(content):
    # Извлекаем заголовочную часть (include/using), пока не начнётся что-то другое
    header_lines = []
    global_lines = []
    setup_func = ""
    inside_setup = False

    for line in content.splitlines():
        stripped = line.strip()

        if not inside_setup and (stripped.startswith("#include") or "using" in stripped):
            header_lines.append(line)
        elif "void setup()" in stripped:
            inside_setup = True
            setup_func += "void esphome_setup() {\n"
        elif inside_setup:
            setup_func += line + "\n"
        elif re.match(r"^\s*(\w+::)+.*\*\s*\w+\s*;", line):  # глобальная переменная
            global_lines.append(line)

    return header_lines, global_lines, setup_func

def generate_main_h(header_lines, global_lines):
    # Формируем main.h
    main_h = "#pragma once\n\n"
    main_h += "\n".join(header_lines) + "\n\n"

    for line in global_lines:
        extern_line = re.sub(r"^(.*?)\s+(\*?\w+)\s*;", r"extern \1 \2;", line)
        main_h += extern_line + "\n"

    main_h += "\nextern void esphome_setup();\n"
    return main_h

def generate_esphome_cpp(global_lines, setup_func):
    # Формируем esphome_setup.cpp
    esphome_cpp = '#include "main.h"\n\n'
    esphome_cpp += "\n".join(global_lines) + "\n\n"

    esphome_cpp += setup_func
    return esphome_cpp

def main():
    parser = argparse.ArgumentParser(description="Generate main.h and esphome_setup.cpp from esphome YAML project")
    parser.add_argument("-i", "--input", required=True, help="Path to esphome YAML file")
    parser.add_argument("-o", "--output", required=True, help="Output directory")
    args = parser.parse_args()

    # Load YAML and extract project name
    with open(args.input, "r") as f:
        yaml_data = yaml.safe_load(f)

    project_name = yaml_data.get("esphome", {}).get("name")
    if not project_name:
        raise ValueError("Missing 'esphome.name' in YAML")

    yaml_dir = os.path.dirname(os.path.abspath(args.input))
    main_cpp_path = os.path.join(yaml_dir, ".esphome", "build", project_name, "src", "main.cpp")

    if not os.path.isfile(main_cpp_path):
        raise FileNotFoundError(f"main.cpp not found at {main_cpp_path}")

     # Ensure output directory exists
    os.makedirs(args.output, exist_ok=True)

    with open(main_cpp_path, "r") as f:
        content = f.read()

    header_lines, global_lines, setup_func = extract_parts(content)
    
    main_h = generate_main_h(header_lines, global_lines)
    esphome_cpp = generate_esphome_cpp(global_lines, setup_func)

    with open(os.path.join(args.output, "main.h"), "w") as f:
        f.write(main_h)

    with open(os.path.join(args.output, "esphome_setup.cpp"), "w") as f:
        f.write(esphome_cpp)

    print("✅ Generated: main.h and esphome_setup.cpp in", args.output)

if __name__ == "__main__":
    main()