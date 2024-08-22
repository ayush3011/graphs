#include <iostream>
#define I INT32_MAX
using namespace std;

int edges[3][9] = { // Set of edges 9 columns because 9 edges
    {1, 1, 2, 2, 3, 4, 4, 5, 5},
    {2, 6, 3, 7, 4, 5, 7, 6, 7},
    {25, 5, 12, 10, 8, 16, 14, 20, 18}};

// Using disjoint subsets to detect cycle
int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
// To mark included edges
int included[9] = {0};
// Storing the solution, i.e. spanning tree
int t[2][6];

void MyUnion(int u, int v)
{
    // set operation to do the weighted union
    if (set[u] < set[v])
    {
        set[u] += set[v];
        set[v] = u;
    }
    else
    {
        set[v] += set[u];
        set[u] = v;
    }
}

int find(int u)
{
    int x = u, v = 0;
    while (set[x] > 0)
    {
        x = set[x];
    }
    // Once you find the parent of any vertex you can directly connect to it
    // This is collapsing find
    while (u != x)
    {
        v = set[u];
        set[u] = x;
        u = v;
    }
    return x;
}

int main()
{
    int i = 0, j, k, u, v, min = I, n = 7, e = 9;
    while (i < n - 1)
    {
        min = I;
        // finding the minimum edge
        for (j = 0; j < e; j++)
        {
            if (edges[2][j] < min && included[j] == 0)
            {
                min = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                k = j;
            }
        }

        // Building the spanning tree
        if (find(u) != find(v))
        {
            t[0][i] = u;
            t[1][i] = v;
            MyUnion(find(u), find(v));
            i++;
        }

        // marking the selected edge as included
        included[k] = 1;
    }

    for (i = 0; i < n - 1; i++)
    {
        cout << "(" << t[0][i] << "," << t[1][i] << ")" << endl;
    }
    return 0;
}