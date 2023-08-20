#include<iostream>
#define max 10
using namespace std;
class array{
    int item[max],cnt=0;
    public:
    void insert(int);
    int remove(int);
    void reverse();
    void display();
    void count(){
        cout<<"\nThe elements of array are::\t"<<cnt;
    }
};
void array::insert(int val){
    item[cnt]=val;
    cnt++;
}
int array::remove(int pos){
    int i,z;
    if(pos>cnt-1||pos<0){
        cout<<"\nEnter valid position";
        return 0;
    }
    else{
        z=item[pos];
        for(i=pos;i<cnt;i++){
            item[i]=item[i+1];
        }
        cnt--;
        return z;
    }
}
void array::reverse(){
    cout<<"\nReversed Array:";
    for(int i=cnt-1;i>=0;i--){
        cout<<"\t"<<item[i];
    }
}
void array::display(){
    cout<<"\nOur Array:";
    for(int i=0;i<cnt;i++){
        cout<<"\t"<<item[i];
    }
}
int main(){
    int val,re,ch,pos;
    array ob;
    do{
        cout<<"\n\n1:Insert\n2:Remove\n3:Reverse\n4:Display\n5:Count\n6.Exit";
        cout<<"\nEnter your choise:";
        cin>>ch;
        switch (ch){
            case 1:
                cout<<"\nEnter value:";
                cin>>val;
                ob.insert(val);
                break;
            case 2:
                cout<<"\nEnter valid position:";
                cin>>pos;
                re=ob.remove(pos);
                cout<<"\nRemoved value:"<<re;
                break;
            case 3:
                ob.reverse();
                break;
            case 4:
                ob.display();
                break;
            case 5:
                ob.count();
                break;
            case 6:
                exit(123);
                break; 
            default:
                cout<<"\nEnter valid choise";
        }
    }while(ch!=6);
    return 0;
}