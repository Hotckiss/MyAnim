#include"anim.h"
// � ��������� � �������� ������� ������ ������� ������� � ������� ��� ���� ������ ������))
namespace akgl
{
    class sneg : public object
    {
    public:
        double SphR;
        double speed;
        // R0 - ������ ���������� �� ������� �� ������, ��������, ������, �� ��������� �� 0.9
        sneg(double R0, double speed, double SphR = 0.9);
        ~sneg()
        {
        }
        void Render(anim &Ani);
        void Response(anim &Ani);
    };
}