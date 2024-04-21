#include <iostream>
#include <ctime>
using namespace std;
void create_arr(int *&arr, int &size)
{
    cout << "Enter size array: ";
    cin >> size;
    arr = new int[size];
}
void input(int *&arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter arr [" << i + 1 << "]= ";
        cin >> arr[i];
    }
}
void output(int *arr, int size)
{
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void create_matrix(int *&arr, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 9 + 1;
    }
}
void convert(int &a, int &b)
{
    int tem = a;
    a = b;
    b = tem;
}
void recursive_arrange(int *&arr, int size)
{
    if (size == 1)

        return;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= arr[size - 1])
            convert(arr[i], arr[size - 1]);
    }
    recursive_arrange(arr, size - 1);
}
// void recursive_
int main()
{
    int *arr, size;
    create_arr(arr, size);
    create_matrix(arr, size);
    output(arr, size);
    recursive_arrange(arr, size);
    output(arr, size);

    return 0;
}