#ifndef __ANIM_H_
#define __ANIM_H_
//�������� ��� 2 ������� ����� �� #include<glut.h>, ��� ����� �����
#include <glut.h>
#include <freeglut.h>

#include<iostream>
#include<time.h>
#include<math.h>
#include"vec.h"
// �������� akgl �� aegl
/*
���� ��������� ������� ��������, ������� �������� � ���� ������������� �������, ������� �� ������� �������� � ����� ��������� � �������*/
namespace akgl
{
    // ������� ����� - anim, ������� ��� ������� ��� ��� �� ����������� ��� ������
    class anim;
    // ������, ����� ������� �������� - �����, ������, �������� � ��
    class object
    {
    // � ���� �������� ����� ���� ������� � ����, ��������� � ������� ����, ��� protected: ��� ��� ������ � �� - �������, ����� �������� ����������� ������� ������, ��� ������, ���
    // ����� ��������� ������������� ������� ���� � ���� ���� � �������, � ����� 2 ������� ����
    protected:
        vec col;
        vec pos;
    // 
    public:
        // ����� virtual ���������, ��� ���� � ������ ���������� - ������, ���� ���� ������� Render, �� ��������� ������ ���
        virtual void Render(anim &Ani) { };
        // ��� ��������������� ������� ������� ��� ��������
        virtual void Response(anim &Ani) { };
        // ��������� ������� � ���� �� ���������
        object() : col(vec::Rnd0()), pos(vec::Rnd1())
        {
        }
    };
    class anim
    {
    private:
        // ����������� ����� ��������
        static const int Max = 100;
        // ������ ��������
        object *Stock[Max];
        // ������� ����� ��������
        int StockSize;
        // ��������� � ��� ����� ���� ������� ��������, ����� �������� ��������� �� �������� �� �������� �� ����� ����� ���, � ����� �� ������ ������ ������ ������ �� ���
        static anim Instance;

        anim(void);
        // �������� ���� ��, ����� ����� ������ �������� ������� ������
        static void Display(void);
        static void Keyboard(unsigned char Key, int x, int y);
        static void Idle(void);
        static void Reshape(int Width, int Height);
    public:
        // �� ��� ������ �� �����
        static double TSK_SyncTime;
       // ���������� ��������� �������� ������
        ~anim(void);
        void Render(void);
        void Timer(void);
        // ��� ������� ����� ����� ������� �� � ����� � ��� ��� ����� ������� �������� ������� �� ������� ���
        static anim & GetRef(void)
        {
            return Instance;
        }
        // ���������� � �������, �������� MyAnim << new el(2, 8, 0.01);
        anim & operator<<(object *obj)
        {
            //���� ������ ���������
            if (StockSize < Max)
                Stock[StockSize++] = obj;
            else
                delete obj;
            return *this;
        }
        // ������
        void Run(void)
        {
            glutMainLoop();
        }
    };
}
#endif
