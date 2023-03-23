#include <iostream>
using namespace std;

struct Node
{
    int pred;
    int dist;
    int stat;
};

struct edge
{
    int u, v;
};

class graph
{
    int adjmat[10][10];
    struct Node state[10];
    struct edge tree[10];
    int wt;

public:
    graph()
    {
        wt = 0;
    }
    void intiGraph(int v, int e)
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                adjmat[i][j] = 0;
            }
            state[i].pred = 0;
            state[i].dist = 999;
            state[i].stat = 0;
        }
    }

    int allperm(int v)
    {
        for (int i = 1; i <= v; i++)
        {
            if (state[i].stat == 0)
            {
                return 0;
            }
            return 1;
        }
    }

    void span(int v, int e)
    {
        int current, count, min, u1, v1;
        for (int i = 0; i < v; i++)
        {
            state[i].pred = 0;
            state[i].dist = 999;
            state[i].stat = 0;
        }
        state[0].pred = 0;
        state[0].dist = 0;
        state[0].stat = 1;
        current = 0;
        count = 0;
        while (allperm(v) != 1)
        {
            for (int i = 0; i < v; i++)
            {
                if (adjmat[current][i] > 0 && state[i].stat == 0)
                {
                    if (adjmat[current][i] < state[i].dist)
                    {
                        state[i].pred = current;
                        state[i].dist = adjmat[current][i];
                    }
                }
            }
            min = 999;
            for (int i = 0; i < v; i++)
            {
                if (state[i].stat == 0 && state[i].dist < min)
                {
                    current = i;
                    u1 = state[current].pred;
                    v1 = current;
                    state[current].stat = 1;
                    tree[count].u = u1;
                    tree[count].v = v1;
                    count++;
                    wt = wt + state[i].dist;
                }
            }
        }
        cout << "Total cost : " << wt;
    }

    void Display(int v, int e)
    {
        int i, j;
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                cout << adjmat[i][j] << "\t";
            }
            cout << "\n";
        }
    }

    void scangraph(int v, int e)
    {
        int s, i, d, cost;
        for (int i = 1; i <= e; i++)
        {
        l1:
            cout << "Enter source : ";
            cin >> s;
            cout << "Enter destination : ";
            cin >> d;
            cout << "Enter weight : ";
            cin >> cost;

            if ((s >= 1 && s <= v) && (d >= 1 && d <= v))
            {
                if (adjmat[s][d] == 0 && adjmat[d][s] == 0)
                {
                    adjmat[s][d] = cost;
                    adjmat[d][s] = cost;
                }
                else
                {
                    cout << "Edge is already exists" << endl;
                    goto l1;
                }
            }
            else
            {
                cout << "Enter correct vertex !!" << endl;
                goto l1;
            }
        }
    }
};
int main()
{
    graph g1;
    g1.intiGraph(3, 3);
    g1.scangraph(3, 3);
    g1.Display(3, 3);
    g1.span(3, 3);

    return 0;
}
