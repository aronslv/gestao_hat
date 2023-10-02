#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "rev.h"

// função do módulo de revendedoras

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
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("§              Digite o número da opção desejada: ");
    scanf("%c", &op);
    getchar();
    return op;
}

void tela_cad_rev(void) {
    char cnpj[20];
    char nome1[30];
    char nome2[50];
    char end[30];
    char cel[12];

    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Cadastro - Revendedoras > > > > > > >            \n");
    printf("                                                                             \n");
    printf("              Digite as informações a seguir:                                \n");
    printf("                                                                             \n");
    printf("              CNPJ (apenas números): ");
    scanf("%[0-9]", cnpj);
    getchar();
    printf("              Nome do estabelecimento: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome1);
    getchar();
    printf("              Endereço do estabelecimento: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ.,0-9]", end);
    getchar();
    printf("              Nome do proprietário(a): ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome2);
    getchar();
    printf("              Celular (apenas números): ");
    scanf("%[0-9]", cel);
    getchar();
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Cadastro concluído!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_pes_rev(void) {
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Pesquisa - Revendedoras > > > > > > >            \n");
    printf("                                                                             \n");
    printf("              Informe o CNPJ que deseja pesquisar:                           \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_edit_rev(void) {
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Edição - Revendedoras > > > > > > >              \n");
    printf("                                                                             \n");
    printf("              Informe o CNPJ para edição de dados:                           \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_exc_rev(void) {
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Exclusão - Revendedoras > > > > > > >            \n");
    printf("                                                                             \n");
    printf("              Informe o CNPJ para excluir do sistema:                        \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}
