# include <iostream>
# include <string>
# include <vector>

using namespace std;

int main() {

    string linha;
    vector<int> pesos;
    vector<bool> subPesos;
    int subPeso, subCadeiaAnterior, pesoMax = 0, qtdSubPesos = 0;
    size_t sup, tamanho;

    cin >> linha;
    tamanho = linha.size();
    pesos = vector<int>(tamanho);

    // Transforma todos os caracteres em pesos
    for (size_t i = 0; i < tamanho; ++i) {
        pesos[i] = linha[i] - 96;
        pesoMax += pesos[i];
    }

    // Instancia o vetor de booleanos que representa os pesos das substrings
    subPesos = vector<bool>(pesoMax + 1, false);

    // Pega os pesos de todas as substrings
    for (size_t i = 1; i <= tamanho; ++i) {
        // 'i' É o limite superior do intervalo
        for (size_t j = 0; j < tamanho - i + 1; ++j) {
            // 'j' É o índice pelo qual o intervalo será deslocado ao longo da sequência
            sup = i + j - 1;
            if (j == 0 && i == 1) { // Se estiver na primeira iteração do programa
                subPeso = pesos[0];
                subCadeiaAnterior = subPeso;
            } else if (j == 0) { // Se for a primeira iteração do intervalo de tamanho j
                subPeso = subCadeiaAnterior + pesos[sup];
                // Aproveita o peso da cadeia da primeira iteração do intervalo anterior
                // Adiciona somente o equivalente ao novo peso no intervalo
                subCadeiaAnterior = subPeso;
            } else {
                subPeso = (subPeso - pesos[j - 1]) + pesos[sup];
                // Subtrai o peso que ficou pra trás, adiciona o novo
            }
            if (!subPesos[subPeso]) {
                subPesos[subPeso] = true;
                ++qtdSubPesos;
            }
        }
    }

    cout << qtdSubPesos << endl;

    return 0;
}
