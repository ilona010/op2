#include "Tree.h"
ExpressionTree::ExpressionTree(string str)
{
    expr = str;
    root = new Node;
}
ExpressionTree::~ExpressionTree()
{
    delete root;
}
Node* ExpressionTree::BuildTree(Node* node, string str)
{
    int c = 0;
    for (int i = 0;i < str.length();i++)
    {
        if (!isalpha(str[i]))
        {
            if (str[i] != '.')
            {
                c++;
            }
        }
    }
    if (c == 0)
    {
        node->inf = str;
        node->l = NULL;
        node->r = NULL;
        return node;
    }
    else
    {
        if (str[0] == '(' && str[str.length() - 1] == ')')
        {
            str = str.substr(1, str.length() - 2);

        }
        c = 0;
        Node* left = new Node;
        Node* right = new Node;
        int i = 0;
        c = OperatorSearch(c, i, str, '+', '-');
        c = OperatorSearch(c, i, str, '*', '/');
        node->inf = str[i];
        node->l = BuildTree(left, str.substr(0, i));
        node->r = BuildTree(right, str.substr(i + 1, str.length() - i - 1));
        return node;
    }
}
void ExpressionTree::OutputTree(string str, Node* node, bool left)
{
    if (node != NULL)
    {
        cout << str + "|____";
        cout << node->inf << '\n';
        OutputTree(str + (left ? "| " : " "), node->l, true);
        OutputTree(str + (left ? "| " : " "), node->r, false);
    }
}
int OperatorSearch(bool c, int& i, string str, char first, char second)
{
    int d = 0;
    if (c == 0)
    {
        i = str.length() - 1;
        while (i != -1)
        {
            if (str[i] == '(') d++;
            if (str[i] == ')') d--;
            if (d == 0 && c == 0)
            {
                if (str[i] == first || str[i] == second)
                {
                    c = 1;
                    break;
                }
            }
            --i;
        }
    }
    return c;
}

double ExpressionTree::Evaluate(Node* node, double a, double b, double c, double d)
{
    double res = (a + b) * c - d;
    return res;
}
