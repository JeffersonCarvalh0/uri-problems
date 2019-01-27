# include <iostream>    // Entrada e saída de dados
# include <cstring>     // memset

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); // Deixar a entrada e saída mais rápidas

    // variáveis
    int t, n, v, a, v1, v2;
    bool adj_mat[55][55];

    cin >> t; // Recebe a quatidade de casos de teste
    while (t--) { // Enquanto ainda houverem casos de teste
        int edges = 0; // Número de arestas
        memset(adj_mat, false, sizeof(adj_mat)); // Coloca falso pra todas as posições da matriz
        cin >> n >> v >> a; // Recebe o vértice inicial, número de vértices e número de arestas
        while (a--) { // Enquanto houverem vértices
            cin >> v1 >> v2; // Recebe os valores dos dois vértices que compõem a aresta
            if (!adj_mat[v1][v2]) { // Se a aresta NÃO existir
                adj_mat[v1][v2] = true; // Aresta que vai de v1 à v2 agora existe
                adj_mat[v2][v1] = true; // Aresta que vai de v2 à v1 agora existe
                ++edges; // Aumenta 1 na quantidade de arestas
            }
        }
        cout << edges * 2 << '\n'; // Exibe na tela a quantidade de arestas * 2
    }

    return 0;
}
