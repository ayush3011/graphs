#include <bits/stdc++.h>
using namespace std;

void DFS(int G[][7], int start, int n)
{
    static int visited[7] = {0}; // static so that it is accessible in all the call
    int col;

    if (visited[start] == 0)
    {
        cout << start << " ";
        visited[start] = 1;
        for (col = 1; col <= n; col++)
        {
            if (G[start][col] == 1 && visited[col] == 0)
            {
                DFS(G, col, n);
            }
        }
    }
}

int main()
{
    int G[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    DFS(G, 4, 7);

    return 0;
}