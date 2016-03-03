#ifndef KEY
#define KEY
typedef char* Key;
#endif // KEY
#ifndef VALUE
#define VALUE
typedef char* Value;
#endif // VALUE
#ifndef HASKTABLE_H
#define HASKTABLE_H
#include <string.h>

class Hasktable
{
    public:
        Hasktable(int n=100);
        virtual ~Hasktable();
        bool isFull();
        bool isEmpty();
        void Put(Key k,const Value v);
        Value Get(Key k);
        Key Find(Value v);
        void Remove(Key k);
        void RemoveAt(int pos);

    protected:

    private:
        Key* key;
        Value* value;
        int n;
        int top;
};

#endif // HASKTABLE_H
