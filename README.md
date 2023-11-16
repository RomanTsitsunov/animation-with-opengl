[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub Actions](https://github.com/RomanTsitsunov/animation-with-opengl/actions/workflows/workflow.yml/badge.svg)](https://github.com/RomanTsitsunov/animation-with-opengl/actions/workflows/workflow.yml)
# Animation-with-opengl
![gif2](https://github.com/RomanTsitsunov/animation-with-opengl/blob/main/data/g.gif)
### Общее описание
<div>
Программа отображает окружность, плавно перетекающую в ромб, и наоборот;
цвет периодически изменяется.<br>
</div>

#### display
Функция display отрисовывает окружность с заданными
радиусом, центром и количеством разбиений.
#### Redraw
Функция Redraw изменяет параметры отрисовки, так чтобы фигура
последовательно преобразовывалась от окружности к ромбу и обратно
с периодическим изменением цвета.
#### Main
Сначала создается начальное окно с заданными размерами и названием, после чего запускается цикл по отрисовке изображения.
#### Установка и запуск
1. Клонируйте репозиторий или скачайте исходный код
   ```
   git clone https://github.com/RomanTsitsunov/animation-with-opengl.git
   ```
2. Установите cmake через vcpkg
   ```
        git clone https://github.com/Microsoft/vcpkg.git
        cd vcpkg
        ./bootstrap-vcpkg.bat
        ./vcpkg.exe install cppzmq:x64-windows
   ```
3. Запустите cmake
   ```
	cd lab5_opengl
        mkdir build
        cd build
        cmake .. -DCMAKE_TOOLCHAIN_FILE={Путь к проекту}/vcpkg/scripts/buildsystems/vcpkg.cmake
   ```
4. Собрать проект
   ```
	cd lab5_opengl
        cmake --build build
   ```