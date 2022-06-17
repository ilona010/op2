#pragma once
#include <iostream>
#include <string>
using namespace std;
int OperatorSearch(bool c, int& i, string str, char first, char second);

struct Node
{
    string inf;
    Node* l, * r;
};
class ExpressionTree
{
public:
    Node* root;
    string expr;
    ExpressionTree(string str);
    ~ExpressionTree();
    Node* BuildTree(Node* node, string str);
    void OutputTree(string str, Node* node, bool c);
    double Evaluate(Node* node, double a, double b, double c, double d);
};