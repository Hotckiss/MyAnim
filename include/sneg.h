#include"anim.h"
// у снеговика в арсенали имеется радиус нижнего комочка и скорось его бега вокруг центра))
namespace akgl
{
    class sneg : public object
    {
    public:
        double SphR;
        double speed;
        // R0 - радиус окружности по которой он бегает, скорость, радиус, по умолчанию он 0.9
        sneg(double R0, double speed, double SphR = 0.9);
        ~sneg()
        {
        }
        void Render(anim &Ani);
        void Response(anim &Ani);
    };
}