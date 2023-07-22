#include<bits/stdc++.h>
using namespace std;

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i= 0; i< m*n; i++){
            for(int j = 0; j < n; j++){
                ans[i] = matrix[i];
            }
            
        }
        return ans;
    }

int main(){
    vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9}};

    int m = matrix.size();
    int n = matrix[0].size();
    cout << "The Original Matrix : " << endl;
    for(int i=0; i< m*n;i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] <<" ";
        }
        cout << endl;
    }

    vector<int> ans =  spiralOrder(matrix);
    cout<< "/nRequired Result : " << endl;
    for(auto i : ans){
        cout << i<<" ";
    }
    return 0 ;
}