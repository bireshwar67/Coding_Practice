#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        next_permutation(nums.begin(), nums.end());
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3};

    cout << "Original permutation: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    solution.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}