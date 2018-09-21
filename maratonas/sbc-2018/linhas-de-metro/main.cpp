# include <iostream>
# include <vector>
# include <set>

using namespace std;

class LCA {
public:
    vector<int> euler, heights, parents, first, logs;
    vector<bool> visited;
    vector<vector<int>> st;

    LCA(vector<set<int>> &adj_list) {
        int n = adj_list.size();

        parents.resize(n);
        first.resize(n);

        logs.resize((n << 1) + 1);
        logs[1] = 0;
        for (int i = 2; i <= n << 1; ++i) logs[i] = logs[i/2] + 1;

        visited.resize(n, false);
        n = (n << 1) - 1;
        euler.reserve(n);
        heights.reserve(n);
        dfs(0, 0, 1, adj_list);

        st = vector<vector<int>>(n, vector<int>(logs[n] + 1));
        buildSt(n);
    }

    void dfs(int v, int p, int h, vector<set<int>> &adj_list) {
        visited[v] = true; parents[v] = p; first[v] = euler.size();
        euler.push_back(v); heights.push_back(h);

        for (auto &adj : adj_list[v]) {
            if (!visited[adj])
                dfs(adj, v, h + 1, adj_list), euler.push_back(v), heights.push_back(h);
        }
    }

    void buildSt(int n) {
        for (int i = 0; i < n; ++i) st[i][0] = i;

        for (int j = 1; j <= logs[n]; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                if (heights[st[i][j - 1]] < heights[st[i + (1 << (j - 1))][j - 1]])
                    st[i][j] = st[i][j - 1];
                else
                    st[i][j] = st[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    int query(int v1, int v2) {
        int l = first[v1], r = first[v2];
        if (r < l) swap(l, r);
        int j = logs[r - l + 1];

        if (heights[st[l][j]] < heights[st[r - (1 << j) + 1][j]])
            return euler[st[l][j]];
        else
            return euler[st[r - (1 << j) + 1][j]];
    }

    int comparePaths(int a, int b, int c, int d) {
        int ans = 0, lca_ab = query(a, b), lca_cd = query(c, d);

        int p = a;
        set<int> path;
        while (p != lca_ab) path.insert(p), p = parents[p];

        p = b;
        while (p != lca_ab) path.insert(p), p = parents[p];
        path.insert(lca_ab);

        p = c;
        while (p != lca_cd) {
            if (path.find(p) != path.end()) ++ans;
            p = parents[p];
        }

        p = d;
        while (p != lca_cd) {
            if (path.find(p) != path.end()) ++ans;
            p = parents[p];
        }

        if (path.find(lca_cd) != path.end()) ++ans;

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q, u, v, a, b, c, d;
    vector<set<int>> adj_list;
    adj_list.reserve(100005);

    cin >> n >> q;
    adj_list.resize(n);

    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v; --u; --v;
        adj_list[u].insert(v); adj_list[v].insert(u);
    }

    LCA lca(adj_list);

    for (int i = 0; i < q; ++i) {
        cin >> a >> b >> c >> d; --a; --b; --c; --d;
        cout << lca.comparePaths(a, b, c, d) << '\n';
    }

    return 0;
}
