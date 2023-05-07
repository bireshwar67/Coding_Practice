// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cout <<"Enter N : " ;
//     cin >> n;
//     vector<int> nums(3*n);
//     cout << "\nEnter "<< 3*n <<" elements in array : ";
//     for(int i=0; i <3*n; i++){
//         cin >>nums[i];
//         // cout << "\n";
//     }
//     // cout << "\n2D Array is : " << endl;
//     //     for(int i=0; i <n; i++){
//     //     for(int j = 0; j < n+1; j++){
//     //         cout << arr[i][j] << " ";
//     //     }
//     //     cout << "\n";
//     // }
//     // for(int i=0; i<nums.size();i++)
//     //     cout << nums[i] << " " ;
//     sort(nums.begin(), nums.end());
//     int mid = nums.size()/2;
//     int left = 0, right = 0;
//     for(int i = 0; i < mid; i++)
//         left += nums[i];
//     for(int j = mid; j < nums.size(); j++)
//         right += nums[j];
//     cout << abs(left-right);
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    cout << "Enter N : ";
    int t;
    cin >> t;
    int maxx = 1, sum = 0;
    vector<pair<int, int>> v;
    cout << "\nEnter elements in pair of 3 : ";
    for (int i = 0; i < t; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        v.push_back({x, x + d});
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        maxx = max(maxx, v[i].first);
        if (maxx <= v[i].second)
        {
            sum += v[i].second - maxx + 1;
            maxx = v[i].second + 1;
        }
    }
    cout << sum << endl;
    return 0;
}