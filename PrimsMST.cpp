#include <bits/stdc++.h>
#define I INT32_MAX
using namespace std;

int cost[][8] = {{I, I, I, I, I, I, I, I},
                 {I, I, 25, I, I, I, 5, I},
                 {I, 25, I, 12, I, I, I, 10},
                 {I, I, 12, I, 8, I, I, I},
                 {I, I, I, 8, I, 15, I, 14},
                 {I, I, I, I, 16, I, 20, 18},
                 {I, 5, I, I, I, 20, I, I},
                 {I, I, 10, I, 14, 18, I, I}}; // not using 0th row and 0th column

int near[8] = {I, I, I, I, I, I, I, I};
int t[2][7]; // generating minimum spanning tree

int main()
{
    int i, j, k, u, v, n = 7, min = I;

    // Finding minimum edge
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    // storing initial solution
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;

    // update the near array
    for (i = 1; i <= n; i++)
    {
        if (near[i] != 0)
        {
            if (near[i] != 0 && cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }

    // this is the repeating procedure for all other vertices and edges
    for (i = 1; i < n - 1; i++)
    {
        min = I;
        for (j = 1; j <= n; j++)
        {
            if (cost[j][near[j]] < min && near[j] != 0)
            {
                k = j;
                min = cost[j][near[j]];
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        for (j = 1; j <= n; j++)
        {
            if (cost[j][k] < cost[j][near[j]] && near[j] != 0)
                near[j] = k;
        }
    }

    // Printing the solution

    for (i = 0; i < n - 1; i++)
    {
        cout << "(" << t[0][i] << "," << t[1][i] << ")" << endl;
    }

    return 0;
}