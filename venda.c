#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "vendas.h"
#include "prods.h"
#include "rel.h"
#include "valid.h"

void ler_cnpj3(char*);
void ler_data_mat(char*);
void ler_cnpj4(char*);
void ler_cpf_vend(char*);
void ler_data_prods(char*);

void modulo_vendas(void) {
    Compras* com_x;
    Vendas* ven_x;
    char opc;
    char op;
    do{
        opc = escolha_vendas();
        switch (opc) {
            case '1':   
            do{
                op = tela_compras();
                switch (op) {
                    case '1':   com_x = tela_cad_com();
                                esc_com(com_x);
                                free(com_x);
                                break;
                    case '2':   com_x = tela_pes_com();
                                exb_com(com_x);
                                free(com_x);
                                break;
                    case '3':   tela_exc_com();
                                break;
                }
            }while (op != '0');
            break; 
            case '2':
            do{
                op = tela_vendas();
                switch (op) {
                    case '1':   ven_x = tela_cad_ven();
                                esc_ven(ven_x);
                                free(ven_x);
                                break;
                    case '2':   ven_x = tela_pes_ven();
                                exb_ven(ven_x);
                                free(ven_x);
                                break;
                    case '3':   tela_exc_ven();
                                break;
                }
            }while (op != '0');
            break;      
        }
    }while (opc != '0');
}

char escolha_vendas(void) {
    char opc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§                  < < < < < < < < Transações > > > > > > > >                 §\n");
    printf("§                                                                             §\n");
    printf("§                  1. Compras                                                 §\n");
    printf("§                  2. Vendas                                                  §\n");
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

char tela_compras(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < < Compras > > > > > > > >                        §\n");
    printf("§                                                                             §\n");
    printf("§              1. Cadastro de Compras                                         §\n");
    printf("§              2. Pesquisar Compras                                           §\n");
    printf("§              3. Cancelar Compras                                            §\n");
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

Compras* tela_cad_com(void) {
    Compras* com;
    char* nome_mat;
    char* nome_forn;
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Cadastro - Compras > > > > > > >                 \n");
    printf("                                                                             \n");
    printf("              Digite as informações a seguir:                                \n");
    printf("                                                                             \n");

    com = (Compras*) malloc(sizeof(Compras));

    printf("ID da matéria-prima: ");
    scanf("%d", &com->id);
    getchar();

    nome_mat = get_mat(com->id);

    printf("Descrição da matéria-prima: %s\n", nome_mat);

    ler_cnpj3(com->cnpj);

    nome_forn = get_forn(com->cnpj);

    printf("Nome do estabelecimento: %s\n", nome_forn);

    printf("Quantidade: ");
    scanf("%d", &com->quant);
    getchar();

    get_est_mat(com->id, com->quant);

    com->valor = get_val_mat(com->id);

    com->preco = com->quant * com->valor;

    ler_data_mat(com->data);

    printf("ID da compra: ");
    scanf("%d", &com->id_compra);
    getchar();

    com->status = 'c';
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Cadastro concluído!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return com;
}

Compras* tela_pes_com(void) {
    FILE* fp;
    Compras* com;
    int id;
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Pesquisa - Compras > > > > > > >                 \n");
    printf("                                                                             \n");
    printf(" Informe o ID da compra para pesquisa: ");
    scanf("%d", &id);
    getchar();
    printf("\n");
    com = (Compras*) malloc(sizeof(Compras));
    fp = fopen("compras.dat", "rb");
    if (fp == NULL) {
      printf("\t\t\t>>> Processando as informações...\n");
      sleep(1);
      printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
      printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
      getchar();
    } else {
        while(fread(com, sizeof(Compras), 1, fp) == 1) {
          if(com->id_compra == id) {
            exb_com(com);
            printf("\n");
          }
        }
      printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
      getchar();
      fclose(fp);
      return com;
    }
    fclose(fp);
    return NULL;
}

void tela_exc_com(void) {
    int id;
    Compras* new_com = (Compras*) malloc(sizeof(Compras));
    FILE* fp;
    int com_found = 0;
    system("clear||cls");
    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                                                                \n");
    printf("              < < < < < < < Cancelar - Compras > > > > > > >                    \n");
    printf("                                                                                \n");
    printf(" Informe o ID da compra para cancelar: ");
    scanf("%d", &id);
    getchar();
    fp = fopen("compras.dat", "r+b");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        while (fread(new_com, sizeof(Compras), 1, fp) == 1) {
            if(new_com->id_compra == id) {
                printf("\n");
                printf("\t\t\t= = = Compra Encontrada = = =\n");
                printf("\n");

                new_com->status = 'e';

                fseek(fp, -sizeof(Compras), SEEK_CUR);
                fwrite(new_com, sizeof(Compras), 1, fp);
                com_found = 1;
                break;
            }
        }
    }
    if (!com_found) {
        printf("\n");
        printf("\t\t\tID não encontrado!\n");
    } else {
        printf("\n");
        printf("\t\t\tCompra cancelada com sucesso!\n");
    }
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  fclose(fp);
}


char tela_vendas(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < < Vendas > > > > > > > >                         §\n");
    printf("§                                                                             §\n");
    printf("§              1. Cadastro de Vendas                                          §\n");
    printf("§              2. Pesquisar Vendas                                            §\n");
    printf("§              3. Cancelar Vendas                                             §\n");
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

Vendas* tela_cad_ven(void) {
    Vendas* ven;
    char* nome_prod;
    char* nome_rev;
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Cadastro - Vendas > > > > > > >                  \n");
    printf("                                                                             \n");
    printf("              Digite as informações a seguir:                                \n");
    printf("                                                                             \n");

    ven = (Vendas*) malloc(sizeof(Vendas));


    printf("ID do Produto: ");
    scanf("%d", &ven->id);
    getchar();

    nome_prod = get_prod(ven->id);

    printf("Descrição do produto: %s\n", nome_prod);

    ler_cnpj4(ven->cnpj);

    nome_rev = get_rev(ven->cnpj);

    printf("Nome do estabelecimento: %s\n", nome_rev);

    ler_cpf_vend(ven->cpf);

    printf("Quantidade: ");
    scanf("%d", &ven->quant);
    getchar();

    ven->quant = get_est_prod(ven->id, ven->quant);

    ven->valor = get_val_prod(ven->id);

    ven->preco = ven->quant * ven->valor;

    ler_data_prods(ven->data);

    printf("ID da venda: ");
    scanf("%d", &ven->id_venda);
    getchar();

    ven->status = 'c';
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Cadastro concluído!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return ven;
}

Vendas* tela_pes_ven(void) {
    FILE* fp;
    Vendas* ven;
    int id;
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Pesquisa - Vendas > > > > > > >                  \n");
    printf("                                                                             \n");
    printf(" Informe o ID da venda para pesquisa: ");
    scanf("%d", &id);
    getchar();
    printf("\n");
    ven = (Vendas*) malloc(sizeof(Vendas));
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
      printf("\t\t\t>>> Processando as informações...\n");
      sleep(1);
      printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
       printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
      getchar();
    } else {
        while(fread(ven, sizeof(Vendas), 1, fp) == 1) {
          if(ven->id_venda == id) {
            exb_ven(ven);
            printf("\n");
          }
        }
      printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
      getchar();
      fclose(fp);
      return ven;
    }
    fclose(fp);
    return NULL;
}

void tela_exc_ven(void) {
    int id;
    Vendas* new_ven = (Vendas*) malloc(sizeof(Vendas));
    FILE* fp;
    int ven_found = 0;
    system("clear||cls");
    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                                                                \n");
    printf("              < < < < < < < Cancelar - Vendas > > > > > > >                     \n");
    printf("                                                                                \n");
    printf(" Informe o ID da venda para cancelar: ");
    scanf("%d", &id);
    getchar();
    fp = fopen("vendas.dat", "r+b");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando as informações...\n");
        sleep(1);
        printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        while (fread(new_ven, sizeof(Vendas), 1, fp) == 1) {
            if(new_ven->id_venda == id) {
                printf("\n");
                printf("\t\t\t= = = Venda Encontrada = = =\n");
                printf("\n");

                new_ven->status = 'e';

                fseek(fp, -sizeof(Vendas), SEEK_CUR);
                fwrite(new_ven, sizeof(Vendas), 1, fp);
                ven_found = 1;
                break;
            }
        }
    }
    if (!ven_found) {
        printf("\n");
        printf("\t\t\tID não encontrado!\n");
    } else {
        printf("\n");
        printf("\t\t\tVenda cancelada com sucesso!\n");
    }
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  fclose(fp);
}

