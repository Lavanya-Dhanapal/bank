#pragma once
# include <iostream>
# include <fstream>
# include <string>
# include "Node_1.h"
class Node
{
public:

	Node * next = nullptr;
	Node_1 * pre = nullptr;
	int data;
	explicit Node();
	explicit Node(int);
};
