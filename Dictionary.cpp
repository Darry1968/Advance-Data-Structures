#include <iostream>
#include <string.h>
using namespace std;

struct DictNode
{
    string key, value;
    struct DictNode *left, *right;
};

class Dictionary
{
    struct DictNode *root;
    string temp;

public:
    Dictionary()
    {
        root = NULL;
    }
    void insert(struct DictNode *r, string key, string val)
    {
        cout << "Entering with key : " << key << " and value : " << val << endl;

        struct DictNode *tmp = new DictNode;
        if (root == NULL)
        {
            tmp->key = key;
            tmp->value = val;
            tmp->left = NULL;
            tmp->right = NULL;
            root = tmp;
        }
        else
        {
            temp = r->key;
            if (strcmp(temp.c_str(), key.c_str()) > 0)
            {
                if (r->left == NULL)
                {
                    tmp->key = key;
                    tmp->value = val;
                    tmp->left = NULL;
                    tmp->right = NULL;
                    r->left = tmp;
                }
                else
                {
                    insert(r->left, key, val);
                }
            }
            else
            {
                if (r->right == NULL)
                {
                    tmp->key = key;
                    tmp->value = val;
                    tmp->left = NULL;
                    tmp->right = NULL;
                    r->right = tmp;
                }
                else
                {
                    insert(r->right, key, val);
                }
            }
        }
    }

    void Insert(string key, string val)
    {
        insert(root, key, val);
    }
    void Inorder(struct DictNode *tmp)
    {
        if (tmp != NULL)
        {
            Inorder(tmp->left);
            cout << tmp->key << " : " << tmp->value << endl;
            Inorder(tmp->right);
        }
    }
    void Display()
    {
        Inorder(root);
    }

    void Search(struct DictNode *p, struct DictNode *r, string key)
    {
        if (root != NULL)
        {
            if (strcmp(key.c_str(), (r->key).c_str()) == 0)
            {
                cout << "Found";
            }
            else if (strcmp(key.c_str(), (r->key).c_str()) > 0)
            {
                Search(r, r->right, key);
            }
            else
            {
                Search(r, r->left, key);
            }
        }
        else
        {
            cout << "Not Found" << endl;
        }
    }
    void for_search(string nme)
    {
        Search(NULL, root, nme);
    }

    void DeleteNode(struct DictNode *p, struct DictNode *r, string key)
    {
        if (root != NULL)
        {
            if (strcmp(key.c_str(), (r->key).c_str()) == 0)
            {
                if (p->left == r)
                {
                    p->left = NULL;
                    delete r;
                }
                else
                {
                    p->right = NULL;
                    delete r;
                }
            }
            else if (strcmp(key.c_str(), (r->key).c_str()) > 0)
            {
                DeleteNode(r, r->right, key);
            }
            else
            {
                DeleteNode(r, r->left, key);
            }
        }
        else
        {
            cout << "Not Found" << endl;
        }
    }
    void Delete()
    {
        string k;
        cout << "Enter value to be deleted from the BST : ";
        cin >> k;
        DeleteNode(NULL, root, k);
    }
};
int main()
{
    Dictionary d1;
    d1.Insert("A", "darshan");
    d1.Insert("B", "darshan");
    d1.Insert("C", "darshan");
    d1.Insert("D", "darshan");
    d1.Insert("roll", "2213273");
    d1.Insert("div", "E");
    d1.Display();
    // d1.for_search("5");
    d1.Delete();
    d1.Display();
    return 0;
}