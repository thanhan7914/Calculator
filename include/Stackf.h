#ifndef STACKF_H
#define STACKF_H


class Stackf
{
    public:
        Stackf(int n=100);
        Stackf(const Stackf& s);
        virtual ~Stackf();
        void Push(float f);
        float Peek();
        float Pop();
        bool isEmpty();
        bool isFull();
        int Count();

    protected:

    private:
        float* data;
        int top;
        int n;
};

#endif // STACKF_H
