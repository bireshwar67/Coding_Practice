#include <bits/stdc++.h>
#include <vector>
using namespace std;

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}
void evenFib(){

}
int main()
{
    int n ;
    cout << "Enter the range of Fibonacci : " << " " ;
    cin >> n;
    int ans = fib(n);
    cout << ans ;

    return 0;
}