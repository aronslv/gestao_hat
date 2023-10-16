// funções func

#ifndef FUNC_H
#define FUNC_H

typedef struct funcionario Funcionario;

struct funcionario {
    char nome[50];
    char cpf[12];
    char prof[25];
    char cel[12];
};

void modulo_func(void);
char tela_funcionarios(void);
void tela_cad_func(void);
void tela_pes_func(void);
void tela_edit_func(void);
void tela_exc_func(void);

#endif 