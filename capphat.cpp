#include <iostream>
using namespace std;

int main()
{
    char *array = new char[1]; // Cấp phát động cho 1 phần tử
    char input;
    int size = 0;
    cout << "Nhập các phần tử của mảng (nhập 'c' để dừng): ";
    while (cin >> input && input != 'c')
    {
        array[size] = input;
        size++;

        char *temp = new char[size]; // Tạo mảng tạm để chứa các phần tử mới
        for (int i = 0; i < size; i++)
        {
            temp[i] = array[i]; // Sao chép các phần tử từ mảng cũ sang mảng mới
        }

        delete[] array; // Giải phóng bộ nhớ của mảng cũ
        array = temp;   // Gán mảng mới cho mảng cũ
    }

    cout << "Các phần tử của mảng là: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    delete[] array; // Giải phóng bộ nhớ đã cấp phát

    return 0;
}