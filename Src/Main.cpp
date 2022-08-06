#include <bits/stdc++.h>

#define pb push_back
#define pf push_front
#define npc node_pool_count

using namespace std;

typedef long long ll;
typedef pair <int, int> p_i;
typedef vector <int> v_i;

struct Node
{
    bool end;
    Node *child[60];
};

int t, n, node_pool_count;

vector <string> arr;
Node node_pool[100000];

inline Node *AllocNode() { return &node_pool[npc++]; }

Node *root = AllocNode();

void Insert(Node *node, const string &text)
{
    for (int i = 0; i < text.size(); node = (node -> child[text[i]]), ++i)
        if (!(node -> child[text[i]]))
            node -> child[text[i]] = AllocNode();
    node -> end = true;
}

void Init()
{
    cin >> n;
    arr.clear();
    arr.resize(n);
    for (auto &it : arr)
    {
        cin >> it;
        Insert(root, it);
    }
}

void DumpDot(FILE *f, Node *node)
{
    size_t index = node - node_pool;
    for (size_t i = '0'; i <= '9'; ++i) 
    {
        if (node -> child[i]) 
        {
            size_t child_index = node->child[i] - node_pool;
            fprintf(f, "    Node_%zu [label=\"%c\"]\n", child_index, (char) i);
            fprintf(f, "    Node_%zu -> Node_%zu [label=\"%c\"]\n", index, child_index, (char) i);
            DumpDot(f, node -> child[i]);
        }
    }
}

void Dbg()
{
        FILE *out = fopen("Trie.dot", "w");
        
        fprintf(out, "digraph Trie {\n");
        fprintf(out, "    Node_%zu [label=root]\n", root - node_pool);
        DumpDot(out, root);
        fprintf(out, "}\n");
        
        fclose(out);
}

bool IsConsist(Node *node = root)
{
    for (int i = '0'; i <= '9'; ++i)
    {
        if (node -> child[i])
        {
            if (node -> end)
                return false;
            else
                return IsConsist(node -> child[i]);
        }
    }
    return true;
}

void Solve()
{
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        Init();
        cout << (IsConsist() ? "YES" : "NO") << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();

    return 0;
}
