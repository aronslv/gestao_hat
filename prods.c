#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "prods.h"
#include "valid.h"

void ler_mat_prim(char*);
void ler_prods(char*);

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
                    case '2':   mat_x = tela_pes_mat();
                                free(mat_x);
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
                    case '2':   prod_x = tela_pes_prods();
                                free(prod_x);
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
    printf("§                  < < < < < < < < Mercadorias > > > > > > > >                §\n");
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

    printf("ID da matéria-prima: ");
    scanf("%d", &mat->id);
    getchar();

    printf("Valor da unidade: R$ ");
    scanf("%f", &mat->valor);
    getchar();

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

Materia* tela_pes_mat(void) {
    FILE* fp;
    Materia* mat;
    int id;
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < Pesquisa - Matérias-Primas > > > > > >             \n");
    printf("                                                                             \n");
    printf(" Informe o ID da matéria-prima para pesquisa: ");
    scanf("%d", &id);
    getchar();
    printf("\n");
    mat = (Materia*) malloc(sizeof(Materia));
    fp = fopen("mat.dat", "rb");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        while(fread(mat, sizeof(Materia), 1, fp) == 1) {
            if((mat->status != 'e') && (mat->id == id)) {
              exb_mat(mat);
              printf("\n");
            }
        }
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        fclose(fp);
        return mat;
    }
    fclose(fp);
    return NULL;
}

void tela_edit_mat(void) {
    int id;
    Materia* new_mat = (Materia*) malloc(sizeof(Materia));
    FILE* fp;
    int mat_found = 0;
    system("clear||cls");
    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                                                                \n");
    printf("              < < < < < < Edição - Matérias-Primas > > > > > >                  \n");
    printf("                                                                                \n");
    printf(" Informe o ID da matéria-prima para edição: ");
    scanf("%d", &id);
    getchar();
    fp = fopen("mat.dat", "r+b");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        while (fread(new_mat, sizeof(Materia), 1, fp) == 1) {
            if((new_mat->status != 'e') && (new_mat->id == id)) {
                printf("\n");
                printf("\t\t\t= = = Matéria-Prima Encontrada = = =\n");
                printf("\n");

                ler_mat_prim(new_mat->mat_prim);

                printf("ID da matéria-prima: ");
                scanf("%d", &new_mat->id);
                getchar();

                printf("Valor da unidade: R$ ");
                scanf("%f", &new_mat->valor);
                getchar();

                new_mat->status = 'c';

                fseek(fp, -sizeof(Materia), SEEK_CUR);
                fwrite(new_mat, sizeof(Materia), 1, fp);
                mat_found = 1;
                break;
            }
        }
    }
    if (!mat_found) {
        printf("\n");
        printf("\t\t\tCNPJ ou Matéria-Prima não encontrada!\n");
    } else {
        printf("\n");
        printf("\t\t\tMatéria-Prima atualizada com sucesso!\n");
    }
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  fclose(fp);
}

void tela_exc_mat(void) {
    int id;
    Materia* new_mat = (Materia*) malloc(sizeof(Materia));
    FILE* fp;
    int mat_found = 0;
    system("clear||cls");
    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                                                                \n");
    printf("              < < < < < < Exclusão - Matérias-Primas > > > > > >                \n");
    printf("                                                                                \n");
    printf(" Informe o ID da matéria-prima para excluir: ");
    scanf("%d", &id);
    getchar();
    fp = fopen("mat.dat", "r+b");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        while (fread(new_mat, sizeof(Materia), 1, fp) == 1) {
            if(new_mat->id == id) {
                printf("\n");
                printf("\t\t\t= = = Matéria-Prima Encontrada = = =\n");
                printf("\n");

                new_mat->status = 'e';

                fseek(fp, -sizeof(Materia), SEEK_CUR);
                fwrite(new_mat, sizeof(Materia), 1, fp);
                mat_found = 1;
                break;
            }
        }
    }
    if (!mat_found) {
        printf("\n");
        printf("\t\t\tCNPJ ou Matéria-Prima não encontrada!\n");
    } else {
        printf("\n");
        printf("\t\t\tMatéria-Prima excluída com sucesso!\n");
    }
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  fclose(fp);
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

    printf("ID do produto: ");
    scanf("%d", &prod->id);
    getchar();

    printf("Valor da unidade: R$ ");
    scanf("%f", &prod->valor);
    getchar();

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

