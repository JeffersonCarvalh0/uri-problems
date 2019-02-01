# include <iostream>
# include <iomanip>
# include <algorithm>
# include <cmath>
# include <vector>

using namespace std;

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n); size.resize(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

struct Edge {
    int v1, v2;
    double dist;

    Edge(int v1 = 0, int v2 = 0, double dist = 0): v1(v1), v2(v2), dist(dist) {}
    bool operator < (const Edge &rhs) { return dist < rhs.dist; }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout << std::fixed;
    int c, n, x, y;
    double total;
    vector<pair<int, int>> coords(505);
    vector<Edge> edges;

    cin >> c;
    while (c--) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> x >> y, coords[i] = { x, y };

        edges.clear();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double dist = hypot(coords[i].first - coords[j].first, coords[i].second - coords[j].second);
                edges.push_back(Edge(i, j, dist));
            }
        }

        sort(edges.begin(), edges.end());
        DSU dsu(n);

        total = 0;
        for (auto &e : edges) {
            if (dsu.find_set(e.v1) != dsu.find_set(e.v2))
                total += e.dist, dsu.union_sets(e.v1, e.v2);
        }

        cout << setprecision(2) << total / 100.0 << '\n';
    }

    return 0;
}
