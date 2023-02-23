#include <iostream>
using namespace std;

struct edge
{
    char name;
    struct edge *link;
};
struct Node
{
    char data;
    struct edge *adj;
    struct Node *next;
};

class Graph
{
    struct Node *start;

public:
    struct Node *bptr, *ptr;
    char s, d;
    int n = 65;
    struct edge *p, *bp;
    Graph()
    {
        start = NULL;
    }
    void ScanGraph(int v, int e)
    {
        for (int i = 0; i < v; i++)
        {
            ptr = new Node;
            ptr->data = (n + i);
            ptr->adj = NULL;
            ptr->next = NULL;
            if (start == NULL)
            {
                start = ptr;
            }
            else
            {
                bptr = start;
                while (bptr->next != NULL)
                    bptr = bptr->next;
                bptr->next = ptr;
            }
        }
        for (int i = 0; i < e; i++)
        {
        l1:
            cout << "Edge no. : " << i + 1 << endl;
            cout << "Enter source : ";
            cin >> s;
            cout << "Enter Destination : ";
            cin >> d;
            if ((s >= n && s < (n + v)) && (d >= n && d < (n + v)))
            {
                bptr = start;
                while (bptr->data != s)
                    bptr = bptr->next;
                if (bptr != NULL)
                {
                    p = new edge;
                    p->name = d;
                    p->link = NULL;
                    bp = bptr->adj;
                    if (bp == NULL)
                    {
                        bptr->adj = p;
                    }
                    else
                    {
                        while (bp->link != NULL)
                        {
                            bp = bp->link;
                        }
                        bp->link = p;
                    }
                }
            }
            else
            {
                cout << "Enter correct source and destination!!" << endl;
                goto l1;
            }
        }
    }
    void DisplayGraph()
    {
        struct Node *ptr;
        struct edge *p;
        ptr = start;
        while (ptr != NULL)
        {
            cout << ptr->data;
            p = ptr->adj;
            while (p != NULL)
            {
                cout << "-->" << p->name;
                p = p->link;
            }
            ptr = ptr->next;
            if (ptr != NULL)
                cout << endl
                     << "|" << endl;
        }
    }
};
int main()
{
    Graph g1;
    g1.ScanGraph(4, 3);
    g1.DisplayGraph();

    return 0;
}