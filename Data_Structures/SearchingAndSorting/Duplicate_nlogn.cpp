#include<bits/stdc++.h>
using namespace std;
 int main(){
    int n;
    cout << "Enter the size for the array : ";
    vector <int> arr;
    cout << "Enter the element of the array : ";
    for(int i= 0; i <n -1 ; i++){
        arr.push_back(i);
    }

    // now the actual work;

    array.sort(arr, n);
    for( int i =0; i<n ; i++){
        if(arr[i] == arr[i+1]){
            return vector <int> arr[i];
        }
    }
    return 0;

 }