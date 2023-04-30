#include <iostream>
using namespace std;

struct node
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
    struct node state[10];
    struct edge tree[10];
    int wt;

public:
    graph()
    {
        wt = 0;
    }
    void initgraph(int v);
    void scangraph(int v, int e);
    void display(int v, int e);
    int allperm(int v);
    void span(int v, int e);
};

int graph::allperm(int v)
{
    int i;
    for (i = 0; i < v; i++)
    {
        if (state[i].stat == 0)
        {
            return 0;
        }
    }
    return 1;
}

void graph::initgraph(int v)
{
    int i, j;
    for (i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            adjmat[i][j] = 0;
        }
    }
}

void graph::scangraph(int v, int e)
{
    int i, s, d, w;
    for (i = 0; i < e; i++)
    {
    l1:
        cout << i + 1 << endl;
        cout << "enter source: ";
        cin >> s;
        cout << "enter destination: ";
        cin >> d;
        cout << "enter weight: ";
        cin >> w;
        if ((s >= 1 && s <= v) && (d >= 1 && d <= v))
        {
            if (adjmat[s - 1][d - 1] == 0 && adjmat[d - 1][s - 1] == 0)
            {
                adjmat[s - 1][d - 1] = w;
                adjmat[d - 1][s - 1] = w;
            }
            else
            {
                cout << "edge already exist";
                goto l1;
            }
        }
        else
        {
            cout << "enter correct values:";
            goto l1;
        }
    }
}

void graph::display(int v, int e)
{
    int i, j;
    for (i = 0; i < v; i++)
    {
        cout << endl;
        for (j = 0; j < v; j++)
        {
            cout << adjmat[i][j] << " ";
        }
    }
}

void graph::span(int v, int e)
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
                state[current].stat = 1;
                u1 = state[current].pred;
                v1 = current;
                tree[count].u = u1;
                tree[count].v = v1;
                count++;
                wt = wt + state[i].dist;
            }
        }
    }
    cout << "Total cost : " << wt;
}

int main()
{
    graph g;
    g.allperm(3);
    g.initgraph(3);
    g.scangraph(3, 3);
    g.display(3, 3);
    g.span(3, 3);
}

/*
    Input and output-
    1
    enter source: 1
    enter destination: 3
    enter weight: 5
    2
    enter source: 1
    enter destination: 2
    enter weight: 6
    3
    enter source: 2
    enter destination: 3
    enter weight: 7

    0 6 5
    6 0 7
    5 7 0 Total cost : 11
*/