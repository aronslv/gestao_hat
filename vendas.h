//funções vendas

#ifndef VENDAS_H
#define VENDAS_H

typedef struct compras Compras;

struct compras {
    int id;
    char cnpj[15];
    int quant;
    float valor;
    float preco;
    char data[11];
    int id_compra;
    char status;
};

typedef struct vendas Vendas;

struct vendas {
    int id;
    char cnpj[15];
    char cpf[12];
    int quant;
    float valor;
    float preco;
    char data[11];
    int id_venda;
    char status;
};

void modulo_vendas(void);
char escolha_vendas(void);
char tela_compras(void);
Compras* tela_cad_com(void);
Compras* tela_pes_com(void);
void tela_exc_com(void);
void esc_com(Compras*);
void exb_com(Compras*);
char tela_vendas(void);
Vendas* tela_cad_ven(void);
Vendas* tela_pes_ven(void);
void tela_exc_ven(void);
void esc_ven(Vendas*);
void exb_ven(Vendas*);



#endif 