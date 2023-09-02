#include<iostream>
#include<cstring>
#define max 50
using namespace std;
class stack{
    public:
    int item[max],top;
    void create(stack*);
    void push(stack*,int);
    int pop(stack*);
};
void stack::create(stack *p){
    p->top=-1;
}
void stack::push(stack *p,int el){
    if(p->top==max-1){
        cout<<"\nStack Overflows.";
    }
    else{
        ++p->top;
        p->item[p->top]=el;
    }
}
int stack::pop(stack *p){
    if(p->top==-1){
        cout<<"\nStack Underflows.";
        return 0;
    }
    else{
        return(p->item[p->top--]);
    }
}
int main(){
    int i=0,j=0;
    char pr[20],in[20],ch;
    stack *oprat,*oprand,ad1,ad2,obj;
    oprat=&ad1;
    oprand=&ad2;
    obj.create(oprat);
    obj.create(oprand);
    cout<<"\nEnter infix string:";
    cin>>in;
    strrev(in);
    while(in[i]!='\0'){
        if(in[i]==')'||in[i]=='+'||in[i]=='-'||in[i]=='*'||in[i]=='/'){
            obj.push(oprat,in[i]);
        }
        else if(in[i]=='('){
            while(oprat->top!=-1){
                ch=obj.pop(oprat);
                if(ch!=')'){
                    obj.push(oprand,ch);
                }
            }
        }
        else{
            obj.push(oprand,in[i]);
        }
        i++;
    }
    while(oprat->top!=-1){
        ch=obj.pop(oprat);
        obj.push(oprand,ch);
    }
    while(oprand->top!=-1){
        pr[j]=obj.pop(oprand);
        j++;
    }
    pr[j]='\0';
    cout<<"\nOur desired prefix string:"<<pr;
    return 0;
}



