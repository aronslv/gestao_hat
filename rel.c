#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "rel.h"
#include "rev.h"
#include "func.h"
#include "forn.h"
#include "prods.h"
#include "vendas.h"

void modulo_rel(void) {
    char opc;
    char op;
    do{
        opc = tela_rel();
        switch (opc) {
            case '1':
            do {
              op = rel_rev();
              switch(op) {
                case '1':   lista_all_rev();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
                case '2':   lista_ativo_rev();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
                case '3':   lista_inativo_rev();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
              }
            }while (op != '0');
            break;   
            case '2':
            do {
              op = rel_func();
              switch(op) {
                case '1':   lista_all_func();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
                case '2':   lista_ativo_func();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
                case '3':   lista_inativo_func();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
              }
            }while (op != '0');
            break;   
            case '3':   
            do {
              op = rel_forn();
              switch(op) {
                case '1':   lista_all_forn();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
                case '2':   lista_ativo_forn();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
                case '3':   lista_inativo_forn();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
              }
            }while (op != '0');
            break;  
            case '4':   
            do {
              op = rel_mat();
              switch(op) {
                case '1':   lista_all_mat();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
                case '2':   lista_ativo_mat();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
                case '3':   lista_inativo_mat();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
              }
            }while (op != '0');
            break;  
            case '5':   
            do {
              op = rel_prod();
              switch(op) {
                case '1':   lista_all_prods();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
                case '2':   lista_ativo_prods();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
                case '3':   lista_inativo_prods();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
              }
            }while (op != '0');
            break;  
            case '6':   
            do {
              op = rel_com();
              switch(op) {
                case '1':   lista_all_com();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
              }
            }while (op != '0');
            break; 
            case '7':   
            do {
              op = rel_ven();
              switch(op) {
                case '1':   lista_all_ven();
                            printf("\n");
                            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                            getchar();
                            break;
              }
            }while (op != '0');
            break; 
        }
        
    }while (opc != '0');
}


