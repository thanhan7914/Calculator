#include "Relative.h"

Relative::Relative(int n)
{
    this->n=n;
    top=-1;
    rel=new char[this->n];
    aValue=new Value[this->n];
    bValue=new Value[this->n];
}

Relative::~Relative()
{
    for(int i=0;i<=top;i++)
    {
        delete[] aValue[i];
        delete[] bValue[i];
    }

    delete[] aValue;
    delete[] bValue;
    delete[] rel;
}

bool Relative::isFull()
{
    return top==n-1;
}

bool Relative::isEmpty()
{
    return top==-1;
}

void Relative::Push(const Value a,char r,const Value b)
{
    if(!isFull())
    {
        rel[++top]=r;
        aValue[top]=new char[strlen(a)];
        strcpy(aValue[top],a);
        bValue[top]=new char[strlen(b)];
        strcpy(bValue[top],b);
    }
}

void Relative::Push(char a,char r,char b)
{
    if(!isFull())
    {
        rel[++top]=r;
        aValue[top]=ToValue(a);
        bValue[top]=ToValue(b);
    }
}

char Relative::Get(const Value a,const Value b)
{
    for(int i=0;i<=top;i++)
    {
        if(!strcmp(aValue[i],a)&&!strcmp(bValue[i],b))
            return rel[i];
    }

    return '\0';
}

char Relative::Get(char a,char b)
{
    Value av=ToValue(a);
    Value bv=ToValue(b);
    for(int i=0;i<=top;i++)
    {
        if(!strcmp(aValue[i],av)&&!strcmp(bValue[i],bv))
            return rel[i];
    }

    return '\0';
}

Value Relative::ToValue(char c)
{
    Value value=new char[1];
    value[0]=c;
    return value;
}
