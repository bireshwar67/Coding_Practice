#include <bits/stdc++.h>
using namespace std;
int hsbc(vector<int> nums, int s){
    nums.push_back(s);
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++){
        if(nums[i] == s){
            int left = i;
            int right = n - i -1 ;
            return abs(left - right);
        }
    }
    return -1;
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // int T;
    // cin >> T;
    // for(int t_i = 0; t_i < T; t_i++)
    // {
    int N, S;
    cin >> N;
    cin >> S;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    // test case 4 3 1 ;
    int out_;
    out_ = hsbc(nums, S);
    cout << out_;
    cout << "\n";

    return 0;
}