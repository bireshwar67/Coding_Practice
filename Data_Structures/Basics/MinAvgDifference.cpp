#include<bits/stdc++.h>
using namespace std;

int minimumAverageDifference(vector<int>& nums) {
    int n = nums.size();
    
    int ans = INT_MAX;
    long long front = 0;
    long long totalSum = 0;
    int index = 0;
    
    for(auto it : nums)
        totalSum += it;
    
    for(int i = 0; i < n; i++){
        front += nums[i];
        long long left = front/ (i+1);
        totalSum -= nums[i];
        long long restAvg = i < n-1 ? (totalSum/ (n-i-1)) : 0;
        
        int diff = abs(left - restAvg);
        if(diff < ans){
            ans = diff;
            index = i;
        }
    }
    return index;
}

int main()
{
    vector<int> nums = {2, 5, 3, 9, 5, 3};
    int result = minimumAverageDifference(nums);
    cout << "Minimum average difference is in Index : " << result << endl;

    return 0;
}
