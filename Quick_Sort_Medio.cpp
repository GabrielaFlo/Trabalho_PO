#include <iostream>
#include <vector>
#include <chrono>
#include <stack>

using namespace std;

// Função para particionar o vetor
int partition(vector<int>& arr, int low, int high, long long& comparisons, long long& swaps) {
    int pivot = arr[high];  // Pivô é o último elemento
    int i = low - 1;  // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] > pivot) {  // Modificado para ordem decrescente
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swaps++;
    return i + 1;
}

// Função iterativa do Quick Sort
void quickSortIterative(vector<int>& arr, int low, int high, long long& comparisons, long long& swaps) {
    stack<pair<int, int>> s;
    s.push({low, high});

    while (!s.empty()) {
        // Acesso mais tradicional aos elementos da pair
        int low = s.top().first;
        int high = s.top().second;
        s.pop();

        if (low < high) {
            // Particiona o vetor e retorna o índice do pivô
            int pi = partition(arr, low, high, comparisons, swaps);

            // Coloca as duas metades na pilha para ordená-las
            s.push({low, pi - 1});
            s.push({pi + 1, high});
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
    const int SIZE = 100000;  // Defina o tamanho do vetor aqui
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

    // Calcula o tempo de execução do Quick Sort
    auto start = chrono::high_resolution_clock::now();
    quickSortIterative(arr, 0, SIZE - 1, comparisons, swaps);
    auto end = chrono::high_resolution_clock::now();

    // Calcula a duração em milissegundos
    chrono::duration<double, milli> duration = end - start;

    // Exibe os resultados
    cout << "Tempo de execução: " << duration.count() << " ms" << endl;
    cout << "Quantidade de comparações: " << comparisons << endl;
    cout << "Quantidade de trocas: " << swaps << endl;

    // Exibe alguns elementos do vetor para confirmação
    cout << "Vetor de 1000 elementos (primeiros 10): "; }
  

