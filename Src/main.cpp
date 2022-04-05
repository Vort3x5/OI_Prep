#include <vector>
#include <iostream>

using namespace std;

const int N = 100010;

int n, q;
vector <int> T[N];
vector <int> depth;
vector <pair <int, int>> io; 
vector <int> l;
vector <int> pos;

void DFS (int r, int p, int odl, int &t) 
{
    l.push_back(r);
    pos[r] = l.size() - 1;
    ++t;
    io[r].first = t;
    depth[r] = odl;
    for (auto neighbour : T[r])
    {
        if (neighbour != p)
        {
            DFS(neighbour, r, odl + 1, t);
            l.push_back(r);
        }
    }
    ++t;
    io[r].second = t;
}

bool isAnc (int a, int b) 
{
    return (io[a].first <= io[b].first && io[a].second <= io[b].second);
}

int LCA (int a, int b) 
{
    if (isAnc(a, b))
        return a;
    if (isAnc(b, a))
        return b;
}

int main()
{
    cin >> n >> q;

    for (int i = 1; i < n; i++) {

        int a, b;
        cin >> a >> b;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    int k;

    DFS(1, 1, 0, k);


    return 0;
}
