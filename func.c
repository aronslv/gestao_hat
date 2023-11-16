#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "func.h"
#include "valid.h"

void ler_cpf(char*);
void ler_nome(char*);
void ler_prof(char*);
void ler_cel2(char*);

// função do módulo de funcionários

void modulo_func(void) {
    Funcionario* func_x;
    char op;
    do{
        op = tela_funcionarios();
        switch (op) {
            case '1':   func_x = tela_cad_func();
                        esc_func(func_x);
                        free(func_x);
                        break;
            case '2':   func_x = tela_pes_func();
                        exb_func(func_x);
                        free(func_x);
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

Funcionario* tela_cad_func(void) {
    Funcionario* func;

    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Cadastro - Funcionários > > > > > > >            \n");
    printf("                                                                             \n");
    printf("              Digite as informações a seguir:                                \n");
    printf("                                                                             \n");

    func = (Funcionario*) malloc(sizeof(Funcionario));
    
    ler_nome(func->nome);

    ler_cpf(func->cpf);

    printf("Salário: R$ ");
    scanf("%f", &func->salario);
    getchar();

    ler_prof(func->prof);

    ler_cel2(func->cel);

    func->status = 'c';
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Cadastro concluído!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return func;
}

Funcionario* tela_pes_func(void) {
  FILE* fp;
  Funcionario* func;
  char cpf[12];
  system("clear||cls");
  printf("\n");
  printf("-----------------------------------------------------------------------------\n");
  printf("                                                                             \n");
  printf("              < < < < < < < Pesquisa - Funcionários > > > > > > >            \n");
  printf("                                                                             \n");
  printf("Informe o CPF que deseja pesquisar: ");
  fgets (cpf, 12, stdin);
  getchar();
  printf("\n");
  func = (Funcionario*) malloc(sizeof(Funcionario));
  fp = fopen("func.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  } else {
      while(!feof(fp)) {
        fread(func, sizeof(Funcionario), 1, fp);
        if((strcmp(func->cpf, cpf) == 0) && (func->status != 'e')) {
          exb_func(func);
          printf("\n");
          printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
          getchar();
          fclose(fp);
          return func;
        }
      }
    }
  fclose(fp);
  return NULL;
}

void tela_edit_func(void) {
  char cpf[12];
  Funcionario* new_func = (Funcionario*) malloc(sizeof(Funcionario));
  FILE* fp;
  int func_found = 0;
  system("clear||cls");
  printf("\n");
  printf("-----------------------------------------------------------------------------\n");
  printf("                                                                             \n");
  printf("              < < < < < < < Edição - Funcionários > > > > > > >              \n");
  printf("                                                                             \n");
  printf("Informe o CPF para edição de dados: ");
  fgets (cpf, 12, stdin);
  getchar();
  fp = fopen("func.dat", "r+b");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  } else {
    while (fread(new_func, sizeof(Funcionario), 1, fp) == 1) {
      if(strcmp(new_func->cpf, cpf) == 0) {
        printf("\n");
        printf("\t\t\t= = = Funcionário Encontrado = = =\n");
        printf("\n");

        ler_nome(new_func->nome);

        ler_cpf(new_func->cpf);

        printf("Salário: R$ ");
        scanf("%f", &new_func->salario);
        getchar();

        ler_prof(new_func->prof);

        ler_cel2(new_func->cel);

        new_func->status = 'c';

        fseek(fp, -sizeof(Funcionario), SEEK_CUR);
        fwrite(new_func, sizeof(Funcionario), 1, fp);
        func_found = 1;
        break;
      }
    }
  }
  if (!func_found) {
        printf("\n");
        printf("\t\t\tCPF não encontrado!\n");
    } else {
        printf("\n");
        printf("\t\t\tFuncionário atualizado com sucesso!\n");
    }
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  fclose(fp);
}

void tela_exc_func(void) {
  char cpf[12];
  Funcionario* new_func = (Funcionario*) malloc(sizeof(Funcionario));
  FILE* fp;
  int func_found = 0;
  system("clear||cls");
  printf("\n");
  printf("-----------------------------------------------------------------------------\n");
  printf("                                                                             \n");
  printf("              < < < < < < < Exclusão - Funcionários > > > > > > >            \n");
  printf("                                                                             \n");
  printf("Informe o CPF para excluir do sistema: ");
  fgets (cpf, 12, stdin);
  getchar();
  fp = fopen("func.dat", "r+b");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  } else {
    while (fread(new_func, sizeof(Funcionario), 1, fp) == 1) {
      if(strcmp(new_func->cpf, cpf) == 0) {
        printf("\n");
        printf("\t\t\t= = = Funcionário Encontrado = = =\n");
        printf("\n");

        new_func->status = 'e';

        fseek(fp, -sizeof(Funcionario), SEEK_CUR);
        fwrite(new_func, sizeof(Funcionario), 1, fp);
        func_found = 1;
        break;
      }
    }
  }
  if (!func_found) {
        printf("\n");
        printf("\t\t\tCPF não encontrado!\n");
    } else {
        printf("\n");
        printf("\t\t\tFuncionário excluído com sucesso!\n");
    }
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  fclose(fp);
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
        printf("CPF inválido! Digite o CPF novamente: ");
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

void ler_cel2 (char* cel) {
    fflush (stdin);
    printf("Digite o Telefone (Apenas Números): ");
    fgets (cel, 12, stdin);

    while (!validarFone (cel)) {
        printf("Telefone inválido! Digite novamente: ");
        fgets (cel, 12, stdin);
    
    }
    getchar();
} 

void esc_func(Funcionario* func) {
  FILE* fp;
  fp = fopen("func.dat", "ab");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  else {
    fwrite(func, sizeof(Funcionario), 1, fp);
    fclose(fp);
  }
}

void exb_func(Funcionario* func) {
  if ((func == NULL) || (func->status == 'e')) {
    printf("\n");
    printf("\t\t\tCPF não encontrado!\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }else{
    char sit[20];
    printf("\t\t\t= = = Funcionário Cadastrado = = =\n");
    printf("\n");
    printf("CPF: %s\n", func->cpf);
    printf("Nome completo: %s\n", func->nome);
    printf("Salário: R$ %.2f\n", func->salario);
    printf("Profissão: %s\n", func->prof);
    printf("Telefone: %s\n", func->cel);
    if (func->status == 'c') {
      strcpy(sit, "Cadastrado");
    } else {
      strcpy(sit, "Não Informado");
    }
    printf("Situação do Funcionário: %s\n", sit);
    printf("\n");
  }
}