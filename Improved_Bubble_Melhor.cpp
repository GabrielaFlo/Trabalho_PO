#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void improvedBubbleSort(vector<int>& arr, long long& comparisons, long long& swaps) {
    int n = arr.size();
    int newN;  // Variável para rastrear a última posição de troca

    do {
        newN = 0;  // Define como 0 no início de cada passagem
        for (int i = 1; i < n; i++) {
            comparisons++;
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                swaps++;
                newN = i;  // Atualiza para o índice da última troca
            }
        }
        n = newN;  // Reduz o alcance do próximo loop
    } while (newN > 0);  // Continua enquanto houver trocas
}

int main() {
    const int SIZE = 100000;
    vector<int> arr(SIZE);

    // Preenche o vetor com valores em sequência crescente
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;  // Números de 1 até 1000 em ordem crescente
    }

    long long comparisons = 0;
    long long swaps = 0;

    // Calcula o tempo de execução do Improved Bubble Sort
    auto start = chrono::high_resolution_clock::now();
    improvedBubbleSort(arr, comparisons, swaps);
    auto end = chrono::high_resolution_clock::now();

    // Calcula a duração em milissegundos
    chrono::duration<double, milli> duration = end - start;

    // Exibe os resultados
    cout << "Tempo de execução: " << duration.count() << " ms" << endl;
    cout << "Quantidade de comparações: " << comparisons << endl;
    cout << "Quantidade de trocas: " << swaps << endl;

    // Exibe alguns elementos do vetor para confirmação
    cout << "Vetor de 1000 elementos (primeiros 10): ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nÚltimos 10 elementos: ";
    for (int i = SIZE - 10; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

