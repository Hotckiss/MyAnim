#include"anim.h"
/*
� ��� � �����
*/
namespace akgl
{
    // ����� ���������� ���� ���� � ������� �� ������ ������
    class ball : public object
    {
    public:
        // ����� ���� � ���� ���� ������
        double R;
        // � ��� ���� ����������� ��������
        vec dir;
        // �����������(��������� ������) ���������� ������� ��������� ���������
        ball(double R0);
        ~ball()
        {
        }
        void Render(anim &Ani);
        void Response(anim &Ani);
    };
}
