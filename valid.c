#include <time.h>
#include <stdlib.h>
#include <string.h>


#define true 1
#define false 0

// Função baseada no código do Prof. Flavius

int ehDigito(char c) {
  if (c >= '0' && c <= '9') {
    return true;
  } else {
    return false;
  }
}

// Função baseada no código do Prof. Flavius

int ehBissexto(int aa) {
  if ((aa % 4 == 0) && (aa % 100 != 0)) {
    return true;
  } else if (aa % 400 == 0) {
    return true;
  } else {
    return false;
  }
}

// Função baseada no código do Prof. Flavius

int ehLetra(char c) {
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
    return true;
  } else if (c == ' ' || c == 13) {
    return true;
  } else {
    return false;
  }
}

// Função baseada no código do Prof. Flavius e Mariana Medeiros

int validarNome(char* nome) {
    for (int i=0; nome[i]!='\0'; i++) {
        if (!ehLetra(nome[i])) {
            return false;
        }
    }
    return true;
}

// Função baseada no código do Prof. Flavius

int validarCpf(char* cpf) {
  int tam;

  tam = strlen(cpf);
  if (tam < 11 || tam > 12) {
    return false;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(cpf[i])) {
      return false;
    }
  }
  return true;
}


// Função baseada no código do Prof. Flavius

int validarData(int dd, int mm, int aa) {
  int maiorDia;
  if (aa < 0 || mm < 1 || mm > 12)
    return false;
  if (mm == 2) {
    if (ehBissexto(aa)) 
      maiorDia = 29;
    else
      maiorDia = 28;
  } else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
    maiorDia = 30;
  } else
    maiorDia = 31;
  if (dd < 1 || dd > maiorDia)
    return false;
  return true;
}

// Função baseada no código do Prof. Flavius

int validarFone(char* fone) {
  int tam;

  tam = strlen(fone);
  if (tam < 11 || tam > 12) {
    return false;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(fone[i])) {
      return false;
    }
  }
  return true;

}

// Função baseada no código do Prof. Flavius

/*void ler_data(char* data) {
  int dia, mes, ano;
  char dd[3], mm[3], aa[5];
  fflush(stdin);
  printf("Data de nascimento: ");
  fgets(data, 11, stdin); 
  getchar();
  
  strncpy(dd, &data[0], 2);
  sscanf(dd, "%d", &dia);
  
  strncpy(mm, &data[3], 2);
  sscanf(mm, "%d", &mes);

  strncpy(aa, &data[6], 4);
  sscanf(aa, "%d", &ano);

  while (!validarData(dia, mes, ano)) {
    printf("Data inválida: %d/%d/%d\n", dia, mes, ano);
    printf("Informe uma nova data\n\n");
    printf("Data de nascimento: ");
    fgets(data, 11, stdin);
    fflush(stdin);
    getchar();
    strncpy(dd, &data[0], 2);
    sscanf(dd, "%d", &dia);
    strncpy(mm, &data[3], 2);
    sscanf(mm, "%d", &mes);
    strncpy(aa, &data[6], 4);
    sscanf(aa, "%d", &ano);
    
  } 
}*/

// Função baseada no código de https://github.com/DayXL/Atividade-projeto-bonelaria.git

int validarNumInteiro(char* numero) {
    int i = 0;

    while (numero[i] != '\0') {
        if ((numero[i] >= '0') && (numero[i] <= '9')) {
            i = i + 1;

        }

        else {
            return false;

        }

    }

    return true;

}

// Função baseada no código de https://github.com/DayXL/Atividade-projeto-bonelaria.git

int verificarCnpj(char* cnpj) {

    int parteUm[12] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    int parteDois[13] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};

    int soma = 0;
    int resto = 0;
    int tam;
    
    tam = strlen(cnpj);
    cnpj[tam - 1] = '\0';

    if ((validarNumInteiro(cnpj)) && (tam == 15)) {

        for (int i = 0; i < 12; i++) {
            soma = soma + ((cnpj[i] - '0' ) * (parteUm[i]));

        }

        resto = soma % 11;

        resto = (resto == 0 || resto == 1) ? 0 : 11 - resto;

        if (resto == (cnpj[12] - '0' )) {
            soma = 0;

            for (int i = 0; i < 13; i++) {
                soma = soma + ((cnpj[i] - '0' ) * (parteDois[i]));

            }

            resto = soma % 11;

            resto = (resto == 0 || resto == 1) ? 0 : 11 - resto;

            if (resto == (cnpj[13] - '0' )) {
                return false;

            }

            else {
                return true;
            }

        }

        else {
            return true;

        }
    }

    else {
        return true;

    }

}

int validarCnpj(char* cnpj) {
  int tam;

  tam = strlen(cnpj);
  if (tam < 14 || tam > 15) {
    return false;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(cnpj[i])) {
      return false;
    }
  }
  return true;
}