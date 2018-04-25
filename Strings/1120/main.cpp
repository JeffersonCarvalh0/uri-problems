# include <iostream>
# include <string>
# include <algorithm>

using namespace std;

int main() {

    int D, N;
    char C;
    string S;

    while(cin >> D >> N) {
        if (D == 0 && N == 0)
            break;

        C = D + '0';
        S = to_string(N);

        remove(S.begin(), S.end(), C);
        N = stoi(S);
        cout << N << '\n';
    }

    return 0;
}
