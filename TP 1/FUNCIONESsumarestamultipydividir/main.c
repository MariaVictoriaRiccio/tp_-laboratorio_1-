#include <stdio.h>
#include <stdlib.h>
//pedir al usuario un numero, que pida operacion (+ - * /) y desp q pida otro numero. Segun la operacion ingresada, se llamara a la funcion q ejecute la operacion, y luego mostrar el resultado

int sumar (int num1,int num2);//prototipo de la funcion
int restar (int num1,int num2);
int multiplicar (int num1,int num2);
float dividir (int num1,int num2);

int main()
{
    int num1;
    int num2;
    int opcion;
    int resultadoInt;
    float resultadoFloat;

    printf ("Ingrese un numero:  \n");
    scanf ("%d", &num1);
    fflush(stdin);
    printf ("Ingrese otro numero:  \n");
    scanf ("%d", &num2);

    printf("Operacion a realizar?\n opcion 1:sumar, opcion 2:restar, opcion 3:multiplicar, opcion 4:dividir ");
    scanf ("%d",&opcion);

    switch (opcion)
    {
    case 1:
        resultadoInt=sumar (num1,num2);

        break;
    case 2:
        resultadoInt=restar (num1,num2);
        break;
    case 3:
        resultadoInt=multiplicar (num1,num2);
        break;
    case 4:
        resultadoFloat=dividir (num1,num2);
        break;
    }
    if (opcion!=4){
        printf ("El resultado es: %d\n", resultadoInt);
    }else {
    printf ("El resultado es: %f\n", resultadoFloat);
    }

    return 0;
}

int sumar (int num1,int num2)
{
    int resultado;
    resultado=num1+num2;
    return resultado;
}

int restar (int num1,int num2)
{
    int resultado;
    resultado=num1-num2;
    return resultado;
}

int multiplicar (int num1,int num2)
{
    int resultado;
    resultado=num1*num2;
    return resultado;
}

float dividir (int num1,int num2)//si quiero puedo ponerle operador 1 o 2, es lo mismo , no influye si las var de mail tienen otro nombre
{
    float resultado;
    resultado=(float)num1/num2;
    return resultado;
}
