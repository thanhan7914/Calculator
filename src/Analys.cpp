#include "Analys.h"

Analys::Analys()
{
    //ctor
}

Analys::~Analys()
{
    //dtor
}

int Analys::getPriority(char o)
{
    int i=-1,r=0;
    while(op[++i]!='\0')
    {
        if(op[i]==' ')
            r++;
        else if(op[i]==o)
            return r;
    }

    return -1;
}

bool Analys::isOperator(char c)
{
    if(c==' ')
        return false;
    int i=-1;
    while(op[++i]!='\0')
        if(op[i]==c)
            return true;

    return false;
}

bool Analys::isOperand(char c)
{
    return !isOperator(c)&&c!='('&&c!=')';
}

Stack Analys::In2Postfix(const char* tk)
{
    Stack s,out;
    int i=-1;
    char c,*token=Format(tk),cf=1;
    while((c=token[++i])!='\0')
    {
        if(isOperand(c))
        {
            out.Push(c);
            if(!isOperand(token[i+1]))
                out.Push(' ');
        }
        else if(c=='(')
            s.Push(c);
        else if(c==')')
        {
            char f;
            while((f=s.Pop())!='(')
                out.Push(f);
        }
        else
        {
            cf=0;
            while(!s.isEmpty()&&getPriority(c)<=getPriority(s.Peek()))
                out.Push(s.Pop());
            s.Push(c);
        }
    }

    if(cf)
    {
        Stack cfout(out.Count()+4);
        cfout.Push('+');
        cfout.Push('0');
        cfout.Push(' ');
        i--;
        while(i>=0)
            cfout.Push(token[i--]);

        return cfout;
    }

    while(!s.isEmpty())
        out.Push(s.Pop());

    Stack reout(out.Count());
    while(!out.isEmpty())
        reout.Push(out.Pop());

    return reout;
}

bool Analys::SyntaxAnalysis(const char* token)
{
    int i=-1,opensig=0;
    char c;

    while((c=token[++i])!='\0')
    {
        if(c=='(')
            opensig++;
        else if(c==')')
            opensig--;
        else if(c=='.')
        {
            if(i==0||!isdigit(token[i-1])||!isdigit(token[i+1]))
                return false;
            else
            {
                int j=i+1;
                while(isdigit(token[++j]));
                if(token[j]=='.')
                    return false;
            }
        }
        else if(isOperator(c))
        {
            if(isOperator(token[i-1])||isOperator(token[i+1]))
                return false;
        }
        else if(c=='e'&&!isOperator(token[i+1]))
            return false;
    }

    return !opensig;
}

char* Analys::Format(const char* token)
{
    int i=-1,len=strlen(token),csub=0;
    char *str=new char[len*3],c;
    strcpy(str,token);
    while((c=str[++i])!='\0')
    {
        if(c==' ')
        {
            char f,j=i;
            while((f=str[++j])!='\0')
                str[j-1]=f;
            str[j-1]='\0';
            len--;
        }
        else if(c=='-'&&(i==0||str[i-1]=='(')&&isOperand(str[i+1]))
        {
            for(int j=len;j>i;j--)
                str[j]=str[j-1];
            str[i]=0x30;
            str[++len]='\0';
        }
        //continues
        else if(isdigit(c)&&(str[i+1]=='('||isalpha(str[i+1])))
        {
            for(int j=len;j>i+1;j--)
                str[j]=str[j-1];
            str[i+1]='*';
            str[++len]='\0';
        }
    }

    return Remath(str);
}

char* Analys::Remath(const char* tk)
{
    char* token;
    token=new char[strlen(tk)*2];
    strcpy(token,tk);
    token=str_replace(token,"e","2.71828182846");
    token=str_replace(token,"pi","3.14159265359");

    int i=-1;
    float calc;
    char c,*tmp,*temp;
    tmp=(char*)calloc(strlen(token)+1,sizeof(char));
    while((c=token[++i])!='\0')
    {
        if(c=='a')
        {
            if(find(token,"asin(",i))
            {
                i+=4;
                Math(token,tmp,i-4,i,asin);
            }
            else if(find(token,"acos(",i))
            {
                i+=4;
                Math(token,tmp,i-4,i,acos);
            }
            else if(find(token,"atan(",i))
            {
                i+=4;
                Math(token,tmp,i-4,i,atan);
            }
            else if(find(token,"abs(",i))
            {
                i+=3;
                Math(token,tmp,i-3,i,fabs);
            }
        }
        else if(c=='s')
        {
            if(find(token,"sqrt(",i))
            {
                i+=4;
                Math(token,tmp,i-4,i,sqrt);
            }
            else if(find(token,"sin(",i))
            {
                i+=3;
                Math(token,tmp,i-3,i,sin);
            }
        }
        else if(c=='c')
        {
            if(find(token,"cos(",i))
            {
                i+=3;
                Math(token,tmp,i-3,i,cos);
            }
        }
        else if(c=='t')
        {
            if(find(token,"tan(",i))
            {
                i+=3;
                Math(token,tmp,i-3,i,tan);
            }
        }
        else if(c=='l')
        {
            if(find(token,"ln(",i))
            {
                i+=2;
                Math(token,tmp,i-2,i,log);
            }
            else if(find(token,"log(",i))
            {
                i+=3;
                Math(token,tmp,i-3,i,log10);
            }
        }
    }

    token=str_replace(token,"(-","(0-");

    return token;
}

