#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "forn.h"
#include "valid.h"

void ler_cnpj1(char*);
void ler_nome1(char*);
void ler_nome2(char*);
void ler_nome3(char*);
void ler_cel1(char*);

// função do módulo de fornecedores

void modulo_forn(void) {
    Fornecedor* forn_x;
    char op;
    do{
        op = tela_fornecedoras();
        switch (op) {
            case '1':   forn_x = tela_cad_forn();
                        esc_forn(forn_x);
                        free(forn_x);
                        break;
            case '2':   forn_x = tela_pes_forn();
                        exb_forn(forn_x);
                        free(forn_x);
                        break;
            case '3':   tela_edit_forn();
                        break;
            case '4':   tela_exc_forn();
                        break;
        }

    }while (op != '0');
}

char tela_fornecedoras(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < < Fornecedoras > > > > > > > >                   §\n");
    printf("§                                                                             §\n");
    printf("§              1. Cadastro de Fornecedoras                                    §\n");
    printf("§              2. Pesquisar Fornecedoras                                      §\n");
    printf("§              3. Editar Dados de Fornecedoras                                §\n");
    printf("§              4. Excluir uma Fornecedora do Sistema                          §\n");
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

Fornecedor* tela_cad_forn(void) {
  Fornecedor* forn;

  system("clear||cls");
  printf("\n");
  printf("-----------------------------------------------------------------------------\n");
  printf("                                                                             \n");
  printf("              < < < < < < < Cadastro - Fornecedoras > > > > > > >            \n");
  printf("                                                                             \n");
  printf("              Digite as informações a seguir:                                \n");
  printf("                                                                             \n");

  forn = (Fornecedor*) malloc(sizeof(Fornecedor));
    
  ler_cnpj1(forn->cnpj);

  ler_nome1(forn->nome_est);

  ler_nome3(forn->end);

  ler_nome2(forn->nome_prop);

  ler_cel1(forn->cel);

  forn->status = 'c';
  printf("                                                                             \n");
  printf("                                                                             \n");
  printf("-----------------------------------------------------------------------------\n");
  printf("\n");
  printf("\t\t\t>>> Processando as informações...\n");
  sleep(1);
  printf("\t\t\t>>> Cadastro concluído!\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  return forn;
}

Fornecedor* tela_pes_forn(void) {
  FILE* fp;
  Fornecedor* forn;
  char cnpj[15];
  system("clear||cls");
  printf("\n");
  printf("-----------------------------------------------------------------------------\n");
  printf("                                                                             \n");
  printf("              < < < < < < < Pesquisa - Fornecedoras > > > > > > >            \n");
  printf("                                                                             \n");
  printf("Informe o CNPJ que deseja pesquisar: ");
  fgets (cnpj, 15, stdin);
  getchar();
  forn = (Fornecedor*) malloc(sizeof(Fornecedor));
  fp = fopen("forn.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  } else {
      while(!feof(fp)) {
        fread(forn, sizeof(Fornecedor), 1, fp);
        if((strcmp(forn->cnpj, cnpj) == 0) && (forn->status != 'e')) {
          exb_forn(forn);
          printf("\n");
          printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
          getchar();
          fclose(fp);
          return forn;
        }
      }
    }
  fclose(fp);
  return NULL;
}

void tela_edit_forn(void) {
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Edição - Fornecedoras > > > > > > >              \n");
    printf("                                                                             \n");
    printf("              Informe o CNPJ para edição de dados:                           \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_exc_forn(void) {
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Exclusão - Fornecedoras > > > > > > >            \n");
    printf("                                                                             \n");
    printf("              Informe o CNPJ para excluir do sistema:                        \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void ler_cnpj1 (char* cnpj) {
    fflush(stdin);
    printf("Digite o CNPJ (Apenas Números): ");
    fgets (cnpj, 15, stdin);
    while (!validarCnpj(cnpj)) {
        printf("CNPJ inválido! Digite o CNPJ novamente: ");
        fgets (cnpj, 15, stdin);
    }
    getchar();
}

void ler_nome1(char* nome_est) {
  fflush(stdin);
  printf("Nome do estabelecimento: ");
  fgets(nome_est, 50, stdin); 
  // Remove o caractere de nova linha do final, se estiver presente
  int tam = strlen(nome_est);
  if (tam > 0 && nome_est[tam - 1] == '\n') {
    nome_est[tam - 1] = '\0';
    fflush(stdin);
  }
  while (!validarNome(nome_est)) {
    printf("Nome inválido: %s\n", nome_est);
    printf("Informe um novo nome de estabelecimento: ");
    fflush(stdin);
    fgets(nome_est, 50, stdin); 
    // Remove o caractere de nova linha do final, se estiver presente
    tam = strlen(nome_est);
    if (tam > 0 && nome_est[tam - 1] == '\n') {
      nome_est[tam - 1] = '\0';
      fflush(stdin);
    }
  } 
}

void ler_nome2(char* nome_prop) {
  fflush(stdin);
  printf("Nome do proprietário: ");
  fgets(nome_prop, 50, stdin); 
  // Remove o caractere de nova linha do final, se estiver presente
  int tam = strlen(nome_prop);
  if (tam > 0 && nome_prop[tam - 1] == '\n') {
    nome_prop[tam - 1] = '\0';
    fflush(stdin);
  }
  while (!validarNome(nome_prop)) {
    printf("Nome inválido: %s\n", nome_prop);
    printf("Informe um novo nome: ");
    fflush(stdin);
    fgets(nome_prop, 50, stdin); 
    // Remove o caractere de nova linha do final, se estiver presente
    tam = strlen(nome_prop);
    if (tam > 0 && nome_prop[tam - 1] == '\n') {
      nome_prop[tam - 1] = '\0';
      fflush(stdin);
    }
  } 
}

void ler_nome3(char* end) {
  fflush(stdin);
  printf("Endereço do estabelecimento: ");
  fgets(end, 50, stdin); 
  // Remove o caractere de nova linha do final, se estiver presente
  int tam = strlen(end);
  if (tam > 0 && end[tam - 1] == '\n') {
    end[tam - 1] = '\0';
    fflush(stdin);
  }
  while (!validarNome(end)) {
    printf("Endereço inválido: %s\n", end);
    printf("Informe um novo endereço de estabelecimento: ");
    fflush(stdin);
    fgets(end, 50, stdin); 
    // Remove o caractere de nova linha do final, se estiver presente
    tam = strlen(end);
    if (tam > 0 && end[tam - 1] == '\n') {
      end[tam - 1] = '\0';
      fflush(stdin);
    }
  } 
}

void ler_cel1 (char* cel) {
    fflush (stdin);
    printf("Digite o Telefone (Apenas Números): ");
    fgets (cel, 12, stdin);

    while (!validarFone (cel)) {
        printf("Telefone inválido! Digite novamente: ");
        fgets (cel, 12, stdin);
    
    }
    getchar();
}

void esc_forn(Fornecedor* forn) {
  FILE* fp;
  fp = fopen("forn.dat", "ab");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  else {
    fwrite(forn, sizeof(Fornecedor), 1, fp);
    fclose(fp);
  }
}

void exb_forn(Fornecedor* forn) {
  if ((forn == NULL) || (forn->status == 'e')) {
    printf("\n");
    printf("\t\t\tCNPJ não encontrado!\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }else{
    char sit[20];
    printf("\n= = = Revendedora Cadastrada = = =\n");
    printf("\n");
    printf("CNPJ: %s\n", forn->cnpj);
    printf("Nome do estabelecimento: %s\n", forn->nome_est);
    printf("Endereço: %s\n", forn->end);
    printf("Nome do proprietário: %s\n", forn->nome_prop);
    printf("Telefone: %s\n", forn->cel);
    if (forn->status == 'c') {
      strcpy(sit, "Cadastrado");
    } else {
      strcpy(sit, "Não Informado");
    }
    printf("Situação da Revendedora: %s\n", sit);
    printf("\n");
  }
}