#include <iostream>
using namespace std;

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// Insert at 1-based position
void insertArray(int arr[], int &n, int value, int position)
{
    int index = position - 1;
    for (int i = n; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    n++;
}

// Delete from 1-based position
void deleteArray(int arr[], int &n, int position)
{
    int index = position - 1;
    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
}

void bubbleSortArray(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void binarySearchArray(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            cout << "Value found at position " << mid + 1 << "!" << endl;
            return;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "Value not found!" << endl;
}