# include <cstdio>
# include <vector>

using namespace std;

int main() {

    int N, M;
    vector<int> regioes, regioesDel;

    while (true) {
        scanf("%d", &N);

        if (N == 0)
            break;

        regioes = vector<int>(N);
        for (int i = 1; i <= N; ++i)
            regioes[i - 1] = i;

        M = 0;
        while (true) {
            regioesDel = regioes;
            for (int i = 0; regioesDel.size() > 1; i = (i + M) % regioesDel.size())
                regioesDel.erase(regioesDel.begin() + i);

            if (regioesDel.front() == 13)
                break;
            ++M;
        }
        printf("%d\n", M + 1);
    }

    return 0;
}
