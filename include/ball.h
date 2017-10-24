#include"anim.h"
/*
А вот и шарик
*/
namespace akgl
{
    // шарик унаследует себе цвет и позицию из класса объект
    class ball : public object
    {
    public:
        // кроме того у него есть радиус
        double R;
        // а еще есть направление движения
        vec dir;
        // конструктор(принимает радиус) деструктор рисовка изменение положения
        ball(double R0);
        ~ball()
        {
        }
        void Render(anim &Ani);
        void Response(anim &Ani);
    };
}
