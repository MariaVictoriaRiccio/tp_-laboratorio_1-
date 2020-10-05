#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcionesCalculadora.h"

int main(){
    float x;
    float y;
    int flagMenu=0;
    int flagA=0;
    int flagB=0;
    int opcion;
    int flagOperandoUno=0;
    int flagOperandoDos=0;
    int flagCalcular=0;
    char seguir='s';
    char confirma;

    do
    {
        system("pause");

        if (flagMenu==0)
        {
            printf ("\n\n***Menu de calculadora***\n\n");
            printf ("1. Ingresar primer operando:A= x\n");
            printf ("2. Ingresar segundo operando B= x\n");
            printf ("3. Calcular todas las operaciones\n");
            printf ("a. Sumar A=X + B=Y \n");
            printf ("b. Restar A=X + B=Y \n");
            printf ("c. Dividir A=X + B=Y \n");
            printf ("d. Facotrizar A=X + B=Y \n");
            printf ("4. Informar resultados\n");
            printf ("5. Salir\n\n");
            scanf  ("%d", &opcion);
            flagMenu=1;

        }
        else if(flagA==0)
        {
            printf ("***Menu de calculadora***\n\n");
            printf ("1. Ingresar primer operando:A = %.2f\n",x);
            printf ("2. Ingresar segundo operando: B = x \n");
            printf ("3. Calcular todas las operaciones\n");
            printf ("a. Sumar A=%.2f + B=Y \n", x);
            printf ("b. Restar A=%.2f + B=Y \n", x);
            printf ("c. Dividir A=%.2f + B=Y \n", x);
            printf ("d. Facotrizar A=%.2f + B=Y \n", x);
            printf ("4. Informar resultados\n");
            printf ("5. Salir\n\n");
            scanf  ("%d", &opcion);
            flagA=1;
            flagB=0;
        }
        else if (flagB==0)
        {
            printf ("***Menu de calculadora***\n\n");
            printf ("1. Ingresar primer operando:A = %.2f\n",x);
            printf ("2. Ingresar segundo operando B = %.2f\n",y);
            printf ("3. Calcular todas las operaciones\n");
            printf ("a. Sumar A=%.2f + B=%.2f \n", x,y);
            printf ("b. Restar A=%.2f + B=%.2f \n", x,y);
            printf ("c. Dividir A=%.2f + B=%.2f \n", x,y);
            printf ("d. Factorizar A=%.2f + B=%.2f \n", x,y);
            printf ("4. Informar resultados\n");
            printf ("5. Salir\n");
            scanf  ("%d", &opcion);
        }


        switch (opcion)
        {
        case 1:
            printf ("Ingrese primer operando: \n");
            scanf ("%f",&x);
            flagOperandoUno=1;
            break;
        case 2:
            printf ("Ingrese segundo operando: \n");
            scanf ("%f",&y);
            flagOperandoDos=1;
            break;

        case 3:
            if (flagOperandoUno==0 || flagOperandoDos==0)
            {
                printf ("Antes de realizar los calculos, por favor ingrese opcion 1 y opcion 2\n");
            }
            else
            {
                sumar (x,y);
                restar (x,y);
                dividir (x,y);
                multiplicar(x,y);
                factorialA (x);
               // factorialB (y);
                printf ("\n\nCalculando operaciones...\n\n");
                flagCalcular=1;
            }

            break;
        case 4:
            if (flagOperandoUno==0 || flagOperandoDos==0)
            {
                printf ("Antes de mostrar los resultados, por favor ingrese opcion 1, opcion 2, y opcion 3\n");
            }
            else if (flagCalcular==0)
            {
                printf("Para mostrar los resultados,primero debe calcular las operaciones, seleccionando opcion 3\n");
            }
            else
            {
                printf("a) El resultado de A+B es: %.2f\n", sumar(x,y));
                printf("b) El resultado de A-B es:%.2f\n",restar(x,y));
                if (y!=0)
                {
                    printf("c) El resultado de A/B es:%.2f\n", dividir(x,y));
                }
                else
                {
                    printf ("c)No se puede dividir por 0\n");
                }

                printf("d) El resultado de A*B es: %.2f\n",multiplicar(x,y));
                if (x<=0)
                {
                    printf("e) No se puede calcular factorial de un numero negativo\n");
                }
                else
                {
                    printf("e) El factorial de A es: %d y el  factorial de B es %d\n ", factorialA (x),factorialA (x));

                }
                break;

            case 5:
                printf("Confirma salida? Ingrese 's' para salir, o 'n' para continuar: \n");
                fflush(stdin);
                confirma=tolower(getchar());
                if (confirma=='s')
                {
                    seguir = 'n';
                }
                break;
            default:
                printf ("Opcion invalida!\n");
                break;
            }
            system("pause");
        }
    }

    while (seguir=='s');
    return 0;
}
