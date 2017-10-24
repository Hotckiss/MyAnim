#ifndef __ANIM_H_
#define __ANIM_H_
//замен€ем эти 2 строчки снизу на #include<glut.h>, спс моему компу
#include <glut.h>
#include <freeglut.h>

#include<iostream>
#include<time.h>
#include<math.h>
#include"vec.h"
// помен€ть akgl на aegl
/*
—уть программы система анимации, котора€ содержит в себе разнообразные объекты, которые мы напишем отдельно и будем добавл€ть в систему*/
namespace akgl
{
    // главный класс - anim, объ€вим его заранее так как он понадобитс€ уже сейчас
    class anim;
    // объект, часть системы анимации - м€чик, елочка, снеговик и тд
    class object
    {
    // у всех объектов точно есть позици€ и цвет, остальное у каждого свое, про protected: все эти м€чики и тд - объекты, будут €вл€тьс€ наследникми данного класса, это значит, что
    // класс наследник автоматически получит себе в пол€ цвет и позицию, а также 2 функции ниже
    protected:
        vec col;
        vec pos;
    // 
    public:
        // слово virtual ознгачает, что если у класса наследника - м€чика, есть сво€ функци€ Render, то вызоветс€ именно она
        virtual void Render(anim &Ani) { };
        // тут пересчитываетс€ позици€ объекта при движении
        virtual void Response(anim &Ani) { };
        // рандомные позици€ и цвет по умолчанию
        object() : col(vec::Rnd0()), pos(vec::Rnd1())
        {
        }
    };
    class anim
    {
    private:
        // максимльное число объектов
        static const int Max = 100;
        // массим объектов
        object *Stock[Max];
        // текущее число объектов
        int StockSize;
        // поскольку у нас всего одна система анимации, чтобы избежать повторных ее созданий мы создадим ее сразу пр€мо тут, в мэйне мы просто вернем ссылку именно на это
        static anim Instance;

        anim(void);
        // типичный опен гл, клава экран таймер звенение размера экрана
        static void Display(void);
        static void Keyboard(unsigned char Key, int x, int y);
        static void Idle(void);
        static void Reshape(int Width, int Height);
    public:
        // ну это никому не нужно
        static double TSK_SyncTime;
       // деструктор отрисовка объектов таймер
        ~anim(void);
        void Render(void);
        void Timer(void);
        // эта функци€ нужна чтобы вызвать ее в мэйне и там уже иметь систему анимации которую мы создали тут
        static anim & GetRef(void)
        {
            return Instance;
        }
        // добавление в систему, например MyAnim << new el(2, 8, 0.01);
        anim & operator<<(object *obj)
        {
            //если размер позвол€ет
            if (StockSize < Max)
                Stock[StockSize++] = obj;
            else
                delete obj;
            return *this;
        }
        // запуск
        void Run(void)
        {
            glutMainLoop();
        }
    };
}
#endif
