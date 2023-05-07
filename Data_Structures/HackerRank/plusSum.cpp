#include<bits/stdc++.h>
using namespace std;
void plusMinus(vector<int> arr) {
    int n = arr.size();
    float positive = 0;
    float negative = 0;
    float zero = 0;
    
    for(int i  = 0; i < n; i++){
        if(arr[i] > 0)
            positive ++;
        if(arr[i] < 0)
            negative ++;
        if(arr[i] == 0)
            zero ++;            
    }
    cout << fixed << setprecision(6) << positive/float(n) << endl;
    cout << fixed << setprecision(6) << negative/float(n) << endl;
    cout << fixed << setprecision(6) << zero/float(n) << endl;

    cout << positive << endl;
    cout << negative << endl;
    cout << zero << endl;

}

void printV(const vector<int> &arr) {
    for(auto v : arr){
        cout << v <<" ";
    }
    cout <<"\n";
}

int main(){
    vector<int> arr({-1,1,0,-1,1});
    printV(arr);
    plusMinus(arr);
}