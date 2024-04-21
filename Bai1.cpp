#include <iostream>
#include <math.h>
using namespace std;
void input(int &a, int &b, int &c)
{
    cout << "Phuong trinh bac 2: ax^2 + bx + c = 0 (a # 0)\n"
         << "Nhap lan luot a, b, c: ";
    cin >> a >> b >> c;
}
int tinhDelta(int a, int b, int c)
{
    int delta;
    delta = (b * b) - (4 * a * c);
    return delta;
}
void output(int a, int b, int c, int fun)
{
    if (fun < 0)
    {
        cout << "Phuon trinh vo nghiem\n";
    }
    else if (fun == 0)
    {
        cout << "phuong trinh co 1 nghiem kep \n"
             << "x1 = x2= " << -b / 2 * a << endl;
    }
    else
    {
        cout << "phuong trinh co hai ngiem pham biet\n";
        cout << "x1= " << (-b - sqrt(fun)) / (2 * a) << endl;
        cout << "x2= " << (-b + sqrt(fun)) / (2 * a) << endl;
    }
}

int main()
{
    int a, b, c;
    input(a, b, c);
    output(a, b, c, tinhDelta(a, b, c));
    return 0;
}