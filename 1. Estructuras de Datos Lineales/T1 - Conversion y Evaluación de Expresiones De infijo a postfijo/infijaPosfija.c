/*T - Conversión y Evaluación de Expresiones: 
De Infijo a Posfijo*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define tam 200

int prioridad(char simbolo){
    switch(simbolo){
        case '^': 
            return 3;
        case '*': 
            return 2;
        case '/': 
            return 2;
        case '+': 
            return 1;
        case '-': 
            return 1;
        case '(': 
            return 0;
        default: 
            return 0;
    }
}

int main (){
    int tope=-1, pos=-1;
    int pila[tam];
    char *epos[tam];
    char expinf[tam];
    
    printf("\nIngrese la expresion en notacion infija (tokens separados por espacio): ");
    fgets(expinf, tam, stdin);


    char *tokens[tam];
    int n = 0;
    char *token = strtok(expinf, " \n");
    while (token != NULL) {
        tokens[n++] = token;
        token = strtok(NULL, " \n");
    }


    for (int i=0; i<n; i++){
        char *tok = tokens[i];

        if (isdigit(tok[0])) {
            epos[++pos] = tok;
        }
        else if (tok[0] == '('){
            pila[++tope] = '(';
        }
        else if (tok[0] == ')'){
            while (pila[tope] != '('){
                char *op = malloc(2);
                op[0] = pila[tope--]; op[1] = '\0';
                epos[++pos] = op;
            }
            tope--;
        }
        else {
            while (tope>-1 && 
                    (prioridad(tok[0]) < prioridad(pila[tope]) ||
                    (prioridad(tok[0]) == prioridad(pila[tope]) && tok[0] != '^'))){
                char *op = malloc(2);
                op[0] = pila[tope--]; op[1] = '\0';
                epos[++pos] = op;
            }
            pila[++tope] = tok[0];
        }
    }

    while (tope > -1){
        char *op = malloc(2);
        op[0] = pila[tope--]; op[1] = '\0';
        epos[++pos] = op;
    }


    printf("\nLa expresion en notacion postfija es: ");
    for (int i=0; i<=pos; i++){
        printf("%s ", epos[i]);
    }

    double pilaNum[tam];
    int topNum = -1;

    for (int i=0; i<=pos; i++){
        char *tok = epos[i];
        if (isdigit(tok[0])) {
            pilaNum[++topNum] = atof(tok); // convierte token a número
        } else {
            double b = pilaNum[topNum--];
            double a = pilaNum[topNum--];
            switch(tok[0]){
                case '+': pilaNum[++topNum] = a + b; break;
                case '-': pilaNum[++topNum] = a - b; break;
                case '*': pilaNum[++topNum] = a * b; break;
                case '/': pilaNum[++topNum] = a / b; break;
                case '^': pilaNum[++topNum] = pow(a, b); break;
            }
        }
    }

    printf("\nEl resultado de la expresion es: %.2f\n", pilaNum[topNum]);

    return 0;
}
