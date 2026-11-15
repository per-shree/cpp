
#include <iostream>
using namespace std;

class Graph
{
    int n;
    string city[10];
    int adj[10][10];
    int visited[10];

public:
    Graph()
    {
        cout << "Enter number of cities: ";
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cout << "Enter city " << i + 1 << ": ";
            cin >> city[i];
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                adj[i][j] = 0;
            }

            visited[i] = 0;
        }
    }

    void createGraph();
    void displayMatrix();
    void displayList();
    void DFS(int v);
    void checkConnected();
};

void Graph :: createGraph()
{
    int edges, u, v, cost;

    cout << "Enter number of flight paths: ";
    cin >> edges;

    for(int i = 0; i < edges; i++)
    {
        cout << "\nEnter source city index (0 to "
             << n - 1 << "): ";
        cin >> u;

        cout << "Enter destination city index: ";
        cin >> v;

        cout << "Enter flight cost/time: ";
        cin >> cost;

        if(u >= 0 && u < n && v >= 0 && v < n && cost > 0)
        {
            adj[u][v] = cost;
            adj[v][u] = cost;
        }
        else
        {
            cout << "Invalid input!" << endl;
            i--;
        }
    }
}

void Graph :: displayMatrix()
{
    cout << "\nAdjacency Matrix:\n\t";

    for(int i = 0; i < n; i++)
    {
        cout << city[i] << "\t";
    }

    cout << endl;

    for(int i = 0; i < n; i++)
    {
        cout << city[i] << "\t";

        for(int j = 0; j < n; j++)
        {
            cout << adj[i][j] << "\t";
        }

        cout << endl;
    }
}

void Graph :: displayList()
{
    cout << "\nAdjacency List:\n";

    for(int i = 0; i < n; i++)
    {
        cout << city[i] << " -> ";

        for(int j = 0; j < n; j++)
        {
            if(adj[i][j] != 0)
            {
                cout << city[j] << "(" << adj[i][j] << ") -> ";
            }
        }

        cout << "NULL" << endl;
    }
}

void Graph :: DFS(int v)
{
    visited[v] = 1;

    cout << city[v] << " ";

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i] != 0 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

void Graph :: checkConnected()
{
    int start;

    cout << "\nEnter starting city index (0 to "
         << n - 1 << "): ";
    cin >> start;

    if(start < 0 || start >= n)
    {
        cout << "Invalid starting city!" << endl;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    cout << "\nDFS Traversal: ";
    DFS(start);

    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 1)
            count++;
    }

    if(count == n)
        cout << "\nGraph is Connected." << endl;
    else
        cout << "\nGraph is Not Connected." << endl;
}

int main()
{
    Graph g;

    g.createGraph();
    g.displayMatrix();
    g.displayList();
    g.checkConnected();

    return 0;
}
