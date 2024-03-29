#include <iostream>
using namespace std;

bool isLeap(int y)
{
    if (y % 4 != 0 || y % 100 == 0)
        if (y % 400 != 0)
            return false;
    return true;
}

void advance(int delta, int &d, int &m, int &y)
{
    int days_in_month;

    for (int i = 1; i <= delta; i++)
    {
        switch (m)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days_in_month = 31;
            break;

        case 2:
            if (isLeap(y))
            {
                days_in_month = 29;
                break;
            }
            days_in_month = 28;
            break;

        default:
            days_in_month = 30;
            break;
        }

        d += 1;
        if (d > days_in_month)
        {
            if (m == 12)
            {
                d = 1;
                m = 1;
                y += 1;
            }
            else
            {
                d = 1;
                m += 1;
            }
        }
    }
}

int main()
{
    {
        int d = 1, m = 1, y = 2022;
        advance(0, d, m, y);
        cout << d << ' ' << m << ' ' << y;
    }
    {
        int d = 1, m = 10, y = 2022;
        advance(10, d, m, y);
        cout << d << ' ' << m << ' ' << y;
    }
    {
        int d = 2, m = 6, y = 2022;
        advance(31, d, m, y);
        cout << d << ' ' << m << ' ' << y << '\n';
    }
    {
        int d = 2, m = 7, y = 2022;
        advance(31, d, m, y);
        cout << d << ' ' << m << ' ' << y << '\n';
    }
    {
        int d = 25, m = 2, y = 2000;
        advance(4, d, m, y);
        cout << d << ' ' << m << ' ' << y << '\n';
    }
    {
        int d = 25, m = 2, y = 2001;
        advance(4, d, m, y);
        cout << d << ' ' << m << ' ' << y << '\n';
    }
    {
        int d = 2, m = 12, y = 1900;
        advance(365 + 5, d, m, y);
        cout << d << ' ' << m << ' ' << y << '\n';
    }
    {
        int d = 31, m = 3, y = 1903;
        advance(365 + 366 + 30 + 5, d, m, y);
        cout << d << ' ' << m << ' ' << y << '\n';
    }
    return 0;
}
