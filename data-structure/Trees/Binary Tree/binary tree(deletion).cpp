/**
 * Problem: To delete a provided node from a binary tree.
 */ 

/**
 * Algorithm:
 *  1.  
 *  2.  
 * 
 * Time Complexity: 
 * Space Complexity:
 */ 

// ----------------- CODE -------------------
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Structure for a node of the binary tree.
 */
struct node
{
    int data;
    node *right;
    node *left;
};

/**
 * Global vector to store the node addresses of the tree.
 */ 
vector<node *> v;

/**
 * Method to create a node for the binary tree.
 * @param data: Value to be inserted as a node in the tree.
 * @return temp: A new node with the data to be added in the tree.
 */ 
node *create(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

/**
 * Method to insert the new node in the binary tree.
 * @param v: Vector with the data from which the tree has to be generated.
 * @param root: Pointer to the root node of the tree.
 * @param n: Size of vector v.
 * @param i: Index of the current node for which it's children are to be calculated. 
 * 
 * @return root: The root node of the binary tree.
 */ 
node *insert(vector<int> v, node *root, int n, int i)
{
    if (i < n)
    {
        node *temp = create(v[i]);
        root = temp;

        root->left = insert(v, root->left, n, 2 * i + 1);

        root->right = insert(v, root->right, n, 2 * i + 2);
    }
    return root;
}

/**
 * Method to print the binary tree in level-order traversal (Breadth-first search).
 * @param root: Root node of the binary tree.
 */ 
void print(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *temp = q.front();
            cout << temp->data << " ";
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

/**
 * Method to create a level order traversal of the given binary tree.
 * @param root: Root node of the binary tree.
 * @param n: Total number of nodes in the tree.
 * 
 * @return root: Root of the tree.
 */ 
node *level_traversal(node *root, int n)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return root;
    }
    else
    {
        v.push_back(root);
        for (int i = 0; i < n; i++)
        {
            node *temp = v[i];
            if (temp->left != NULL)
            {
                v.push_back(temp->left);
            }
            if (temp->right != NULL)
            {
                v.push_back(temp->right);
            }
        }
    }
    return root;
}

/**
 * Method to delete the asked node.
 * @param root: Root node of the tree.
 * @param del: Value to be deleted from the tree.
 * 
 * @return root: Root node of the tree.
 */ 
node *deleting(node *root, int del)
{
    int len = v.size();
    node *last_index = v[len - 1];
    int l = len - 1;
    int parent_index;
    bool is_right;
    if (l % 2 == 0)
    {
        parent_index = (l - 2) / 2;
        is_right = true;
    }
    else
    {
        parent_index = (l - 1) / 2;
        is_right = false;
    }
    int i;
    for (i = 0; i < len; i++)
    {
        if (v[i]->data == del)
        {
            break;
        }
    }

    v[i]->data = last_index->data;

    if (is_right)
    {
        v[parent_index]->right = NULL;
    }
    else
    {
        v[parent_index]->left = NULL;
    }
    return root;
}

int main()
{
    cout << " enter the number of element u want in your tree" << endl;
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cout << "enter the elements" << endl;
        int num;
        cin >> num;
        v.push_back(num);
    }
    node *root = NULL;
    root = insert(v, root, n, 0);
    cout << "so your present tree is" << endl;
    cout << "************Tree*************" << endl;
    print(root);
    cout << endl;
    int del;
    cout << "enter the number you want to delete" << endl;
    cin >> del;
    root = level_traversal(root, n);
    root = deleting(root, del);
    cout << "tree after deletion" << endl;
    print(root);
}
