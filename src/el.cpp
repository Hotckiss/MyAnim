#include"el.h"
using namespace akgl;

el::el(double Base, double Height, double speed) : object()
{
    //я опускаю елочку вниз чтобы она не была в воздухе, умножаю на 4 чтобы елочка появилась в круге радиуса 4 а не радиуса 1 - это почти в 1 точке
    pos = pos * 4;
    pos.y = -7;
    R = Base;
    //через стрелочку так как одинаковые имена и надо отличать аргумент функции от поля класса
    this->speed = speed;
    H = Height;
    // таки елочка зеленая)))
    col.x = 0;
    col.y = 1;
    col.z = 0;
    col.print();
    pos.print();
}
void el::Render(anim &Ani)
{
    //рисовка
    glPushMatrix();
    //цвет
    glColor3d(col.x, col.y, col.z);
    //позиция
    glTranslated(pos.x, pos.y, pos.z);
    //ставим его вверх
    glRotated(270, 1, 0, 0);
    //это чтобы он колебался я его поворачиваю немножко всегда по разному в зависимости от времени
    glRotated(R * sin(speed * clock()), 1, 1, 1);
    //1 конус, аналогично колебаю с иставлю так 2 и 3 конус
    glutSolidCone(R, H, 30, 30);
    glTranslated(0, 0, 0.9 * H);
    glRotated(2 * R * sin(speed * clock()), 1, 1, 1);
    glutSolidCone(0.8 * R, 0.75 * H, 30, 30);
    glRotated(3 * R * sin(speed * clock()), 1, 1, 1);
    glTranslated(0, 0, 0.9 * 0.75 * H);
    glutSolidCone(0.6 * R, 0.5 * H, 30, 30);
    glPopMatrix();
}
//елочка стоит качается, зачем ее двигать?)
void el::Response(anim &Ani)
{
}