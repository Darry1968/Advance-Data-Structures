#include <iostream>
#include <limits.h>
using namespace std;

#define V 3
class Shortest_path
{
    int adjmat[10][10];

public:
    int minDistance(int dist[], bool sptSet[])
    {
        int min = INT_MAX, min_index;

        for (int v = 0; v < V; v++)
        {
            if (sptSet[v] == false && dist[v] <= min)
            {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    void initgraph(int v)
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

    void scangraph(int v, int e)
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
    void display(int v)
    {
        int i, j;
        for (i = 0; i < V; i++)
        {
            cout << endl;
            for (j = 0; j < V; j++)
            {
                cout << adjmat[i][j] << " ";
            }
        }
        cout << endl;
    }

    void Dijkstra(int src)
    {
        int dist[V];
        bool sptSet[V];
        int parent[V];

        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
            dist[i] = INT_MAX;
            sptSet[i] = false;
        }
        dist[src] = 0;

        for (int count = 0; count < V - 1; count++)
        {
            int u = minDistance(dist, sptSet);
            sptSet[u] = true;
            for (int v = 0; v < V; v++)
                if (!sptSet[v] && adjmat[u][v] && dist[u] != INT_MAX && dist[u] + adjmat[u][v] < dist[v])
                {
                    parent[v] = u;
                    dist[v] = dist[u] + adjmat[u][v];
                }
        }
        printSolution(dist, V, parent);
    }

    void printPath(int parent[], int j)
    {
        if (parent[j] == -1)
            return;
        printPath(parent, parent[j]);
        cout << "->" << j;
    }

    void printSolution(int dist[], int n, int parent[])
    {
        int src = 0;
        printf("Vertex\t Distance \t Path");
        for (int i = 1; i < n; i++)
        {
            printf("\n%d -> %d \t %d \t\t%d", src, i, dist[i], src);
            printPath(parent, i);
        }
    }
};
int main()
{
    Shortest_path s1;
    s1.initgraph(V);
    s1.scangraph(V, 2);
    s1.display(V);
    s1.Dijkstra(0);
    return 0;
}

/*
1
enter source: 1
enter destination: 2
enter weight: 2
2
enter source: 2
enter destination: 3
enter weight: 3

0 2 0
2 0 3
0 3 0
Vertex           Distance                Path
0 ->1           2               00
0 ->2           5               001
*/
