#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "prods.h"
#include "valid.h"

void ler_mat_prim(char*);
void ler_prods(char*);
void ler_cnpj3(char*);
void ler_cnpj4(char*);

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
    Materia* materia;

    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < Cadastro - Matérias-Primas > > > > > >             \n");
    printf("                                                                             \n");
    printf("              Digite as informações a seguir:                                \n");
    printf("                                                                             \n");

    materia = (Materia*) malloc(sizeof(Materia));

    ler_mat_prim(materia->mat_prim);

    printf("Quantidade: ");
    scanf("%d", &materia->quant_mat);
    getchar();

    printf("Valor da unidade: R$ ");
    scanf("%f", &materia->valor);
    getchar();

    printf("Digite a data de compra(dd/mm/aaaa): ");
    scanf("%[0-9/]", materia->data);
    getchar();
    while(!validarData(materia->data)) {
      printf("Data inválida!\n");
      printf("Informe uma nova data: ");
      scanf("%[0-9/]", materia->data);
      getchar();
    }

    ler_cnpj3(materia->cnpj);
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
    Produto* produto;

    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Cadastro - Produtos > > > > > > >                \n");
    printf("                                                                             \n");
    printf("              Digite as informações a seguir:                                \n");
    printf("                                                                             \n");

    produto = (Produto*) malloc(sizeof(Produto));

    ler_mat_prim(produto->prods);

    printf("Quantidade: ");
    scanf("%d", &produto->quant_prods);
    getchar();

    printf("Valor da unidade: R$ ");
    scanf("%f", &produto->valor);
    getchar();

    printf("Digite a data de compra(dd/mm/aaaa): ");
    scanf("%[0-9/]", produto->data);
    getchar();
    while(!validarData(produto->data)) {
      printf("Data inválida!\n");
      printf("Informe uma nova data: ");
      scanf("%[0-9/]", produto->data);
      getchar();
    }

    ler_cnpj4(produto->cnpj);
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

void ler_mat_prim(char* mat_prim) {
  fflush(stdin);
  printf("Nome completo: ");
  fgets(mat_prim, 25, stdin); 
  // Remove o caractere de nova linha do final, se estiver presente
  int tam = strlen(mat_prim);
  if (tam > 0 && mat_prim[tam - 1] == '\n') {
    mat_prim[tam - 1] = '\0';
    fflush(stdin);
  }
  while (!validarNome(mat_prim)) {
    printf("Nome inválido: %s\n", mat_prim);
    printf("Informe um novo nome: ");
    fflush(stdin);
    fgets(mat_prim, 25, stdin); 
    // Remove o caractere de nova linha do final, se estiver presente
    tam = strlen(mat_prim);
    if (tam > 0 && mat_prim[tam - 1] == '\n') {
      mat_prim[tam - 1] = '\0';
      fflush(stdin);
    }
  } 
}

void ler_cnpj3 (char* cnpj) {
    fflush(stdin);
    printf("Digite o CNPJ (Apenas Números): ");
    fgets (cnpj, 15, stdin);
    while (!validarCnpj(cnpj)) {
        printf("CNPJ inválido! Digite o CNPJ novamente: ");
        fgets (cnpj, 15, stdin);
    }
    getchar();
}

void ler_prods(char* prods) {
  fflush(stdin);
  printf("Tipo de Produto: ");
  fgets(prods, 25, stdin); 
  // Remove o caractere de nova linha do final, se estiver presente
  int tam = strlen(prods);
  if (tam > 0 && prods[tam - 1] == '\n') {
    prods[tam - 1] = '\0';
    fflush(stdin);
  }
  while (!validarNome(prods)) {
    printf("Tipo inválido: %s\n", prods);
    printf("Informe um novo tipo: ");
    fflush(stdin);
    fgets(prods, 25, stdin); 
    // Remove o caractere de nova linha do final, se estiver presente
    tam = strlen(prods);
    if (tam > 0 && prods[tam - 1] == '\n') {
      prods[tam - 1] = '\0';
      fflush(stdin);
    }
  } 
}

void ler_cnpj4 (char* cnpj) {
    fflush(stdin);
    printf("Digite o CNPJ (Apenas Números): ");
    fgets (cnpj, 15, stdin);
    while (!validarCnpj(cnpj)) {
        printf("CNPJ inválido! Digite o CNPJ novamente: ");
        fgets (cnpj, 15, stdin);
    }
    getchar();
}