#include <stdio.h>
#include <stdlib.h>
#include "rev.h"
#include "func.h"

//funções base
char tela_main(void);
void tela_info(void);

//programa main
int main(void) {
    char op;
    do {
        op = tela_main();
        switch(op) {
            case '1':   tela_revendedoras();
                        break;
            case '2':   tela_funcionarios();
                        break;
            case '3':   tela_fornecedoras();
                        break;
            case '4':   printf("Em desenvolvimento!\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '5':   printf("Em desenvolvimento!\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '6':   tela_info();
                        break;
        }
    } while (op != '0');   
    return 0;
}

//funções telas
char tela_main(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < Sistema Hat and Cap > > > > >                        §\n");
    printf("§                                                                             §\n");
    printf("§              1. Revendedoras                                                §\n");
    printf("§              2. Funcionários                                                §\n");
    printf("§              3. Fornecedores                                                §\n");
    printf("§              4. Produtos                                                    §\n");
    printf("§              5. Relatórios                                                  §\n");
    printf("§              6. Informações                                                 §\n");
    printf("§              0. Sair                                                        §\n");
    printf("§                                                                             §\n");
    printf("§              Digite o número da opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return op;
}

void tela_info(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§                   < < < < < Sistema Hat and Cap > > > > >                   §\n");
    printf("§                                                                             §\n");
    printf("§       Universidade Federal do Rio Grande do Norte (UFRN)                    §\n");
    printf("§       Centro de Ensino Superior do Seridó (CERES)                           §\n");
    printf("§       Programa desenvolvido pelo discente Aron Silva                        §\n");
    printf("§       Temática: Gestão de Fábrica de Chapéus e Bonés                        §\n");
    printf("§       Auxílios e Influências: Flavius Gorgônio                              §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}