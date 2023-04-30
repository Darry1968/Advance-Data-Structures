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
    BSTNode *st[20];
    int top;

public:
    BST()
    {
        root = NULL;
        top = -1;
    }
    // stack operations
    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }

    // stack operations
    void push(BSTNode *p)
    {
        st[++top] = p;
    }

    // stack operations
    BSTNode *pop()
    {
        if (!isEmpty())
        {
            struct BSTNode *p;
            p = st[top];
            top--;
            return p;
        }
    }

    void insert(struct BSTNode *p, int val)
    {
        struct BSTNode *temp;
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

    // With recursion
    void InorderDisplay(struct BSTNode *temp)
    {
        if (temp != NULL)
        {
            InorderDisplay(temp->left);
            cout << temp->data << " ";
            InorderDisplay(temp->right);
        }
    }

    // With recursion
    void PreorderDisplay(struct BSTNode *temp)
    {
        if (temp != NULL)
        {
            cout << temp->data << " ";
            PreorderDisplay(temp->left);
            PreorderDisplay(temp->right);
        }
    }

    // With recursion
    void PostorderDisplay(struct BSTNode *temp)
    {
        if (temp != NULL)
        {
            PostorderDisplay(temp->left);
            PostorderDisplay(temp->right);
            cout << temp->data << " ";
        }
    }
    void Display()
    {
        cout << "Inorder display with recursion : " << endl;
        InorderDisplay(root);
        cout << endl;
        cout << "Preorder display with recursion : " << endl;
        PreorderDisplay(root);
        cout << endl;
        cout << "Post display with recursion : " << endl;
        PostorderDisplay(root);
        cout << endl;
    }

    void Preorder_Non_recursive()
    {
        struct BSTNode *temp;
        if (root != NULL)
        {
            temp = root;
            while (1)
            {
                while (temp != NULL)
                {
                    cout << temp->data << " ";
                    push(temp);
                    temp = temp->left;
                }
                if (!isEmpty())
                {
                    temp = pop();
                    temp = temp->right;
                }
                else
                    return;
            }
        }
    }

    void Inorder_Non_recursive()
    {
        struct BSTNode *temp;
        if (root != NULL)
        {
            temp = root;
            while (1)
            {
                while (temp != NULL)
                {
                    push(temp);
                    temp = temp->left;
                }
                if (isEmpty())
                {
                    break;
                }
                temp = pop();
                cout << temp->data << " ";
                temp = temp->right;
            }
        }
    }
    int Search(struct BSTNode *pt, int val)
    {
        if (pt != NULL)
        {
            if (pt->data == val)
            {
                return 1;
            }
            else if (pt->data <= val)
            {
                Search(pt->right, val);
            }
            else
            {
                Search(pt->left, val);
            }
        }
    }

    void search()
    {
        int val;
        cout << "Enter the value to be searched : ";
        cin >> val;
        if (Search(root, val) == 1)
        {
            cout << "Found the Key" << endl;
        }
        else
        {
            cout << "Key doesn't exists" << endl;
        }
    }

    // Mirror image
    void Mirror_Image(struct BSTNode *r)
    {
        if (r == NULL)
        {
            return;
        }
        else
        {
            Mirror_Image(r->left);
            Mirror_Image(r->right);
            struct BSTNode *temp;
            temp = r->left;
            r->left = r->right;
            r->right = temp;
        }
    }
    void Mirror()
    {
        Mirror_Image(root);
        cout << "Displaying in INORDER way : " << endl;
        InorderDisplay(root);
    }

    // PRINTING LEAF NODES
    void printLeafNode(struct BSTNode *r)
    {
        if (r == NULL)
            return;
        else if (r->left == NULL && r->right == NULL)
        {
            cout << r->data << " ";
        }
        else
        {
            printLeafNode(r->left);
            printLeafNode(r->right);
        }
    }
    void PLN()
    {
        cout << "Leaf Nodes are : ";
        printLeafNode(root);
    }

    int Height(struct BSTNode *r)
    {
        int leftHT, rightHT;
        if (r == NULL)
        {
            return 0;
        }
        else
        {
            leftHT = Height(r->left);
            rightHT = Height(r->right);
            if (leftHT > rightHT)
                return leftHT + 1;
            return rightHT + 1;
        }
    }
    void HT()
    {
        int h;
        h = Height(root);
        cout << "Height of tree is : " << h << endl;
    }
    // lEVEL DISPLAY
    void LevelDisplay(struct BSTNode *tmp, int l)
    {
        if (tmp == NULL)
            return;
        else
        {
            if (tmp == NULL)
            {
                return;
            }
            else if (l == 0)
            {
                cout << tmp->data << " ";
            }
            else
            {
                LevelDisplay(tmp->left, l - 1);
                LevelDisplay(tmp->right, l - 1);
            }
        }
    }
    void LevelDisplay1()
    {
        int h = Height(root);
        for (int i = 0; i < h; i++)
        {
            LevelDisplay(root, i);
        }
    }
};
int main()
{
    BST b1;
    b1.insert1(10);
    b1.insert1(5);
    b1.insert1(15);
    b1.insert1(12);
    b1.insert1(18);
    b1.Display();

    cout << "Preorder NON recursive display : " << endl;
    b1.Preorder_Non_recursive();
    cout << endl;
    cout << "Inorder NON recursive display : " << endl;
    b1.Inorder_Non_recursive();
    cout << endl;

    b1.search();
    cout << endl;

    b1.Mirror();
    cout << endl;

    b1.PLN();
    cout << endl;

    b1.HT();
    cout << endl;

    cout << "Displaying Levelwise : " << endl;
    b1.LevelDisplay1();
    return 0;
}

/*
    there are no inputs here except
    for search provide any key its on you and do not change any line
*/