# include <iostream>

using namespace std;

int h, l, m[205][205];
bool visited[205][205];

int dfs(int i, int j) {
    int size = 1;
    if (!visited[i][j]) {
        visited[i][j] = true;
        if (i > 0 && !visited[i - 1][j] && m[i - 1][j] == m[i][j]) size += dfs(i - 1, j);
        if (i < h - 1 && !visited[i + 1][j] && m[i + 1][j] == m[i][j]) size += dfs(i + 1, j);
        if (j > 0 && !visited[i][j - 1] && m[i][j - 1] == m[i][j]) size += dfs(i, j - 1);
        if (j < l - 1 && !visited[i] [j + 1] && m[i][j + 1] == m[i][j]) size += dfs(i, j + 1);
    }
    return size;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int min_value = 40005;

    cin >> h >> l;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < l; ++j) {
            cin >> m[i][j];
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < l; ++j) {
            if (!visited[i][j]) min_value = min(min_value, dfs(i, j));
        }
    }

    cout << min_value << '\n';

    return 0;
}
