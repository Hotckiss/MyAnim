#include<cstdio>
#include<cstdlib>
/*akgl - просто пространство имен, как и std, все классы и функции и тд пишем внутри него, для тебя это будет aegl.
Это класс вектора, считай что это по сути struct vec, если в классе стоит public: то все что идет за ним по сути ничем не отличается от стандартной структуры для тебя, все можно менять откуда угодно,
например в мэйне можно написать vec a; a.x = 0; если бы там было private: то это нельзя было бы сделать*/
namespace akgl
{
    // вектор задается просто 3 точками
    class vec
    {
    public:
        //3 точки
        double x, y, z;
        // если мы напишем vec a; а потом cout << a.x << a.y << a.z; будет выведено 000, конструктор по умолчанию
        vec(void) : x(0), y(0), z(0)
        {
        }
        // vec a(1.1, 2.2, 3.3); задаем 3 точками
        vec(double a, double b, double c) : x(a), y(b), z(c)
        {
        }
        // Если мы пишем в классе какую то функцию, например сложение 2 векторов, то считается, что у нас 1 вектор уже(!) есть, и для написания функции нужен 1 параметр - 2й вектор.
        // операция присваивания, например vec a; vec b(1, 1, 1); теперь можно написать a = b;
        // так как мы пишем все внутри класса, то у нас уже есть вектор, в который мы хотим присвоить из другого вектора, а вернуть надо сам наш вектор - *this
        // const vec &V const означает, что мы не будем менять вектор который к нам поступает, после a = b; b останется без изменений
        vec & operator=(const vec &V)
        {
            x = V.x;
            y = V.y;
            z = V.z;
            return *this;
        }
        // добавление к нашему(1) вектору другого вектора
        vec & operator+=(const vec &V)
        {
            x += V.x;
            y += V.y;
            z += V.z;
            return *this;
        }
        // в отличие от предыдущей, создает новый(!) вектор, vec c; c = a - b;
        vec operator-(const vec &V) const
        {
            return vec(x - V.x, y - V.y, z - V.z);
        }
        // сумма двух
        vec operator+(const vec &V) const
        {
            return vec(x + V.x, y + V.y, z + V.z);
        }
        // умножение вектора на число
        vec operator*(const double a) const
        {
            return vec(x * a, y * a, z * a);
        }
        // векторное произведение, формулу дал сомс через матрицы, могу рассказать если нужно)))
        vec operator^(const vec &V) const
        {
            return vec(y * V.z - z * V.y, z * V.x - x * V.z, x * V.y - y * V.x);
        }
        // квадрат длины вектора
        double operator!(void)
        {
            return x * x + y * y + z * z;
        }
        // сумма попарных произведений координат
        double operator&(const vec &V) const
        {
            return x * V.x + y * V.y + z * V.z;
        }
        // функция возвращает рандомний вектор скоординатами от 0 до 1, static означает, что мы не используем наш вектор this (там переменные x, y, z просто)
        static vec Rnd0(void)
        {
            return vec(1.0 * rand() / RAND_MAX, 1.0 * rand() / RAND_MAX, 1.0 * rand() / RAND_MAX);
        }
        // от -1 до 1
        static vec Rnd1(void)
        {
            return Rnd0() * 2 - vec(1, 1, 1);
        }
        // ну на экран напечатали
        void print(void)
        {
            printf(" %lf %lf %lf \n", x, y, z);
        }
    };
}

