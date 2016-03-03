#include "Stack.h"

Stack::Stack(int n)
{
    this->n=n;
    top=-1;
    data=new char[this->n];
}

Stack::Stack(const Stack& s)
{
    n=s.n;
    top=s.top;
    data=new char[n];
    for(int i=0;i<=top;i++)
        data[i]=s.data[i];
}

Stack::~Stack()
{
    delete[] data;
}

bool Stack::isEmpty()
{
    return top==-1;
}

bool Stack::isFull()
{
    return top==n-1;
}

char Stack::Pop()
{
    if(!isEmpty())
    {
        return data[top--];
    }
    return '\0';
}

char Stack::Peek()
{
    if(!isEmpty())
    {
        return data[top];
    }

    return '\0';
}

void Stack::Push(char c)
{
    if(!isFull())
    {
        data[++top]=c;
    }
}

int Stack::Count()
{
    return top+1;
}
