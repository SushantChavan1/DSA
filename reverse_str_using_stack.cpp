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
       
    }
}

int main(){
    reverse_str obj;
    char ss[20],ch[20];
    cout<<"Enter the string\n";
    cin>>ss;
    int i=0;
    while(ss[i]!='\0'){
        obj.push(ss[i]);
        i++;
    }
    cout<<"The Reverse String Is::";
    int j=0;
    while(i>0){
        ch[j]=obj.pop();
        //cout<<ch[j];
        j++;
        i--;
    }
    int flg=0;
    for(int i=0;i<j;i++){
        if(ch[i]==ss[i])flg=1;
        else flg=0;
    }
    if(flg==1)cout<<"Palindrom\n";
    else cout<<"NOt palindrom\n";
    return 0;
}