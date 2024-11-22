#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> // Para std::shuffle
#include <random>    // Para std::default_random_engine

using namespace std;

// Fun��o para mesclar dois subvetores ordenados
void merge(vector<int>& arr, int left, int mid, int right, long long& comparisons, long long& swaps) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1), rightArr(n2);

    // Copia os dados para os subvetores tempor�rios
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    // Mescla os subvetores tempor�rios de volta ao vetor original
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++; // Incrementa o contador de compara��es
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            swaps++; // Contabiliza a movimenta��o
            i++;
        } else {
            arr[k] = rightArr[j];
            swaps++; // Contabiliza a movimenta��o
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de leftArr, se houver
    while (i < n1) {
        arr[k] = leftArr[i];
        swaps++; // Contabiliza a movimenta��o
        i++;
        k++;
    }

    // Copia os elementos restantes de rightArr, se houver
    while (j < n2) {
        arr[k] = rightArr[j];
        swaps++; // Contabiliza a movimenta��o
        j++;
        k++;
    }
}

// Fun��o recursiva do Merge Sort
void mergeSort(vector<int>& arr, int left, int right, long long& comparisons, long long& swaps) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Calcula o meio do vetor

        // Ordena as duas metades
        mergeSort(arr, left, mid, comparisons, swaps);
        mergeSort(arr, mid + 1, right, comparisons, swaps);

        // Mescla as duas metades ordenadas
        merge(arr, left, mid, right, comparisons, swaps);
    }
}

int main() {
    const int SIZE = 100000; // Tamanho do vetor
    vector<int> arr(SIZE);

    // Preenche o vetor com valores em sequ�ncia crescente
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1; // N�meros de 1 at� SIZE
    }

    // Define a semente para o embaralhamento (consist�ncia)
    int seed = 42; // Exemplo de semente
    shuffle(arr.begin(), arr.end(), default_random_engine(seed)); // Embaralha o vetor

    long long comparisons = 0; // Contador de compara��es
    long long swaps = 0;       // Contador de movimenta��es

    // Calcula o tempo de execu��o do Merge Sort
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, SIZE - 1, comparisons, swaps);
    auto end = chrono::high_resolution_clock::now();

    // Calcula a dura��o em milissegundos
    chrono::duration<double, milli> duration = end - start;

    // Exibe os resultados
    cout << "Tempo de execu��o: " << duration.count() << " ms" << endl;
    cout << "Quantidade de compara��es: " << comparisons << endl;
    cout << "Quantidade de movimenta��es: " << swaps << endl;

    return 0;
}
