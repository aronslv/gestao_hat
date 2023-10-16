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
    char op;
    do{
        op = tela_fornecedoras();
        switch (op) {
            case '1':   tela_cad_forn();
                        break;
            case '2':   tela_pes_forn();
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

void tela_cad_forn(void) {
    Fornecedor* fornecedor;

    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Cadastro - Fornecedoras > > > > > > >            \n");
    printf("                                                                             \n");
    printf("              Digite as informações a seguir:                                \n");
    printf("                                                                             \n");

    fornecedor = (Fornecedor*) malloc(sizeof(Fornecedor));
    
    ler_cnpj1(fornecedor->cnpj);

    ler_nome1(fornecedor->nome_est);

    ler_nome3(fornecedor->end);

    ler_nome2(fornecedor->nome_prop);

    ler_cel1(fornecedor->cel);
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

void tela_pes_forn(void) {
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Pesquisa - Fornecedoras > > > > > > >            \n");
    printf("                                                                             \n");
    printf("              Informe o CNPJ que deseja pesquisar:                           \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
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