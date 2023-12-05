// funções prods

#ifndef PRODS_H
#define PRODS_H

typedef struct materia Materia;

struct materia {
    char mat_prim[25];
    int id;
    int quant;
    float valor;
    char data[11];
    char status;
};

typedef struct produto Produto;

struct produto {
    char prods[25];
    int id;
    int quant;
    float valor;
    char data[11];
    char status;
};

void modulo_prods(void);
char escolha_prods(void);
char tela_material(void);
Materia* tela_cad_mat(void);
void esc_mat(Materia*);
Materia* tela_pes_mat(void);
void exb_mat(Materia*);
void tela_edit_mat(void);
void tela_exc_mat(void);
char tela_produtos(void);
Produto* tela_cad_prods(void);
void esc_prod(Produto*);
Produto* tela_pes_prods(void);
void exb_prod(Produto*);
void tela_edit_prods(void);
void tela_exc_prods(void);

char *get_mat(const int id);
void get_est_mat(int id, int quant);
char *get_prod(const int id);
int get_est_prod(int id, int quant);
float get_val_mat(int id);
float get_val_prod(int id);

#endif