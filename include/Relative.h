#ifndef A_B
#define A_B
typedef char* Value;
#endif
#ifndef RELATIVE_H
#define RELATIVE_H
#include <string.h>


class Relative
{
    public:
        Relative(int n=100);
        virtual ~Relative();
        void Push(const Value a,char r,const Value b);
        void Push(char a,char r,char b);
        char Get(const Value a,const Value b);
        char Get(char a,char b);
        bool isEmpty();
        bool isFull();

    protected:

    private:
        Value* aValue;
        Value* bValue;
        char* rel;
        int n;
        int top;
        Value ToValue(char c);
};

#endif // RELATIVE_H
