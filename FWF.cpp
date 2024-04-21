#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

void nhapkichco(int &r, int &c)
{
    cout << "nhap so dong: ";
    cin >> r;
    cout << "nhap so cot: ";
    cin >> c;
}
void taoMang(int **&a, int const r, int const c)
{
    a = new int *[r];
    for (int i = 0; i < r; i++)
        a[i] = new int[c];
}
void taoMaTran(int **&a, int const r, int const c)
{
    srand(time(NULL));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            a[i][j] = rand() % 9 + 1;
        }
    }
}
void xuatMang(int **a, int const r, int const c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void xoaMang(int **&a, int const r)
{
    for (int i = 0; i < r; i++)
        delete[] a[i];
    delete[] a;
}

bool ktsochinhphuong(int value)
{
    if (value == 1)
    {
        return true;
    }

    for (int i = 2; i <= sqrt(value); i++)
    {
        if (i * i == value)
            return true;
    }
    return false;
}
int demsoluong(int **a, int r, int c)
{
    int soluong = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (ktsochinhphuong(a[i][j]))
                soluong++;
        }
    }
    return soluong;
}
int tongUoc(int value)
{
    int tonguoc = 0;
    for (int i = 1; i < value; i++)
    {
        if (value % i == 0)
            tonguoc += i;
    }
    return tonguoc;
}
bool kiemtrasohoanthien(int **a, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] == tongUoc(a[i][j]))
                return true;
        }
    }
    return false;
}
void sumarr(int **a, int r, int c)
{
    int sum = 0;
    int **p = a;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum += *(*(p + i) + j);
        }
    }
    cout << "tong arr: " << sum << endl;
}
int main()
{

    int **a, r, c;
    nhapkichco(r, c);
    taoMang(a, r, c);
    taoMaTran(a, r, c);
    xuatMang(a, r, c);
    cout << "so luong so chinh phuong: " << demsoluong(a, r, c) << endl;
    cout << "Mang ";
    (kiemtrasohoanthien(a, r, c)) ? cout << " co " : cout << "khong co ";
    cout << "so hoan thien\n";
    sumarr(a, r, c);
    xoaMang(a, r);
    return 0;
}