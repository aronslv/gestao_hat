#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "prods.h"
#include "valid.h"

void ler_mat_prim(char*);
void ler_prods(char*);
void ler_data_mat(char*);
void ler_data_prods(char*);
void ler_cnpj3(char*);
void ler_cnpj4(char*);

// função do módulo de produtos

void modulo_prods(void) {
    Materia* mat_x;
    Produto* prod_x;
    char opc;
    char op;
    do{
        opc = escolha_prods();
        switch (opc) {
            case '1':   
            do{
                op = tela_material();
                switch (op) {
                    case '1':   mat_x = tela_cad_mat();
                                esc_mat(mat_x);
                                free(mat_x);
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
                    case '1':   prod_x = tela_cad_prods();
                                esc_prod(prod_x);
                                free(prod_x);
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

Materia* tela_cad_mat(void) {
    Materia* mat;

    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < Cadastro - Matérias-Primas > > > > > >             \n");
    printf("                                                                             \n");
    printf("              Digite as informações a seguir:                                \n");
    printf("                                                                             \n");

    mat = (Materia*) malloc(sizeof(Materia));

    ler_mat_prim(mat->mat_prim);

    printf("Quantidade: ");
    scanf("%d", &mat->quant_mat);
    getchar();

    printf("Valor da unidade: R$ ");
    scanf("%f", &mat->valor);
    getchar();

    ler_data_mat(mat->data);

    ler_cnpj3(mat->cnpj);

    mat->status = 'c';
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Cadastro concluído!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return mat;
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

Produto* tela_cad_prods(void) {
    Produto* prod;

    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Cadastro - Produtos > > > > > > >                \n");
    printf("                                                                             \n");
    printf("              Digite as informações a seguir:                                \n");
    printf("                                                                             \n");

    prod = (Produto*) malloc(sizeof(Produto));

    ler_prods(prod->prods);

    printf("Quantidade: ");
    scanf("%d", &prod->quant_prods);
    getchar();

    printf("Valor da unidade: R$ ");
    scanf("%f", &prod->valor);
    getchar();

    ler_data_prods(prod->data);

    ler_cnpj4(prod->cnpj);

    prod->status = 'c';
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Cadastro concluído!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return prod;
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
  printf("Descrição da Matéria-Prima: ");
  fgets(mat_prim, 25, stdin); 
  // Remove o caractere de nova linha do final, se estiver presente
  int tam = strlen(mat_prim);
  if (tam > 0 && mat_prim[tam - 1] == '\n') {
    mat_prim[tam - 1] = '\0';
    fflush(stdin);
  }
  while (!validarNome(mat_prim)) {
    printf("Descrição inválida: %s\n", mat_prim);
    printf("Informe uma nova descrição: ");
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

void ler_data_mat(char* data) {
  int dia, mes, ano;
  char dd[3], mm[3], aa[5];
  fflush(stdin);
  printf("Digite a data de compra(dd/mm/aaaa): ");
  fgets(data, 11, stdin); 
  getchar();
  
  strncpy(dd, &data[0], 2);
  sscanf(dd, "%d", &dia);
  
  strncpy(mm, &data[3], 2);
  sscanf(mm, "%d", &mes);

  strncpy(aa, &data[6], 4);
  sscanf(aa, "%d", &ano);

  while (!validarData(dia, mes, ano)) {
    printf("Data inválida: %d/%d/%d\n", dia, mes, ano);
    printf("Informe uma nova data\n\n");
    printf("Data de compra(dd/mm/aaaa): ");
    fgets(data, 11, stdin);
    fflush(stdin);
    getchar();
    strncpy(dd, &data[0], 2);
    sscanf(dd, "%d", &dia);
    strncpy(mm, &data[3], 2);
    sscanf(mm, "%d", &mes);
    strncpy(aa, &data[6], 4);
    sscanf(aa, "%d", &ano);
    
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
  printf("Descrição do Produto: ");
  fgets(prods, 25, stdin); 
  // Remove o caractere de nova linha do final, se estiver presente
  int tam = strlen(prods);
  if (tam > 0 && prods[tam - 1] == '\n') {
    prods[tam - 1] = '\0';
    fflush(stdin);
  }
  while (!validarNome(prods)) {
    printf("Descrição inválida: %s\n", prods);
    printf("Informe uma nova descrição: ");
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

void ler_data_prods(char* data) {
  int dia, mes, ano;
  char dd[3], mm[3], aa[5];
  fflush(stdin);
  printf("Digite a data de compra(dd/mm/aaaa): ");
  fgets(data, 11, stdin); 
  getchar();
  
  strncpy(dd, &data[0], 2);
  sscanf(dd, "%d", &dia);
  
  strncpy(mm, &data[3], 2);
  sscanf(mm, "%d", &mes);

  strncpy(aa, &data[6], 4);
  sscanf(aa, "%d", &ano);

  while (!validarData(dia, mes, ano)) {
    printf("Data inválida: %d/%d/%d\n", dia, mes, ano);
    printf("Informe uma nova data\n\n");
    printf("Data de compra(dd/mm/aaaa): ");
    fgets(data, 11, stdin);
    fflush(stdin);
    getchar();
    strncpy(dd, &data[0], 2);
    sscanf(dd, "%d", &dia);
    strncpy(mm, &data[3], 2);
    sscanf(mm, "%d", &mes);
    strncpy(aa, &data[6], 4);
    sscanf(aa, "%d", &ano);
    
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

void esc_mat(Materia* mat) {
  FILE* fp;
  fp = fopen("mat.dat", "ab");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  else {
    fwrite(mat, sizeof(Materia), 1, fp);
    fclose(fp);
  }
}

void esc_prod(Produto* prod) {
  FILE* fp;
  fp = fopen("prod.dat", "ab");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  else {
    fwrite(prod, sizeof(Materia), 1, fp);
    fclose(fp);
  }
}