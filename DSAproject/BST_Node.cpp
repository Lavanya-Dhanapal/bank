
# include "BST_Node.h"

BST_Node:: BST_Node() : name(""), address(""), account_number(0), password(0), balance(0)
{
}
BST_Node:: BST_Node(string name, string adress, int accountno, int password, int balance)
{
	
	this->name = name;
	this->account_number = accountno;
	this->adress = adress;
	this->balance = balance;
	this->password = password;
}
