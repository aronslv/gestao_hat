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
    Revendedor* rev_x;
    char op;
    do{
        op = tela_revendedoras();
        switch (op) {
            case '1':   rev_x = tela_cad_rev();
                        esc_rev(rev_x);
                        free(rev_x);
                        break;
            case '2':   rev_x = tela_pes_rev();
                        exb_rev(rev_x);
                        free(rev_x);
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

Revendedor* tela_cad_rev(void) {
    Revendedor* rev;

    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                                                                             \n");
    printf("              < < < < < < < Cadastro - Revendedoras > > > > > > >            \n");
    printf("                                                                             \n");
    printf("              Digite as informações a seguir:                                \n");
    printf("                                                                             \n");

    rev = (Revendedor*) malloc(sizeof(Revendedor));
    
    ler_cnpj2(rev->cnpj);

    ler_nome4(rev->nome_est);

    ler_nome6(rev->end);

    ler_nome5(rev->nome_prop);

    ler_cel3(rev->cel);

    rev->status = 'c';
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Cadastro concluído!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return rev;
}

Revendedor* tela_pes_rev(void) {
  FILE* fp;
  Revendedor* rev;
  char cnpj[15];
  system("clear||cls");
  printf("\n");
  printf("-----------------------------------------------------------------------------\n");
  printf("                                                                             \n");
  printf("              < < < < < < < Pesquisa - Revendedoras > > > > > > >            \n");
  printf("                                                                             \n");
  printf("Informe o CNPJ que deseja pesquisar: ");
  fgets (cnpj, 15, stdin);
  getchar();
  rev = (Revendedor*) malloc(sizeof(Revendedor));
  fp = fopen("rev.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  } else {
      while(!feof(fp)) {
        fread(rev, sizeof(Revendedor), 1, fp);
        if((strcmp(rev->cnpj, cnpj) == 0) && (rev->status != 'e')) {
          exb_rev(rev);
          printf("\n");
          printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
          getchar();
          fclose(fp);
          return rev;
        }
      }
    }
  fclose(fp);
  return NULL;
}

void tela_edit_rev(void) {
  char cnpj[15];
  Revendedor* new_rev = (Revendedor*) malloc(sizeof(Revendedor));
  FILE* fp;
  int rev_found = 0;
  system("clear||cls");
  printf("\n");
  printf("-----------------------------------------------------------------------------\n");
  printf("                                                                             \n");
  printf("              < < < < < < < Edição - Revendedoras > > > > > > >              \n");
  printf("                                                                             \n");
  printf("Informe o CNPJ para edição de dados: ");
  fgets (cnpj, 15, stdin);
  getchar();
  fp = fopen("rev.dat", "r+b");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  } else {
    while (fread(new_rev, sizeof(Revendedor), 1, fp) == 1) {
      if(strcmp(new_rev->cnpj, cnpj) == 0) {
        printf("\n");
        printf("\t\t\t= = = Revendedora Encontrada = = =\n");
        printf("\n");

        ler_cnpj2(new_rev->cnpj);

        ler_nome4(new_rev->nome_est);

        ler_nome6(new_rev->end);

        ler_nome5(new_rev->nome_prop);

        ler_cel3(new_rev->cel);

        new_rev->status = 'c';

        fseek(fp, -sizeof(Revendedor), SEEK_CUR);
        fwrite(new_rev, sizeof(Revendedor), 1, fp);
        rev_found = 1;
        break;
      }
    }
  }
  if (!rev_found) {
        printf("\n");
        printf("\t\t\tCNPJ não encontrado!\n");
    } else {
        printf("\n");
        printf("\t\t\tRevendedora atualizada com sucesso!\n");
    }
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  fclose(fp);
}

void tela_exc_rev(void) {
  char cnpj[15];
  Revendedor* new_rev = (Revendedor*) malloc(sizeof(Revendedor));
  FILE* fp;
  int rev_found = 0;
  system("clear||cls");
  printf("\n");
  printf("-----------------------------------------------------------------------------\n");
  printf("                                                                             \n");
  printf("              < < < < < < < Exclusão - Revendedoras > > > > > > >            \n");
  printf("                                                                             \n");
  printf("Informe o CNPJ para excluir do sistema: ");
  fgets (cnpj, 15, stdin);
  getchar();
  fp = fopen("rev.dat", "r+b");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  } else {
    while (fread(new_rev, sizeof(Revendedor), 1, fp) == 1) {
      if(strcmp(new_rev->cnpj, cnpj) == 0) {
        printf("\n");
        printf("\t\t\t= = = Revendedora Encontrada = = =\n");
        printf("\n");

        new_rev->status = 'e';

        fseek(fp, -sizeof(Revendedor), SEEK_CUR);
        fwrite(new_rev, sizeof(Revendedor), 1, fp);
        rev_found = 1;
        break;
      }
    }
  }
  if (!rev_found) {
        printf("\n");
        printf("\t\t\tCNPJ não encontrado!\n");
    } else {
        printf("\n");
        printf("\t\t\tRevendedora excluída com sucesso!\n");
    }
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  fclose(fp);
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

void exb_rev(Revendedor* rev) {
  if ((rev == NULL) || (rev->status == 'e')) {
    printf("\n");
    printf("\t\t\tCNPJ não encontrado!\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }else{
    char sit[20];
    printf("\t\t\t= = = Revendedora Cadastrada = = =\n");
    printf("\n");
    printf("CNPJ: %s\n", rev->cnpj);
    printf("Nome do estabelecimento: %s\n", rev->nome_est);
    printf("Endereço: %s\n", rev->end);
    printf("Nome do proprietário: %s\n", rev->nome_prop);
    printf("Telefone: %s\n", rev->cel);
    if (rev->status == 'c') {
      strcpy(sit, "Cadastrado");
    } else {
      strcpy(sit, "Não Informado");
    }
    printf("Situação da Revendedora: %s\n", sit);
    printf("\n");
  }
}

// arquivos

void esc_rev(Revendedor* rev) {
  FILE* fp;
  fp = fopen("rev.dat", "ab");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informações...\n");
    sleep(1);
    printf("\t\t\t>>> Houve um erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  else {
    fwrite(rev, sizeof(Revendedor), 1, fp);
    fclose(fp);
  }
}
