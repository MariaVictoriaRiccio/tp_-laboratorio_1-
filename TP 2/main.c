#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"

#define TAM 1000

int main()
{
    int opcion;
    char confirma;
    char seguir;
    int proxId=1;
    int flagA=0;
    Employee lista[TAM];


    validInic (lista,TAM);

    do
    {
        printf("\n\n");
        printf("*******************************************************************\n");
        printf("                     ABM DE EMPLEADOS                              \n");
        printf("*******************************************************************\n");

        printf("\n\n");
        printf("1. ALTA\n");
        printf("2. MODIFICAR\n");
        printf("3. BAJA\n");
        printf("4. INFORMAR\n");
        printf("5. SALIR\n\n");
        printf("\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            if (addEmployee(lista,TAM, proxId)==0)
            {
                proxId++;
                printf("Personas inicializadas con exito!\n");
            }
            else
            {
                printf("Problemas al inicializar personas\n");
            }
            flagA=1;
            break;
        case 2:
            if (flagA==1)
            {
                changeEmployee(lista,TAM);
            }
            else
            {
                printf("Primero dar de alta a un empleado\n");
            }
            break;
        case 3:
            if (flagA==0)
            {
                printf ("Para dar de baja, primero debe dar de alta a un empleado\n");
            }
            else
            {
                removeEmployee(lista,TAM);
            }
            break;
        case 4:
            if (flagA==1)
            {
                sortEmployees(lista,TAM);
                printEmployees(lista,TAM);
                salary(lista, TAM);
            }
            else
            {
                printf("Antes de informar y ordenar, primero debe dar de alta a los empleados\n");
            }
            break;
        case 5:
            printf("Confirma que quiere salir? s/n \n");
            fflush(stdin);
            confirma=tolower(getchar());
            if (confirma=='s')
            {
                seguir='n';
            }
            break;
        default:
            printf ("Opcion invalida!\n");
            break;
        }
        system("pause");

    }
    while (seguir!='n');
    return 0;
}
