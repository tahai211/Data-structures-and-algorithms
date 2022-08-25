#include <iostream>
using namespace std;

void InsertionSort(int a[], int n)
{
    bool flag = true;
    int tmp;

    for (int i = 1; i < n; i++)
    {
        int ai = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > ai)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = ai;
    }
}
void BubbleSort(int a[], int n)
{
    int tmp;
    bool flag = false;
    for (int i = 0; i < n - 1; i++)
    {
        flag = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = true;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
}
void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(a[i], a[min]);
        }
    }
}
void QuickSort(int a[], int l, int r)
{
    // l diem bat dau sap xep
    // r diem cuoi cung sap xep
    int p = a[(l + r) / 2];
    int i = l, j = r;
    while (i < j)
    {
        while (a[i] < p)
        {
            i++;
        }
        while (a[j] > p)
        {
            j--;
        }
        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (i < r)
    {
        QuickSort(a, i, r);
    }
    if (l < j)
    {
        QuickSort(a, l, j);
    }
}
void merge(int a[], int l, int m, int r)
{
    // l vi tri dau
    // r vi tri cuoi
    // m vi tri giua
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1]; // tao cac mang tam de luu gt
    int R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = a[m + 1 + j];
    }
    int i = 0; // khoi tao chi so dau
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)//copy cac phan tu con lai vao mang a[]
    {
         a[k] = L[i];
            i++;
            k++;
    }
     while (j < n2)
    {
         a[k] = R[j];
            j++;
            k++;
    }
    
}
void MergeSort(int a[], int l, int r){
    if (r>l)
    {
        int m = l+(r-l)/2;
        MergeSort(a,l,m);
        MergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
    
} 
int main()
{
    int n;
    int a[] = {64, 34, 25, 12, 22, 11, 90};
    cin >> n;
    /*for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }*/
    int x = 3;
    int y = n - 1;
    MergeSort(a, x, y);
    for (int j = 0; j < n; j++)
    {
        cout << a[j] << "  ";
    }
}