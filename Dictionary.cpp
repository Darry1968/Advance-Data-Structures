#include <iostream>
#include <string.h>
using namespace std;

struct Dictnode
{
    string key, value;
    struct Dictnode *left, *right;
};

class Dict
{
    struct Dictnode *root;

public:
    Dict()
    {
        root = NULL;
    }
    void insert1(string k, string v)
    {
        insert(root, k, v);
    }
    void insert(struct Dictnode *r, string k, string v)
    {
        if (root == NULL)
        {
            struct Dictnode *tmp = new Dictnode;
            tmp->key = k;
            tmp->value = v;
            tmp->left = NULL;
            tmp->right = NULL;
            root = tmp;
        }
        else
        {
            if (strcmp(r->key.c_str(), k.c_str()) <= 0)
            {
                if (r->right == NULL)
                {
                    struct Dictnode *tmp = new Dictnode;
                    tmp->key = k;
                    tmp->value = v;
                    tmp->left = NULL;
                    tmp->right = NULL;
                    r->right = tmp;
                }
                else
                {
                    insert(r->right, k, v);
                }
            }
            else
            {
                if (r->left == NULL)
                {
                    struct Dictnode *tmp = new Dictnode;
                    tmp->key = k;
                    tmp->value = v;
                    tmp->left = NULL;
                    tmp->right = NULL;
                    r->left = tmp;
                }
                else
                {
                    insert(r->left, k, v);
                }
            }
        }
    }
    void search(struct Dictnode *p, struct Dictnode *r, string key)
    {
        if (root == NULL)
            cout << "Empty tree ";
        else
        {
            if (strcmp(key.c_str(), r->key.c_str()) == 0)
            {
                if (r->left == NULL && r->right == NULL)
                {

                    if (p->left = r)
                    {
                        p->left = NULL;
                        delete (r);
                        cout << "After deletion the dictionary is :" << endl;
                        Display1();
                    }
                    else
                    {
                        p->right = NULL;
                        delete (r);
                        cout << "After deletion the dictionary is :";
                        Display1();
                    }
                }
                else if (r->left != NULL && r->right == NULL)
                {
                    if (p->left == r)
                    {
                        p->left = r->left;
                        delete (r);
                        cout << "After deletion of one child in dictionary is :" << endl;
                        Display1();
                    }
                    else
                    {
                        p->right = r->left;
                        delete (r);
                        cout << "After deletion of one child in dictionary is :" << endl;
                        Display1();
                    }
                }
                else if (r->left == NULL && r->right != NULL)
                {
                    if (p->right == r)
                    {
                        p->right = r->right;
                        delete (r);
                        cout << "After deletion of one child in dictionary is :" << endl;
                        Display1();
                    }
                    else
                    {
                        p->left = r->right;
                        delete (r);
                        cout << "After deletion of one child in dictionary is :" << endl;
                        Display1();
                    }
                }
            }
            else if (strcmp(key.c_str(), r->key.c_str()) > 0)
            {
                search(r, r->right, key);
            }
            else
            {
                search(r, r->left, key);
            }
        }
    }
    void search1(string key)
    {
        search(NULL, root, key);
    }

    void display(struct Dictnode *tmp)
    {
        if (tmp != NULL)
        {
            display(tmp->left);
            cout << tmp->key << " : " << tmp->value << endl;
            display(tmp->right);
        }
    }
    void Display1()
    {
        display(root);
    }
};
int main()
{
    Dict d;
    d.insert1("Q", "PQR");
    d.insert1("A", "ABC");
    d.insert1("P", "GFP");
    d.insert1("C", "LMN");
    d.Display1();
    d.search1("P");
    return 0;
}
