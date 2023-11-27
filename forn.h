// funções forn

#ifndef FORN_H
#define FORN_H

typedef struct fornecedor Fornecedor;

struct fornecedor{
    char cnpj[15];
    char nome_est[30];
    char cid[30];
    char nome_prop[50];
    char cel[12];
    char status;
};

void modulo_forn(void);
char tela_fornecedoras(void);
Fornecedor* tela_cad_forn(void);
void esc_forn(Fornecedor*);
Fornecedor* tela_pes_forn(void);
void exb_forn(Fornecedor*);
void tela_edit_forn(void);
void tela_exc_forn(void);

#endif 