void ler_cnpj3 (char* cnpj) {
    fflush(stdin);
    printf("Digite o CNPJ da Fornecedora (Apenas Números): ");
    fgets (cnpj, 15, stdin);
    while (!validarCnpj(cnpj)) {
        printf("CNPJ inválido! Digite o CNPJ novamente: ");
        fgets (cnpj, 15, stdin);
    }
    getchar();
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

void ler_cnpj4 (char* cnpj) {
    fflush(stdin);
    printf("Digite o CNPJ da Revendedora (Apenas Números): ");
    fgets (cnpj, 15, stdin);
    while (!validarCnpj(cnpj)) {
        printf("CNPJ inválido! Digite o CNPJ novamente: ");
        fgets (cnpj, 15, stdin);
    }
    getchar();
}

void ler_cpf_vend (char* cpf) {
    fflush(stdin);
    printf("Digite o CPF do Vendedor (Apenas Números): ");
    fgets (cpf, 12, stdin);
    while (!validarCpf (cpf)) {
        printf("CPF inválido! Digite o CPF novamente: ");
        fgets (cpf, 12, stdin);
    }
    getchar();
}

void ler_data_prods(char* data) {
  int dia, mes, ano;
  char dd[3], mm[3], aa[5];
  fflush(stdin);
  printf("Digite a data de venda(dd/mm/aaaa): ");
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
    printf("Data de venda(dd/mm/aaaa): ");
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

void esc_com(Compras* com) {
  FILE* fp;
  fp = fopen("compras.dat", "ab");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  else {
    fwrite(com, sizeof(Compras), 1, fp);
    fclose(fp);
  }
}

void esc_ven(Vendas* ven) {
  FILE* fp;
  fp = fopen("vendas.dat", "ab");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  else {
    fwrite(ven, sizeof(Vendas), 1, fp);
    fclose(fp);
  }
}

void exb_com(Compras* com) {
  if (com == NULL) {
    printf("\n");
    printf("\t\t\tID não encontrado!\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }else{
    printf("\t\t\t= = = Compra Cadastrada = = =\n");
    printf("\n");
    printf("ID da Compra: %d\n", com->id_compra);
    printf("ID da Matéria-Prima: %d\n", com->id);
    printf("CNPJ da Fornecedora: %s\n", com->cnpj);
    printf("Quantidade: %d\n", com->quant);
    printf("Valor da Unidade: R$ %.2f\n", com->valor);
    printf("Data da compra: %s\n", com->data);
  }
}

void exb_ven(Vendas* ven) {
  if (ven == NULL) {
    printf("\n");
    printf("\t\t\tID não encontrado!\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }else{
    printf("\t\t\t= = = Venda Cadastrada = = =\n");
    printf("\n");
    printf("ID da Venda: %d\n", ven->id_venda);
    printf("ID do Produto: %d\n", ven->id);
    printf("CNPJ da Fornecedora: %s\n", ven->cnpj);
    printf("CPF do Vendendor: %s\n", ven->cpf);
    printf("Quantidade: %d\n", ven->quant);
    printf("Valor da Unidade: R$ %.2f\n", ven->valor);
    printf("Data da compra: %s\n", ven->data);
  }
}

char *get_mat(const int id) {
  Materia mat;
  FILE* fp = fopen("mat.dat", "rb");

  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  while (fread(&mat, sizeof(mat), 1, fp) == 1) {
    if(mat.id == id) {
      char* x = (char*)malloc(strlen(mat.mat_prim) + 1);
      if (x == NULL) {
        printf("Ocorreu um erro.\n");
        fclose(fp);
        return NULL;
      }
      strcpy(x, mat.mat_prim);
      fclose(fp);
      return x;
      
    }
  }
  fclose(fp);
  return NULL;
}

char *get_prod(const int id) {
  Produto prod;
  FILE* fp = fopen("prod.dat", "rb");

  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  while (fread(&prod, sizeof(prod), 1, fp) == 1) {
    if(prod.id == id) {
      char* x = (char*)malloc(strlen(prod.prods) + 1);
      if (x == NULL) {
        printf("Ocorreu um erro.\n");
        fclose(fp);
        return NULL;
      }
      strcpy(x, prod.prods);
      fclose(fp);
      return x;
      
    }
  }
  fclose(fp);
  return NULL;
}

void get_est_mat(int id, int quant) {
  Materia* mat;
  FILE* fp = fopen("mat.dat", "r+b");

  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  mat = (Materia*) malloc(sizeof(Materia));
  while (fread(mat, sizeof(Materia), 1, fp) == 1) {
    if (mat->id == id) {
      mat->quant += quant;
      fseek(fp, -sizeof(Materia), SEEK_CUR);
      fwrite(mat, sizeof(Materia), 1, fp);
    }
  }
  fclose(fp);
}

int get_est_prod(int id, int quant) {
  Produto* prod;
  FILE* fp = fopen("prod.dat", "r+b");

  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  prod = (Produto*) malloc(sizeof(Produto));
  while (fread(prod, sizeof(Produto), 1, fp) == 1) {
    if (prod->id == id) {
      if (prod->quant == 0) {
        printf("\n\t\t\tO estoque desse produto está vazio!");
        printf("\n\t\t\tEssa venda não prosseguirá!\n");
        fclose(fp);
        return 0;
      }
      else if (quant > prod->quant) {
        do {
          printf("A quantidade excede a do estoque! Estoque: %d\n", prod-> quant);
          printf("Quantidade: ");
          scanf("%d", &quant);
          getchar();
        }while (quant > prod->quant);
      }
      prod->quant -= quant;
      fseek(fp, -sizeof(Produto), SEEK_CUR);
      fwrite(prod, sizeof(Produto), 1, fp);
    }
  }
  fclose(fp);
  return quant;
}

float get_val_mat(int id) {
  Materia* mat;
  float valor;
  FILE* fp = fopen("mat.dat", "rb");

  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  mat = (Materia*) malloc(sizeof(Materia));
  while (fread(mat, sizeof(Materia), 1, fp) == 1) {
    if (mat->id == id) {
      valor = mat->valor;
      return valor;
    } else {
      return 0;
    }
  }
}

float get_val_prod(int id) {
  Produto* prod;
  float valor;
  FILE* fp = fopen("prod.dat", "rb");

  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  prod = (Produto*) malloc(sizeof(Produto));
  while (fread(prod, sizeof(Produto), 1, fp) == 1) {
    if (prod->id == id) {
      valor = prod->valor;
      return valor;
    } else {
      return 0;
    }
  }
}