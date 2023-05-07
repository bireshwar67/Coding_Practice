#include <iostream>
using namespace std; // print the no of ordered pair (i,j) where i < j & a[i] > a[j];

int merge(int A[], int start, int mid, int end)
{
    int count = 0;
    int i = start, j = mid + 1;
    int Arr[end - start + 1], k = 0;
    // auto printArr = [&](int st, int ed)  {
    //     for(int x = st ; x <= ed;++x) {
    //         cout << A[x] <<" ";
    //     }
    //     cout <<"\n";
    // };
    // printArr(start, mid);
    // printArr(mid + 1, end);
    while (i <= mid && j <= end)
    {
        if (A[i] > A[j])
        {
            cout << A[i] << ">" << A[j] << "\n";
            Arr[k++] = A[j++];
            count += (mid - i + 1);
        }
        else
        {
            Arr[k++] = A[i++];
        }
    }
    while (i <= mid)
    {
        Arr[k++] = A[i++];
    }
    while (j <= end)
    {
        Arr[k++] = A[j++];
    }

    for (int i = start, x = 0; i <= end; ++i)
    {
        A[i] = Arr[x++];
    }
    return count;
}

int merge_sort(int A[], int start, int end)
{
    if (start >= end)
        return 0;
    // cout << "here\n";
    int mid = (start + end) / 2;                   // defines the current array in 2 parts .
    int count_left = merge_sort(A, start, mid);    // sort the 1st part of array .
    int count_right = merge_sort(A, mid + 1, end); // sort the 2nd part of array.

    // merge the both parts by comparing elements of both the parts.
    return count_left + count_right + merge(A, start, mid, end);
}

int main()
{
    int n;
    cin >> n; // Reading input from STDIN
    int Arr[n];
    cout << "Input number is " << n << endl; // Writing output to STDOUT
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }
    int ans = merge_sort(Arr, 0, n - 1);
    cout << "Total Ordered pair" << endl;
    cout << ans << endl;
    return 0;
}