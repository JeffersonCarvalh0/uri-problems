# include <iostream>
# include <vector>

using namespace std;

inline int norm(int n) { return n == 0 ? 0 : abs(n) / n; }

class SegTree {
public:
    vector<int> tree;
    int n;

    SegTree(int *a, int n): n(n) {
        tree.resize(n << 1);

        for (int i = 0; i < n; ++i) tree[i + n] = norm(a[i]);
        for (int i = n - 1; i > 0; --i) tree[i] = tree[i<<1] * tree[i<<1|1];
    }

    int query(int l, int r) {
        int ans = 1;
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) ans *= tree[l++];
            if (!(r & 1)) ans *= tree[r--];
        }
        return ans;
    }

    void update(int p, int v) {
        for (tree[p += n] = norm(v); p > 1; p >>= 1) tree[p>>1] = tree[p] * tree[p^1];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, l, r;
    char q;
    int a[100005];

    while (cin >> n >> k) {
        for (int i = 0; i < n; ++i) cin >> a[i];

        SegTree tree(a, n);

        while (k--) {
            cin >> q >> l >> r;

            if (q == 'C') tree.update(--l, r);
            else {
                int ans = tree.query(--l, --r);
                if (ans == -1) cout << '-';
                if (ans == 0) cout << '0';
                if (ans == 1) cout << '+';
            }
        }
        cout << '\n';
    }

    return 0;
}
