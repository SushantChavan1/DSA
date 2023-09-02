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
    char in[20],po[20],ch;
    int i=0,j=0;
    stack *p,q,obj;
    p=&q;
    obj.create(p);
    cout<<"\nEnter infix expression:";
    cin>>in;
    while(in[i]!='\0'){
        if(in[i]=='('||in[i]=='+'||in[i]=='-'||in[i]=='*'||in[i]=='/'){
            obj.push(p,in[i]);
        }
        else if(in[i]==')'){
            while(p->item[p->top]!='('){
                ch=obj.pop(p);
                if(ch!='('){
                    po[j]=ch;
                    j++;
                }
            }
            obj.pop(p);
        }
        else{
            po[j]=in[i];
            j++;
        }
        i++;
    }
    while(p->top!=-1){
        po[j]=obj.pop(p);
        j++;
    }
    po[j]='\0';
    cout<<"\nOur desired postfix string:"<<po;
    return 0;
}