#include"el.h"
using namespace akgl;

el::el(double Base, double Height, double speed) : object()
{
    //� ������� ������ ���� ����� ��� �� ���� � �������, ������� �� 4 ����� ������ ��������� � ����� ������� 4 � �� ������� 1 - ��� ����� � 1 �����
    pos = pos * 4;
    pos.y = -7;
    R = Base;
    //����� ��������� ��� ��� ���������� ����� � ���� �������� �������� ������� �� ���� ������
    this->speed = speed;
    H = Height;
    // ���� ������ �������)))
    col.x = 0;
    col.y = 1;
    col.z = 0;
    col.print();
    pos.print();
}
void el::Render(anim &Ani)
{
    //�������
    glPushMatrix();
    //����
    glColor3d(col.x, col.y, col.z);
    //�������
    glTranslated(pos.x, pos.y, pos.z);
    //������ ��� �����
    glRotated(270, 1, 0, 0);
    //��� ����� �� ��������� � ��� ����������� �������� ������ �� ������� � ����������� �� �������
    glRotated(R * sin(speed * clock()), 1, 1, 1);
    //1 �����, ���������� ������� � ������� ��� 2 � 3 �����
    glutSolidCone(R, H, 30, 30);
    glTranslated(0, 0, 0.9 * H);
    glRotated(2 * R * sin(speed * clock()), 1, 1, 1);
    glutSolidCone(0.8 * R, 0.75 * H, 30, 30);
    glRotated(3 * R * sin(speed * clock()), 1, 1, 1);
    glTranslated(0, 0, 0.9 * 0.75 * H);
    glutSolidCone(0.6 * R, 0.5 * H, 30, 30);
    glPopMatrix();
}
//������ ����� ��������, ����� �� �������?)
void el::Response(anim &Ani)
{
}