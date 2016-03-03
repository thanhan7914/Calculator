#include "Calculate.h"

Calculate::Calculate()
{

}

Calculate::~Calculate()
{
    //dtor
}

float Calculate::Calc(const char* token)
{
    /*Stack postfix=analys.In2Postfix(token);
    Stackf out(postfix.Count());
    Stack s(postfix.Count());

    while(!postfix.isEmpty())
    {
        char c=postfix.Pop();

        if(c==' '||(analys.isOperand(c)&&analys.isOperator(postfix.Peek())))
        {
            if(c!=' ')
                s.Push(c);
            float value=0,fract=0,idiv=1;
            char f;
            Stack ss(s.Count());
            while(!s.isEmpty())
                ss.Push(s.Pop());

            while(!ss.isEmpty()&&(f=ss.Pop())!='.')
                value=value*10+(float)(f-0x30);

            while(!ss.isEmpty())
            {
                fract=fract*10+(float)(ss.Pop()-0x30);
                idiv*=10;
            }
            value+=(float)fract/idiv;
            out.Push(value);
        }
        else if(analys.isOperand(c))
        {
            s.Push(c);
        }
        else if(analys.isOperator(c))
        {
            //add
            out.Push(Proc(out.Pop(),out.Pop(),c));
        }
    }

    return out.Peek();*/
    return analys.Calc(token);
}


float Calculate::Proc(float a,float b,char c)
{
    switch(c)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '%': return a-b*((int)(a/b));
        case '^': return (float)pow(a,b);
        default: return 0;
    }
}
