#include<bits/stdc++.h>
using namespace std;

vector<int> getConcat(vector<int> &nums){
    nums.insert(nums.end(),nums.begin(),nums.end());
    return nums;
}
int main(){
    vector<int> nums = {1,2,3,4};

    cout << "Objective is to repeate the same vector twice without using any extra space;" << endl;

    vector<int> ans = getConcat(nums);
    for(auto i : ans)
        cout << i << " ";
    return 0;
}