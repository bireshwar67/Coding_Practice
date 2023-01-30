#include <iostream>
#include <stack>
using namespace std;

bool isOpenParenthesis(char ch) {
   return ch == '(' || ch == '[' || ch == '{' || ch == '<';
}

bool isClosedParenthesis(char ch) {
    return ch == ')' || ch == ']' || ch == '}' || ch == '>';
}

bool compatible(char open, char close) {
    return (open == '(' && close == ')')
          || (open == '[' && close == ']') 
          || (open == '{' && close == '}')
          || (open == '<' && close == '>');
}

bool paranthesischecker(string st)
{
    stack <char> temp;
    for (int i=0; i < st.length(); i++)
    {
        if (isOpenParenthesis(st[i]))
        {
            temp.push(st[i]);
        }
        else if (isClosedParenthesis(st[i]))
        {
            if (!temp.empty() && compatible(temp.top(), st[i])) {
                temp.pop();
            } else {
                return false;
            }
        }
    }

    return temp.empty();
}

int main()
{
    string st = "{}";
    if ( paranthesischecker(st))
    {cout << "Matched";}
    else 
    {cout << "error";}
    return 0;
}