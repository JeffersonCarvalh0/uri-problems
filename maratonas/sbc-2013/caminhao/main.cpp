// Not finished yet

# include <iostream>
# include <algorithm>
# include <stack>
# include <vector>
# include <list>

using namespace std;

class DSU {
public:
    vector<int> p, s;

    DSU(int n) {
        p.resize(n); s.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i, s[i] = 1;
    }

    int find(int v) { if (p[v] == v) return v; return p[v] = find(p[v]); }

    void merge(int v1, int v2) {
        int a = find(v1);
        int b = find(v2);
        if (a != b) {
            if (s[a] < s[b]) swap(a, b);
            p[b] = a, s[b] += s[a];
        }
    }
};

int logs[100005];

class SparseTable {
public:
    vector<vector<int>> st;
    vector<int> &a;

    SparseTable(vector<int> &a): a(a) {
        int n = a.size();
        st = vector<vector<int>>(n, vector<int>(logs[n] + 1));
        for (int i = 0; i < n; ++i) st[i][0] = i;
        for (int j = 1; j <= logs[n]; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                if (a[st[i][j - 1]] < a[st[i + (1 << (j - 1))][j - 1]])
                    st[i][j] = st[i][j - 1];
                else
                    st[i][j] = st[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    int query(int l, int r) {
        if (r < l) swap(l, r);
        int span = r - l + 1, j = logs[span];
        if (a[st[l][j]] < a[st[l + span - (1 << j)][j]])
            return st[l][j];
        else
            return st[l + span - (1 << j)][j];
    }
};

class LCA {
public:
    vector<int> euler, dists, first;
    vector<bool> visited;

    LCA(vector<list<pair<int, int>>> &adj_list) {
        first.resize(adj_list.size());
        visited.resize(adj_list.size(), false);
        dfs(0, 1e6, adj_list);

        for (auto &e : euler) cout << e << ' ';
        cout << '\n';
        for (auto &e : dists) cout << e << ' ';
        cout << '\n';
        for (auto &e : first) cout << e << ' ';
        cout << '\n';
    }

    void dfs(int v, int d, vector<list<pair<int, int>>> &adj_list) {
        visited[v] = true;
        first[v] = euler.size(); euler.push_back(v); dists.push_back(d);

        for (auto &adj : adj_list[v]) {
            if (!visited[adj.first])
                dfs(adj.first, adj.second, adj_list), euler.push_back(v), dists.push_back(d);
        }
    }

    int query(int v1, int v2, SparseTable st) {
        return dists[st.query(first[v1], first[v2])];
    }
};

struct Edge {
    int v1, v2, w;
    Edge(int v1 = 0, int v2 = 0, int w = 0): v1(v1), v2(v2), w(w) {}
    bool operator < (Edge &e) { return w < e.w; }
};

vector<Edge> kruskal(vector<Edge> &edges, int n) {
    vector<Edge> ans;
    DSU dsu(n);

    for (int i = edges.size() - 1; i >= 0; --i) {
        if (dsu.find(edges[i].v1) != dsu.find(edges[i].v2))
            ans.push_back(edges[i]), dsu.merge(edges[i].v1, edges[i].v2);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<Edge> edges;
    vector<list<pair<int, int>>> adj_list;
    int n, m, s, a, b, p;

    logs[1] = 0;
    for (int i = 2; i < 100005; ++i) logs[i] = logs[i/2] + 1;

    while (cin >> n >> m >> s) {
        edges.clear();
        adj_list.clear();

        while (m--) cin >> a >> b >> p, edges.push_back(Edge(--a, --b, p));
        sort(edges.begin(), edges.end());
        auto tree = kruskal(edges, n);

        adj_list.resize(n);
        for (auto &e : tree)
            adj_list[e.v1].push_back({ e.v2, e.w }), adj_list[e.v2].push_back({ e.v1, e.w });

        for (int i = 0; i < adj_list.size(); ++i)
            for (auto &e : adj_list[i])
                cout << i << ' ' <<  e.first << ' ' << e.second << '\n';

        LCA lca(adj_list);
        SparseTable st(lca.dists);

        while (s--) cin >> a >> b, cout << lca.query(--a, --b, st) << '\n';
    }

    return 0;
}
