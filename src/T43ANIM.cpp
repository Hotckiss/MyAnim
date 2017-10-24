#define _CRT_SECURE_NO_WARNINGS
#include"anim.h"
#include"ball.h"
#include"sneg.h"
#include"el.h"
#include"bp.h"
#include"bezier.h"

using namespace akgl;\
// создали нашу систему анимации
anim anim::Instance;
/// опять не нужная вещь
double anim::TSK_SyncTime;
int main(int argc, char* argv[])
{
    // запихнули в нашу антимацию ту самую единственную анимацию из класса
    anim & MyAnim = anim::GetRef();
    // добавили мячиков
    for (int i = 0; i < 7; i++)
    {
        MyAnim << new ball((double)rand() / RAND_MAX);
    }
    // елка снеговик
    MyAnim << new sneg(5, 0.3, 1);
    MyAnim << new el(2, 8, 0.01);
    //кривые безье
    for (int j = 0; j < 1; j++)
    {
        // 25 управляющих точек
        int dots = 25;
        vec v[25];
        // заполняем их
        for (int i = 0; i < dots; i++)
            v[i] = vec::Rnd1() * 6.9;
        // создаем кривую
        MyAnim << new bez(v, dots);
    }
    // 16 точек для плоскости
    vec v[4][4];
    // заполняем их
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            v[i][j].x = 3 + j;
            v[i][j].y = 10 * sin(3 * i);
            v[i][j].z = 2 * i - 4;
        }
    // создаем плоскость безье
    MyAnim << new bp(v);
    //рисовка таймер запуск
    MyAnim.Render();
    MyAnim.Timer();;
    MyAnim.Run();
    return 0;
}