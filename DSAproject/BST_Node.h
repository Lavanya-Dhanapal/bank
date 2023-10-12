#pragma once
# include <iostream>
# include <vector>
# include <fstream>
# include <string>

class BST_Node 
{
public:
	BST_Node * left = nullptr;
	BST_Node * right = nullptr;
	string name;
	string adress;
	int account_number;
	int password;
	int balance;

	BST_Node();
	BST_Node(string, string, int, int, int);
	
};
