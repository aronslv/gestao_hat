#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "func.h"
#include "valid.h"

void ler_cpf(char*);
void ler_nome(char*);
void ler_data(char*);
void ler_cel(char*);

// função do módulo de funcionários

void modulo_func(void) {
    char op;
    do{
        op = tela_funcionarios();
        switch (op) {
            case '1':   tela_cad_func();
                        break;
            case '2':   tela_pes_func();
                        break;
            case '3':   tela_edit_func();
                        break;
            case '4':   tela_exc_func();
                        break;
        }

    }while (op != '0');
}

char tela_funcionarios(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < < Funcionários > > > > > > > >                   §\n");
    printf("§                                                                             §\n");
    printf("§              1. Cadastro de Funcionários                                    §\n");
    printf("§              2. Pesquisar Funcionários                                      §\n");
    printf("§              3. Editar Dados de Funcionários                                §\n");
    printf("§              4. Excluir um Funcionário do Sistema                           §\n");
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

void tela_cad_func(void) {
    char nome[50];
    char cpf[12];
    char prof[25];
    char cel[12];

    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Cadastro - Funcionários > > > > > > >            \n");
    printf("                                                                             \n");
    printf("              Digite as informações a seguir:                                \n");
    printf("                                                                             \n");
    ler_nome(nome);

    ler_cpf(cpf);

    ler_prof(prof);

    ler_cel(cel);
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

void tela_pes_func(void) {
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Pesquisa - Funcionários > > > > > > >            \n");
    printf("                                                                             \n");
    printf("              Informe o CPF que deseja pesquisar:                            \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_edit_func(void) {
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Edição - Funcionários > > > > > > >              \n");
    printf("                                                                             \n");
    printf("              Informe o CPF para edição de dados:                            \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_exc_func(void) {
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Exclusão - Funcionários > > > > > > >            \n");
    printf("                                                                             \n");
    printf("              Informe o CPF para excluir do sistema:                         \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

// Função inspirada no código do Prof. Flavius

void ler_nome(char* nome) {
  fflush(stdin);
  printf("Nome completo: ");
  fgets(nome, 50, stdin); 
  // Remove o caractere de nova linha do final, se estiver presente
  int tam = strlen(nome);
  if (tam > 0 && nome[tam - 1] == '\n') {
    nome[tam - 1] = '\0';
    fflush(stdin);
  }
  while (!validarNome(nome)) {
    printf("Nome inválido: %s\n", nome);
    printf("Informe um novo nome: ");
    fflush(stdin);
    fgets(nome, 50, stdin); 
    // Remove o caractere de nova linha do final, se estiver presente
    tam = strlen(nome);
    if (tam > 0 && nome[tam - 1] == '\n') {
      nome[tam - 1] = '\0';
      fflush(stdin);
    }
  } 
}

// Função inspirada no código do Prof. Flavius

void ler_cpf (char* cpf) {
    fflush(stdin);
    printf("Digite o CPF (Apenas Números): ");
    fgets (cpf, 12, stdin);
    while (!validarCpf (cpf)) {
        printf("Erro! Digite novamente: ");
        fgets (cpf, 12, stdin);
    }
    getchar();
}

void ler_prof(char* prof) {
  fflush(stdin);
  printf("Profissão: ");
  fgets(prof, 50, stdin); 
  // Remove o caractere de nova linha do final, se estiver presente
  int tam = strlen(prof);
  if (tam > 0 && prof[tam - 1] == '\n') {
    prof[tam - 1] = '\0';
    fflush(stdin);
  }
  while (!validarNome(prof)) {
    printf("Escrita inválida: %s\n", prof);
    printf("Informe a profissão novamente: ");
    fflush(stdin);
    fgets(prof, 50, stdin); 
    // Remove o caractere de nova linha do final, se estiver presente
    tam = strlen(prof);
    if (tam > 0 && prof[tam - 1] == '\n') {
      prof[tam - 1] = '\0';
      fflush(stdin);
    }
  } 
}

void ler_cel (char* cel) {
    fflush (stdin);
    printf("Digite o Telefone (Apenas Números): ");
    fgets (cel, 12, stdin);

    while (!validarFone (cel)) {
        printf("Erro! Digite novamente: ");
        fgets (cel, 12, stdin);
    
    }
} 
