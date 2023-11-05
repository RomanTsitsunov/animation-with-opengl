#include <iostream>
#include <time.h>
#include <cstdlib>
#include "GL/freeglut.h"

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
    //Количество разбиений для задания окружности
    double points = 20;
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
    //Запуск вечного цикла
    glutMainLoop();
}