#ifndef STACK_H
#define STACK_H

class Stack
{
    public:
        Stack(int n=100);
        Stack(const Stack& s);
        virtual ~Stack();
        char Pop();
        char Peek();
        void Push(char c);
        bool isEmpty();
        bool isFull();
        int Count();

    protected:

    private:
        int top;
        int n;
        char* data;
};

#endif // STACK_H
