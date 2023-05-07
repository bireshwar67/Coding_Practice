#include <bits/stdc++.h>
using namespace std;
class Memoization
{
public:
    int convert(int n)
    {
        int t[n];
        t[0] = t[1] = 2;
        t[2] = 2 * t[1] * t[0];
        for (int i = 3; i <= n; i++)
        {
            t[i] = t[i - 1] + 2 * t[i - 1] * t[i - 2];
        }
        return t[n];
    }
};

class solution
{
public:
    int convert(int n)
    {
        int sum = 0;
        if (n == 0 || n == 1)
            return 2;
        for (int i = 1; i < n; i++)
        {
            sum += 2 * convert(i) * convert(i - 1);
        }
        return sum;
    }
};

int main()
{
    int n = 0;
    cout << "Enter a number: \n";
    cin >> n;
    // solution obj1;
    Memoization obj1;
    int sum = obj1.convert(n);
    cout << sum << "\n";

    return 0;
}