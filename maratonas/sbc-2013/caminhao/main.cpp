// TLE

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

int dfs(vector<list<pair<int, int>>> &adj_list, int a, int b) {
    stack<pair<int, int>> s;
    vector<bool> visited(adj_list.size(), false);
    vector<pair<int, int>> parents(adj_list.size());
    int min_weight = 1e6;

    for (int i = 0; i < parents.size(); ++i) parents[i] = { i, 1e6 };
    s.push({ a, 1e6 });

    while (!s.empty()) {
        auto cur = s.top(); s.pop();
        visited[cur.first] = true;
        if (cur.first == b) break;

        for (auto &e : adj_list[cur.first])
            if (!visited[e.first])
                s.push(e), parents[e.first] = { cur.first, e.second };
    }

    int v = b;
    while (parents[v].first != v) {
        int w = parents[v].second;
        v = parents[v].first;
        min_weight = min(min_weight, w);
    }

    return min_weight;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<Edge> edges;
    vector<list<pair<int, int>>> adj_list;
    int n, m, s, a, b, p;

    while (cin >> n >> m >> s) {
        edges.clear();
        adj_list.clear();

        while (m--) cin >> a >> b >> p, edges.push_back(Edge(--a, --b, p));
        sort(edges.begin(), edges.end());
        auto tree = kruskal(edges, n);

        adj_list.resize(n);
        for (auto &e : tree)
            adj_list[e.v1].push_back({ e.v2, e.w }), adj_list[e.v2].push_back({ e.v1, e.w });

        while (s--) cin >> a >> b, cout << dfs(adj_list, --a, --b) << '\n';
    }

    return 0;
}
