[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# Animation-with-opengl
![gif2](https://github.com/RomanTsitsunov/animation-with-opengl/blob/main/g.gif)
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
2. Запустите приложение по пути
   ```
   "animation-with-opengl\lab5 opengl\x64\Release\lab5 opengl"
   ```