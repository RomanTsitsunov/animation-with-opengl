#include <iostream>
#include <time.h>
#include <cstdlib>
#include "GL/freeglut.h"

//Количество разбиений для задания окружности
int points = 20;
//Определение преобразование - от окружности к ромбу или наоборот
bool toRomb = true;
//Функция отрисовки
void display()
{
    //Очищает буфер перед отрисовкой нового кадра
    glClear(GL_COLOR_BUFFER_BIT);
    double red = rand() % 256;
    double green = rand() % 256;
    double blue = rand() % 256;
    //Задает цвет фона
    glClearColor(0.0, 0.4, 0.4, 1.0);
    //Радиус окружности
    double radius = 50;
    //Центр фигуры
    double cx = 160;
    double cy = 120;
    //Задает цвет изображения
    glColor3ub(red, green, blue);
    //Задает полигон из points + 1 вершины, равномерно расположенных на окружности радиуса radius
    glBegin(GL_POLYGON);
    double angle;
    double x;
    double y;
    for (int i = 0; i <= points; i++) {
        //Вычисляется угол
        angle = 2 * 3.14 * i / points;
        //Вычисляется координата x
        x = cx + radius * cos(angle);
        //Вычисляется координата Y
        y = cy + radius * sin(angle);
        //Отмечаем очередную вершину
        glVertex2d(x, y);
    }
    glEnd();
    //Отображает изображение
    glFlush();
}
//Функция, изменяющая параметры отрисовки
void Redraw()
{
    //Пока количество вершин не уменьшится до 4 - преобразовывает окружность к ромбу
    if (toRomb) {
        points--;
        toRomb = (points > 4);
    }
    //Пока количество вершин не достигнет до 20 - преобразовывает ромб к окружности
    else {
        points++;
        toRomb = (points == 20);
    }
    //Интервал между кадрами - 0.2 секунды
    Sleep(200);
    //Запрос на повторную отрисовку
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //Задаются начальные размеры окна
    glutInitWindowSize(320, 240);
    //Создается окно с заданным заголовком
    glutCreateWindow("OpenGL");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 320, 0, 240);
    //Функция отрисовки
    glutDisplayFunc(display);
    //Функция, изменяющая параметры отрисовки
    glutIdleFunc(Redraw);
    //Запуск вечного цикла
    glutMainLoop();
}