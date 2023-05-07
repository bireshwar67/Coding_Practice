#include<bits/stdc++.h>
using namespace std;
void miniMaxSum(vector<int> arr) {
    long int total = 0;
    int minV = arr[0];
    int maxV = arr[0];
    
    for(int i = 0; i < arr.size(); i++) {
        total += arr[i];
        minV = min(minV, arr[i]);
        maxV = max(maxV, arr[i]);
    }
    cout <<(total - maxV)<<" "<<(total - minV)<<"\n"; 
}

void printV(const vector<int> &arr) {
    for(auto v : arr){
        cout << v <<" ";
    }
    cout <<"\n";
}

int main(){
    vector<int> arr({1,3,5,7,9});
    printV(arr);
    miniMaxSum(arr);
}