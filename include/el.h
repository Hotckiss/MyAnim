#include"anim.h"
// ель задается радиусом основания нижнего конуса (из трех) и его высотой, speed скорость качания елочки))
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
