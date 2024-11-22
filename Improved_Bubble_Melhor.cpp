#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void improvedBubbleSort(vector<int>& arr, long long& comparisons, long long& swaps) {
    int n = arr.size();
    int newN;  // Vari�vel para rastrear a �ltima posi��o de troca

    do {
        newN = 0;  // Define como 0 no in�cio de cada passagem
        for (int i = 1; i < n; i++) {
            comparisons++;
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                swaps++;
                newN = i;  // Atualiza para o �ndice da �ltima troca
            }
        }
        n = newN;  // Reduz o alcance do pr�ximo loop
    } while (newN > 0);  // Continua enquanto houver trocas
}

int main() {
    const int SIZE = 100000;
    vector<int> arr(SIZE);

    // Preenche o vetor com valores em sequ�ncia crescente
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;  // N�meros de 1 at� 1000 em ordem crescente
    }

    long long comparisons = 0;
    long long swaps = 0;

    // Calcula o tempo de execu��o do Improved Bubble Sort
    auto start = chrono::high_resolution_clock::now();
    improvedBubbleSort(arr, comparisons, swaps);
    auto end = chrono::high_resolution_clock::now();

    // Calcula a dura��o em milissegundos
    chrono::duration<double, milli> duration = end - start;

    // Exibe os resultados
    cout << "Tempo de execu��o: " << duration.count() << " ms" << endl;
    cout << "Quantidade de compara��es: " << comparisons << endl;
    cout << "Quantidade de trocas: " << swaps << endl;

    // Exibe alguns elementos do vetor para confirma��o
    cout << "Vetor de 1000 elementos (primeiros 10): ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n�ltimos 10 elementos: ";
    for (int i = SIZE - 10; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

