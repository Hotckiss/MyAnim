#include"anim.h"
// ��� �������� �������� ��������� ������� ������ (�� ����) � ��� �������, speed �������� ������� ������))
namespace akgl
{
    class el : public object
    {
    public:
        double R, H;
        double speed;
        el(double Base, double Height, double speed);
        ~el()
        {
        }
        void Render(anim &Ani);
        void Response(anim &Ani);
    };
}
