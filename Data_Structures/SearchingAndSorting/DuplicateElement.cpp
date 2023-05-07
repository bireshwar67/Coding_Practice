#include<bits/stdc++.h>
using namespace std;
 
//Finding duplicate element of an Array with size n;

int checkDuplicate(int arr[], int n){
    for(int i  = 0; i< n ; i ++){
        for(int j = i+1 ; j < n ; j++){
            if(arr[i] == arr[j])
            cout << "Found the Duplicate Element" << arr[i];
            return arr[i];
        }
    }
    cout << "Found no Duplicate" ;
    return 0;
}

int main(){
    int n;
    cout << "Enter the length of an array : ";
    cin >> n;
    
    cout << "Enter the element of the array : ";  
    int arr[n]; 
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << checkDuplicate(arr, n) << endl;
    /*
    for (int i = 0; i < n ; i ++){
        for( int j = i+1; i<n ; j++){
            if(arr[i] == arr[j]){
                cout<< "The duplicate Element is " << arr[i];
                return 0;
            }
        }
        cout << "No Duplicate element found";
    }*/
    cout << "Entered element in the array was :  "<< endl;
    for(int j = 0; j< n; j++){
        cout << arr[j] << " ";
    }
    return 0;
}