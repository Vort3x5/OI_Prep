#include <vector>
#include <iostream>

using namespace std;

const int N = 100010;

int n, q;
vector <int> T[N];

void DFS (int r, int p, int odl) {
    for (auto neighbour : T[r])
        if (neighbour != p)
            DFS(neighbour, r, odl + 1);
}

bool isAnc (int a, int b) {

}

int LCA (int a, int b) {

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

    DFS(1, 1, 0);


    return 0;
}