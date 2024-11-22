#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Fun��o para mesclar dois subvetores em ordem crescente
void merge(vector<int>& arr, int left, int mid, int right, long long& comparisons, long long& assignments) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1), rightArr(n2);

    // Copia os dados para os subvetores tempor�rios
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
        assignments++;
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
        assignments++;
    }

    // Mescla os subvetores tempor�rios de volta ao vetor original
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++;
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        assignments++;
        k++;
    }

    // Copia os elementos restantes de leftArr, se houver
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
        assignments++;
    }

    // Copia os elementos restantes de rightArr, se houver
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
        assignments++;
    }
}

// Fun��o recursiva do Merge Sort
void mergeSort(vector<int>& arr, int left, int right, long long& comparisons, long long& assignments) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Calcula o meio do vetor

        // Ordena as duas metades
        mergeSort(arr, left, mid, comparisons, assignments);
        mergeSort(arr, mid + 1, right, comparisons, assignments);

        // Mescla as duas metades ordenadas
        merge(arr, left, mid, right, comparisons, assignments);
    }
}

int main() {
    const int SIZE = 10000;
    vector<int> arr(SIZE);

    // Preenche o vetor com valores em sequ�ncia crescente
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;  // N�meros de 1 at� 100000 em ordem crescente
    }

    long long comparisons = 0;
    long long assignments = 0;

    // Calcula o tempo de execu��o do Merge Sort
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, SIZE - 1, comparisons, assignments);
    auto end = chrono::high_resolution_clock::now();

    // Calcula a dura��o em milissegundos
    chrono::duration<double, milli> duration = end - start;

    // Exibe os resultados
    cout << "Tempo de execu��o: " << duration.count() << " ms" << endl;
    cout << "Quantidade de compara��es: " << comparisons << endl;
    cout << "Quantidade de atribui��es: " << assignments << endl;

    // Exibe alguns elementos do vetor para confirma��o
    cout << "Vetor de 100000 elementos (primeiros 10): ";
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

