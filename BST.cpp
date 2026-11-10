#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
node *insert(node *root, int val)
{
    if (root == NULL)
    {
        node *tmp = new node(val);
        return tmp;
    }
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
void inoder(node *root)
{
    if (root == NULL)
        return;
    inoder(root->left);
    cout << root->data << " ";
    inoder(root->right);
}
int main()
{
    int a[] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 17};
    node *root = NULL;
    for (int i = 0; i < 10; i++)
    {
        root = insert(root, a[i]);
    }
    inoder(root);
}