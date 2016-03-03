#include "Hasktable.h"
#include <iostream>
using namespace std;

Hasktable::Hasktable(int n)
{
    this->n=n;
    top=-1;
    key=new Key[this->n];
    value=new Value[this->n];
}

Hasktable::~Hasktable()
{
    for(int i=0;i<=top;i++)
    {
        delete[] key[i];
        delete[] value[i];
    }

    delete[] key;
    delete[] value;
}

bool Hasktable::isFull()
{
    return top==n-1;
}

bool Hasktable::isEmpty()
{
    return top==-1;
}

void Hasktable::Put(const Key k,const Value v)
{
    if(!isFull())
    {
        key[++top]=new char[strlen(k)];
        strcpy(key[top],k);
        value[top]=new char[strlen(v)];
        strcpy(value[top],v);
    }
}

Value Hasktable::Get(const Key k)
{
    for(int i=0;i<=top;i++)
        if(strcmp(key[i],k))
            return value[i];

    return "\0";
}

Key Hasktable::Find(const Value v)
{
    for(int i=0;i<=top;i++)
        if(!strcmp(value[i],v))
            return key[i];

    return "\0";
}

void Hasktable::Remove(const Key k)
{

}

void Hasktable::RemoveAt(int pos)
{

}
