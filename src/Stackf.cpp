#include "Stackf.h"

Stackf::Stackf(int n)
{
    this->n=n;
    top=-1;
    data=new float[this->n];
}

Stackf::Stackf(const Stackf& s)
{
    n=s.n;
    top=s.top;
    data=new float[n];
    for(int i=0;i<=top;i++)
        data[i]=s.data[i];
}

Stackf::~Stackf()
{
    delete[] data;
}

bool Stackf::isEmpty()
{
    return top==-1;
}

bool Stackf::isFull()
{
    return top==n-1;
}

float Stackf::Pop()
{
    if(!isEmpty())
    {
        return data[top--];
    }
    return 0;
}

float Stackf::Peek()
{
    if(!isEmpty())
    {
        return data[top];
    }

    return 0;
}

void Stackf::Push(float c)
{
    if(!isFull())
    {
        data[++top]=c;
    }
}

int Stackf::Count()
{
    return top+1;
}
