#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void selectionSort(vector<int>& arr, long long& comparisons, long long& swaps) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
    }
}

// Função para embaralhar os elementos do vetor na mesma sequência sempre
void embaralhaVetor(vector<int>& arr, int seed) {
    for (int i = arr.size() - 1; i > 0; i--) {
        int j = (i + seed) % (i + 1); // Usa a semente para gerar um índice j
        swap(arr[i], arr[j]);
    }
}

int main() {
    const int SIZE = 100000;
    vector<int> arr(SIZE);

    // Preenche o vetor com valores em sequência crescente
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;  // Números de 1 até 100000 em ordem crescente
    }

    // Define a semente para o embaralhamento (pode ser qualquer número inteiro)
    int seed = 42; // Exemplo de semente

    // Embaralha os valores do vetor na mesma sequência sempre
    embaralhaVetor(arr, seed);

    long long comparisons = 0;
    long long swaps = 0;

    // Calcula o tempo de execução do Selection Sort
    auto start = chrono::high_resolution_clock::now();
    selectionSort(arr, comparisons, swaps);
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

