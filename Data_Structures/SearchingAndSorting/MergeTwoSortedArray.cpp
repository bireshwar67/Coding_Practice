#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // Given : nums1.size() = m+n;
        int k = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while (j >= 0)
        {
            if (i >= 0 && nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
    }
};
// int main(){
//     vector<int> nums1;
//     vector<int> nums2;
//     int m,n;
//     cout<<"Enter Size of nums1 : ";
//     cin >> m;
//     cout<<"\nEnter Size of nums2 : ";
//     cin >> n;
//     cout <<"\nEnter Elements of size "<<m+n<<" where last "<<n<<" element shouldbe '0' : ";
//     for(int i = 0; i<m+n; i++){
//         cin >> nums1[i];
//     }
//     cout<<"\nEnter Element of size "<<n<<" for nums2";
//     for(int i = 0;i < n; i++){
//         cin >> nums2[i];
//     }
//     merge(nums1,m+n,nums2,n);
//     for(int i : nums1){
//         cout<< i << endl;
//     }

//     return 0;
// }
int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // m = 3
    vector<int> nums2 = {2, 5, 6};          // n = 3

    Solution s;
    s.merge(nums1, 3, nums2, 3);

    // Expected output: [1, 2, 2, 3, 5, 6]
    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}