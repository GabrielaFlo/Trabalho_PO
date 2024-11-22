#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Função para manter a propriedade do heap (heapify)
void heapify(vector<int>& arr, int n, int i, long long& comparisons, long long& swaps) {
    int largest = i;   // Inicializa o maior como raiz
    int left = 2 * i + 1; // Filho à esquerda
    int right = 2 * i + 2; // Filho à direita

    // Verifica se o filho à esquerda é maior que a raiz
    if (left < n && arr[left] > arr[largest]) {
        comparisons++;
        largest = left;
    }

    // Verifica se o filho à direita é maior que a raiz ou o filho à esquerda
    if (right < n && arr[right] > arr[largest]) {
        comparisons++;
        largest = right;
    }

    // Se o maior não for a raiz
    if (largest != i) {
        swap(arr[i], arr[largest]);
        swaps++;

        // Recursivamente heapify a subárvore afetada
        heapify(arr, n, largest, comparisons, swaps);
    }
}

// Função para ordenar o vetor usando o Heap Sort
void heapSort(vector<int>& arr, long long& comparisons, long long& swaps) {
    int n = arr.size();

    // Construa o heap (rearranja o vetor)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons, swaps);
    }

    // Um por um, extrai elementos do heap
    for (int i = n - 1; i >= 1; i--) {
        // Move a raiz atual para o final
        swap(arr[0], arr[i]);
        swaps++;

        // Chama heapify no vetor reduzido
        heapify(arr, i, 0, comparisons, swaps);
    }
}

int main() {
    const int SIZE = 100000;
    vector<int> arr(SIZE);

    // Preenche o vetor com valores em sequência crescente
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;  // Números de 1 até 100000 em ordem crescente
    }

    long long comparisons = 0;
    long long swaps = 0;

    // Calcula o tempo de execução do Heap Sort
    auto start = chrono::high_resolution_clock::now();
    heapSort(arr, comparisons, swaps);
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

