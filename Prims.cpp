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
    graph()
    {
        wt = 0;
    }
    void intiGraph(int v, int e)
    {
        for (int i = 1; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                adjmat[i][j] = 0;
            }
        }
    }

    int allsperms(int v)
    {
        for (int i = 0; i < v; i++)
        {
            if (state[i].stat == 0)
            {
                return 1;
            }
            return 0;
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

            state[0].pred = 0;
            state[i].dist = 0;
            state[i].stat = 1;

            current = 0;
            count = 0;

            while (allsperms(v) != 1)
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
            }
        }
    }

    void Display(int v, int e)
    {
        int i, j;
        for (int i = 1; i < v; i++)
        {
            for (int j = 1; j < v; j++)
            {
                cout << adjmat[i][j] << "\t";
            }
            cout << "\n";
        }
    }

    void scangraph(int v, int e)
    {
    }
};
int main()
{

    return 0;
}
