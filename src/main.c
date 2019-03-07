/* Lucas Morandi - 202031
 *
 * Contador de floats
 *
 * Este programa deve identificar floats no meio de uma string e printar a soma deles.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//defini a entrada maxima em 400 palavras com 200 caracters cada
#define MAX_CHAR 200
#define MAX_WORDS 400

int main() {

    char line[MAX_CHAR];
    int n=0;
    char array_de_palavras[MAX_WORDS][MAX_CHAR];
    float soma=0;

    //le a linha toda e armazena na string line
    scanf("%[^\n]s", line);

    //separa a string pelo caracter de espaco e armazena no array_de_palavras
    char delim[] = " ";
	char *ptr = strtok(line, delim);

	while(ptr != NULL)	{
        strcpy(array_de_palavras[n], ptr);
        n++;
		ptr = strtok(NULL, delim);
	}

    //Percorre o array de palavras analisando cada uma delas
    for(int i=0; i<n; i++){
        unsigned int j=0;
        while(array_de_palavras[i][j]>=48 && array_de_palavras[i][j]<=57){      //checa se eh um numero pela tabela ascii
            j++;
            if(j == strlen(array_de_palavras[i])){              //se chegar ao final da palavra
                soma += atof(array_de_palavras[i]);             //adiciona a soma de floats
                break;
            }
            if(array_de_palavras[i][j] == '.'){                                //se encontrar um ponto
                j++;
                while(array_de_palavras[i][j]>=48 && array_de_palavras[i][j]<=57){      //continua checando por numeros
                    j++;
                    if(j == strlen(array_de_palavras[i])){     //se chegar ao final da palavra
                        soma += atof(array_de_palavras[i]);    //adiciona a soma de floats
                        break;
                    }
                break;
                }
            }
        }
    }

    printf("%g\n", soma);     //printa o resultado final

  return 0;
}
