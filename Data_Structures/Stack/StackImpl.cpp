/**
 * Write a program to implemnet a stack using arrays
 * 
 * Pending things to improve here
 * 1 -> Implemnet resizing mechanism to handle stack overflow scenario
 */
#include <iostream>
using namespace std;

struct Stack
{
    int *data;
    int n;
    int top;

    Stack(int stack_size)
    {
        n = stack_size;
        data = new int[n];
        top = -1;
    }

    bool empty()
    {
        return top == -1;
    }

    int peek()
    {
        return data[top];
    }

    void pop()
    {
        --top;
    }

    void push(int val)
    {
        data[top + 1] = val;
        ++top;
    }

    int size()
    {
        return top + 1;
    }
};

int main()
{
    Stack stk(10);
    for (int i = 1; i <= 10; ++i)
    {
        stk.push(i);
    }

    cout << "Size = " << stk.size() << "\n";
    cout << "Peek = " << stk.peek() << "\n";
    for (int i = 1; i <= 9; ++i)
    {
        cout << "Popping = " << stk.peek() << "\n";
        stk.pop();
    }

    if (stk.empty())
    {
        cout << "Stack is empty\n";
    }

    if (!stk.empty())
    {
        cout << "Stack is not empty\n";
        cout << "Peek = " << stk.peek() << "\n";
    }

    return 0;
}