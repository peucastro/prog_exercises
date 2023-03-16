#include "complex.h"
#include <math.h>

void add(const complex &a, const complex &b, complex &r)
{
    r = {a.x + b.x, a.y + b.y};
}

void mul(const complex &a, const complex &b, complex &r)
{
    r = {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};
}

void mandelbrot(const complex &c, unsigned int n, complex &z_n)
{
    complex z0 = {0.0, 0.0};
    complex mult;

    for (unsigned int i = 1; i <= n; i++)
    {
        mul(z0, z0, mult);
        add(mult, c, z_n);
        z0 = z_n;
    }
}

int main()
{
    complex z_n;
    mandelbrot({0.1, 3.2}, 4, z_n);
    cout << z_n << '\n';
    return 0;
}
