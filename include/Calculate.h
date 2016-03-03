#ifndef CALCULATE_H
#define CALCULATE_H
#include <math.h>
#include "Stack.h"
#include "Stackf.h"
#include "Queue.h"
#include "Analys.h"

class Calculate
{
    public:
        Calculate();
        virtual ~Calculate();
        float Calc(const char* token);

    protected:

    private:
        Analys analys;
        float Proc(float a,float b,char op);
};

#endif // CALCULATE_H
