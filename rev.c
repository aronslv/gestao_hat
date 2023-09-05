#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "rev.h"

// função do módulo de revendedoras

#ifndef REV_H
#define REV_H

void modulo_rev(void) {
    char op;
    do{
        op = tela_revendedoras();
        switch (op) {
            case '1':   tela_cad_rev();
                        break;
            case '2':   tela_pes_rev();
                        break;
            case '3':   tela_edit_rev();
                        break;
            case '4':   tela_exc_rev();
                        break;
        }
        
    }while (op != '0');
}

char tela_revendedoras(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < < Revendedoras > > > > > > > >                   §\n");
    printf("§                                                                             §\n");
    printf("§              1. Cadastro de Revendedoras                                    §\n");
    printf("§              2. Pesquisar Revendedoras                                      §\n");
    printf("§              3. Editar Dados de Revendedoras                                §\n");
    printf("§              4. Excluir uma Revendedora do Sistema                          §\n");
    printf("§              0. Retornar ao Menu Principal                                  §\n");
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

void tela_cad_rev(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Cadastro - Revendedoras > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Digite as informações a seguir:                                §\n");
    printf("§                                                                             §\n");
    printf("§              CNPJ:                                                          §\n");
    printf("§              Nome do estabelecimento:                                       §\n");
    printf("§              Endereço do estabelecimento:                                   §\n");
    printf("§              Nome do proprietário(a):                                       §\n");
    printf("§              Celular (apenas números):                                      §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_pes_rev(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Pesquisa - Revendedoras > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CNPJ que deseja pesquisar:                           §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_edit_rev(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Edição - Revendedoras > > > > > > >              §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CNPJ para edição de dados:                           §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_exc_rev(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Exclusão - Revendedoras > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CNPJ para excluir do sistema:                        §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

#endif REV_H