#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "func.h"

// função do módulo de funcionários

void modulo_func(void) {
    char op;
    do{
        op = tela_funcionarios();
        switch (op) {
            case '1':   tela_cad_func();
                        break;
            case '2':   tela_pes_func();
                        break;
            case '3':   tela_edit_func();
                        break;
            case '4':   tela_exc_func();
                        break;
        }

    }while (op != '0');
}

char tela_funcionarios(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < < Funcionários > > > > > > > >                   §\n");
    printf("§                                                                             §\n");
    printf("§              1. Cadastro de Funcionários                                    §\n");
    printf("§              2. Pesquisar Funcionários                                      §\n");
    printf("§              3. Editar Dados de Funcionários                                §\n");
    printf("§              4. Excluir um Funcionário do Sistema                           §\n");
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

void tela_cad_func(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Cadastro - Funcionários > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Digite as informações a seguir:                                §\n");
    printf("§                                                                             §\n");
    printf("§              CPF:                                                           §\n");
    printf("§              Nome completo:                                                 §\n");
    printf("§              Profissão:                                                     §\n");
    printf("§              Celular (apenas números):                                      §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_pes_func(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Pesquisa - Funcionários > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CPF que deseja pesquisar:                            §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_edit_func(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Edição - Funcionários > > > > > > >              §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CPF para edição de dados:                            §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_exc_func(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Exclusão - Funcionários > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CPF para excluir do sistema:                         §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}
