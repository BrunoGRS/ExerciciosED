#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    
    int pai(int i) {
        return (i - 1) / 2;
    }

    
    int esquerda(int i) {
        return 2 * i + 1;
    }

    
    int direita(int i) {
        return 2 * i + 2;
    }

    
    void subir(int i) {
        while (i > 0 && heap[pai(i)] < heap[i]) {
            swap(heap[i], heap[pai(i)]);
            i = pai(i);
        }
    }

    
    void descer(int i) {
        int maior = i;
        int esq = esquerda(i);
        int dir = direita(i);

        if (esq < heap.size() && heap[esq] > heap[maior]) {
            maior = esq;
        }
        if (dir < heap.size() && heap[dir] > heap[maior]) {
            maior = dir;
        }

        if (maior != i) {
            swap(heap[i], heap[maior]);
            descer(maior);
        }
    }

public:
    
    void inserir(int valor) {
        heap.push_back(valor);
        subir(heap.size() - 1);
    }

    
    int remover() {
        if (heap.empty()) {
            cout << "Fila de prioridades vazia!" << endl;
            return -1;
        }
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        descer(0);
        return max;
    }

 
    int obterMaior() {
        if (heap.empty()) {
            cout << "Fila de prioridades vazia!" << endl;
            return -1;
        }
        return heap[0];
    }

    
    void imprimir() {
        cout << "Heap: ";
        for (int i : heap) {
            cout << i << " ";
        }
        cout << endl;
    }
};


int main() {
    MaxHeap* heap = new MaxHeap();

    int opcao, valor;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Inserir elemento\n";
        cout << "2. Remover elemento de maior prioridade\n";
        cout << "3. Exibir elemento de maior prioridade\n";
        cout << "4. Exibir heap\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o valor a ser inserido: ";
                cin >> valor;
                heap->inserir(valor);
                break;
            case 2:
                valor = heap->remover();
                if (valor != -1) {
                    cout << "Elemento removido: " << valor << endl;
                }
                break;
            case 3:
                valor = heap->obterMaior();
                if (valor != -1) {
                    cout << "Elemento de maior prioridade: " << valor << endl;
                }
                break;
            case 4:
                heap->imprimir();
                break;
            case 0:
                cout << "Saindo..." << endl;
                delete heap;
                return 0;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
                break;
        }
    }

    return 0;
}
