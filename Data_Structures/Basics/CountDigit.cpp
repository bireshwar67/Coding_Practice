#include<bits/stdc++.h>
using namespace std;

int evenlyDivides(int n)
{
    // code here
    int count = 0;
    while (n > 0)
    {
        int digit = n % 10;
        n = n / 10;
        if (digit % n == 0)
            count++;
    }
    return count;
}
int main(){
    int n = 12;
    cout << evenlyDivides(n);
    return 0;
}