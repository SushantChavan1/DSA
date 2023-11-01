#include<iostream>
using namespace std;
class Node
{
public:
	int info;
	Node *pre, *next;
} *head;

Node *create()
{
	Node *z = new Node;
	return z;
}

void insert_begin(int val)
{

	Node *p, *q;
	p = head;
	if (p == NULL)
	{
		p = create();
		p->pre = NULL;
		p->info = val;
		p->next = NULL;
		head = p;
	}
	else
	{
		q = create();
		q->pre = NULL;
		q->info = val;
		q->next = p;
		p->pre = q;
		head = q;
	}
}

void insert_end(int val)
{
	Node *p, *q;
	p = head;
	if (p == NULL)
	{
		p = create();
		p->pre = NULL;
		p->info = val;
		p->next = NULL;
		head = p;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		q = create();
		q->next = NULL;
		q->info = val;
		q->pre = p;
		p->next = q;
	}
}

void insert_between(int after, int val)
{
	Node *p, *q;
	p = head;
	if (p == NULL || p->next->next == NULL)
	{
		cout << "The operation is not possible\n";
	}
	else
	{
		while (p->next != NULL)
		{
			if (p->info == after)
			{
				q = create();
				q->info = val;
				q->next = p->next;
				p->next = q;
				q->pre = p;
			}
			p = p->next;
		}
	}
}

void display()
{
	Node *p;
	p = head;
	while (p != NULL)
	{
		cout << "  " << p->info;
		p = p->next;
	}
}

int remove_begin()
{
	Node *p;
	int r;
	p = head;
	if (p->next == NULL)
	{
		r = p->info;
		delete p;
	}
	else
	{
		r = p->info;
		p->next->pre = NULL;
		head = p->next;
		delete p;
	}
	return r;
}

int remove_end()
{
	Node *p, *temp;
	p = head;
	int r;
	if (p->next == NULL)
	{
		r = p->info;
		delete p;
	}
	else
	{
		while (p->next->next != NULL)
		{
			p = p->next;
		}
		temp = p->next;
		r = temp->info;
		p->next = NULL;
		delete temp;
	}
	return r;
}

int remove_between(int after)
{
	Node *temp, *p;
	int r;
	p = head;
	if (p == NULL || (p->pre == NULL && p->next == NULL))
	{
		cout << "The operation is not successful\n";
	}
	else
	{
		while (p->next != NULL)
		{
			if (p->info == after)
			{
				temp = p->next;
				temp->next->pre = p;
				p->next = temp->next;
				r = temp->info;

				delete temp;
			}
			p = p->next;
		}
	}
	return r;
}

int count()
{
	Node *p;
	p = head;
	int cnt = 0;
	while (p != NULL)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}
int search(int se)
{
	Node *p;
	p = head;
	while (p != NULL)
	{
		if (p->info == se)
			return 0;
		p = p->next;
	}
	return 1;
}
void reverse()
{
	Node *temp, *curr;
	temp = NULL;
	curr = head;
	while (curr != NULL)
	{
		temp = curr->pre;
		curr->pre = curr->next;
		curr->next = temp;
		curr = curr->pre;
	}
	head = temp->pre;
}

int main()
{
	int ch, num, af;
	clrscr();
	do
	{
		cout << "\n1.Insert_beg\n2.Insert_end\n3.insert_between\n4.display\n5.Remove_begning\n6.Remove_end\n7.remove_between\n8.Count\n9.Search\n10.reverse\n11.exit\n";
		cout << "Enter your choise\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter the number\n";
			cin >> num;
			insert_begin(num);
			break;

		case 2:
			cout << "Enter the number\n";
			cin >> num;
			insert_end(num);
			break;

		case 3:
			cout << "Enter the after element \n";
			cin >> num;
			cout << "Enter the element";
			cin >> af;
			insert_between(num, af);
			break;

		case 4:
			display();
			break;

		case 5:
			num = remove_begin();
			cout << num << " is removed\n";
			break;
		case 6:
			num = remove_end();
			cout << num << " is removed\n";
			break;
		case 7:
			cout << "Enter the after position\n";
			cin >> num;
			num = remove_between(num);
			cout << num << " is removed\n";
			break;
		case 8:
			num = count();
			cout << num << " elements in list\n";
			break;
		case 9:
			cout << "Enter the number to search\n";
			cin >> num;
			num = search(num);
			if (num == 0)
				cout << "Number is Present\n";
			else
				cout << "Number is not Present\n";
			break;
		case 10:
			reverse();
			break;
		case 11:
			exit(0);
		}
	} while (ch != 11);
	return 0;
}