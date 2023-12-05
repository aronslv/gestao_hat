// funções rel

#ifndef REL_H
#define REL_H

void modulo_rel(void);
char tela_rel(void);
char rel_rev(void);
void lista_all_rev(void);
void lista_ativo_rev(void);
void lista_inativo_rev(void);
void lista_ord_rev(void);
char rel_func(void);
void lista_all_func(void);
void lista_ativo_func(void);
void lista_inativo_func(void);
char rel_forn(void);
void lista_all_forn(void);
void lista_ativo_forn(void);
void lista_inativo_forn(void);
void lista_ord_forn(void);
char rel_mat(void);
void lista_all_mat(void);
void lista_ativo_mat(void);
void lista_inativo_mat(void);
char rel_prod(void);
void lista_all_prods(void);
void lista_ativo_prods(void);
void lista_inativo_prods(void);
char rel_com(void);
void lista_all_com(void);
char rel_ven(void);
void lista_all_ven(void);

char *get_forn(const char *cnpj);
char *get_rev(const char *cnpj);

#endif 