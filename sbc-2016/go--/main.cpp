# include <iostream>
# include <cstring>

using namespace std;

// 0 == empty
// 1 == black
// 2 == white

int board[505][505][2];

inline void update(int i1, int j1, int k1, int i2, int j2, int k2) {
    if (board[i1][j1][k1] != board[i2][j2][k2] && board[i2][j2][k2] != 0) {
        if (board[i1][j1][k1] == 0) board[i1][j1][k1] = board[i2][j2][k2];
        else board[i1][j1][k1] = 3;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie(0);
    int n, p, l, c, w, b;

    cin >> n >> p;
    memset(board, 0, sizeof(int) * n * n);

    for (int i = 0; i < p; ++i) cin >> l >> c, board[l - 1][c - 1][0] = 1;
    for (int i = 0; i < p; ++i) cin >> l >> c, board[l - 1][c - 1][0] = 2;

    w = b = p;

    for (int d = 2; d <= n; ++d) {
        for (int i = 0; i + d - 1 < n; ++i) {
            for (int j = 0; j + d - 1 < n; ++j) {
                board[i][j][1] = board[i][j][0];
                update(i, j, 1, i + 1, j, 0);
                update(i, j, 1, i, j + 1, 0);
                update(i, j, 1, i + 1, j + 1, 0);

                if (board[i][j][1] == 1) ++b;
                if (board[i][j][1] == 2) ++w;
            }
        }

        for (int i2 = 0; i2 < n; ++i2) for (int j2 = 0; j2 < n; ++j2) board[i2][j2][0] = board[i2][j2][1];
    }

    cout << b << ' ' << w << '\n';

    return 0;
}
