#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// função do módulo de produtos

void modulo_prods(void) {
    char op;
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

void tela_cad_prods(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Cadastro - Produtos > > > > > > >                §\n");
    printf("§                                                                             §\n");
    printf("§              Digite as informações a seguir:                                §\n");
    printf("§                                                                             §\n");
    printf("§              Tipo do Produto:                                               §\n");
    printf("§              Custo da Produção(Unidade):                                    §\n");
    printf("§              Quantidade:                                                    §\n");
    printf("§              Data da Produção:                                              §\n");
    printf("§              Revendedora Designada:                                         §\n");
    printf("§              Preço de Revenda(Unidade):                                     §\n");
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
    printf("§              < < < < < < < Pesquisa - Produtos > > > > > > >                §\n");
    printf("§                                                                             §\n");
    printf("§     Informe o CNPJ da revendedora para pesquisa de produtos:                §\n");
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
    printf("----------------------------------------------------------------------------------\n");
    printf("§                                                                                §\n");
    printf("§              < < < < < < < Edição - Produtos > > > > > > >                     §\n");
    printf("§                                                                                §\n");
    printf("§     Informe o CNPJ da revendedora para edição de produtos:                     §\n");
    printf("§                                                                                §\n");
    printf("§                                                                                §\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_exc_rev(void) {
    system("clear||cls");
    printf("\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("§                                                                                §\n");
    printf("§              < < < < < < < Exclusão - Produtos > > > > > > >                   §\n");
    printf("§                                                                                §\n");
    printf("§     Informe o CNPJ da revendedora para exclusão de produtos:                   §\n");
    printf("§                                                                                §\n");
    printf("§                                                                                §\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}