// #include<bits/stdc++.h>
// using namespace std;
// // You are given a string of length 2N consisting of only digits from 0 to 9. 
// // You can make a move to choose an arbitrary position and replace the digit in that position with any digit from 0 to 9.
// int solve (int n, string s) {
//    // Write your code here
//     int count = 0, diff;
//     sort(s.begin() , s.begin() + n);
//     sort(s.begin() + n, s.end());
//     int leftSum, rightSum;
//     for(int i = 0; i < n; i++){
//         leftSum += s[i] - '0';
//     }
//     for(int j = n; j < 2*n; j++){
//         rightSum += s[j] - '0';
//     }
//     // int diff = high - low; 
//     // int high = max(leftSum, rightSum);
//     // int low = min(leftSum, rightSum);
//     if(leftSum < rightSum){
//         diff = rightSum - leftSum;
//         while(diff != 0){
//             for(int i = 0; i < n; i++){
//                 if(diff <= 9){
//                     s[i] = s[i] + diff;
//                     count ++;
//                     break;
//                 }
//                 else{
//                     s[i] += 9;
//                     count ++;
//                     diff -= 9;
//                     continue;
//                 }
//             }
//         }
//     }
//     else{
//         diff = leftSum - rightSum;
//         while(diff != 0){
//             for(int i = n +1; i < s.size(); i++){
//                 if(diff <= 9){
//                     s[i] = s[i] + diff;
//                     count ++;
//                     break;
//                 }
//                 else{
//                     s[i] += 9;
//                     count ++;
//                     diff -= 9;
//                     continue;
//                 }
//             }
//         }
//     }
//     return count;
// }

// int main() {

//     // ios::sync_with_stdio(0);
//     // cin.tie(0);
//     // int T;
//     // cin >> T;
//     // for(int t_i = 0; t_i < T; t_i++)
//     // {
//     //     int N;
//     //     cin >> N;
//     //     string S;
//     //     cin>>S;
//     //     int out_;
//     //     out_ = solve(N, S);
//     //     cout << out_;
//     //     cout << "\n";
//     // }
//     int n;
//     cout << "Enter N : " ;
//     cin >> n;
//     string s;
//     for(int i = 0; i < (2*n); i++){
//         cin >> s[i];
//     }
//     return solve(n, s);
// }
#include<bits/stdc++.h>
using namespace std;

int solve (int n, string s) {
   // Write your code here
    int count = 0, diff;
    sort(s.begin() , s.begin() + n);
    sort(s.begin() + n , s.end());
    int leftSum = 0, rightSum = 0;
    for(int i = 0; i < n; i++){
        leftSum += s[i] - '0';
    }
    for(int j = n; j < s.size(); j++){
        rightSum += s[j] - '0';
    }
    if(leftSum < rightSum){
        diff = rightSum - leftSum;
        while(diff != 0){
            for(int i = 0; i < n; i++){
                if(diff <= 9){
                    s[i] = s[i] + char(diff);
                    count ++;
                    break;
                }
                else{
                    s[i] += '9';
                    count ++;
                    diff -= 9;
                }
            }
        }
    }
    else{
        diff = leftSum - rightSum;
        while(diff != 0){
            for(int i = n; i < s.size(); i++){
                if(diff <= 9){
                    s[i] = s[i] + char(diff);
                    count ++;
                    break;
                }
                else{
                    s[i] += '9';
                    count ++;
                    diff -= 9;
                }
            }
        }
    }
    return count;
}

int main() {

    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // int T;
    // cin >> T;
    // for(int t_i = 0; t_i < T; t_i++)
    // {
    //     int N;
    //     cin >> N;
    //     string S;
    //     cin>>S;
    //     int out_;
    //     out_ = solve(N, S);
    //     cout << out_;
    //     cout << "\n";
    // }
    // return 0;
    int n;
    cout << "Enter N : " ;
    cin >> n;
    string s;
    for(int i = 0; i < (2*n); i++){
        cin >> s[i];
    }
    return solve(n, s);
    int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        string S;
        cin>>S;
        int out_;
        out_ = solve(N, S);
        cout << out_;
        cout << "\n";
    }
}
}
