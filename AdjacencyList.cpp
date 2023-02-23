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
    struct edge *adj, *next;
};

class Graph
{
    struct Node *start;

public:
    struct Node *bptr, *ptr;
    Graph()
    {
        start = NULL;
    }
    void ScanGraph(int v, int e)
    {
        ptr = new Node;
    }
};
int main()
{

    return 0;
}