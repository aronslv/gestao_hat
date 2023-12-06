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

int validarQuant(char* x) {
  int tam;

  tam = strlen(x);
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(x[i])) {
      return false;
    }
  }
  return true;
}


// Função baseada no código https://github.com/Gabrielygor/Clinica-dentaria-UFRN

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

// Função baseada no código de https://github.com/RenanMRb/ProjetoEagleEyes.git

int valid_cnpj(char*  cnpj) {
    int size = strlen(cnpj);
    if (size != 14) {
        return false; 
    }
    int digits[14];
    for (int i = 0; i < size; i++) {
        if (cnpj[i] < '0' || cnpj[i] > '9') {
            return false; 
        }
        digits[i] = cnpj[i] - '0'; 
    }
    int sum = 0;
    int weight = 5;
    for (int i = 0; i < 12; i++) {
        sum += digits[i] * weight;
        weight = (weight == 2) ? 9 : (weight - 1); 
    }
    int remainder = sum % 11;
    int digit1 = (remainder < 2) ? 0 : (11 - remainder);
    if (digits[12] != digit1) {
        return false;
    }
    sum = 0;
    weight = 6;
    for (int i = 0; i < 13; i++) {
        sum += digits[i] * weight;
        weight = (weight == 2) ? 9 : (weight - 1); 
    }
    remainder = sum % 11;
    int digit2 = (remainder < 2) ? 0 : (11 - remainder);
    if (digits[13] == digit2) {
        return true; 
    }
    return false; 
}

// Função baseada no código de https://github.com/RenanMRb/ProjetoEagleEyes.git

int valid_cpf (char* cpf) {
    int i, j, digito1 = 0, digito2 = 0;
    if (strlen(cpf) != 11) {
        return false;
    }
    else if(/*(strcmp (cpf,"00000000000") == 0) ||(strcmp (cpf,"11111111111") == 0) || (strcmp (cpf,"22222222222") == 0) ||*/
            // (strcmp (cpf,"33333333333") == 0) || (strcmp (cpf,"44444444444") == 0) || (strcmp (cpf,"55555555555") == 0) ||
            // (strcmp (cpf,"66666666666") == 0) || (strcmp (cpf,"77777777777") == 0) || (strcmp (cpf,"88888888888") == 0) ||
            /*(strcmp (cpf,"99999999999") == 0) || */(strcmp (cpf,"12345678909") == 0)) {
        return false; //se o CPF estiver dentre os mencionados acima, ele é considerado cpf de teste.
    }
    else {
        //digito 1
        for (i = 0, j = 10; i < strlen (cpf) - 2; i++, j--) { //multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        }
        digito1 %= 11;
        if (digito1 < 2) {
            digito1 = 0;
        }
        else {
            digito1 = 11 - digito1;
        }
        if ((cpf[9] - 48) != digito1) {
            return false; //se o digito 1 não for o mesmo que o da validação CPF é inválido
        }
        else { //digito 2
            for (i = 0, j = 11; i < strlen (cpf) - 1; i++, j--) //multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                digito2 += (cpf[i] - 48) * j;
            digito2 %= 11;
            if (digito2 < 2) {
                digito2 = 0;
            }
            else {
                digito2 = 11 - digito2;
                if ((cpf[10]-48) != digito2)
                    return false;
            } 
        } 
    } //se o digito 2 não for o mesmo que o da validação CPF é inválido
    return true;
}


