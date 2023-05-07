#include<bits/stdc++.h>
using namespace std;
int divisibleSumPairs(int n, int k, vector<int> ar) {
    vector<pair<int,int>> ans;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++ ){
            if((ar[i] + ar[j] ) % k == 0)
                ans.push_back(make_pair(ar[i],ar[j]));
        }
    }                  
     
   for (auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }   
    
    return ans.size();
}
int main(){
    vector<int> ar = {1, 3 ,2, 6, 1, 2};
    int result = divisibleSumPairs(6,3,ar);
    cout << result;
    return 0;
}