#include<iostream>
using namespace std;
int linear_search(int [],int,int);
int binary_search(int [],int,int);
int* simple_sort(int [],int);

int* simple_sort(int p[],int size){
    int temp;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (p[i] < p[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    return p;
}


int linear_search(int p[] ,int size,int key){
    //here I implement the logic of linear search method
    int flg=0;
    for(int i=0;i<size;i++){
        if(p[i]==key){
            flg=1;
            break;
        }
    }
    return flg;
}

int binary_search(int p[],int size,int key){
    //here I implement the logic of binary search
    int up,down,mid,temp,flg=0;
    p=simple_sort(p, size);//call to sorting function
    cout<<"Sorted DAta::";
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << p[i];
    }
    down=0;
    up=size-1;
    while(down<=up){
        mid=(up+down)/2;
        if(key==p[mid]){
            flg=1;
            break;
        }
        else if(key>p[mid]){
            down=mid+1;
        }
        else if(key<p[mid]){
            up=mid-1;
        }
    }
    return flg;
}

int main(){
    int ch,num,result,key;
    cout<<"\nEnter the size of array::";
    cin>>num;
    int *p=new int[num];
    cout<<"\nEnter the elements of array::";
    for(int i=0;i<num;i++){
        cin>>p[i];
    }
    do{
        cout<<"\nEnter the value of Key to search::";
        cin>>key;
        cout<<"\n1.Linear Search\n2.Binary Search\n3.Exit\n";
        cout<<"\nEnter your choise\n";
        cin>>ch;
        switch(ch){
            case 1:
                result=linear_search(p,num,key);
                if(result==1){
                    cout<<"\nElement is present";
                }
                else {
                    cout<<"\nElement is not present";
                }
                break;
            case 2:
                result=binary_search(p,num,key);
                if(result==1){
                    cout<<"\nElement is present";
                }
                else cout<<"\nElement is not present";
                break;
            case 3:
                exit(0);
            default:
                cout<<"\nEnter the correct choise";
        }
    }while(ch!=3);
    return 0;
}