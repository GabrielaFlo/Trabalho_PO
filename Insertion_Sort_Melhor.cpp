#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void insertionSort(vector<int>& arr, long long& comparisons, long long& swaps) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move os elementos maiores que 'key' para uma posi��o � frente
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

int main() {
    const int SIZE = 100000;
    vector<int> arr(SIZE);

    // Preenche o vetor com valores em sequ�ncia crescente
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;  // N�meros de 1 at� 100000 em ordem crescente
    }

    long long comparisons = 0;
    long long swaps = 0;

    // Calcula o tempo de execu��o do Insertion Sort
    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr, comparisons, swaps);
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

