#ifndef ANALYS_H
#define ANALYS_H
#include "Stack.h"
#include "Stackf.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

class Analys
{
    public:
        Analys();
        virtual ~Analys();
        int getPriority(char o);
        bool isOperator(char c);
        bool isOperand(char c);
        Stack In2Postfix(const char* tk);
        float Calc(const char* token);
        bool SyntaxAnalysis(const char* token);

    protected:

    private:
        char* Format(const char* token);
        const char* op="+- */% ^";
        char* str_replace(char *orig, char *rep, char *with);
        char* Remath(const char* tk);
        float fSubCalc(const char* token,char*& tmp,int& j);
        char* SubCalc(const char* token,char*& tmp,int& j);
        float Proc(float a,float b,char op);
        char* ftoString(float a,bool zero=false);
        void Retoken(char*& token,float a,int ls,int& i);//replace token
        void Math(char*& token,char*& tmp,int ls,int& i,double (*calculate)(double));
        bool find(const char* token,const char* f,int i);
};

#endif // ANALYS_H
