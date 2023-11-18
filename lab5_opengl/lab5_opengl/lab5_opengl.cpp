#include <iostream>
#include <time.h>
#include <cstdlib>
#include "GL/freeglut.h"

/*
    stage - Номер этапа смены цвета (всего 7 этапов)
    radius - Радиус окружности (наименьшее значение 0.0f соответствует ромбу,
        наибольшее значение ~ 0.354f соотвествует окружности)
    dr - Изменение радиуса окружности (0.001f - преобразование от ромба к окружности,
        -0.001f - преобразование от окружности к ромбу)
    red, green, blue  - Доли красного, зеленого, синего цветов соответственно
        (максимальное и минимальное значение доли цвета 1.0f и 0.0f соответственно)
    dc - Изменение доли цвета
*/
int stage = 1;
float radius = 0.001f;
float dr = 0.001f;
float red = 1.0f, green = 0.0f, blue = 0.0f, dc = 0.01f;

/*
Функция display отрисовывает 1 из промежуточных состояний фигуры
при преобразовании от ромба к окружности и наоборот
    upCircleCenterX - координата центра верхнего скругления по оси ОХ
    upCircleCenterY - координата центра верхнего скругления по оси ОY
    leftCircleCenterX - координата центра левого скругления по оси ОX
    leftCircleCenterY - координата центра левого скругления по оси ОY
    downCircleCenterX - координата центра нижнего скругления по оси ОХ
    downCircleCenterY - координата центра нижнего скругления по оси ОY
    rightCircleCenterX - координата центра правого скругления по оси ОХ
    rightCircleCenterY - координата центра правого скругления по оси ОY
    angle - угол между соседними сегментами
*/
void display() {
    //Очищает буфер перед отрисовкой нового кадра
    glClear(GL_COLOR_BUFFER_BIT);
    const float upCircleCenterX = 0.0f;
    const float upCircleCenterY = 0.5f - sqrt(2 * radius * radius);
    const float leftCircleCenterX = -0.5f + sqrt(2 * radius * radius);
    const float leftCircleCenterY = 0.0f;
    const float downCircleCenterX = 0.0f;
    const float downCircleCenterY = -0.5f + sqrt(2 * radius * radius);
    const float rightCircleCenterX = 0.5f - sqrt(2 * radius * radius);
    const float rightCircleCenterY = 0.0f;
    float angle;
    float x, y;
    //Задает цвет изображения
    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);
    // Цикл отрисовывает скругление верхнего угла ромба
    for (int i = 45; i < 135; i++) {
        angle = i * 3.14159f / 180.0f;
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex2f(upCircleCenterX + x, upCircleCenterY + y);
    }
    // Цикл отрисовывает скругление левого угла ромба
    for (int i = 135; i < 225; i++) {
        angle = i * 3.14159f / 180.0f;
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex2f(leftCircleCenterX + x, leftCircleCenterY + y);
    }
    // Цикл отрисовывает скругление нижнего угла ромба
    for (int i = 225; i < 315; i++) {
        angle = i * 3.14159f / 180.0f;
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex2f(-downCircleCenterX + x, downCircleCenterY + y);
    }
    // Цикл отрисовывает скругление правого угла ромба
    for (int i = -45; i < 45; i++) {
        angle = i * 3.14159f / 180.0f;
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex2f(rightCircleCenterX + x, rightCircleCenterY + y);
    }
    glEnd();
    //Отображает изображение
    glFlush();
}

/*
Функция redraw изменяет параметры отрисовки
    MaxColorValue - максимальное значение, которое может принимать переменная цвета
    MinColorValue - минимальное значение, которое может принимать переменная цвета
    maxRadius - 0.354f соотвествует окружности
    delay - интервал между кадрами отрисовки
*/
void redraw()
{
    const float maxColorValue = 1.0f;
    const float minColorValue = 0.0f;
    const float maxRadius = sqrt((0.5f * 0.5f) / 2);
    const int delay = 10;
    if (radius >= maxRadius) {
        dr = -dr;
    }
    else if (radius <= 0.0f) {
        dr = -dr;
    }
    radius += dr;
    switch (stage) {
    case(1):
        red += dc;
        stage = (red < maxColorValue ? 1 : 2);
        break;
    case(2):
        blue += dc;
        stage = (blue < maxColorValue ? 2 : 3);
        break;
    case(3):
        red -= dc;
        stage = (red > minColorValue ? 3 : 4);
        break;
    case(4):
        green += dc;
        stage = (green < maxColorValue ? 4 : 5);
        break;
    case(5):
        blue -= dc;
        stage = (blue > minColorValue ? 5 : 6);
        break;
    case(6):
        red += dc;
        stage = (red < maxColorValue ? 6 : 7);
        break;
    case(7):
        green -= dc;
        stage = (green > minColorValue ? 7 : 1);
        break;
    }
    Sleep(delay);
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL");
    glutDisplayFunc(display);
    glutIdleFunc(redraw);
    glutMainLoop();
    return 0;
}