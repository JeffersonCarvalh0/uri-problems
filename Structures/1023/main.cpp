# include <cstdio>
# include <utility> // std::pair
# include <set>

/* Não entendi a questão direito, então a resposta não está correta. */

using namespace std;

struct comparar { // Functor para ser usado na comparação entre os pairs
    bool operator () (const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return (lhs.second < rhs.second) ? true : false;
    }
};

int main() {
    int N, pessoasCasa, consumoCasa, pessoasCidade, cidadeAtual;
    float consumoCidade;
    set<pair<int, int>, comparar> casas;

    cidadeAtual = 1;
    while (true) {
        scanf("%d", &N);
        if (N == 0)
            break;

        if (cidadeAtual == 1)
            printf("Cidade# %d:\n", cidadeAtual);
        else
            printf("\nCidade# %d:\n", cidadeAtual);


        consumoCidade = 0.00;
        pessoasCidade = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%d%d", &pessoasCasa, &consumoCasa);
            consumoCidade += consumoCasa;
            pessoasCidade += pessoasCasa;
            casas.insert(pair<int, int>(pessoasCasa, consumoCasa / pessoasCasa));
        }

        for (auto it = casas.begin(); it != casas.end(); ++it) {
            if (it == --casas.end())
                printf("%d-%d", it->first, it->second);
            else
                printf("%d-%d ", it->first, it->second);
        }

        consumoCidade /= pessoasCidade;
        printf("\nConsumo medio: %.2f m3.\n", consumoCidade);
        ++cidadeAtual;
        casas.clear();
    }
    return 0;
}
