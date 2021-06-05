#include<iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;

void swapping(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void display(int *array, int size)
{
    for(int i = 0; i<size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
void bubbleSort(int *array, int size)
{
    cout << "Array before sorting" << endl;
    display(array,size);
    for(int i = 0; i<size; i++)
    {
        int swaps = 0;
        for(int j = 0; j<size-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                swapping(array[j], array[j+1]);
                swaps = 1;
            }
        }
        if(!swaps)
            break;
    }
    cout << "Array after sorting" << endl;
    display(array,size);

}
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true)
    {
        do{
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)return j;
        swap(arr[i], arr[j]);
    }
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout <<("\n");
}

void merge(int a[],int b[],int m,int n)
{
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(a[i]<b[j])
        {
            cout<<a[i++]<<" ";
        }
        else
        {
            cout<<b[j++]<<" ";
        }
    }
    while(i<m)
    {
        cout<<a[i++]<<" ";
    }
    while(j<n)
    {
        cout<<b[j++]<<" ";
    }

}
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
void printArray_merge(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}
void combsort(int arr1[],int size)
{
    cout << endl;
    cout << "Combosort" << endl;
    if(size<35)
    {
        cout << "Use bubblesort" << endl;
        bubbleSort(arr1,size);
    }else {
        quickSort(arr1, 0, size - 1);
        printArray(arr1,size);
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
void Demostrative()
{
    int size = 0;
    cout << "Size of array" << endl;
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++) {
        array[i] = 0 + rand() % 10;
    }
    cout << "Created an array of random numbers:" << endl;
    for(int i = 0;i<size;i++){
        cout << array[i] << " ";
    }

    cout << "First is bubbleSort" << endl;
    bubbleSort(array,size);

    cout << "Second is Hoare’s " << endl;
    quickSort(array,0,size-1);
    printArray(array,size);

    cout << "the third is merge " << endl;
    mergeSort(array,0,size-1);
    printArray_merge(array,size);
    cout << endl;

    combsort(array,size);
    cout << endl;

    cout << " library sort"<< endl;
    library_sort(array,size);

}
void benchmark() {
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
    cout << endl;
    int chose = 0;
    cout << "1.bubblesort" << endl;
    cout << "2.quicksort" << endl;
    cout << "3. mergesort" << endl;
    cout << "4.combosort" << endl;
    cout << "5.library sort" << endl;
    cin >> chose;
    double time1;
    double time2;
    switch (chose) {
        case 0:
            break;
        case 1:
            time1 = clock();
            bubbleSort(array,size);
            time2 = clock();
            cout << "time=" << (double)(time2 - time1)*1000.0 / CLOCKS_PER_SEC << endl;
            benchmark();
            break;
        case 2:
            time1 = clock();
            quickSort(array,0,size-1);
            printArray(array,size);
            time2 = clock();
            cout << "time=" << (double)(time2 - time1)*1000.0 / CLOCKS_PER_SEC << endl;
            benchmark();
            break;
        case 3:
            time1 = clock();
            mergeSort(array,0,size-1);
            printArray_merge(array,size);
            time2 = clock();
            cout << "time=" << (double)(time2 - time1)*1000.0 / CLOCKS_PER_SEC << endl;
            benchmark();
            break;
        case 4:
            time1 = clock();
            combsort(array,size);
            time2 = clock();
            cout << "time=" << (double)(time2 - time1)*1000.0 / CLOCKS_PER_SEC << endl;
            benchmark();
            break;
        case 5:
            time1 = clock();
            library_sort(array,size);
            time2 = clock();
            cout << "time=" << (double)(time2 - time1)*1000.0 / CLOCKS_PER_SEC << endl;
            benchmark();
            break;
    }
}
int main()
{
    int chose=0;
    cout << "0.Exit" << endl;
    cout << "1.Demo" << endl;
    cout << "2.benchmark" << endl;
    cin >> chose;
    switch (chose) {
        case 0:
            break;
        case 1:
            Demostrative();
            break;
        case 2:
            benchmark();
            break;
    }
    benchmark();
    return 0;
}