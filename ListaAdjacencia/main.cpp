#include <iostream>
#include <cstdlib>  // Para usar rand() e srand()
#include <ctime>    // Para seed do gerador de números aleatórios

// Estrutura de nó para a lista encadeada
struct Node {
    int value;
    Node* next;
};

// Função para adicionar um valor ao final da lista
void append(Node*& head, int value) {
    Node* newNode = new Node();  // Cria um novo nó
    newNode->value = value;
    newNode->next = nullptr;

    if (!head) {  // Se a lista estiver vazia
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Função para popular a lista com valores aleatórios
void populateList(Node*& head, int size) {
    srand(time(0));  // Inicializa o gerador de números aleatórios com base no tempo atual
    for (int i = 0; i < size; i++) {
        int randomValue = rand() % 100;  // Gera um número aleatório entre 0 e 99
        append(head, randomValue);
    }
}

// Função para exibir a lista
void displayList(Node* head) {
    if (!head) {
        std::cout << "A lista está vazia." << std::endl;
        return;
    }

    Node* temp = head;
    std::cout << "Valores na lista: ";
    while (temp != nullptr) {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Função para unir (somar) os valores da lista
int sumList(Node* head) {
    if (!head) {
        std::cout << "A lista está vazia." << std::endl;
        return 0;
    }

    int sum = 0;
    Node* temp = head;
    while (temp != nullptr) {
        sum += temp->value;
        temp = temp->next;
    }
    return sum;
}

// Função para liberar a memória alocada pela lista
void freeList(Node*& head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;  // Para evitar que o ponteiro aponte para lixo
}

// Função para exibir o menu
void showMenu() {
    std::cout << "\n=== MENU ===" << std::endl;
    std::cout << "1. Popular a lista com valores aleatórios" << std::endl;
    std::cout << "2. Mostrar valores da lista" << std::endl;
    std::cout << "3. Somar os valores da lista" << std::endl;
    std::cout << "4. Limpar lista" << std::endl;
    std::cout << "5. Sair" << std::endl;
    std::cout << "Escolha uma opção: ";
}

int main() {
    Node* list = nullptr;  // Ponteiro para a cabeça da lista
    int option, size;

    do {
        showMenu();
        std::cin >> option;

        switch (option) {
            case 1:
                if (list != nullptr) {
                    std::cout << "A lista já foi populada. Deseja limpar a lista e repopular? (1 - Sim, 2 - Não): ";
                    int choice;
                    std::cin >> choice;
                    if (choice == 1) {
                        freeList(list);
                    } else {
                        break;
                    }
                }
                std::cout << "Digite o tamanho da lista: ";
                std::cin >> size;
                populateList(list, size);
                std::cout << "Lista populada com " << size << " valores aleatórios." << std::endl;
                break;

            case 2:
                displayList(list);
                break;

            case 3: {
                int totalSum = sumList(list);
                std::cout << "Soma dos valores: " << totalSum << std::endl;
                break;
            }

            case 4:
                freeList(list);
                std::cout << "Lista limpa." << std::endl;
                break;

            case 5:
                std::cout << "Saindo..." << std::endl;
                freeList(list);
                break;

            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    } while (option != 5);

    return 0;
}
