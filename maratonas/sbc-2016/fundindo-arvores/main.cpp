# include <iostream>
# include <vector>

using namespace std;

struct Node {
    int l, c, r;
    Node(int l = 0, int c = 0, int r = 0): l(l), c(c), r(r) {};
};

inline int count(vector<Node> &t, vector<bool> &v, int idx) {
    int c = 1;
    while (t[idx].c) ++c, v[idx] = true, idx = t[idx].c;
    return c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, i, l, k, mrl = 0, ml = 0, mrr = 0, mr = 0;
    vector<Node> t1, t2;
    vector<bool> v1, v2;

    cin >> n;
    t1.resize(n + 1);
    v1.resize(n + 1, false);
    for (int j = 0; j < n; ++j) cin >> i >> l >> k, t1[i] = Node(l, k, 0);

    mrl = ml = count(t1, v1, 1);
    for (int j = 1; j <= n; ++j) if (!v1[j]) ml = max(ml, count(t1, v1, j));

    cin >> m;
    t2.resize(m + 1);
    v2.resize(m + 1, false);
    for (int j = 0; j < m; ++j) cin >> i >> l >> k, t2[i] = Node(0, l, k);

    mrr = mr = count(t2, v2, 1);
    for (int j = 1; j <= m; ++j) if (!v2[j]) mr = max(mr, count(t2, v2, j));

    cout << (n + m) - max(min(mrl, mr), min(mrr, ml)) << '\n';

    return 0;
}
