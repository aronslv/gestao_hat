#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "forn.h"

// função do módulo de fornecedores

void modulo_forn(void) {
    char op;
    do{
        op = tela_funcionarios();
        switch(op) {
            case '1':   tela_cad_forn();
                        break;
            case '2':   tela_pes_forn();
                        break;
            case '3':   tela_edit_forn();
                        break;
            case '4':   tela_exc_forn();
                        break;
        }

    }while (op != '0');
}

char tela_fornecedoras(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < < Fornecedoras > > > > > > > >                   §\n");
    printf("§                                                                             §\n");
    printf("§              1. Cadastro de Fornecedoras                                    §\n");
    printf("§              2. Pesquisar Fornecedoras                                      §\n");
    printf("§              3. Editar Dados de Fornecedoras                                §\n");
    printf("§              4. Excluir uma Fornecedora do Sistema                          §\n");
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
}

void tela_cad_forn(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Cadastro - Fornecedoras > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Digite as informações a seguir:                                §\n");
    printf("§                                                                             §\n");
    printf("§              CNPJ:                                                          §\n");
    printf("§              Nome do estabelecimento:                                       §\n");
    printf("§              Endereço do estabelecimento:                                   §\n");
    printf("§              Matéria-prima fornecida:                                       §\n");
    printf("§              Nome do proprietário(a):                                       §\n");
    printf("§              Celular (apenas números):                                      §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_pes_forn(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Pesquisa - Fornecedoras > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CNPJ que deseja pesquisar:                           §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_edit_forn(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Edição - Fornecedoras > > > > > > >              §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CNPJ para edição de dados:                           §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_exc_forn(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Exclusão - Fornecedoras > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CNPJ para excluir do sistema:                        §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}