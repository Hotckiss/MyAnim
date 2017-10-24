#include"anim.h"
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a > b) ? b : a)
namespace akgl
{
    class bp : public object
    {
    public:
        vec P[4][4];
        bp(vec p[4][4]) : object()
        {
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    P[i][j] = p[i][j];
        }
        ~bp()
        {
        }
        void Render(anim &Ani);
        void Response(anim &Ani);
    private:
        vec dir[4][4];
        vec ps[100][100];
        int C(int k, int n)
        {
            long long res = 1;
            for (int i = MAX(k, n - k) + 1; i <= n; i++)
                res *= i;
            for (int i = 2; i <= MIN(k, n - k); i++)
                res /= i;
            return (int)res;
        }
        double B(int k, int n, double u)
        {
            return C(k, n) * pow(u, k) * pow(1 - u, n - k);
        }
    };
}
