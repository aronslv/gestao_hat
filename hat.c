#include <stdio.h>
#include <stdlib.h>

//funções base
void tela_main(void);
void tela_info(void);
void tela_revendedoras(void);
void tela_cad_rev(void);
void tela_pes_rev(void);
void tela_edit_rev(void);
void tela_exc_rev(void);
void tela_funcionarios(void);
void tela_cad_func(void);
void tela_pes_func(void);
void tela_edit_func(void);
void tela_exc_func(void);
void tela_fornecedoras(void);
void tela_cad_forn(void);
void tela_pes_forn(void);
void tela_edit_forn(void);
void tela_exc_forn(void);
void tela_produtos(void);
void tela_cad_prods(void);
void tela_pes_prods(void);
void tela_edit_prods(void);
void tela_exc_prods(void);

//programa main
int main(void) {
    tela_main();
    tela_info();
    tela_revendedoras();
    tela_cad_rev();
    tela_pes_rev();
    tela_edit_rev();
    tela_exc_rev();
    tela_funcionarios();
    tela_cad_func();
    tela_pes_func();
    tela_edit_func();
    tela_exc_func();
    tela_fornecedoras();
    tela_cad_forn();
    tela_pes_forn();
    tela_edit_forn();
    tela_exc_forn();
    tela_produtos();
    tela_cad_prods();
    tela_pes_prods();
    tela_edit_prods();
    tela_exc_prods();
    return 0;
}

//funções telas
void tela_main(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < Sistema Hat and Cap > > > > >                        §\n");
    printf("§                                                                             §\n");
    printf("§              1. Revendedoras                                                §\n");
    printf("§              2. Funcionários                                                §\n");
    printf("§              3. Fornecedores                                                §\n");
    printf("§              4. Produtos                                                    §\n");
    printf("§              5. Relatórios                                                  §\n");
    printf("§              0. Sair                                                        §\n");
    printf("§                                                                             §\n");
    printf("§              Digite o nº da opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_info(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§                   < < < < < Sistema Hat and Cap > > > > >                   §\n");
    printf("§                                                                             §\n");
    printf("§       Universidade Federal do Rio Grande do Norte (UFRN)                    §\n");
    printf("§       Centro de Ensino Superior do Seridó (CERES)                           §\n");
    printf("§       Programa desenvolvido pelo discente Aron Silva                        §\n");
    printf("§       Temática: Gestão de Fábrica de Chapéus e Bonés                        §\n");
    printf("§       Auxílios e Influências: Flavius Gorgônio                              §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_revendedoras(void) {
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
    printf("§              Digite o nº da opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_cad_rev(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Cadastro - Revendedoras > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Digite as informações a seguir:                                §\n");
    printf("§                                                                             §\n");
    printf("§              CNPJ:                                                          §\n");
    printf("§              Nome do estabelecimento:                                       §\n");
    printf("§              Endereço do estabelecimento:                                   §\n");
    printf("§              Nome do proprietário(a):                                       §\n");
    printf("§              Celular (apenas números):                                      §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_pes_rev(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Pesquisa - Revendedoras > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CNPJ que deseja pesquisar:                           §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_edit_rev(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Edição - Revendedoras > > > > > > >              §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CNPJ para edição de dados:                           §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_exc_rev(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Exclusão - Revendedoras > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CNPJ para excluir do sistema:                        §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_funcionarios(void) {
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
    printf("§              Digite o nº da opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_cad_func(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Cadastro - Funcionários > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Digite as informações a seguir:                                §\n");
    printf("§                                                                             §\n");
    printf("§              CPF:                                                           §\n");
    printf("§              Nome completo:                                                 §\n");
    printf("§              Profissão:                                                     §\n");
    printf("§              Celular (apenas números):                                      §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_pes_func(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Pesquisa - Funcionários > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CPF que deseja pesquisar:                            §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_edit_func(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Edição - Funcionários > > > > > > >              §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CPF para edição de dados:                            §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_exc_func(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Exclusão - Funcionários > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CPF para excluir do sistema:                         §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_fornecedoras(void) {
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
    printf("§              Digite o nº da opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_cad_forn(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Cadastro - Fornecedoras > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Digite as informações a seguir:                                §\n");
    printf("§                                                                             §\n");
    printf("§              CNPJ:                                                          §\n");
    printf("§              Nome do estabelecimento:                                       §\n");
    printf("§              Endereço do estabelecimento:                                   §\n");
    printf("§              Matéria-prima fornecida:                                       §\n");
    printf("§              Nome do proprietário(a):                                       §\n");
    printf("§              Celular (apenas números):                                      §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_pes_forn(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Pesquisa - Fornecedoras > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CNPJ que deseja pesquisar:                           §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_edit_forn(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Edição - Fornecedoras > > > > > > >              §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CNPJ para edição de dados:                           §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void tela_exc_forn(void) {
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("§                                                                             §\n");
    printf("§              < < < < < < < Exclusão - Fornecedoras > > > > > > >            §\n");
    printf("§                                                                             §\n");
    printf("§              Informe o CNPJ para excluir do sistema:                        §\n");
    printf("§                                                                             §\n");
    printf("§                                                                             §\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}
