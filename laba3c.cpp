#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <time.h>
//Task 12
using namespace std;

void insertionsort(int a[], int low, int high)
{

    for (int i = low + 1; i <= high; i++)
    {
        int value = a[i];
        int j = i;
        while (j > low && a[j - 1] > value)
        {
            a[j] = a[j - 1];
            j--;
        }

        a[j] = value;
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int pIndex = low;
    for (int i = low; i < high; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap (a[pIndex], a[high]);
    return pIndex;
}
int randPartition(int a[], int low, int high)
{

    int pivotIndex = rand() % (high - low + 1) + low;
    swap(a[pivotIndex], a[high]);
    return partition(a, low, high);
}

void heapsort(int *begin, int *end)
{
    make_heap(begin, end);
    sort_heap(begin, end);
}
void introsort(int a[], int *begin, int *end, int maxdepth)
{
    if ((end - begin) < 16) {
        insertionsort(a, begin - a, end - a);
    }
    else if (maxdepth == 0) {
        heapsort(begin, end + 1);
    }
    else {
        int pivot = randPartition(a, begin - a, end - a);
        introsort(a, begin, a + pivot - 1, maxdepth - 1);
        introsort(a, a + pivot + 1, end, maxdepth - 1);
    }
}
void library_sort(int array[],int size)
{
    sort(array,array+8);
    for(int i =0;i<size;i++)
    {
        cout << array[i] << " ";
    }
}
void Demo()
{
    int size = 0;
    cout << "Size of array" << endl;
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++) {
        array[i] = 0 + rand() % 10;
    }
    cout << "Created an array of random numbers:" << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    int n = sizeof(array) / sizeof(array[0]);
    int maxdepth = log(n) * 2;
    introsort(array, array, array + n - 1, maxdepth);
    cout << endl;
    cout << " Array now " << endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
}
void benchmark()
{
    clock_t tic = clock();
    Demo();
    clock_t toc = clock();
    cout << endl;
    double result = (double)(toc - tic) / CLOCKS_PER_SEC;
    cout << "Library sort" << endl;
    clock_t tic2 = clock();
    int size = 0;
    cout << "Size of array" << endl;
    cin >> size;
    int array2[size];
    for (int i = 0; i < size; i++) {
        array2[i] = 0 + rand() % 10;
    }
    library_sort(array2,size);
    clock_t toc2 = clock();
    cout << endl;
    double result2 = (double)(toc2 - tic2) / CLOCKS_PER_SEC;

    cout << "Time=" << result-result2 << endl;
}
int main()
{
    int chose=0;
    cout << "0.exit" << endl;
    cout << "1.Demo" << endl;
    cout << "2. Bench" << endl;
    cin >> chose;
    switch (chose) {
        case 0:
            break;
        case 1:
            Demo();
            break;
        case 2:
            benchmark();
            break;
    }
}

