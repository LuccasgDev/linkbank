#include <stdio.h>

#define MAX_TRANSACOES 100

typedef struct {
    char tipo;
    float valor;
} Transacao;

int main() {
    float saca, conta, deposito;
    int opcao, quant_ves = 0;
    Transacao extrato[MAX_TRANSACOES];
    int num_transacoes = 0;
    int tree = 1;

    while (tree) {
        printf("----------------------\n");
        printf("--- BANCO LINKBANK ---\n");
        printf("----------------------\n");
        printf("1 - Sacar\n");
        printf("2 - Depositar\n");
        printf("3 - Extrato\n");
        printf("4 - Sair\n");
        printf("Qual e a opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (quant_ves >= 3) {
                    printf("Quantidade maxima de saques atingida.\n");
                    break;
                }
                printf("Opcao escolhida: Sacar\n");
                printf("Digite o valor para sacar: \n");
                scanf("%f", &saca);
                if (saca <= 0 || saca > 500) {
                    printf("Valor invalido. O valor do saque deve ser maior que zero e no maximo 500.\n");
                } else if (saca > conta) {
                    printf("Saque invalido. O valor do saque e maior do que o saldo disponivel.\n");
                } else {
                    conta -= saca;
                    extrato[num_transacoes].tipo = 'S';
                    extrato[num_transacoes].valor = saca;
                    num_transacoes++;
                    printf("Saque efetuado com sucesso.\n");
                    printf("Saldo na conta: R$%.2f\n", conta);
                    quant_ves++;
                }
                break;
            case 2:
                printf("Opcao escolhida: Depositar\n");
                printf("Digite o valor para depositar: \n");
                scanf("%f", &deposito);
                if (deposito <= 0) {
                    printf("Digite um valor valido para deposito.\n");
                    break;
                }
                conta += deposito;
                extrato[num_transacoes].tipo = 'D';
                extrato[num_transacoes].valor = deposito;
                num_transacoes++;
                printf("Deposito efetuado com sucesso.\n");
                printf("Saldo na conta: R$%.2f\n", conta);
                break;
            case 3:
                printf("Opcao escolhida: Extrato\n");
                printf("Extrato da conta:\n");
                printf("Tipo\tValor\n");
                for (int i = 0; i < num_transacoes; i++) {
                    printf("%c\t%.2f\n", extrato[i].tipo, extrato[i].valor);
                }
                printf("Saldo atual: R$%.2f\n", conta);
                break;
            case 4:
                printf("Opcao escolhida: Sair\n");
                tree = 0;
                break;
            default:
                printf("Opcao invalida. Por favor, escolha novamente.\n");
        }
    }

    printf("Obrigado por usar o Banco LinkBank!\n");

    return 0;
}
//
// Created by lucas on 13/04/2024.
//
