// Not finished yet

# include <iostream>

using namespace std;

int play(int *a, int i, int j, int sum) {
    if (i == j - 1) return sum + max(a[i], a[j]);

    if (a[i + 1] > a[j]) {
        if (a[j - 1] > a[i])
            return max(play(a, i + 2, j, sum + a[i]), play(a, i, j - 2, sum + a[j]));
        else
            return max(play(a, i + 2, j, sum + a[i]), play(a, i + 1, j - 1, sum + a[j]));
    } else {
        if (a[j - 1] > a[i])
            return max(play(a, i + 1, j - 1, sum + a[i]), play(a, ))
    }

    return max(play(a, i + 2, j, sum + a[i]),
            max(play(a, i + 1, j - 1, sum + a[i]),
            max(play(a, i, j - 2, sum + a[j]), play(a, i + 1, j - 1, sum + a[j]))));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a[10005];

    while (cin >> n) {
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << play(a, 0, n - 1, 0) << '\n';
    }

    return 0;
}
