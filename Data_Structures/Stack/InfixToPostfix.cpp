#include <iostream>
#include <stack>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// to convert infix to postfix
string infixtopostfix(string s)
{
    stack<char> st;
    string result;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result += c;
        }
        // check for open paranthesis, if found then push
        else if (c == '(')
        {
            st.push('(');
        }
        // pop to result string when ')' is found until '(' is encountered.
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    // POP all the remaining elements from the stack
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}
// Driver code
int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    // call the function
    string postfix = infixtopostfix(exp);
    cout << postfix <<"\n";
    return 0;
}