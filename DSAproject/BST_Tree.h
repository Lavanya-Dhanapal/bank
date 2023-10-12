#pragma once
#include "BST_Node.h"
#include "Hashtable.h"
#include <vector>
#include <string>

class BST_Tree
{
private:
    BST_Node *Root;
    std::vector<int> v;

public:
    BST_Tree();
    void add_Account(std::string, std::string, int, int, int);
    BST_Node *delete_Account(BST_Node *, int);
    void withdraw(int, int);
    void deposit(int, int);
    void editaccount_byAdmin();
    void transfer(int, int, int);
    void transaction_history();
    void findMax(BST_Node *);
    void load_Server();
    void update_server(BST_Node *);
    BST_Node *search(BST_Node *, int);
    void printoinfo(BST_Node *);

private:
    Hashtable h;
};
