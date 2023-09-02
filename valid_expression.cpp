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
    int i=0,temp=0;
    stack *p,q,obj;
    p=&q;
    obj.create(p);
    cout<<"\nEnter any expression:";
    cin>>in;
    while(in[i]!='\0'){
        if(in[i]=='('||in[i]=='['||in[i]=='{'){
            obj.push(p,in[i]);
        }
        else if(in[i]==')'||in[i]==']'||in[i]=='}'){
            ch=obj.pop(p);
            if((in[i]==')'&&ch!='(')||(in[i]==']'&&ch!='[')||(in[i]=='}'&&ch!='{')){
                temp=1;
                break;
            }
        }
        i++;
    }
    if(temp==1||p->top!=-1){
        cout<<"\nExpression is Invalid.";
    }
    else{
        cout<<"\nExpression is Valid.";
    }
    return 0;
}