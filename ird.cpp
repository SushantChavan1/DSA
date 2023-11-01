#include<iostream>
using namespace std;
#define max 5
class ird{
    public:
    int right,left,item[max] ;
    void insert(int);
    int remove_left();
    int remove_right();
    void create();
    void display();
    void isempty();
    void isfull();
};

void ird::isempty(){
    if(left==right){
        cout<<"The ird is empty\n";
    }
    else{
        cout<<"The ird is not empty\n";
    }
}

void ird::isfull(){
    if(right==max-1){
        cout<<"The ird is full\n";
    }
    else{
        cout<<"The ird is not full\n";
    }
}

void ird::create(){
    right=left=-1;
    cout<<"The IRD is Created\n";
}

void ird::insert(int ele){
        if(right==max-1){
            cout<<"The ird is full\n";
        }
        else{
            right++;
            item[right]=ele;
        }
}

int ird::remove_left(){
    int x;
    if(right==left){
        cout<<"The ird is empty\n";
    }
    else{
        left++;
        x=item[left];
    }
    return x;
}

int ird::remove_right(){
    int x;
    if(right==left){
        cout<<"The ird is empty\n";
    }
    else{
        x=item[right];
        right--;
    }
    return x;
}

void ird::display(){
        for(int i=left+1;i<=right;i++){
            cout<<" "<<item[i];
        }
}

int main(){
    int num,ch;
    ird obj;
    do{
            cout<<"\n1.Create\n2.Insert\n3.Remove_right\n4.Remove_left\n5.Display\n6.isfull\n7.isempty\n8.exit\n";
            cout<<"Enter your choise\n";
            cin>>ch;
            switch (ch)
            {
            case 1:
                obj.create();
                break;

            case 2:
                cout<<"Enter the element\n";
                cin>>num;
                obj.insert(num);
                break;

            case 3:
                num=obj.remove_right();
                cout<<num<<" is removed\n";
                break;

            case 4:
                num=obj.remove_left();
                cout<<num<<" is removed\n";
                break;

            case 5:
                obj.display();
                break;
            
            case 6:
                obj.isfull();
                break;

            case 7:
                obj.isempty();
                break;

            case 8:
                exit(0);


            default:
                cout<<"Enter the correct choise\n";
                break;
            }
    }while(ch!=8);
    return 0;
}