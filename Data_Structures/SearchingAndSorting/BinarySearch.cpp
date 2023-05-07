#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int n, int data)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (a[mid] == data)
        {
            return mid;
        }
        else if (a[mid] < data)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int n;
    int arr[n];
    cout << "Enter the length of an array : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cout << "Enter key to find :";
    cin >> k;
    cout << binarySearch(arr, n, k) << "\n";

    return 0;
}