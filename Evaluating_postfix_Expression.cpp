#include<iostream>
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
    char po[20],ch;
    int i=0,a,b;
    stack *p,q,obj;
    p=&q;
    obj.create(p);
    cout<<"\nEnter postfix expression:";
    cin>>po;
    while(po[i]!='\0'){
        if(po[i]=='+'||po[i]=='-'||po[i]=='*'||po[i]=='/'){
            b=obj.pop(p);
            a=obj.pop(p);
            switch(po[i]){
                case '+':
                    obj.push(p,a+b);
                    break;
                case '-':
                    obj.push(p,a-b);
                    break;
                case '*':
                    obj.push(p,a*b);
                    break;
                case '/':
                    obj.push(p,a/b);
                    break;
            }
        }
        else{
            obj.push(p,po[i]-48);
        }
        i++;
    }
    cout<<"\nValue of Postfix expression is "<<obj.pop(p);
    return 0;
}