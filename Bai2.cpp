#include <iostream>
#include <math.h>
using namespace std;
void push(int *&arr, int size, int value)
{
    int *temp = new int[size + 1];
    temp[size] = value;
    for (int i = 0; i < size; i++)
        temp[i] = arr[i];
    delete[] arr;
    arr = temp;
}

int input(int *&arr)
{
    char value;
    int size = 0;

    cout << "Enter the values of the array (or x to stop) \n";

    while (true)
    {
        cout << "Loop: ";
        cin >> value;
        if (value == 'x')
            break;

        push(arr, size, value - '0');
        size++;
    }

    return size;
}
void output(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void delete_arr(int *arr) { delete[] arr; }

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
int demsoluong(int *arr, int n)
{
    int soluong = 0;
    for (int i = 0; i < n; i++)
    {
        if (ktsochinhphuong(arr[i]))
            soluong++;
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
bool kiemtrasohoanthien(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == tongUoc(arr[i]))
            return true;
    }
    return false;
}
int main()
{
    int *arr = new int[0];
    int size = input(arr);
    output(arr, size);
    cout << "so luong so chinh phuong: " << demsoluong(arr, size) << endl;
    cout << "Mang ";
    (kiemtrasohoanthien(arr, size)) ? cout << " co " : cout << "khong co ";
    cout << "so hoan thien\n";
    delete_arr(arr);
    return 0;
}
