#include <iostream>
using namespace std;
class node
{
public:
    int info;
    node *right, *left;
} *root;

node *create()
{
    node *z = new node;
    return (z);
}



void insert(int val)
{
    node *temp, *p;
    p = create();
    p->right = NULL;
    p->left = NULL;
    p->info = val;
    if (root == NULL)
    {
        root = p;
    }
    else
    {
        temp = root;
        while (temp != NULL)
        {

            if (p->info < temp->info)
            {
                if (temp->left == NULL)
                {
                    temp->left = p;
                    cout << "\nNode is inserted";
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if (p->info > temp->info)
            {
                if (temp->right == NULL)
                {
                    temp->right = p;
                    cout << "\nNode is inserted";
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                cout << "The node is repeted\n";
                break;
            }
        }
    }
}

void search(int key){
    int flg=0;
    node *temp=root;
    while(temp!=NULL){
        if(key==temp->info){
            flg=1;
            break;
        }
        else if(key<temp->info){
            temp=temp->left;
        }
        else if(key>temp->info){
            temp=temp->right;
        }
    }
    if(flg==1){
        cout<<"\nThe Node is Found";
    }
    else{
        cout<<"\nThe Node is Not Found";
    }
}

void del_leaf(node *parent,node *child ){
    if(child==parent->left){
        parent->left=NULL;
    }
    else if(child==parent->right){
        parent->right=NULL;
    }
    delete child;
    cout<<"\nNode is deleted";
}

void del_one(node *parent,node *child){
    if(child==parent->left){
        if(child->left!=NULL){
            parent->left=child->left;
        }
        else{
            parent->left=child->right;
        }
    }
    else if(child==parent->right){
        if(child->right!=NULL){
            parent->right=child->right;
        }
        else {
            parent->right=child->left;
        }
    }
    delete child;
}

void del_two(node *child){
    node *lft,*parent=NULL;
    lft=child->left;
    while(lft->right!=NULL){
        parent=lft;
        lft=lft->right;
    }
    child->info=lft->info;
    if(parent==NULL){
        parent=child;
    }
    if(lft->right==NULL&&lft->left==NULL){
        del_leaf(parent,lft);
    }
    else {
        del_one(parent,lft);
    }
}

void delete_node(int s){
    int f=0;
    node *parent=NULL;
    node *child=root;
    while(child!=NULL){
        if(s==child->info){
            f=1;
            break;
        }
        else if(s<child->info){
            parent=child;
            child=child->left;
        }
        else if(s>child->info){
            parent=child;
            child=child->right;
        }
    }
    if(f==1){
        if(child->left==NULL&&child->right==NULL){
            del_leaf(parent,child);
        }
        else if(child->left!=NULL&&child->right!=NULL){
            del_two(child);
        }
        else{
            del_one(parent,child);
        }

    }
}

int count_leaf(node *p){
    if(p==NULL){
        return 0;
    }
    else if(p->left==NULL && p->right==NULL){
        return 1;
    }
    else{
        return (count_leaf(p->left)+count_leaf(p->right));
    }
}

int count_total(node *p){
    if (p == NULL)
        return 0;
    else
        return 1 + count_total(p->left) + count_total(p->right);
}



void inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout << "\t" << p->info;
        inorder(p->right);
    }
}

int main()
{
    int ch, num;
    do
    {
        cout << "\n1.Insert Node\n2.Display Node\n3.Search\n4.Count Leaf Node\n5.Count Total Nodes\n6.Delete Node\n7.Exit\n";
        cout << "Enter your choise\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "enter the number";
            cin >> num;
            insert(num);
            break;
        case 2:
            cout << "\nThe graph is below\n";
            inorder(root);
            break;
        case 3:
            cout<<"\nEnter the number to search::";
            cin>>num;
            search(num);
            break;
        case 4:
            num=count_leaf(root);
            cout<<"\n The leaf Nodes are::"<<num;
            break;
        case 5:
            int cnt;
            cnt=count_total(root);
            cout<<"\n The Total Nodes are::"<<cnt;
            break;
        case 6:
            cout<<"\nEnter the number to delete::";
            cin>>num;
            delete_node(num);
            break;
        case 7:
            exit(0);
        default:
            cout << "\nChoose The Correct choise";
            break;
        }
    } while (ch != 7);
    return 0;
}