Produto* tela_pes_prods(void) {
    FILE* fp;
    Produto* prod;
    int id;
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Pesquisa - Produtos > > > > > > >                \n");
    printf("                                                                             \n");
    printf("  Informe o ID do produto para pesquisa: ");
    scanf("%d", &id);
    getchar();
    printf("\n");
    prod = (Produto*) malloc(sizeof(Produto));
    fp = fopen("prod.dat", "rb");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        while(fread(prod, sizeof(Produto), 1, fp) == 1) {
            if((prod->id == id) && (prod->status != 'e')) {
              exb_prod(prod);
              printf("\n");
            }
        }
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        fclose(fp);
        return prod;
    }
    fclose(fp);
    return NULL;
}

void tela_edit_prods(void) {
    int id;
    Produto* new_prod = (Produto*) malloc(sizeof(Produto));
    FILE* fp;
    int prod_found = 0;
    system("clear||cls");
    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                                                                \n");
    printf("              < < < < < < < Edição - Produtos > > > > > > >                     \n");
    printf("                                                                                \n");
    printf(" Informe o ID do produto para edição: ");
    scanf("%d", &id);
    getchar();
    fp = fopen("prod.dat", "r+b");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        while (fread(new_prod, sizeof(Produto), 1, fp) == 1) {
            if((new_prod->id == id) && (new_prod->status != 'e')) {
                printf("\n");
                printf("\t\t\t= = = Produto Encontrado = = =\n");
                printf("\n");

                ler_prods(new_prod->prods);

                printf("ID do produto: ");
                scanf("%d", &new_prod->id);
                getchar();

                printf("Valor da unidade: R$ ");
                scanf("%f", &new_prod->valor);
                getchar();

                new_prod->status = 'c';

                fseek(fp, -sizeof(Produto), SEEK_CUR);
                fwrite(new_prod, sizeof(Produto), 1, fp);
                prod_found = 1;
                break;
            }
        }
    }
    if (!prod_found) {
        printf("\n");
        printf("\t\t\tCNPJ ou Produto não encontrado!\n");
    } else {
        printf("\n");
        printf("\t\t\tProduto atualizado com sucesso!\n");
    }
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  fclose(fp);
}

void tela_exc_prods(void) {
    int id;
    Produto* new_prod = (Produto*) malloc(sizeof(Produto));
    FILE* fp;
    int prod_found = 0;
    system("clear||cls");
    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                                                                \n");
    printf("              < < < < < < < Exclusão - Produtos > > > > > > >                   \n");
    printf("                                                                                \n");
    printf(" Informe o ID do produto para excluir: ");
    scanf("%d", &id);
    getchar();
    fp = fopen("prod.dat", "r+b");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        while (fread(new_prod, sizeof(Produto), 1, fp) == 1) {
            if(new_prod->id == id) {
                printf("\n");
                printf("\t\t\t= = = Produto Encontrado = = =\n");
                printf("\n");

                new_prod->status = 'e';

                fseek(fp, -sizeof(Produto), SEEK_CUR);
                fwrite(new_prod, sizeof(Produto), 1, fp);
                prod_found = 1;
                break;
            }
        }
    }
    if (!prod_found) {
        printf("\n");
        printf("\t\t\tCNPJ ou Produto não encontrado!\n");
    } else {
        printf("\n");
        printf("\t\t\tProduto excluído com sucesso!\n");
    }
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  fclose(fp);
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

void exb_mat(Materia* mat) {
  if ((mat == NULL) || (mat->status == 'e')) {
    printf("\n");
    printf("\t\t\tID não encontrado!\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }else{
    char sit[20];
    printf("\t\t\t= = = Matéria-Prima Cadastrada = = =\n");
    printf("\n");
    printf("ID da Matéria-Prima: %d\n", mat->id);
    printf("Descrição da Matéria-Prima: %s\n", mat->mat_prim);
    printf("Valor da Unidade: R$ %.2f\n", mat->valor);
    if (mat->status == 'c') {
      strcpy(sit, "Comprada");
    } else {
      strcpy(sit, "Não Informada");
    }
    printf("Situação da Matéria-Prima: %s\n", sit);
    printf("\n");
  }
}

void exb_prod(Produto* prod) {
  if ((prod == NULL) || (prod->status == 'e')) {
    printf("\n");
    printf("\t\t\tID não encontrado!\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }else{
    char sit[20];
    printf("\t\t\t= = = Produto Cadastrado = = =\n");
    printf("\n");
    printf("ID do Produto: %d\n", prod->id);
    printf("Descrição do Produto: %s\n", prod->prods);
    printf("Valor da Unidade: R$ %.2f\n", prod->valor);
    if (prod->status == 'c') {
      strcpy(sit, "Vendido");
    } else {
      strcpy(sit, "Não Informada");
    }
    printf("Situação do Produto: %s\n", sit);
    printf("\n");
  }
}