bool Analys::find(const char* token,const char* f,int i)
{
    char c;
    int j=-1;
    while((c=f[++j])!='\0')
        if(token[i+j]!=c)
            return false;

    return true;
}

void Analys::Math(char*& token,char*& tmp,int ls,int& i,double (*calculate)(double))
{
    float calc;
    calc=fSubCalc(token,tmp,i);
    calc=calculate(calc);
    Retoken(token,calc,ls,i);
}

void Analys::Retoken(char*& token,float a,int ls,int& i)
{
    char* tmp=ftoString(a,true);
    char* temp=(char*)calloc(strlen(token)+1,sizeof(char));
    int j=i;
    int tlen=strlen(tmp),clen=0;
    char f;
    while((f=token[++j])!='\0')
    {
        temp[j-i-1]=f;
        clen++;
    }
    temp[j-i-1]='\0';

    for(int k=0;k<tlen;k++)
        token[k+ls]=tmp[k];

    for(int k=0;k<clen;k++)
        token[k+ls+tlen]=temp[k];
    token[ls+tlen+clen]='\0';
    i=ls+tlen;
    free(tmp);
    free(temp);
}

float Analys::fSubCalc(const char* token,char*& tmp,int& j)
{
    char c;
    int i=j+1,opensig=0;
    while(!((c=token[++j])==')'&&!opensig))
    {
        tmp[j-i]=c;
        if(c=='(')
            opensig++;
        else if(c==')')
            opensig--;
    }

    tmp[j-i]='\0';

    float cl=Calc(tmp);
    return cl;
}

char* Analys::SubCalc(const char* token,char*& tmp,int& j)
{
    char *result=ftoString(fSubCalc(token,tmp,j));
    return result;
}


// You must free the result if result is non-NULL.
char *Analys::str_replace(char *orig, char *rep, char *with) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep
    int len_with; // length of with
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    if (!orig)
        return NULL;
    if (!rep)
        rep = "";
    len_rep = strlen(rep);
    if (!with)
        with = "";
    len_with = strlen(with);

    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    tmp = result = (char*)malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}

//Calculator
float Analys::Calc(const char* token)
{
    Stack postfix=In2Postfix(token);
    Stackf out(postfix.Count());
    Stack s(postfix.Count());

    while(!postfix.isEmpty())
    {
        char c=postfix.Pop();

        if(c==' '||(isOperand(c)&&isOperator(postfix.Peek())))
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
        else if(isOperand(c))
        {
            s.Push(c);
        }
        else if(isOperator(c))
        {
            //add
            out.Push(Proc(out.Pop(),out.Pop(),c));
        }
    }

    return out.Peek();
}


float Analys::Proc(float a,float b,char c)
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

char* Analys::ftoString(float a,bool zero)
{
    char* str=(char*)calloc(50,sizeof(char));
    int value,fract,i=51,sig=0;
    value=(int)fabs(a);
    fract=(int)((fabs(a)-value)*10000);

    if(a<0)
    {
        if(zero)
        {
            sig=2;
            str[0]='(';
            str[1]='-';
        }
        else
        {
            sig=1;
            str[0]='-';
        }
    }
    if(!value)
    {
        sig++;
        str[sig-1]='0';
    }
    str[--i]='\0';

    if(fract>0)
    {
        if(fract<1000)
            str[--i]='0';
        if(fract<100)
            str[--i]='0';
        if(fract<10)
            str[--i]='0';

        while(fract)
        {
            str[--i]=(char)((fract%10)+0x30);
            fract/=10;
        }

        str[--i]='.';
    }
    while(value)
    {
        str[--i]=(char)((value%10)+0x30);
        value/=10;
    }

    for(int j=i;j<50;j++)
        str[j-i+sig]=str[j];
    if(zero&&a<0)
    {
        str[50-i+sig]=')';
        str[50-i+sig+1]='\0';
    }

    return str;
}
