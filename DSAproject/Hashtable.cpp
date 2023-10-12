# include <iostream>
# include "Hashtable.h"
# include <vector>
using namespace std;

Hashtable:: Hashtable(): start(nullptr)
{
	start = nullptr;
}
void Hashtable:: starthash()
{
	for (int i = 0; i < 12; i++)
	{
		auto temp1 = make_shared<Node>(i);
		if (start == nullptr)
		{
			start = temp1;
		}
		else
		{
			shared_ptr<Node> current = start;
			while (current ->next != nullptr)
			{
				current = current->next;
			}
			current->next = temp1;
		}
	}
	loadhashtable();
}
void Hashtable::add(int a, int p)
{
	static int i = 0;
	ofstream write;
	write.open("hashtable.txt",ios::app);
	if (i != 0)
	{
		write << endl;
		write << a << endl << p;
	}
	else
	{
		i++;
		write << a << endl << p;
	}
	write.close();

	starthash();
}
bool Hashtable::match(int a, int p)
{
	bool flag = false;
	int r = a % 10;
	Node * c = start;
	while (c->data != r)
	{
		c = c->next;
	}
	Node_1 *c1 = c->pre;
	while (c1 != nullptr)
	{
		if (c1->accountNumber == a && c1->password == p)
		{
			flag = true;
			break;
		}
		c1 = c1->next;
	}
	return flag;
}
void Hashtable:: display()
{
	Node * current = start;
	while (current != nullptr)
	{
		cout<<current->data<<endl;
		current = current->next;
	}
}
void Hashtable::loadhashtable()
{
    ifstream read;
    read.open("hashtable.txt");

    int acc = 0;
    int r;
    int pass;

    while (read >> acc >> pass)
    {
        if (match(acc, pass) || acc == -858993460 || pass == -858993460)
        {
            // Skip invalid or duplicate entries.
            continue;
        }

        r = acc % 10;
        Node *c = findNodeByData(r);
        if (!c)
        {
            // Handle the case where the node doesn't exist.
            continue;
        }

        std::shared_ptr<Node_1> temp = std::make_shared<Node_1>(acc, pass);
        insertNode_1(c, temp);
    }

    read.close();
}

Node *Hashtable::findNodeByData(int data)
{
    Node *c = start;
    while (c->data != data)
    {
        c = c->next;
        if (!c)
        {
            // Handle the case where the desired node doesn't exist.
            return nullptr;
        }
    }
    return c;
}

void Hashtable::insertNode_1(Node *node, std::shared_ptr<Node_1> temp)
{
    if (node->pre == nullptr)
    {
        node->pre = temp;
    }
    else
    {
        Node_1 *root = node->pre;
        while (root->next != nullptr)
        {
            root = root->next;
        }
        root->next = temp;
    }
}

void  Hashtable::displayPasswords()
{
	starthash();
	Node *c = start;
	while (c != nullptr)
	{
		Node_1 *c1 = c->pre;
		while (c1 != nullptr)
		{
			cout<<c1->accountNumber<<endl;
			cout<<c1->password<<endl<<endl;
			c1 = c1->next;
		}
		c = c->next;
	}
}
void  Hashtable:: delete_password(int accountno)
{
	ifstream read;
	read.open("hashtable.txt");
	vector <int> v;
	int acc=0;
	int pass=0;
	int i = 0;
	while (!read.eof())
	{
		i++;
		read >> acc;
		read >> pass;
		if (acc == accountno)
		{	                                           // read both account number and password to skip them
			continue;
		}
		v.push_back(acc);
		v.push_back(pass);
	}
	read.close();
	ofstream write;
	write.open("temp.txt", ios::app);
	
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] != 0)
			{
				write << v[j] << endl;
			}
		}
	
	
	write.close();
	remove("hashtable.txt");
	rename("temp.txt", "hashtable.txt");
}
