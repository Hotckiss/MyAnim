#include"anim.h"
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a > b) ? b : a)
//  рива€ безье задаетс€ н точками, есть формула ее посторени€котора€ аписана в википедии - по индукции доказываетс€ что это —(k n) * (t)^i * (1 - t) ^ (n - i)
namespace akgl
{   
    class bez : public object
    {
    public:
        vec P[25];
        // конструктор по массиву вершин и числу элементов в нем - число точек Ќ и сами точки
        bez(vec *p, int n) : object()
        {
            //записываем управл€ющие точки и их направление движени€
            for (int i = 0; i < n; i++)
            {
                P[i] = p[i];
                dir[i] = vec::Rnd1();
            }
            //число точек, n = size - 1
            size = n;
        }
        ~bez()
        {
        }
        void Render(anim &Ani);
        void Response(anim &Ani);
    private:
        // размер как и у массива –
        vec dir[25];
        // не мен€ем от балды размер // этот коммент был не тебе :)
        // это массив точек кривой, 500 норм
        vec positions[500];
        // число основных точек - массив –
        int size;
        // считаем сочетани€ дл€ формулы // ну кого € тут учу)
        int C(int k, int n)
        {
            long long res = 1;
            for (int i = MAX(k, n - k) + 1; i <= n; i++)
                res *= i;
            for (int i = 2; i <= MIN(k, n - k); i++)
                res /= i;
            return (int)res;
        }
    };
}