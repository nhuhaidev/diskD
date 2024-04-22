#include <iostream>
using namespace std;
int calculate_combination(int n)
{
    int sum = 1;
    for (int i = 1; i <= n; i++)
        sum *= i;
    return sum;
}
void create_2_arr(int **&arr, int size_n, int size_combination)
{
    arr = new int *[size_combination];
    for (int i = 0; i < size_combination; i++)
        arr[i] = new int[size_n];
}
void create_1_arr(int *&num, int size_n)
{
    num = new int[size_n];
    for (int i = 1; i <= size_n; i++)
        num[i] = 0;
}
void deleter_2_arr(int **&arr, int size)
{
    for (int i = 0; i < size; i++)
        delete arr[i];
    delete[] arr;
}
void deleter_1_arr(int *&num, int size)
{
    delete[] num;
}
void combination_num(int **&arr, int *&num, int n, int tem)
{
    if (tem == n)
    {
        static int count = 0;
        for (int i = 0; i < n; i++)
        {
            arr[count][i] = num[i];
        }
        count++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (num[i] == 0)
        {
            num[i] = tem + 1;
            combination_num(arr, num, n, tem + 1);
            num[i] = 0;
        }
    }
}
void output(int **arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int **arr, *num;
    int n, sum, tem = 0;
    cout << "Nhap N= ";
    cin >> n;
    sum = calculate_combination(n);
    create_2_arr(arr, n, sum);
    create_1_arr(num, n);
    combination_num(arr, num, n, tem);
    output(arr, sum, n);
    deleter_1_arr(num, n);
    deleter_2_arr(arr, sum);
    return 0;
}