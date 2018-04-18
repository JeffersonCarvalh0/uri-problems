# include <cstdio>
# include <set>
# include <vector>
# include <list>

// Não funciona

using namespace std;

int L, K, fileiras, fileirasMax;
set<int> X;
vector<int> Xvec;

inline int somaTabuas(int i, int altura) {
    int tamParcial, tamParcialAtual;
    list<vector<int>::iterator> selecionados;
    bool fechou = false;

    while (true) {
        tamParcial = Xvec[i];
        tamParcialAtual = tamParcial;
        for (auto it = Xvec.begin() + i + 1; it < Xvec.end(); ++it) {
            tamParcialAtual += *it;
            if (tamParcialAtual == altura) {
                tamParcial = tamParcialAtual;
                selecionados.push_back(it);
                fechou = true;
                break;
            } else if (tamParcialAtual > altura)
                tamParcialAtual = tamParcial;
            else {
                tamParcial = tamParcialAtual;
                selecionados.push_back(it);
            }
        }

        if (fechou) {
            for (auto &e : selecionados)
                Xvec.erase(e);
            return selecionados.size();
        } else
            return 0;
    }
}

inline int verifica(int largura, int altura) {
    int tabuas = 0, tabuas2;
    fileiras = 0;

    if ((largura * 100) % L != 0)
        return 0;
    else
        fileirasMax = largura / (L/100.0);

    for (int i = 0; i < K; ++i) {
        if (fileiras == fileirasMax)
            break;

        if (Xvec[i] <= altura) {
            if (Xvec[i] == altura) {
                ++tabuas;
                ++fileiras;
                Xvec.erase(Xvec.begin() + i);
            } else {
                tabuas2 = somaTabuas(i, altura);
                if (tabuas2 > 0)
                    --i;
                tabuas += tabuas2;
            }
        }
    }
    return tabuas;
}

int main() {

    int N, M, Xi, fileirasN, fileirasM, tabuasN, tabuasM, fileirasMaxN, fileirasMaxM;

    while (true) {
        scanf("%d%d", &N, &M);
        if (N == 0 && M == 0)
            break;

        scanf("%d%d", &L, &K);
        X.clear();
        for(int i = 0; i < K; ++i) {
            scanf("%d", &Xi);
            X.insert(Xi);
        }

        Xvec = vector<int>(X.rbegin(), X.rend());

        tabuasN = verifica(N, M);
        fileirasN = fileiras;
        fileirasMaxN = fileirasMax;
        printf("tabuasN: %d\n", tabuasN);

        tabuasM = verifica(M, N);
        fileirasM = fileiras;
        fileirasMaxM = fileirasMax;
        printf("tabuasM: %d\n", tabuasM);

        if (fileirasN == fileirasMaxN && fileirasM == fileirasMaxM)
            (tabuasN < tabuasM) ? printf("%d\n", tabuasN) : printf("%d\n", tabuasM);
        else if (fileirasN == fileirasMaxN)
            printf("%d\n", tabuasN);
        else if (fileirasM == fileirasMaxM)
            printf("%d\n", tabuasM);
        else
            printf("impossivel\n");
    }

    return 0;
}
