#include "Queue.h"

Queue::Queue(int n)
{
    this->n=n;
    head=-1;
    data=new char[this->n];
}

Queue::Queue(const Queue& q)
{
    n=q.n;
    head=q.head;
    data=new char[n];
    for(int i=0;i<=head;i++)
        data[i]=q.data[i];
}

Queue::~Queue()
{
    delete[] data;
}

bool Queue::isEmpty()
{
    return head==-1;
}

bool Queue::isFull()
{
    return head==n-1;
}

char Queue::Pop()
{
    if(!isEmpty())
        return data[head--];
    return '\0';
}

char Queue::Peek()
{
    if(!isEmpty())
        return data[head];
    return '\0';
}

void Queue::Push(char c)
{
    if(!isFull())
    {
        head++;
        for(int i=1;i<=head;i++)
            data[i]=data[i-1];

        data[0]=c;
    }
}

int Queue::Count()
{
    return head;
}
