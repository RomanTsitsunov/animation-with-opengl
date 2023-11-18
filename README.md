[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub Actions](https://github.com/RomanTsitsunov/animation-with-opengl/actions/workflows/workflow.yml/badge.svg)](https://github.com/RomanTsitsunov/animation-with-opengl/actions/workflows/workflow.yml)
# Animation-with-opengl
![gif2](https://github.com/RomanTsitsunov/animation-with-opengl/blob/main/data/g.gif)
### Общее описание
<div>
Программа отображает анимацию, в которой окружность плавно перетекает в ромб, и наоборот;
цвет периодически изменяется.<br>
</div>

### Используемые библиотеки
- Vcpkg - пакетный менеджер, использовался для установки всех необходимых библиотек;
- CMake - программное средство автоматизации сборки программного обеспечения;
- Freedlut - позволяет пользователю создавать окна, предоставляющие контекст OpenGL на широком спектре платформ;
- Google Test - библиотека для модульного тестирования на языке C++.

### Установка и запуск
1. Клонируйте репозиторий или скачайте исходный код
   ```
   git clone https://github.com/RomanTsitsunov/animation-with-opengl.git
   ```
2. Установите cmake через vcpkg
   ```
   git clone https://github.com/Microsoft/vcpkg.git
   ```
   ```
   cd vcpkg
   ```
   ```
   ./bootstrap-vcpkg.bat
   ```
   ```
   ./vcpkg.exe install cppzmq:x64-windows
   ```
3. Запустите cmake
   ```
   cd ..
   ```
   ```
   cd animation-with-opengl/lab5_opengl
   ```
   ```
   mkdir build
   ```
   ```
   cd build
   ```
   ```
   cmake .. -DCMAKE_TOOLCHAIN_FILE={Путь к проекту}/vcpkg/scripts/buildsystems/vcpkg.cmake
   ```
4. Собрать проект
   ```
   cd ..
   ```
   ```
   cmake --build build --config Release
   ```