#include<iostream>
using namespace std;
#define max 5
class queue{

    public:
    int front,rear,item[max];
    void create(){
          front=rear=-1;
          cout<<"Queue is created"<<endl;
    }
    void display();
    int insert(int);
    int remove();
    void isempty();
    void isfull();
};

void queue::isempty(){
    if(front==-1){
        cout<<"\nThe Queue is Empty...!";
    }
    else{
        cout<<"\nThe Queue is not Empty....!";
    }
}

void queue::isfull(){
    if((front==0&&rear==max-1)||front==rear+1){
        cout<<"\nThe Queue is Full";
    }
    else{
        cout<<"\nThe Queue is not Full";
    }
}

void queue::display(){
    for(int i=front;i!=rear;i=(i+1)%max){
        cout<<"  "<<item[i];
    }
    cout<<" "<<item[rear];
}

int queue::insert(int ele){
    if((front==0&&rear==max-1)||front==rear+1){
        cout<<"The Queue is full"<<endl;
    }
    else{
        if(rear==-1){
            front=rear=0;
        }
        else{
            rear=(rear+1)%max;
        }
        item[rear]=ele;
    }
}

int queue::remove(){
    int r;
    if(front==-1){
        cout<<"The Queue is empty"<<endl;
    }
    else{
         r=item[front];
        if(front==rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%max;
        }
    }
    return r;
}

int main(){

    int num,ch,n;
    queue obj;
    do{
        cout<<"\n1.Create\n2.Insert\n3.Remove\n4.Display\n5.Isempty\n6.Isfull\n7.Exit\n";
        cout<<"Enter your choise\n";
        cin>>ch;
        switch (ch)
        {
        case 1:
            obj.create();
            break;
        case 2:
            cout<<"Enter the number\n";
            cin>>num;
            obj.insert(num);
            break;

        case 3:
            n=obj.remove();
            cout<<n<<"is removed\n";
            break;
        case 4:
            obj.display();
            break;
        
        case 5:
            obj.isempty();
            break;

        case 6:
            obj.isfull();
            break;

        case 7:
            exit(0);
            break;


        default:
        cout<<"Enter the valid choise\n";
            break;
        }
    }while(ch!=7);
    return 0;
}