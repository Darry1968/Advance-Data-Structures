#include <iostream>
using namespace std;

struct TBTNode
{
    int data;
    struct TBTNode *left, *right;
    int lbit, rbit;
};

class TBTtree
{
    struct TBTNode *root, *header;

public:
    TBTtree()
    {
        root = NULL;
        header = NULL;
    }
    TBTNode *createNode()
    {
        struct TBTNode *tmp = new TBTNode;
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->lbit = 1;
        tmp->rbit = 1;

        cout << "Enter the data : ";
        cin >> tmp->data;
        return tmp;
    }
    void insert(struct TBTNode *r, struct TBTNode *t)
    {
        if (t->data < r->data)
        {
            if (r->lbit == 1)
            {
                cout << "Inserting in the left of " << r->data << endl;
                t->left = r->left;
                r->left = t;
                r->lbit = 0;
                t->right = r;
            }
            else
            {
                insert(r->left, t);
            }
        }
        else
        {
            if (r->rbit == 1)
            {
                cout << "Inserting in the right of " << r->data << endl;
                t->right = r->right;
                r->right = t;
                r->rbit = 0;
                t->left = r;
            }
            else
            {
                insert(r->right, t);
            }
        }
    }
    void create()
    {
        struct TBTNode *tmp;
        tmp = createNode();
        // cout << tmp->data;
        if (root == NULL)
        {
            root = tmp;
            header = new TBTNode;
            header->data = -999;
            header->left = root;
            root->left = header;
            root->right = header;
            cout << root->data << " " << root->left << " " << root->right << endl;
        }
        else
        {
            insert(root, tmp);
        }
    }
    void inorderDisplay(struct TBTNode *r, struct TBTNode *h)
    {
        while (r != h)
        {
            while (r->lbit == 0)
            {
                r = r->left;
            }
            cout << r->data << " ";
            while (r->rbit == 1)
            {
                r = r->right;
                if (r == h)
                    return;
                cout << r->data << " ";
            }
            r = r->right;
        }
    }
    void Display()
    {
        inorderDisplay(root, header);
    }
};

int main()
{
    TBTtree t1;
    t1.create();
    t1.create();
    t1.create();
    t1.create();
    t1.create();
    t1.create();
    cout << "\nOutput is : " << endl;
    t1.Display();

    return 0;
}

/*
    Inputs - 20 21 12 11 26 69
    Output must be - 11 12 20 21 26 69

    hint to verify whether code is working or not -
    provide your input and check Output is in increasing order
*/