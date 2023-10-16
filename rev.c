#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "rev.h"
#include "valid.h"

void ler_cnpj2(char*);
void ler_nome4(char*);
void ler_nome5(char*);
void ler_nome6(char*);
void ler_cel3(char*);

// função do módulo de revendedoras

void modulo_rev(void) {
    char op;
    do{
        op = tela_revendedoras();
        switch (op) {
            case '1':   tela_cad_rev();
                        break;
            case '2':   tela_pes_rev();
                        break;
            case '3':   tela_edit_rev();
                        break;
            case '4':   tela_exc_rev();
                        break;
        }
        
    }while (op != '0');
}

char tela_revendedoras(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < < Revendedoras > > > > > > > >                   §\n");
    printf("§                                                                             §\n");
    printf("§              1. Cadastro de Revendedoras                                    §\n");
    printf("§              2. Pesquisar Revendedoras                                      §\n");
    printf("§              3. Editar Dados de Revendedoras                                §\n");
    printf("§              4. Excluir uma Revendedora do Sistema                          §\n");
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

void tela_cad_rev(void) {
    Revendedor* revendedor;

    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Cadastro - Revendedoras > > > > > > >            \n");
    printf("                                                                             \n");
    printf("              Digite as informações a seguir:                                \n");
    printf("                                                                             \n");

    revendedor = (Revendedor*) malloc(sizeof(Revendedor));
    
    ler_cnpj2(revendedor->cnpj);

    ler_nome4(revendedor->nome_est);

    ler_nome6(revendedor->end);

    ler_nome5(revendedor->nome_prop);

    ler_cel3(revendedor->cel);
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

void tela_pes_rev(void) {
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Pesquisa - Revendedoras > > > > > > >            \n");
    printf("                                                                             \n");
    printf("              Informe o CNPJ que deseja pesquisar:                           \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_edit_rev(void) {
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Edição - Revendedoras > > > > > > >              \n");
    printf("                                                                             \n");
    printf("              Informe o CNPJ para edição de dados:                           \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_exc_rev(void) {
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Exclusão - Revendedoras > > > > > > >            \n");
    printf("                                                                             \n");
    printf("              Informe o CNPJ para excluir do sistema:                        \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void ler_cnpj2 (char* cnpj) {
    fflush(stdin);
    printf("Digite o CNPJ (Apenas Números): ");
    fgets (cnpj, 15, stdin);
    while (!validarCnpj(cnpj)) {
        printf("CNPJ inválido! Digite o CNPJ novamente: ");
        fgets (cnpj, 15, stdin);
    }
    getchar();
}

void ler_nome4(char* nome_est) {
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

void ler_nome5(char* nome_prop) {
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

void ler_nome6(char* end) {
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

void ler_cel3 (char* cel) {
    fflush (stdin);
    printf("Digite o Telefone (Apenas Números): ");
    fgets (cel, 12, stdin);

    while (!validarFone (cel)) {
        printf("Telefone inválido! Digite novamente: ");
        fgets (cel, 12, stdin);
    
    }
    getchar();
}