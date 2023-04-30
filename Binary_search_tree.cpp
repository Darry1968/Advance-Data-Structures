#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    struct BSTNode *left, *right;
};

class BST
{
    struct BSTNode *root;

public:
    BST()
    {
        root = NULL;
    }
    void insert(BSTNode *p, int val)
    {
        BSTNode *temp;
        temp = new BSTNode;

        if (root == NULL)
        {
            temp->data = val;
            temp->left = NULL;
            temp->right = NULL;
            root = temp;
        }
        else
        {
            if (p->data <= val)
            {
                if (p->right != NULL)
                {
                    insert(p->right, val);
                }
                else
                {
                    temp->data = val;
                    temp->left = NULL;
                    temp->right = NULL;
                    p->right = temp;
                }
            }
            else
            {
                if (p->left != NULL)
                {
                    insert(p->left, val);
                }
                else
                {
                    temp->data = val;
                    temp->left = NULL;
                    temp->right = NULL;
                    p->left = temp;
                }
            }
        }
    }
    void insert1(int val)
    {
        insert(root, val);
    }

    BSTNode *Search(struct BSTNode *temp, int val)
    {
        int flag = 0;
        if (temp != NULL)
        {
            if (temp->data == val)
            {
                cout << "\nElement is found" << endl;
                return temp;
            }
            else if (temp->data > val)
            {
                Search(temp->left, val);
            }
            else
            {
                Search(temp->right, val);
            }
        }
    }

    void for_search(int val)
    {
        Search(root, val);
    }
    void Inorder(struct BSTNode *tmp)
    {
        if (tmp != NULL)
        {
            Inorder(tmp->left);
            cout << tmp->data << " ";
            Inorder(tmp->right);
        }
    }
    void Preorder(struct BSTNode *tmp)
    {
        if (tmp != NULL)
        {
            cout << tmp->data << " ";
            Inorder(tmp->left);
            Inorder(tmp->right);
        }
    }
    void Postorder(struct BSTNode *tmp)
    {
        if (tmp != NULL)
        {
            Inorder(tmp->left);
            Inorder(tmp->right);
            cout << tmp->data << " ";
        }
    }
    void Display()
    {
        cout << "\nInorder display : " << endl;
        Inorder(root);
        cout << "\nPreorder display : " << endl;
        Preorder(root);
        cout << "\nPostorder display : " << endl;
        Postorder(root);
        cout << endl;
    }
    void Modify(struct BSTNode *temp, int val, int modified_val)
    {
        if (temp != NULL)
        {
            if (temp->data == val)
            {
                temp->data = modified_val;
                cout << "\nValue is modified" << endl;
            }
            else if (temp->data > val)
            {
                Modify(temp->left, val, modified_val);
            }
            else
            {
                Modify(temp->right, val, modified_val);
            }
        }
    }
    void Modify1()
    {
        int modified_val, val;
        cout << "\nEnter the value to be modified : ";
        cin >> val;

        cout << "\nEnter the new value : ";
        cin >> modified_val;
        Modify(root, val, modified_val);
    }
};
int main()
{
    BST b1;
    b1.insert1(10);
    b1.insert1(5);
    b1.insert1(20);
    b1.insert1(30);
    b1.insert1(15);
    b1.Display();
    b1.for_search(20);
    b1.Modify1();
    b1.Display();

    return 0;
}