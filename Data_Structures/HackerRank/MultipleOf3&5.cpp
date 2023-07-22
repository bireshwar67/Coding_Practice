#include <bits/stdc++.h>

using namespace std;

long multipleSum(long n){
    long sum = 0;
    for(long i = 1; i < n; i++){
        if((i%3 == 0) ||(i%5 == 0))
            sum += i;
    }
    return sum;
}

int main()
{
    long t=0,n=0;
    cin>> t;
    for(long i=0; i<t;i++){
        cin >> n;
        cout << multipleSum(n)<<endl;
    }
    return 0;
}
