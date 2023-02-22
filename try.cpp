#include <iostream>
using namespace std;

struct ETreesNode
{
    char data;
    struct ETreesNode *left, *right;
};

class Etree
{
    struct ETreesNode *root;
    struct ETreesNode *st[20];
    int top;

public:
    struct ETreesNode *temp, *lnode;
    Etree()
    {
        root = NULL;
        top = -1;
    }

    void push(struct ETreesNode *temp)
    {
        if (top <= 19)
            st[++top] = temp;
    }

    struct ETreesNode *pop()
    {
        struct ETreesNode *temp;
        if (top != -1)
        {
            temp = st[top--];
        }
        return temp;
    }
    bool isOperator(char c)
    {
        if (isalpha(c) || isdigit(c))
        {
            return false;
        }
        return true;
    }

    void Create_Node()
    {
        char exp[20];
        int len = 0;

        cout << "Enter the expression : ";
        cin.getline(exp, 20);
        cout << "Your exp is : ";
        for (int i = 0; exp[i] != '\0'; i++)
        {
            cout << exp[i];
            len++;
        }

        cout << endl;
        for (int i = len - 1; i >= 0; i--)
        {
            if (!isOperator(exp[i]))
            {
                temp = new ETreesNode;
                temp->data = exp[i];
                temp->left = NULL;
                temp->right = NULL;
                // cout << "pushing" << temp->data;
                push(temp);
            }
            else
            {
                temp = new ETreesNode;
                temp->data = exp[i];
                temp->left = pop();
                temp->right = pop();
                push(temp);
            }
        }
        root = pop();
    }
    void Inorder(struct ETreesNode *temp)
    {
        if (temp != NULL)
        {

            Inorder(temp->left);
            cout << temp->data;
            Inorder(temp->right);
        }
    }
    void preOrder()
    {
        struct ETreesNode *pt;
        pt = root;
        cout << "Hi";
        if (pt != NULL)
        {

            while (1)
            {
                while (pt != NULL)
                {
                    cout << pt->data;
                    push(pt);
                    pt = pt->left;
                }
                if (top != -1)
                {
                    pop();
                    pt = pt->right;
                }
                else
                    return;
            }
        }
    }
    void display()
    {
        // cout<<"HELLO";
        Inorder(root);
    }
};

int main()
{
    Etree t1;
    t1.Create_Node();
    // t1.display();
    t1.preOrder();

    return 0;
}