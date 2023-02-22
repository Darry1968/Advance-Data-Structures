#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};
class BSTree
{
public:
    struct BSTNode *root;
    BSTree()
    {
        root = NULL;
    }
    void insert(BSTNode *p, int val)
    {
        BSTNode *tmp = new BSTNode;
        if (root == NULL)
        {

            tmp->data = val;
            tmp->left = NULL;
            tmp->right = NULL;
            root = tmp;
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
                    tmp->data = val;
                    tmp->left = NULL;
                    tmp->right = NULL;
                    p->right = tmp;
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
                    tmp->data = val;
                    tmp->left = NULL;
                    tmp->right = NULL;
                    p->left = tmp;
                }
            }
        }
    }
    void insert1(int val)
    {
        insert(root, val);
    }
    void InOrder(struct BSTNode *tmp)
    {
        if (tmp != NULL)
        {
            // left-root-right
            InOrder(tmp->left);
            cout << tmp->data;
            cout << endl;
            InOrder(tmp->right);
        }
    }
    void PostOrder(struct BSTNode *tmp)
    {
        if (tmp != NULL)
        {
            // left-right-root
            PostOrder(tmp->left);
            PostOrder(tmp->right);
            cout << tmp->data;
            cout << endl;
        }
    }
    void PreOrder(struct BSTNode *tmp)
    {
        if (tmp != NULL)
        {
            // root-left-right
            cout << tmp->data;
            cout << endl;
            PreOrder(tmp->left);
            PreOrder(tmp->right);
        }
    }
    void search(struct BSTNode *tmp, int n)
    {
        if (tmp != NULL)
        {
            if (tmp->data == n)
            {
                cout << "\nElement Found" << endl;
                return;
            }
            else if (tmp->data > n)
            {

                search(tmp->left, n);
            }
            else
            {

                search(tmp->right, n);
            }
        }
        else
        {
            cout << "Element Not Found";
        }
    }
    void search1(int n)
    {
        search(root, n);
    }
    void display()
    {
        cout << "InOrder : " << endl;
        InOrder(root);
        cout << "\nPostOrder :" << endl;
        PostOrder(root);
        cout << "\nPreOrder :" << endl;
        PreOrder(root);
    }

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
        InOrder(root);
    }

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
            return 0;
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
        cout << "Sidha ->" << endl;
        for (int i = 0; i < h; i++)
        {
            LevelDisplay(root, i);
        }
    }

    void LevelDisplay2(struct BSTNode *tmp, int l)
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
                LevelDisplay2(tmp->left, l - 1);
                LevelDisplay2(tmp->right, l - 1);
            }
        }
    }
    void LevelDisplay3()
    {
        int h = Height(root);
        // cout << "h : " << h;
        cout << "\nUlta ->" << endl;
        for (int i = h; i >= 0; i--)
        {
            LevelDisplay2(root, i);
        }
    }
    void findPaths(struct BSTNode *tmp, int path[], int pathLen)
    {
        if (tmp == NULL)
            return;
        else
        {
            path[pathLen] = tmp->data;
            pathLen++;

            if (tmp->left == NULL && tmp->right == NULL)
            {
                for (int i = 0; i < pathLen; i++)
                {
                    cout << path[i] << " ";
                }
                cout << endl;
            }
            else
            {
                findPaths(tmp->left, path, pathLen);
                findPaths(tmp->right, path, pathLen);
            }
        }
    }
    void getPaths()
    {
        int path[15];
        findPaths(root, path, 0);
    }
    bool isBST(BSTNode *tmp)
    {
        if (tmp == NULL)
        {
            return true;
        }

        if (tmp->left != NULL && tmp->left->data > tmp->data)
        {
            return false;
        }
        if (tmp->right != NULL && tmp->right->data < tmp->data)
        {
            return false;
        }

        if (!isBST(tmp->left) || !isBST(tmp->right))
        {
            return false;
        }

        return true;
    }
    void CheckBST()
    {
        if (isBST(root))
            cout << "Tree is BST" << endl;
        else
            cout << "Tree is not a BST" << endl;
    }
};

int main()
{
    BSTree b1;
    // b1.insert1(10);
    // b1.insert1(5);
    // b1.insert1(18);
    // b1.insert1(30);
    // b1.insert1(15);

    b1.insert1(1);
    b1.insert1(2);
    b1.insert1(3);
    b1.insert1(4);
    b1.insert1(5);
    b1.insert1(6);
    b1.insert1(7);

    // b1.display();
    // cout<<endl;
    // b1.search1(18);
    // cout<<endl;
    // b1.PLN();
    // cout<<endl;
    // b1.Mirror();
    // cout<<endl;

    // b1.HT();
    // b1.LevelDisplay1();
    // b1.LevelDisplay3();
    // b1.getPaths();
    b1.CheckBST();
}