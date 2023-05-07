#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter a range :" << " ";
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            cout << " " << i << endl;
            ans += i;
        }
    }
    cout << "Ans = " << ans ;
    return 0;
}