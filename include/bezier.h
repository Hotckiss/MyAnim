#include"anim.h"
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a > b) ? b : a)
// ������ ����� �������� � �������, ���� ������� �� ����������������� ������� � ��������� - �� �������� ������������ ��� ��� �(k n) * (t)^i * (1 - t) ^ (n - i)
namespace akgl
{   
    class bez : public object
    {
    public:
        vec P[25];
        // ����������� �� ������� ������ � ����� ��������� � ��� - ����� ����� � � ���� �����
        bez(vec *p, int n) : object()
        {
            //���������� ����������� ����� � �� ����������� ��������
            for (int i = 0; i < n; i++)
            {
                P[i] = p[i];
                dir[i] = vec::Rnd1();
            }
            //����� �����, n = size - 1
            size = n;
        }
        ~bez()
        {
        }
        void Render(anim &Ani);
        void Response(anim &Ani);
    private:
        // ������ ��� � � ������� �
        vec dir[25];
        // �� ������ �� ����� ������ // ���� ������� ��� �� ���� :)
        // ��� ������ ����� ������, 500 ����
        vec positions[500];
        // ����� �������� ����� - ������ �
        int size;
        // ������� ��������� ��� ������� // �� ���� � ��� ���)
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