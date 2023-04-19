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
    int V;
    struct edge *p, *bp;
    Graph()
    {
        start = NULL;
    }
    void ScanGraph(int v, int e)
    {
        V = v;
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

    void dfs(struct Node *s)
    {
        char sv;
        int visited[V];
        struct edge *st[10];
        int top = -1;
        cout << "\nenter start vertex: ";
        cin >> sv;
        // sv = sv+65;
        struct edge *e1 = new edge;
        e1->name = sv;
        // cout<<e1->name;
        e1->link = NULL;
        top++;
        st[top] = e1;

        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
        }
        //       cout<<"reached";
        while (top != -1)
        {
            e1 = st[top];
            //  cout<<"poped->"<<e1->name;
            top--;
            int t = e1->name - 65;
            // cout<<endl<<"t->"<<t;
            sv = e1->name;
            struct Node *tmp = s;
            if (visited[t] == 0)
            {
                // cout<<2;
                visited[t] = 1;
                cout << e1->name;

                while (tmp->next != NULL)
                {
                    if (tmp->data == sv)
                    {
                        // cout<<tmp->data;
                        //                     cout<<"breaking";
                        break;
                    }
                    else
                    {
                        tmp = tmp->next;
                    }
                }

                struct edge *e;
                e = tmp->adj;
                // cout<<"e->"<<e;
                if (e != NULL)
                {
                    do
                    {

                        // cout<<endl<<"pushing->"<<e->name<<endl;

                        st[++top] = e;
                        // cout<<endl<<e->name;
                        e = e->link;

                        // cout<<
                    } while (e != NULL);
                }
            }
        }
    }

    void bfs(struct Node *s)
    {
        char sv;
        int max = 50;
        int visited[V];
        struct edge *q[max];
        int rear = -1;
        int front = -1;
        cout << "\nenter start vertex: ";
        cin >> sv;

        // sv = sv+65;
        struct edge *e1 = new edge;
        e1->name = sv;
        //  cout<<e1->name;
        e1->link = NULL;
        rear++;
        q[rear] = e1;
        front++;

        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
        }
        visited[sv - 65] = 1;

        while (front != -1 && front <= rear)
        {
            // cout<<"FRONT"<<front<<"REAR "<<rear<<endl;
            e1 = q[front];
            cout << e1->name << " ";
            front++;
            sv = e1->name;
            int t = sv - 65;
            // cout<<endl<<"t->"<<t;

            struct Node *tmp = s;

            while (tmp->next != NULL)
            {
                if (tmp->data == sv)
                {
                    // cout<<tmp->data;
                    // cout<<"breaking";
                    break;
                }
                else
                {
                    tmp = tmp->next;
                }
            }

            struct edge *e;
            e = tmp->adj;
            // cout<<"e->"<<e;
            if (e != NULL)
            {
                do
                {

                    int t1 = e->name - 65;
                    //   cout<<endl<<"pushing->"<<t1<<visited[t1];
                    if (visited[t1] != 1)
                    {

                        rear++;
                        q[rear] = e;
                        visited[t1] = 1;
                        //  cout<<endl<<e->name<<"rear"<<rear;;
                    }
                    e = e->link;
                } while (e != NULL);
            }
        }
    }
    void dummy()
    {
        bfs(start);
    }
};
int main()
{
    Graph g1;
    g1.ScanGraph(4, 5);
    g1.DisplayGraph();
    g1.dummy();
    return 0;
}
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
    int V;
    struct edge *p, *bp;
    Graph()
    {
        start = NULL;
    }
    void ScanGraph(int v, int e)
    {
        V = v;
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

    void dfs(struct Node *s)
    {
        char sv;
        int visited[V];
        struct edge *st[10];
        int top = -1;
        cout << "\nenter start vertex: ";
        cin >> sv;
        // sv = sv+65;
        struct edge *e1 = new edge;
        e1->name = sv;
        // cout<<e1->name;
        e1->link = NULL;
        top++;
        st[top] = e1;

        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
        }
        //       cout<<"reached";
        while (top != -1)
        {
            e1 = st[top];
            //  cout<<"poped->"<<e1->name;
            top--;
            int t = e1->name - 65;
            // cout<<endl<<"t->"<<t;
            sv = e1->name;
            struct Node *tmp = s;
            if (visited[t] == 0)
            {
                // cout<<2;
                visited[t] = 1;
                cout << e1->name;

                while (tmp->next != NULL)
                {
                    if (tmp->data == sv)
                    {
                        // cout<<tmp->data;
                        //                     cout<<"breaking";
                        break;
                    }
                    else
                    {
                        tmp = tmp->next;
                    }
                }

                struct edge *e;
                e = tmp->adj;
                // cout<<"e->"<<e;
                if (e != NULL)
                {
                    do
                    {

                        // cout<<endl<<"pushing->"<<e->name<<endl;

                        st[++top] = e;
                        // cout<<endl<<e->name;
                        e = e->link;

                        // cout<<
                    } while (e != NULL);
                }
            }
        }
    }

    void bfs(struct Node *s)
    {
        char sv;
        int max = 50;
        int visited[V];
        struct edge *q[max];
        int rear = -1;
        int front = -1;
        cout << "\nenter start vertex: ";
        cin >> sv;

        // sv = sv+65;
        struct edge *e1 = new edge;
        e1->name = sv;
        //  cout<<e1->name;
        e1->link = NULL;
        rear++;
        q[rear] = e1;
        front++;

        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
        }
        visited[sv - 65] = 1;

        while (front != -1 && front <= rear)
        {
            // cout<<"FRONT"<<front<<"REAR "<<rear<<endl;
            e1 = q[front];
            cout << e1->name << " ";
            front++;
            sv = e1->name;
            int t = sv - 65;
            // cout<<endl<<"t->"<<t;

            struct Node *tmp = s;

            while (tmp->next != NULL)
            {
                if (tmp->data == sv)
                {
                    // cout<<tmp->data;
                    // cout<<"breaking";
                    break;
                }
                else
                {
                    tmp = tmp->next;
                }
            }

            struct edge *e;
            e = tmp->adj;
            // cout<<"e->"<<e;
            if (e != NULL)
            {
                do
                {

                    int t1 = e->name - 65;
                    //   cout<<endl<<"pushing->"<<t1<<visited[t1];
                    if (visited[t1] != 1)
                    {

                        rear++;
                        q[rear] = e;
                        visited[t1] = 1;
                        //  cout<<endl<<e->name<<"rear"<<rear;;
                    }
                    e = e->link;
                } while (e != NULL);
            }
        }
    }
    void dummy()
    {
        bfs(start);
    }
};
int main()
{
    Graph g1;
    g1.ScanGraph(4, 5);
    g1.DisplayGraph();
    g1.dummy();
    return 0;
}