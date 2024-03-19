#include <iostream>
using namespace std;
void simple_sort(int p[], int);
void bubble_sort(int p[], int);
void selection_sort(int p[], int);
void shell_sort(int p[], int);

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
        cout << "\n1.Simple Sort\n2.Bubble Sort\n3.Selection Sort\n4.shell Sort\n5.Exit\n";
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
            exit(0);
        default:
            cout << "\nEnter correct choise";
        }
    } while (ch != 5);
    return 0;
}