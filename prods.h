// funções prods

#ifndef PRODS_H
#define PRODS_H

typedef struct materia Materia;

struct materia {
    char mat_prim[25];
    int quant_mat;
    float valor;
    char data[11];
    char cnpj[15];
};

typedef struct produto Produto;

struct produto {
    char prods[25];
    int quant_prods;
    float valor;
    char data[11];
    char cnpj[15];
};

void modulo_prods(void);
char escolha_prods(void);
char tela_material(void);
void tela_cad_mat(void);
void tela_pes_mat(void);
void tela_edit_mat(void);
void tela_exc_mat(void);
char tela_produtos(void);
void tela_cad_prods(void);
void tela_pes_prods(void);
void tela_edit_prods(void);
void tela_exc_prods(void);

#endif