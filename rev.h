// funções rev

#ifndef REV_H
#define REV_H

typedef struct revendedor Revendedor;

struct revendedor{
    char cnpj[15];
    char nome_est[30];
    char cid[30];
    char nome_prop[50];
    char cel[12];
    char status;
    Revendedor* prox;
};

void modulo_rev(void);
char tela_revendedoras(void);
Revendedor* tela_cad_rev(void);
void esc_rev(Revendedor*);
Revendedor* tela_pes_rev(void);
void exb_rev(Revendedor*);
void tela_edit_rev(void);
void tela_exc_rev(void);
int verificaCNPJ2Duplicado(const char* cnpj);

#endif 