# include <iostream>
# include <string>

using namespace std;

inline int abs(int a) { return a >= 0 ? a : a * (-1); }
inline int map(int a) { return a == 0 ? 0 : a / abs(a); }

class SegTree {
public:
    int *tree, n;

    SegTree(int *arr, int n) : n(n) {
        tree = new int[n * 2];
        for (int i = 0; i < n; ++i) tree[i + n] = map(arr[i]);
        for (int i = n - 1; i > 0; --i) tree[i] = tree[i<<1] * tree[i<<1|1];
    }

    char query(int l, int r) {
        int res = 1;
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) res *= tree[l++];
            if (!(r & 1)) res *= tree[r--];
        }
        if (res == -1) return '-';
        else if (res == 0) return '0';
        else return '+';
    }

    void modify(int p, int value) {
        for (tree[p += n] = map(value); p > 1; p >>= 1) tree[p>>1] = tree[p] * tree[p^1];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, K, X[int(1e5)], l, r;
    char op;
    string result;

    while (cin >> N >> K) {
        for (int i = 0; i < N; ++i) cin >> X[i];
        auto tree = SegTree(X, N);

        result = "";
        while (K--) {
            cin >> op >> l >> r;
            if (op == 'P') result += tree.query(--l, --r);
            if (op == 'C') tree.modify(--l, r);
        }
        cout << result << '\n';
    }
}
