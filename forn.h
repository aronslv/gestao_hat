// funções forn

#ifndef FORN_H
#define FORN_H

typedef struct fornecedor Fornecedor;

struct fornecedor{
    char cnpj[15];
    char nome_est[30];
    char nome_prop[50];
    char end[30];
    char cel[12];
};

void modulo_forn(void);
char tela_fornecedoras(void);
void tela_cad_forn(void);
void tela_pes_forn(void);
void tela_edit_forn(void);
void tela_exc_forn(void);

#endif 