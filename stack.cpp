#include<iostream>
using namespace std;
#define max 100

class stack{

      public:
      int item[max],top;


      void create(stack * sp){
	   sp->top=-1;
	   cout<<"stack is created successfully\n";
      }


      void count(stack * sp){
	  cout<<"The elements of stack are::"<<sp->top+1<<endl;
      }
      int pop(stack * sp);

      void push(stack * sp,int);

      int isempty(stack * sp);

      int isfull(stack * sp);

      void display(stack * sp);

  };


  void stack::push(stack * sp,int x){

	 stack ob;
	 int s=isfull(&ob);
	 if(s==0){
	    sp->top++;
	    item[sp->top]=x;
	 }
	 else{
	    cout<<"The stack is overflow"<<endl;
	 }
  }


  int stack::pop(stack * sp){

      int a;
      stack obje;
      int p=isempty(&obje);
      if(p==0){

	  a=item[sp->top];
	  sp->top--;

	  return a;
      }
      else{
	    cout<<"The stack is underflow"<<endl;
	    return 0;
      }
  }



  int stack::isempty(stack * sp){

      if(sp->top==-1){
	   return 1;
      }
      else{
	  return 0;
      }
  }


  int stack::isfull(stack * sp){

      if(sp->top==max-1){
	 return 1;
      }
      else{
	 return 0;
      }
  }


  void stack::display(stack * sp){


      for(int i=sp->top;i>-1;i--){

	cout<<item[i]<<"\n";
      }
  }



  int main(){
       int num,ch,a;
       stack ob;


       do{

	   cout<<"1.Create\n2.push\n3.pop\n4.display\n5.count\n6.exit\n";
	   cout<<"Enter your choise";
	   cin>>ch;
	   cout<<endl;
	   switch(ch){

		 case 1:
		 ob.create(&ob);
		 break;

		 case 2:
		  cout<<"Enter the element to push\n";
		  cin>>num;
		  ob.push(&ob,num);
		  break;

		 case 3:
		  a=ob.pop(&ob);
		  cout<<"The "<<a<<"is poped from stack\n";
		  break;

		  case 4:
		     ob.display(&ob);
		     break;

		  case 5:
		     ob.count(&ob);
		     break;

		  case 6:
		     exit(1);
		     break;


		  default:
		    cout<<"Enter the valid choise\n";
		    break;
	   }
       }while(ch!=6);
      return 0;
    } 