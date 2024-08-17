#include <bits/stdc++.h>
#include "Queue.h"
using namespace std;

void BFS(int G[][7], int start, int n)
{
    int row = start, col;
    int visited[7] = {0};

    cout << row << " ";
    visited[row] = 1;
    enqueue(row);

    while (!isEmpty())
    { // exploring the vertex of the rowth row
        row = dequeue();
        for (col = 1; col < n; col++)
        {
            if (G[row][col] == 1 && visited[col] == 0)
            {
                cout << col << " ";
                visited[col] = 1;
                enqueue(col);
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

    BFS(G, 1, 7);

    return 0;
}