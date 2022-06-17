#include <iostream>
#include <string>
#include "Tree.h"
using namespace std;

int main()
{
    string expr = "((a+b)*c-d)";
    cout << "Expression:" << expr << endl;
    ExpressionTree tree(expr);
    tree.BuildTree(tree.root, tree.expr);
    cout << "Built tree:" << endl;
    tree.OutputTree("", tree.root, false);
    string y1 = "(a+b)";
    string y2 = y1 + "*c";
    string y3 = y2 + "-d";
    cout << "\nBuilt tree y1:" << endl;
    ExpressionTree y1_tree(y1);
    y1_tree.BuildTree(y1_tree.root, y1_tree.expr);
    y1_tree.OutputTree("", y1_tree.root, false);
    cout << "\nBuilt tree y2:" << endl;
    ExpressionTree y2_tree(y2);
    y2_tree.BuildTree(y2_tree.root, y2_tree.expr);
    y2_tree.OutputTree("", y2_tree.root, false);
    cout << "\nBuilt tree y3:" << endl;
    ExpressionTree y3_tree(y3);
    y3_tree.BuildTree(y3_tree.root, y3_tree.expr);
    y3_tree.OutputTree("", y3_tree.root, false);
    float a, b, c, d;
    cout << "\na=";cin >> a;
    cout << "b=";cin >> b;
    cout << "c=";cin >> c;
    cout << "d=";cin >> d;
    cout << "\nResult=" << tree.Evaluate(tree.root, a, b, c, d);
}