char tela_rel(void) {
    char opc;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < < Relatórios > > > > > > > >                     §\n");
    printf("§                                                                             §\n");
    printf("§              1. Revendedoras                                                §\n");
    printf("§              2. Funcionários                                                §\n");
    printf("§              3. Fornecedoras                                                §\n");
    printf("§              4. Matérias-Primas                                             §\n");
    printf("§              5. Produtos                                                    §\n");
    printf("§              6. Compras                                                     §\n");
    printf("§              7. Vendas                                                      §\n");
    printf("§              0. Retornar ao Menu Principal                                  §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("§              Digite o número da opção desejada: ");
    scanf("%c", &opc);
    getchar();
    return opc;
}

char rel_rev(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§               < < < < < < Relatórios - Revendedoras > > > > > >             §\n");
    printf("§                                                                             §\n");
    printf("§               1. Listar todas as Revendedoras                               §\n");
    printf("§               2. Listar as Revendedoras Ativas                              §\n");
    printf("§               3. Listar as Revendedoras Inativas                            §\n");
    printf("§               0. Retornar ao Menu de Opções                                 §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("§              Digite o número da opção desejada: ");
    scanf("%c", &op);
    getchar();
    return op;
}

char rel_func(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§               < < < < < < Relatórios - Funcionários > > > > > >             §\n");
    printf("§                                                                             §\n");
    printf("§               1. Listar todos os Funcionários                               §\n");
    printf("§               2. Listar os Funcionários Ativos                              §\n");
    printf("§               3. Listar os Funcionários Inativos                            §\n");
    printf("§               0. Retornar ao Menu de Opções                                 §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("§              Digite o número da opção desejada: ");
    scanf("%c", &op);
    getchar();
    return op;
}

char rel_forn(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§               < < < < < < Relatórios - Fornecedoras > > > > > >             §\n");
    printf("§                                                                             §\n");
    printf("§               1. Listar todas as Fornecedoras                               §\n");
    printf("§               2. Listar as Fornecedoras Ativas                              §\n");
    printf("§               3. Listar as Fornecedoras Inativas                            §\n");
    printf("§               0. Retornar ao Menu de Opções                                 §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("§              Digite o número da opção desejada: ");
    scanf("%c", &op);
    getchar();
    return op;
}

char rel_mat(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§               < < < < < < Relatórios - Matérias-Primas > > > > > >          §\n");
    printf("§                                                                             §\n");
    printf("§               1. Listar todas as Matérias-Primas                            §\n");
    printf("§               2. Listar as Matérias-Primas Ativas                           §\n");
    printf("§               3. Listar as Matérias-Primas Inativas                         §\n");
    printf("§               0. Retornar ao Menu de Opções                                 §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("§              Digite o número da opção desejada: ");
    scanf("%c", &op);
    getchar();
    return op;
}

char rel_prod(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§               < < < < < < Relatórios - Produtos > > > > > >                 §\n");
    printf("§                                                                             §\n");
    printf("§               1. Listar todos os Produtos                                   §\n");
    printf("§               2. Listar os Produtos Ativos                                  §\n");
    printf("§               3. Listar os Produtos Inativos                                §\n");
    printf("§               0. Retornar ao Menu de Opções                                 §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("§              Digite o número da opção desejada: ");
    scanf("%c", &op);
    getchar();
    return op;
}

char rel_com(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§               < < < < < < Relatórios - Compras > > > > > >                  §\n");
    printf("§                                                                             §\n");
    printf("§               1. Listar todas as Compras                                    §\n");
    printf("§               0. Retornar ao Menu de Opções                                 §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("§              Digite o número da opção desejada: ");
    scanf("%c", &op);
    getchar();
    return op;
}

char rel_ven(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§               < < < < < < Relatórios - Vendas > > > > > >                   §\n");
    printf("§                                                                             §\n");
    printf("§               1. Listar todas as Vendas                                     §\n");
    printf("§               0. Retornar ao Menu de Opções                                 §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("§              Digite o número da opção desejada: ");
    scanf("%c", &op);
    getchar();
    return op;
}

void lista_all_rev(void) {
  system("clear||cls");
  FILE* fp;
  Revendedor* revendedor;
  printf("\n = Lista de Revendedoras = \n");
  printf("\n");
  revendedor = (Revendedor*) malloc(sizeof(Revendedor));
  fp = fopen("rev.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-15s", "CNPJ");
  printf("|");
  printf("%-30s", "Nome do Estabelecimento");
  printf("|");
  printf("%-30s", "Nome do Proprietário");
  printf("\n");
  printf("%16s", "|");
  printf("%31s", "|");
  printf("\n");
  while (fread(revendedor, sizeof(Revendedor), 1, fp)) { 
    printf("%-15s", revendedor->cnpj);
    printf("|");
    printf("%-30s", revendedor->nome_est);
    printf("|");
    printf("%-30s", revendedor->nome_prop);
    printf("\n");

  }
  fclose(fp);
  free(revendedor);
}

void lista_ativo_rev(void) {
  system("clear||cls");
  FILE* fp;
  Revendedor* revendedor;
  printf("\n = Lista de Revendedoras Ativas = \n");
  printf("\n");
  revendedor = (Revendedor*) malloc(sizeof(Revendedor));
  fp = fopen("rev.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-15s", "CNPJ");
  printf("|");
  printf("%-30s", "Nome do Estabelecimento");
  printf("|");
  printf("%-31s", "Nome do Proprietário");
  printf("|");
  printf("%-8s", "Status");
  printf("\n");
  printf("%16s", "|");
  printf("%31s", "|");
  printf("%31s", "|");
  printf("\n");
  while (fread(revendedor, sizeof(Revendedor), 1, fp)) { 
    if (revendedor->status != 'e') {
      printf("%-15s", revendedor->cnpj);
      printf("|");
      printf("%-30s", revendedor->nome_est);
      printf("|");
      printf("%-30s", revendedor->nome_prop);
      printf("|");
      printf("%-7s", "Ativo");
      printf("\n");
    }
  }
  fclose(fp);
  free(revendedor);
}

void lista_inativo_rev(void) {
  system("clear||cls");
  FILE* fp;
  Revendedor* revendedor;
  printf("\n = Lista de Revendedoras Inativas = \n");
  printf("\n");
  revendedor = (Revendedor*) malloc(sizeof(Revendedor));
  fp = fopen("rev.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-15s", "CNPJ");
  printf("|");
  printf("%-30s", "Nome do Estabelecimento");
  printf("|");
  printf("%-31s", "Nome do Proprietário");
  printf("|");
  printf("%-8s", "Status");
  printf("\n");
  printf("%16s", "|");
  printf("%31s", "|");
  printf("%31s", "|");
  printf("\n");
  while (fread(revendedor, sizeof(Revendedor), 1, fp)) { 
    if (revendedor->status == 'e') {
      printf("%-15s", revendedor->cnpj);
      printf("|");
      printf("%-30s", revendedor->nome_est);
      printf("|");
      printf("%-30s", revendedor->nome_prop);
      printf("|");
      printf("%-9s", "Inativo");
      printf("\n");
    }
  }
  fclose(fp);
  free(revendedor);
}

void lista_all_func(void) {
  system("clear||cls");
  FILE* fp;
  Funcionario* funcionario;
  printf("\n = Lista de Funcionários = \n");
  printf("\n");
  funcionario = (Funcionario*) malloc(sizeof(Funcionario));
  fp = fopen("func.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-12s", "CPF");
  printf("|");
  printf("%-31s", "Nome do Funcionário");
  printf("|");
  printf("%-10s", "Salário");
  printf("\n");
  printf("%13s", "|");
  printf("%31s", "|");
  printf("\n");
  while (fread(funcionario, sizeof(Funcionario), 1, fp)) { 
    printf("%-12s", funcionario->cpf);
    printf("|");
    printf("%-30s", funcionario->nome);
    printf("|");
    printf("R$ %-10.2f", funcionario->salario);
    printf("\n");
  }
  fclose(fp);
  free(funcionario);
}

void lista_ativo_func(void) {
  system("clear||cls");
  FILE* fp;
  Funcionario* funcionario;
  printf("\n = Lista de Funcionários Ativos = \n");
  printf("\n");
  funcionario = (Funcionario*) malloc(sizeof(Funcionario));
  fp = fopen("func.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-12s", "CPF");
  printf("|");
  printf("%-31s", "Nome do Funcionário");
  printf("|");
  printf("%-16s", "Salário");
  printf("|");
  printf("%-8s", "Status");
  printf("\n");
  printf("%13s", "|");
  printf("%31s", "|");
  printf("%16s", "|");
  printf("\n");
  while (fread(funcionario, sizeof(Funcionario), 1, fp)) { 
    if (funcionario->status != 'e') {
      printf("%-12s", funcionario->cpf);
      printf("|");
      printf("%-30s", funcionario->nome);
      printf("|");
      printf("R$ %-12.2f", funcionario->salario);
      printf("|");
      printf("%-7s", "Ativo");
      printf("\n");
    }
  }
  fclose(fp);
  free(funcionario);
}

void lista_inativo_func(void) {
  system("clear||cls");
  FILE* fp;
  Funcionario* funcionario;
  printf("\n = Lista de Funcionários Inativos = \n");
  printf("\n");
  funcionario = (Funcionario*) malloc(sizeof(Funcionario));
  fp = fopen("func.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-12s", "CPF");
  printf("|");
  printf("%-31s", "Nome do Funcionário");
  printf("|");
  printf("%-16s", "Salário");
  printf("|");
  printf("%-8s", "Status");
  printf("\n");
  printf("%13s", "|");
  printf("%31s", "|");
  printf("%16s", "|");
  printf("\n");
  while (fread(funcionario, sizeof(Funcionario), 1, fp)) { 
    if (funcionario->status == 'e') {
      printf("%-12s", funcionario->cpf);
      printf("|");
      printf("%-30s", funcionario->nome);
      printf("|");
      printf("R$ %-12.2f", funcionario->salario);
      printf("|");
      printf("%-9s", "Inativo");
      printf("\n");
    }
  }
  fclose(fp);
  free(funcionario);
}

void lista_all_forn(void) {
  system("clear||cls");
  FILE* fp;
  Fornecedor* fornecedor;
  printf("\n = Lista de Fornecedoras = \n");
  printf("\n");
  fornecedor = (Fornecedor*) malloc(sizeof(Fornecedor));
  fp = fopen("forn.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-15s", "CNPJ");
  printf("|");
  printf("%-30s", "Nome do Estabelecimento");
  printf("|");
  printf("%-30s", "Nome do Proprietário");
  printf("\n");
  printf("%16s", "|");
  printf("%31s", "|");
  printf("\n");
  while (fread(fornecedor, sizeof(Fornecedor), 1, fp)) { 
    printf("%-15s", fornecedor->cnpj);
    printf("|");
    printf("%-30s", fornecedor->nome_est);
    printf("|");
    printf("%-30s", fornecedor->nome_prop);
    printf("\n");
  }
  fclose(fp);
  free(fornecedor);
}

void lista_ativo_forn(void) {
  system("clear||cls");
  FILE* fp;
  Fornecedor* fornecedor;
  printf("\n = Lista de Fornecedoras Ativas = \n");
  printf("\n");
  fornecedor = (Fornecedor*) malloc(sizeof(Fornecedor));
  fp = fopen("forn.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-15s", "CNPJ");
  printf("|");
  printf("%-30s", "Nome do Estabelecimento");
  printf("|");
  printf("%-31s", "Nome do Proprietário");
  printf("|");
  printf("%-8s", "Status");
  printf("\n");
  printf("%16s", "|");
  printf("%31s", "|");
  printf("%31s", "|");
  printf("\n");
  while (fread(fornecedor, sizeof(Fornecedor), 1, fp)) { 
    if (fornecedor->status != 'e') {
      printf("%-15s", fornecedor->cnpj);
      printf("|");
      printf("%-30s", fornecedor->nome_est);
      printf("|");
      printf("%-30s", fornecedor->nome_prop);
      printf("|");
      printf("%-7s", "Ativo");
      printf("\n");
    }
  }
  fclose(fp);
  free(fornecedor);
}

void lista_inativo_forn(void) {
  system("clear||cls");
  FILE* fp;
  Fornecedor* fornecedor;
  printf("\n = Lista de Fornecedoras Inativas = \n");
  printf("\n");
  fornecedor = (Fornecedor*) malloc(sizeof(Fornecedor));
  fp = fopen("forn.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-15s", "CNPJ");
  printf("|");
  printf("%-30s", "Nome do Estabelecimento");
  printf("|");
  printf("%-31s", "Nome do Proprietário");
  printf("|");
  printf("%-8s", "Status");
  printf("\n");
  printf("%16s", "|");
  printf("%31s", "|");
  printf("%31s", "|");
  printf("\n");
  while (fread(fornecedor, sizeof(Fornecedor), 1, fp)) { 
    if (fornecedor->status == 'e') {
      printf("%-15s", fornecedor->cnpj);
      printf("|");
      printf("%-30s", fornecedor->nome_est);
      printf("|");
      printf("%-30s", fornecedor->nome_prop);
      printf("|");
      printf("%-9s", "Inativo");
      printf("\n");
    }
  }
  fclose(fp);
  free(fornecedor);
}

void lista_all_mat(void) {
  system("clear||cls");
  FILE* fp;
  Materia* mat;
  printf("\n = Lista de Matérias-Primas = \n");
  printf("\n");
  mat = (Materia*) malloc(sizeof(Materia));
  fp = fopen("mat.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-7s", "ID");
  printf("|");
  printf("%-33s", "Descrição da Matéria-Prima");
  printf("|");
  printf("%-18s", "Valor da Unidade");
  printf("\n");
  printf("%8s", "|");
  printf("%31s", "|");
  printf("\n");
  while (fread(mat, sizeof(Materia), 1, fp)) { 
    printf("%-7d", mat->id);
    printf("|");
    printf("%-30s", mat->mat_prim);
    printf("|");
    printf("R$ %-10.2f", mat->valor);
    printf("\n");
  }
  fclose(fp);
  free(mat);
}

void lista_ativo_mat(void) {
  system("clear||cls");
  FILE* fp;
  Materia* mat;
  printf("\n = Lista de Matérias-Primas Ativas = \n");
  printf("\n");
  mat = (Materia*) malloc(sizeof(Materia));
  fp = fopen("mat.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-7s", "ID");
  printf("|");
  printf("%-33s", "Descrição da Matéria-Prima");
  printf("|");
  printf("%-18s", "Valor da Unidade");
  printf("|");
  printf("%-8s", "Status");
  printf("\n");
  printf("%8s", "|");
  printf("%31s", "|");
  printf("%19s", "|");
  printf("\n");
  while (fread(mat, sizeof(Materia), 1, fp)) { 
    if (mat->status != 'e') {
      printf("%-7d", mat->id);
      printf("|");
      printf("%-30s", mat->mat_prim);
      printf("|");
      printf("R$ %-15.2f", mat->valor);
      printf("|");
      printf("%-7s", "Ativo");
      printf("\n");
    }
  }
  fclose(fp);
  free(mat);
}

void lista_inativo_mat(void) {
  system("clear||cls");
  FILE* fp;
  Materia* mat;
  printf("\n = Lista de Matérias-Primas Inativas = \n");
  printf("\n");
  mat = (Materia*) malloc(sizeof(Materia));
  fp = fopen("mat.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-7s", "ID");
  printf("|");
  printf("%-33s", "Descrição da Matéria-Prima");
  printf("|");
  printf("%-18s", "Valor da Unidade");
  printf("|");
  printf("%-8s", "Status");
  printf("\n");
  printf("%8s", "|");
  printf("%31s", "|");
  printf("%19s", "|");
  printf("\n");
  while (fread(mat, sizeof(Materia), 1, fp)) { 
    if (mat->status == 'e') {
      printf("%-7d", mat->id);
      printf("|");
      printf("%-30s", mat->mat_prim);
      printf("|");
      printf("R$ %-15.2f", mat->valor);
      printf("|");
      printf("%-9s", "Inativo");
      printf("\n");
    }
  }
  fclose(fp);
  free(mat);
}

void lista_all_prods(void) {
  system("clear||cls");
  FILE* fp;
  Produto* prod;
  printf("\n = Lista de Produtos = \n");
  printf("\n");
  prod = (Produto*) malloc(sizeof(Produto));
  fp = fopen("prod.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-8s", "ID");
  printf("|");
  printf("%-32s", "Descrição do Produto");
  printf("|");
  printf("%-18s", "Valor da Unidade");
  printf("\n");
  printf("%9s", "|");
  printf("%31s", "|");
  printf("\n");
  while (fread(prod, sizeof(Produto), 1, fp)) { 
    printf("%-8d", prod->id);
    printf("|");
    printf("%-30s", prod->prods);
    printf("|");
    printf("R$ %-10.2f", prod->valor);
    printf("\n"); 
  }
  fclose(fp);
  free(prod);
}

void lista_ativo_prods(void) {
  system("clear||cls");
  FILE* fp;
  Produto* prod;
  printf("\n = Lista de Produtos Ativos = \n");
  printf("\n");
  prod = (Produto*) malloc(sizeof(Produto));
  fp = fopen("prod.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-8s", "ID");
  printf("|");
  printf("%-32s", "Descrição do Produto");
  printf("|");
  printf("%-18s", "Valor da Unidade");
  printf("|");
  printf("%-8s", "Status");
  printf("\n");
  printf("%9s", "|");
  printf("%31s", "|");
  printf("%19s", "|");
  printf("\n");
  while (fread(prod, sizeof(Produto), 1, fp)) { 
    if (prod->status != 'e') {
      printf("%-8d", prod->id);
      printf("|");
      printf("%-30s", prod->prods);
      printf("|");
      printf("R$ %-15.2f", prod->valor);
      printf("|");
      printf("%-7s", "Ativo");
      printf("\n");
    }
  }
  fclose(fp);
  free(prod);
}

void lista_inativo_prods(void) {
  system("clear||cls");
  FILE* fp;
  Produto* prod;
  printf("\n = Lista de Produtos Inativos = \n");
  printf("\n");
  prod = (Produto*) malloc(sizeof(Produto));
  fp = fopen("prod.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-8s", "ID");
  printf("|");
  printf("%-32s", "Descrição do Produto");
  printf("|");
  printf("%-18s", "Valor da Unidade");
  printf("|");
  printf("%-8s", "Status");
  printf("\n");
  printf("%9s", "|");
  printf("%31s", "|");
  printf("%19s", "|");
  printf("\n");
  while (fread(prod, sizeof(Produto), 1, fp)) { 
    if (prod->status == 'e') {
      printf("%-8d", prod->id);
      printf("|");
      printf("%-30s", prod->prods);
      printf("|");
      printf("R$ %-15.2f", prod->valor);
      printf("|");
      printf("%-9s", "Inativo");
      printf("\n");
    }
  }
  fclose(fp);
  free(prod);
}

void lista_all_com(void) {
  system("clear||cls");
  FILE* fp;
  Compras* com;
  printf("\n = Lista de Compras = \n");
  printf("\n");
  com = (Compras*) malloc(sizeof(Compras));
  fp = fopen("compras.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-14s", "ID da Compra");
  printf("|");
  printf("%-23s", "ID da Matéria-Prima");
  printf("|");
  printf("%-15s", "CNPJ");
  printf("|");
  printf("%-13s", "Valor Total");
  printf("|");
  printf("%-16s", "Data da Compra");
  printf("\n");
  printf("%15s", "|");
  printf("%23s", "|");
  printf("%16s", "|");
  printf("%14s", "|");
  printf("\n");
  while (fread(com, sizeof(Compras), 1, fp)) { 
    printf("%-14d", com->id_compra);
    printf("|");
    printf("%-22d", com->id);
    printf("|");
    printf("%-15s", com->cnpj);
    printf("|");
    printf("R$ %-10.2f", com->preco);
    printf("|");
    printf("%-12s", com->data);
    printf("\n");
    
  }
  fclose(fp);
  free(com);
}

void lista_all_ven(void) {
  system("clear||cls");
  FILE* fp;
  Vendas* ven;
  printf("\n = Lista de Vendas = \n");
  printf("\n");
  ven = (Vendas*) malloc(sizeof(Vendas));
  fp = fopen("vendas.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  printf("%-14s", "ID da Venda");
  printf("|");
  printf("%-15s", "ID do Produto");
  printf("|");
  printf("%-15s", "CNPJ");
  printf("|");
  printf("%-17s", "CPF do Vendedor");
  printf("|");
  printf("%-13s", "Valor Total");
  printf("|");
  printf("%-16s", "Data da Venda");
  printf("\n");
  printf("%15s", "|");
  printf("%16s", "|");
  printf("%16s", "|");
  printf("%18s", "|");
  printf("%14s", "|");
  printf("\n");
  while (fread(ven, sizeof(Vendas), 1, fp)) { 
    printf("%-14d", ven->id_venda);
    printf("|");
    printf("%-15d", ven->id);
    printf("|");
    printf("%-15s", ven->cnpj);
    printf("|");
    printf("%-17s", ven->cpf);
    printf("|");
    printf("R$ %-10.2f", ven->preco);
    printf("|");
    printf("%-12s", ven->data);
    printf("\n");
    
  }
  fclose(fp);
  free(ven);
}