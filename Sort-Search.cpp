#include <iostream>
using namespace std;
void swap(int &num1, int &num2)
{
    int tem = num1;
    num1 = num2;
    num2 = tem;
}
void selectionSort(int a[], int n)
{
    int min_pos, i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            min_pos = i;
            if (a[i] >= a[j])
                min_pos = j;
            swap(a[min_pos], a[i]);
        }
    }
}
void insertSort(int a[], int n)
{
    int tem, i, j;
    for (i = 1; i < n; i++)
    {
        tem = a[i];
        j = i - 1;
        while (j >= 0 && tem < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tem;
    }
}
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        }
    }
}
void interchangeSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
void quickSort(int a[], int left, int right)
{
    int center = a[(left + right) / 2];
    int l = left;
    int r = right;
    while (l < r)
    {
        while (a[l] < center)
            l++;
        while (a[r] > center)
            r--;
        if (l <= r)
        {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }
    if (left < r)
        quickSort(a, left, r);
    if (right > l)
        quickSort(a, l, right);
}
void shift(int a[], int i, int n)
{
    int j = 2 * i + 1;
    if (j > n)
        return;
    if (j + 1 < n)
        if (a[j] < a[j + 1])
            j++;
    if (a[i] >= a[j])
        return;
    else
    {
        swap(a[i], a[j]);
        shift(a, j, n);
    }
}
void heapSortt(int a[], int n)
{
    int i = n / 2 - 1;
    while (i >= 0)
    {
        shift(a, i, n);
        i--;
    }
    int right = n - 1;
    while (right > 0)
    {
        swap(a[0], a[right]);
        right--;
        if (right > 0)
            shift(a, 0, right);
    }
}

void merge(int a[], int tem[], int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos - 1;
    int temPos = leftPos;
    int num_size = rightEnd - leftPos + 1;
    while (leftPos <= leftEnd && rightPos <= rightEnd)
    {
        if (a[leftPos] < a[rightPos])
        {
            tem[leftPos] = a[leftPos];
            leftPos++;
        }
        else
        {
            tem[temPos] = a[rightPos];
            rightPos++;
        }
        temPos++;
    }
    while (leftPos <= leftEnd)
    {
        tem[temPos] = a[leftPos];
        temPos++;
        leftPos++;
    }
    while (rightPos <= rightEnd)
    {
        tem[temPos] = a[rightPos];
        temPos++;
        rightPos++;
    }
    for (int i = 0; i < num_size; i++)
    {
        a[rightEnd] = tem[rightEnd];
        rightEnd--;
    }
}

void mergeSort(int a[], int tem[], int left, int right)
{

    int center;
    if (left < right)
    {
        center = (left + right) / 2;
        mergeSort(a, tem, left, center);
        mergeSort(a, tem, center + 1, right);
        merge(a, tem, left, center + 1, right);
    }
}
int main()
{
    int tem[100];
    int a[] = {1, 4, 6, 2, 3, 5, 10, 7, 9, 8};
    int n = sizeof(a) / sizeof(int);
    display(a, n);
    // selectionSort(a, n);
    // insertSort(a, n);
    // bubbleSort(a, n);
    // interchangeSort(a, n);
    // quickSort(a, 0, n - 1);
    // heapSortt(a, n);
    mergeSort(a, tem, 0, n - 1);
    display(a, n);
    return 1;
}