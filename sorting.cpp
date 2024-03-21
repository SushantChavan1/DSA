#include <iostream>
using namespace std;
void simple_sort(int p[], int);
void bubble_sort(int p[], int);
void selection_sort(int p[], int);
void shell_sort(int p[], int);
int split(int[], int, int);
int *quick(int[], int, int);
int *mergesort(int[], int, int);
void merge(int[], int, int, int, int);
int *insertion_sort(int[], int);

int *insertion_sort(int p[], int size){
    int k,t;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (p[i] < p[j])
            {
                t = p[j];
                p[j] = p[i];
                for ( k = i; k > j; k--)
                {
                    p[k] = p[k - 1];
                }
                p[k + 1] = t;
            }
        }
    }
    return p;
}

int *mergesort(int a[], int i, int j){
    int mid;
    if (i < j)
    {
        mid = (i + j) / 2;
        mergesort(a, i, mid);         // left recursion
        mergesort(a, mid + 1, j);     // right recursion
        merge(a, i, mid, mid + 1, j); // merging of two sorted sub-arrays
    }
    return a;
}
void merge(int a[], int i1, int j1, int i2, int j2)
{
    int temp[50]; // array used for merging
    int i, j, k;
    i = i1; // beginning of the first list
    j = i2; // beginning of the second list
    k = 0;
    while (i <= j1 && j <= j2) // while elements in both lists
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= j1) // copy remaining elements of the first list
    {
        temp[k++] = a[i++];
    }
    while (j <= j2) // copy remaining elements of the second list
    {
        temp[k++] = a[j++];
    }
    // Transfer elements from temp[] back to a[]
    for (i = i1, j = 0; i <= j2; i++, j++)
    {
        a[i] = temp[j];
    }
}

int *quick(int z[], int lw, int up)
{
    int i;
    if (up > lw)
    {
        i = split(z, lw, up);
        quick(z, lw, i - 1);
        quick(z, i + 1, up);
    }
    return z;
}
int split(int z[], int lw, int up)
{
    int pivot, upper, lower, t;
    lower = lw;
    upper = up;
    pivot = z[lw];
    while (upper > lower)
    {
        while (z[lower] <= pivot)
        {
            lower++;
        }
        while (z[upper] > pivot)
        {
            upper--;
        }
        if (upper > lower)
        {
            t = z[lower];
            z[lower] = z[upper];
            z[upper] = t;
        }
    }
    t = z[lw];
    z[lw] = z[upper];
    z[upper] = t;
    return (upper);
}

void shell_sort(int p[], int size)
{
    int temp, gap = size / 2;
    while (gap != 0)
    {
        for (int j = gap; j < size; j++)
        {
            for (int i = j - gap; i >= 0; i = i - gap)
            {
                if (p[gap + i] <= p[i])
                {
                    temp = p[i];
                    p[i] = p[gap + i];
                    p[gap + i] = temp;
                }
            }
        }
        gap = gap / 2;
    }
    cout << "\nSorted array by using Shell Sort::\n";
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << p[i];
    }
    cout << "\n";
}

void selection_sort(int p[], int size)
{
    int min, temp, pos;
    for (int i = 0; i < size; i++)
    {
        min = p[i];
        for (int j = i; j < size; j++)
        {
            if (min > p[j])
            {
                min = p[j];
                pos = j;
            }
        }
        if (p[i] != min)
        {
            temp = p[i];
            p[i] = p[pos];
            p[pos] = temp;
        }
    }
    cout << "\nSorted array by using Selection Sort::\n";
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << p[i];
    }
    cout << "\n";
}

void simple_sort(int p[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (p[i] > p[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    cout << "\nSorted array by using Simple Sort::\n";
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << p[i];
    }
    cout << "\n";
}

void bubble_sort(int p[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    cout << "\nSorted array using Bubble Sort::\n";
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << p[i];
    }
    cout << "\n";
}
int main()
{
    int ch, num;
    cout << "\nEnter the size of array";
    cin >> num;
    int *p = new int[num];
    cout << "\nEnter the " << num << " elements";
    for (int i = 0; i < num; i++)
    {
        cin >> p[i];
    }
    do
    {
        cout << "\n1.Simple Sort\n2.Bubble Sort\n3.Selection Sort\n4.shell Sort\n5.Quick Sort\n6.Merge Sort\n7.Insertion Sort\n8.Exit\n";
        cout << "\nEnter your choise";
        cin >> ch;
        switch (ch)
        {
        case 1:
            simple_sort(p, num);
            break;
        case 2:
            bubble_sort(p, num);
            break;
        case 3:
            selection_sort(p, num);
            break;
        case 4:
            shell_sort(p, num);
            break;
        case 5:
            p = quick(p, 0, num - 1);
            cout << "\nSorting Data\n";
            for (int i = 0; i < num; i++)
            {
                cout << "\t" << p[i];
            }
            break;
        case 6:
            p = mergesort(p, 0, num - 1);
            cout << "\nSorting Data\n";
            for (int i = 0; i < num; i++)
            {
                cout << "\t" << p[i];
            }
            break;
        case 7:
            p=insertion_sort(p,num);
            cout << "\nSorting Data\n";
            for (int i = 0; i < num; i++)
            {
                cout << "\t" << p[i];
            }
            break;
        case 8:
            exit(0);
        default:
            cout << "\nEnter correct choise";
        }
    } while (ch != 7);
    return 0;
}