#include<iostream>
#include<vector>
using namespace std;

int tt[100001];
bool visited[100001];
vector<int> arr[100001];
int N, R, Q;

void DFS(int node, int parent)
{
    visited[node] = true;
    for (int i = 0; i < arr[node].size(); i++)
    {
        int next = arr[node][i];
        if (visited[next])
            continue;
        DFS(next, node);
    }
    if (parent != -1)
    {
        tt[parent] += tt[node];
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    fill_n(tt, 100001, 1);
    cin >> N >> R >> Q;
    
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    DFS(R, -1);

    for (int i = 0; i < Q; i++)
    {
        int x;
        cin >> x;
        cout << tt[x] << "\n";
    }

    return 0;
}
