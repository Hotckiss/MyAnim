#define _CRT_SECURE_NO_WARNINGS
#include"anim.h"
#include"ball.h"
#include"sneg.h"
#include"el.h"
#include"bp.h"
#include"bezier.h"

using namespace akgl;
anim anim::Instance;
double anim::TSK_SyncTime;
int main(int argc, char* argv[])
{

    anim & MyAnim = anim::GetRef();

    for (int i = 0; i < 7; i++)
    {
        MyAnim << new ball((double)rand() / RAND_MAX);
    }

    MyAnim << new sneg(5, 0.3, 1);
    MyAnim << new el(2, 8, 0.01);

    for (int j = 0; j < 1; j++)
    {

        int dots = 25;
        vec v[25];

        for (int i = 0; i < dots; i++)
            v[i] = vec::Rnd1() * 6.9;

        MyAnim << new bez(v, dots);
    }

    vec v[4][4];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            v[i][j].x = 3 + j;
            v[i][j].y = 10 * sin(3 * i);
            v[i][j].z = 2 * i - 4;
        }

    MyAnim << new bp(v);

    MyAnim.Render();
    MyAnim.Timer();;
    MyAnim.Run();
    return 0;
}
