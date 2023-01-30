#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> stk;
    for (int i = 1; i <= 10; ++i)
    {
        stk.push(i);
    }

    cout << "Stack size = " << stk.size() << "\n";
}

