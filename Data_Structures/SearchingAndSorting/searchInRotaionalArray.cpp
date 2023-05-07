//Search in Rotated Sorted Array    with time complexity O(log n);
#include<bits/stdc++.h>
using namespace std;
int search(int nums[], int n, int target) {
        int low = 0;
        int high = n - 1;
        while (low <= high){
            int mid = low + (high-low)/2;
            if (nums[mid] == target){
                return mid;
            }
            if (nums[mid] >= nums[low]){
                if(target >= nums[low] && target <= nums[mid]){
                    high = mid -1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(target >= nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return -1;
}
int main (){
     
    int n;
    int nums[n];
    cout << "Enter the length of an array : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cout << "Enter key to find :";
    cin >> k;
    cout << search(nums, n, k) << "\n";

    return 0;
}
