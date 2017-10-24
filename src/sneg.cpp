#include"sneg.h"
using namespace akgl;

sneg::sneg(double R0, double speed, double SphR) : object()
{
    //опускаю его вниз, ставлю на окружность
    vec a(R0, -7, 0);
    pos = a;
    this->SphR = SphR;
    this->speed = speed;
    //беленький)
    col.x = 1;
    col.y = 1;
    col.z = 1;
    col.print();
    pos.print();
}
void sneg::Render(anim &Ani)
{
    glPushMatrix();
    glColor3d(col.x, col.y, col.z);
    // вращение по окружности
    glRotated(speed * clock(), 0, 1, 0);
    // ставим 3 сферы друг на друга, страшный транслейт по оси х это он типо качается влево-вправо
    glTranslated(pos.x, pos.y, pos.z);
    glutSolidSphere(SphR, 20, 20);
    glTranslated(0.3 * SphR * sin(0.007 * clock()), 1.75 * SphR, 0);
    glutSolidSphere(0.75 * SphR, 20, 20);
    glTranslated(0.3 * SphR * sin(0.007 * clock()), 1.25 * SphR, 0);
    glutSolidSphere(0.5 * SphR, 20, 20);
    glPopMatrix();
}
void sneg::Response(anim &Ani)
{
}