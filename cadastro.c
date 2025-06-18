#include <stdio.h>
#include <string.h>
#include <ctype.h> // Para usar tolower na comparação

// Definição da struct Cliente
typedef struct {
    char nome[100];
    char email[100];
    char endereco[100];
    int idade;
} Cliente;

// Declaração das funções
void adicionarCliente(Cliente clientes[], int *qtdClientes);
void listarClientes(Cliente clientes[], int qtdClientes);
void buscarCliente(Cliente clientes[], int qtdClientes);

int main() {
    Cliente clientes[50];      // Array para armazenar até 50 clientes
    int qtdClientes = 0;       // Contador de clientes cadastrados
    int opcao;

    do {
        printf("================================ SISTEMA DE CADASTRO ================================\n");
        printf("1 - Adicionar Cliente\n");
        printf("2 - Listar Clientes\n");
        printf("3 - Buscar Cliente\n");
        printf("0 - Sair\n");
        printf("=====================================================================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();  // Limpa o buffer do teclado após o número

        switch(opcao) {
            case 1:
                adicionarCliente(clientes, &qtdClientes);
                break;
            case 2:
                listarClientes(clientes, qtdClientes);
                break;
            case 3:
                buscarCliente(clientes, qtdClientes);
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}

// Função para adicionar um novo cliente
void adicionarCliente(Cliente clientes[], int *qtdClientes) {
    if (*qtdClientes >= 50) {
        printf("Limite de clientes atingido!\n");
        return;
    }

    Cliente novoCliente;

    printf("Digite o nome do cliente: ");
    fgets(novoCliente.nome, sizeof(novoCliente.nome), stdin);

    printf("Digite o email do cliente: ");
    fgets(novoCliente.email, sizeof(novoCliente.email), stdin);

    printf("Digite o endereco do cliente: ");
    fgets(novoCliente.endereco, sizeof(novoCliente.endereco), stdin);

    printf("Digite a idade do cliente: ");
    scanf("%d", &novoCliente.idade);
    getchar(); // Limpa o buffer após o número

    clientes[*qtdClientes] = novoCliente;
    (*qtdClientes)++;
    printf("Cliente adicionado com sucesso!\n");
}

// Função para listar todos os clientes
void listarClientes(Cliente clientes[], int qtdClientes) {
    if (qtdClientes == 0) {
        printf("Nenhum cliente cadastrado ainda.\n");
        return;
    }

    for(int i = 0; i < qtdClientes; i++) {
        printf("-------------------------------\n");
        printf("Nome: %s\n", clientes[i].nome);
        printf("Email: %s\n", clientes[i].email);
        printf("Endereco: %s\n", clientes[i].endereco);
        printf("Idade: %d\n", clientes[i].idade);
        printf("-------------------------------\n");
    }
}

// Função para buscar cliente por nome
void buscarCliente(Cliente clientes[], int qtdClientes) {
    char nomeBusca[100];
    int encontrado = 0;

    printf("Digite o nome do cliente que deseja buscar: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);

    for(int i = 0; i < qtdClientes; i++) {
        // Compara os nomes sem considerar maiúsculas/minúsculas
        if (strcasecmp(clientes[i].nome, nomeBusca) == 0) {
            printf("-------------------------------\n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("Email: %s\n", clientes[i].email);
            printf("Endereco: %s\n", clientes[i].endereco);
            printf("Idade: %d\n", clientes[i].idade);
            printf("-------------------------------\n");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum cliente encontrado com esse nome.\n");
    }
}