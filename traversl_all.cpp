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

void inorder_traverse(node *p)
{
    if (p != NULL)
    {
        inorder_traverse(p->left);
        cout << "\t" << p->info;
        inorder_traverse(p->right);
    }
}

void preorder_traverse(node *p)
{
    if (p != NULL)
    {
        cout << "\t" << p->info;
        preorder_traverse(p->left);
        preorder_traverse(p->right);
    }
}

void postorder_traverse(node *p)
{
    if (p != NULL)
    {
        postorder_traverse(p->left);
        postorder_traverse(p->right);
        cout << "\t" << p->info;
    }
}

int main()
{
    int ch, num;
    do
    {
        cout << "\n1.insert\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n";
        cout << "\nEnter your choise::";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter the number ::";
            cin >> num;
            insert(num);
            break;
        case 2:
            cout<<"\nThis is Inorder Traversal\n";
            inorder_traverse(root);
            break;
        case 3:
            cout<<"\nThis is preorder Traversal\n";
            preorder_traverse(root);
            break;
        case 4:
            cout<<"\nThis is postorder Traversal\n";
            postorder_traverse(root);
            break;
        case 5:
            exit(0);
        default:
            cout << "\nEnter the correct choise";
            break;
        }
    } while (ch!=5);
    return 0;
}