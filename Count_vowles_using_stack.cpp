// Online C++ compiler to run C++ program online
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
    char ss[20],ch[20];
    cout<<"Enter the string\n";
    cin>>ss;
    int i=0,cnt=0;
    while(ss[i]!='\0'){
if(ss[i]=='a' || ss[i]=='i' || ss[i]=='o' || ss[i]=='e' ||ss[i]=='u'|| ss[i]=='A' || ss[i]=='I' || ss[i]=='O' || ss[i]=='E' ||ss[i]=='U'){
            obj.push(ss[i]);
            cnt++;
        }
        i++;
    }
   
    int j=0;
    while(cnt>0){
        obj.pop();
        j++;
        cnt--;
    }
    cout<<"The Vowles are in string::"<<j;
    return 0;
}