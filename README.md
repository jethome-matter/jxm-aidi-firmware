# Проект для платы jxm-aidi
Плата расширение для JXD-E1 для измерения тока, напряжения и подключения сухих контактов

## Build instruments
 - esp-idf 5.1.5
 - .vscode/settings_template.json - создать settings.json, поправить пути
 - esphome - версии в файле requirements.txt. Используется для кодогенрации части проекта

 ### Установка и использование esphome
 ```
 python -m venv .venv
 .venv/Scripts/Activate.ps1
 cd esphome
 pip install -r requirements.txt
 esphome compile --only-generate jxm_aidi.yaml
 ```

## Состав папок
 - esphome - исходники yaml, из которых генерируется часть компонент проекта
 - main - код прошивки
