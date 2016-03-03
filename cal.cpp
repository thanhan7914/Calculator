#include <iostream>
#include <stdio.h>
#include "Calculate.h"

using namespace std;

void help()
{
    cout <<"------------------ JAV Calculator Help --------------"<<endl;
    cout <<"Functions:"<<endl;
    cout <<"     sin, cos, tan\n     sqrt, log, ln\n     asin, acos, atan"<<endl;
    cout <<"Operator:"<<endl;
    cout <<"     +, -, *, /, ^, %"<<endl;
}

int main(int argc,char** argv)
{
    Analys analys;
    float a;
    bool tf;

    if(argc>1)
    {
        if(argv[1][0]=='-')
        {
            if(argv[1][1]=='h')
            {
                help();
            }
        }
        else
        {
            tf=analys.SyntaxAnalysis(argv[1]);
            if(tf)
                a=analys.Calc(argv[1]);
            else
                cout <<"Syntax Error!"<<"\nGet help jav -h";
        }
    }
    else
    {
        cout <<"Nhap bieu thuc(-h tro giup): ";
        char token[256];
        gets(token);
        fflush(stdin);

        if(token[0]=='-'&&token[1]=='h')
            help();
        else
        {
            tf=analys.SyntaxAnalysis(token);
            if(tf)
                a=analys.Calc(token);
            else
                cout <<"Syntax Error!"<<"\nGet help jav -h";
        }
    }
    if(tf)
        cout <<a<<"\n";

    system("pause");
    return 0;
}
