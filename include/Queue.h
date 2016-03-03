#ifndef QUEUE_H
#define QUEUE_H


class Queue
{
    public:
        Queue(int n=100);
        Queue(const Queue& q);
        virtual ~Queue();
        char Pop();
        char Peek();
        void Push(char c);
        int Count();
        bool isEmpty();
        bool isFull();

    protected:

    private:
        int head;
        int n;
        char* data;
};

#endif // QUEUE_H
