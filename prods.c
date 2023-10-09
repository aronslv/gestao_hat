#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "prods.h"
#include "valid.h"

// função do módulo de produtos

void modulo_prods(void) {
    char opc;
    char op;
    do{
        opc = escolha_prods();
        switch (opc) {
            case '1':   
            do{
                op = tela_material();
                switch (op) {
                    case '1':   tela_cad_mat();
                                break;
                    case '2':   tela_pes_mat();
                                break;
                    case '3':   tela_edit_mat();
                                break;
                    case '4':   tela_exc_mat();
                                break;
                }
            }while (op != '0');
            break; 
            case '2':
            do{
                op = tela_produtos();
                switch (op) {
                    case '1':   tela_cad_prods();
                                break;
                    case '2':   tela_pes_prods();
                                break;
                    case '3':   tela_edit_prods();
                                break;
                    case '4':   tela_exc_prods();
                                break;
                }
            }while (op != '0');
            break;      
        }
    }while (opc != '0');
}

char escolha_prods(void) {
    char opc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§                  < < < < < < < Opções de Produtos > > > > > > >             §\n");
    printf("§                                                                             §\n");
    printf("§                  1. Matérias-primas                                         §\n");
    printf("§                  2. Produtos                                                §\n");
    printf("§                  0. Retornar ao Menu Principal                              §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("§              Digite o número da opção desejada: ");
    scanf("%c", &opc);
    getchar();
    return opc;
}

char tela_material(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Matérias-Primas > > > > > > >                    §\n");
    printf("§                                                                             §\n");
    printf("§              1. Cadastro de Matérias-Primas                                 §\n");
    printf("§              2. Pesquisar Matérias-Primas                                   §\n");
    printf("§              3. Editar Dados de Matérias-Primas                             §\n");
    printf("§              4. Excluir uma Matéria-Prima do Sistema                        §\n");
    printf("§              0. Retornar ao Menu de Opções                                  §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("§              Digite o número da opção desejada: ");
    scanf("%c", &op);
    getchar();
    return op;
}

void tela_cad_mat(void) {

    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < Cadastro - Matérias-Primas > > > > > >             \n");
    printf("                                                                             \n");
    printf("              Digite as informações a seguir:                                \n");
    printf("                                                                             \n");
    printf("              Tipo de Matéria-Prima:                                         \n");
    printf("              Valor da Compra(Unidade): R$                                   \n");                             
    printf("              Quantidade:                                                    \n");
    printf("              Data da Compra:                                                \n");
    printf("              CNPJ da Fornecedora (apenas números):                          \n");
    printf("                                                                             \n");
    printf("              ID da Matéria-Prima: (gerado)                                  \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_pes_mat(void) {
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < Pesquisa - Matérias-Primas > > > > > >             \n");
    printf("                                                                             \n");
    printf("     Informe o CNPJ da fornecedora para pesquisa de matérias-primas:         \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_edit_mat(void) {
    system("clear||cls");
    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                                                                \n");
    printf("              < < < < < < Edição - Matérias-Primas > > > > > >                  \n");
    printf("                                                                                \n");
    printf("     Informe o CNPJ da fornecedora para edição de matérias-primas:              \n");
    printf("                                                                                \n");
    printf("                                                                                \n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_exc_mat(void) {
    system("clear||cls");
    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                                                                \n");
    printf("              < < < < < < Exclusão - Matérias-Primas > > > > > >                \n");
    printf("                                                                                \n");
    printf("     Informe o CNPJ da fornecedora para exclusão de matérias-primas:            \n");
    printf("                                                                                \n");
    printf("                                                                                \n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

char tela_produtos(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < < Produtos > > > > > > > >                       §\n");
    printf("§                                                                             §\n");
    printf("§              1. Cadastro de Produtos                                        §\n");
    printf("§              2. Pesquisar Produtos                                          §\n");
    printf("§              3. Editar Dados de Produtos                                    §\n");
    printf("§              4. Excluir um Produto do Sistema                               §\n");
    printf("§              0. Retornar ao Menu de Opções                                  §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("§              Digite o número da opção desejada: ");
    scanf("%c", &op);
    getchar();
    return op;
}

void tela_cad_prods(void) {
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Cadastro - Produtos > > > > > > >                \n");
    printf("                                                                             \n");
    printf("              Digite as informações a seguir:                                \n");
    printf("                                                                             \n");
    printf("              Tipo do Produto:                                               \n");
    printf("              Custo da Produção(Unidade):                                    \n");
    printf("              Quantidade:                                                    \n");
    printf("              Data da Produção:                                              \n");
    printf("              CNPJ da Revendedora (apenas números):                          \n");
    printf("                                                                             \n");
    printf("              ID do Produto: (gerado)                                        \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_pes_prods(void) {
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Pesquisa - Produtos > > > > > > >                \n");
    printf("                                                                             \n");
    printf("     Informe o CNPJ da revendedora para pesquisa de produtos:                \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_edit_prods(void) {
    system("clear||cls");
    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                                                                \n");
    printf("              < < < < < < < Edição - Produtos > > > > > > >                     \n");
    printf("                                                                                \n");
    printf("     Informe o CNPJ da revendedora para edição de produtos:                     \n");
    printf("                                                                                \n");
    printf("                                                                                \n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_exc_prods(void) {
    system("clear||cls");
    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                                                                \n");
    printf("              < < < < < < < Exclusão - Produtos > > > > > > >                   \n");
    printf("                                                                                \n");
    printf("     Informe o CNPJ da revendedora para exclusão de produtos:                   \n");
    printf("                                                                                \n");
    printf("                                                                                \n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}