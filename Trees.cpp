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

    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
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
    void display()
    {
        Inorder(root);
    }

    void Preorder()
    {
        // Preorder Display without recursion
        struct ETreesNode *pt, *pt1;
        pt = root;
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
                    pt = pop();
                    pt = pt->right;
                }
                else
                    return;
            }
        }
    }
    void Pre_rec(struct ETreesNode *temp)
    {
        // Preorder display with recursion
        if (temp != NULL)
        {
            cout << temp->data;
            Pre_rec(temp->left);
            Pre_rec(temp->right);
        }
    }
    void Display2()
    {
        // For Preorder
        Pre_rec(root);
    }

    void PostOrder(struct ETreesNode *temp)
    {
        // Postorder display
        if (temp != NULL)
        {
            PostOrder(temp->left);
            PostOrder(temp->right);
            cout << temp->data;
        }
    }
    void Display3()
    {
        // Postorder display
        PostOrder(root);
    }
};

int main()
{
    Etree t1;
    t1.Create_Node();
    cout << "In order display : ";
    t1.display();
    cout << "\nPre order display : ";
    t1.Preorder();
    cout << "\nPost order display : ";
    t1.Display3();
    return 0;
}

/*  Provide input
    +a*bc
*/