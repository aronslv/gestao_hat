#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "rel.h"
#include "rev.h"
#include "func.h"
#include "forn.h"

void modulo_rel(void) {
    char op;
    do{
        op = tela_rel();
        switch (op) {
            case '1':   lista_all_rev();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '2':   lista_all_func();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '3':   lista_all_forn();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
        }
        
    }while (op != '0');
}


char tela_rel(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < < Relatórios > > > > > > > >                     §\n");
    printf("§                                                                             §\n");
    printf("§              1. Listar todas as Revendedoras                                §\n");
    printf("§              2. Listar todos os Funcionários                                §\n");
    printf("§              3. Listar todos os Fornecedores                                §\n");
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

void lista_all_rev(void) {
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
    if (revendedor->status != 'e') {
      printf("%-15s", revendedor->cnpj);
      printf("|");
      printf("%-30s", revendedor->nome_est);
      printf("|");
      printf("%-30s", revendedor->nome_prop);
      printf("\n");
    }
  }
  fclose(fp);
  free(revendedor);
}

void lista_all_func(void) {
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
  printf("%-30s", "Profissão");
  printf("\n");
  printf("%13s", "|");
  printf("%31s", "|");
  printf("\n");
  while (fread(funcionario, sizeof(Funcionario), 1, fp)) { 
    if (funcionario->status != 'e') {
      printf("%-12s", funcionario->cpf);
      printf("|");
      printf("%-30s", funcionario->nome);
      printf("|");
      printf("%-30s", funcionario->prof);
      printf("\n");
    }
  }
  fclose(fp);
  free(funcionario);
}

void lista_all_forn(void) {
  FILE* fp;
  Fornecedor* fornecedor;
  printf("\n = Lista de Fornecedores = \n");
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
    if (fornecedor->status != 'e') {
      printf("%-15s", fornecedor->cnpj);
      printf("|");
      printf("%-30s", fornecedor->nome_est);
      printf("|");
      printf("%-30s", fornecedor->nome_prop);
      printf("\n");
    }
  }
  fclose(fp);
  free(fornecedor);
}