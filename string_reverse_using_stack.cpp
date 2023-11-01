#include<iostream>
using namespace std;
#define max 30
class reverse_str{
    public:
    int top;
    char s[max];
    void create(){
        top=-1;
        cout<<"Stack is Created\n";
    }
    int pop();
    void push(char);
};

int reverse_str::pop(){
    char ch;
    if(top==-1){
        cout<<"The operation is failed\n";
    }
    else{
        ch=s[top];
        top--;
    }
    return ch;
}

void reverse_str::push(char ch){
    if(top==max-1){
        cout<<"The operation is failed\n";
    }
    else{
        top++;
        s[top]=ch;
       // cout<<"The char is pushed/n";
    }
}

int main(){
    reverse_str obj;
    char ss[20],ch;
    cout<<"Enter the string\n";
    cin>>ss;
    int i=0;
    while(ss[i]!='\0'){
        obj.push(ss[i]);
        i++;
    }
    cout<<"The Reverse String Is::";
    while(i>0){
        ch=obj.pop();
        cout<<ch;
        i--;
    }
    return 0;
}