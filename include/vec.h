#include<cstdio>
#include<cstdlib>
/*akgl - ������ ������������ ����, ��� � std, ��� ������ � ������� � �� ����� ������ ����, ��� ���� ��� ����� aegl.
��� ����� �������, ������ ��� ��� �� ���� struct vec, ���� � ������ ����� public: �� ��� ��� ���� �� ��� �� ���� ����� �� ���������� �� ����������� ��������� ��� ����, ��� ����� ������ ������ ������,
�������� � ����� ����� �������� vec a; a.x = 0; ���� �� ��� ���� private: �� ��� ������ ���� �� �������*/
namespace akgl
{
    // ������ �������� ������ 3 �������
    class vec
    {
    public:
        //3 �����
        double x, y, z;
        // ���� �� ������� vec a; � ����� cout << a.x << a.y << a.z; ����� �������� 000, ����������� �� ���������
        vec(void) : x(0), y(0), z(0)
        {
        }
        // vec a(1.1, 2.2, 3.3); ������ 3 �������
        vec(double a, double b, double c) : x(a), y(b), z(c)
        {
        }
        // ���� �� ����� � ������ ����� �� �������, �������� �������� 2 ��������, �� ���������, ��� � ��� 1 ������ ���(!) ����, � ��� ��������� ������� ����� 1 �������� - 2� ������.
        // �������� ������������, �������� vec a; vec b(1, 1, 1); ������ ����� �������� a = b;
        // ��� ��� �� ����� ��� ������ ������, �� � ��� ��� ���� ������, � ������� �� ����� ��������� �� ������� �������, � ������� ���� ��� ��� ������ - *this
        // const vec &V const ��������, ��� �� �� ����� ������ ������ ������� � ��� ���������, ����� a = b; b ��������� ��� ���������
        vec & operator=(const vec &V)
        {
            x = V.x;
            y = V.y;
            z = V.z;
            return *this;
        }
        // ���������� � ������(1) ������� ������� �������
        vec & operator+=(const vec &V)
        {
            x += V.x;
            y += V.y;
            z += V.z;
            return *this;
        }
        // � ������� �� ����������, ������� �����(!) ������, vec c; c = a - b;
        vec operator-(const vec &V) const
        {
            return vec(x - V.x, y - V.y, z - V.z);
        }
        // ����� ����
        vec operator+(const vec &V) const
        {
            return vec(x + V.x, y + V.y, z + V.z);
        }
        // ��������� ������� �� �����
        vec operator*(const double a) const
        {
            return vec(x * a, y * a, z * a);
        }
        // ��������� ������������, ������� ��� ���� ����� �������, ���� ���������� ���� �����)))
        vec operator^(const vec &V) const
        {
            return vec(y * V.z - z * V.y, z * V.x - x * V.z, x * V.y - y * V.x);
        }
        // ������� ����� �������
        double operator!(void)
        {
            return x * x + y * y + z * z;
        }
        // ����� �������� ������������ ���������
        double operator&(const vec &V) const
        {
            return x * V.x + y * V.y + z * V.z;
        }
        // ������� ���������� ��������� ������ ������������� �� 0 �� 1, static ��������, ��� �� �� ���������� ��� ������ this (��� ���������� x, y, z ������)
        static vec Rnd0(void)
        {
            return vec(1.0 * rand() / RAND_MAX, 1.0 * rand() / RAND_MAX, 1.0 * rand() / RAND_MAX);
        }
        // �� -1 �� 1
        static vec Rnd1(void)
        {
            return Rnd0() * 2 - vec(1, 1, 1);
        }
        // �� �� ����� ����������
        void print(void)
        {
            printf(" %lf %lf %lf \n", x, y, z);
        }
    };
}

