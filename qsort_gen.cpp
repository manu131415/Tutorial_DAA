//Quicksort using two pivots
#include<iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void qsort(int arr[], int low, int high)
{
    if (low < high)
    {
        if (arr[low] > arr[high])
            swap(&arr[low], &arr[high]);
        int j = low + 1;
        int g = high - 1, k = low + 1, p = arr[low], q = arr[high];
        while (k <= g)
        {
            if (arr[k] < p)
            {
                swap(&arr[k], &arr[j]);
                j++;
            }
            else if (arr[k] >= q)
            {
                while (arr[g] > q && k < g)
                    g--;
                swap(&arr[k], &arr[g]);
                g--;
                if (arr[k] < p)
                {
                    swap(&arr[k], &arr[j]);
                    j++;
                }
            }
            k++;
        }
        j--;
        g++;
        swap(&arr[low], &arr[j]);
        swap(&arr[high], &arr[g]);
        qsort(arr, low, j - 1);
        qsort(arr, j + 1, g - 1);
        qsort(arr, g + 1, high);
    }
}
int main()
{
    int arr[] = {24, 8, 42, 75, 29, 77, 38, 57};
    int n = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
