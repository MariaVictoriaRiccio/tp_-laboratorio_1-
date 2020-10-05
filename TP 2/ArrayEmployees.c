#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "ArrayEmployees.h"

int initEmployees(Employee list[], int tam)
{
    int error=-1;
    for (int i=0; i<tam; i++)
    {
        if (list[i].isEmpty==1)
        {
            error=i;
            break;
        }
    }
    return error;
}

int addEmployee(Employee list[], int len, int id)
{
    int error=1;
    int indice;
    Employee newEmployee;
    if (list!=NULL && len>0 && id>0)
    {
        printf("\n\n");
        printf ("----------------------------------------------------------------\n");
        printf("                ***ALTA DE EMPLEADOS***                          \n");
        printf ("----------------------------------------------------------------\n");
        printf("\n\n");
        indice= initEmployees(list,len);
        system("pause");
        if (indice ==-1)
        {
            printf("Sistema completo\n");
        }
        else
        {
            newEmployee.id=id;
            newEmployee.isEmpty=0;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(newEmployee.name);

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(newEmployee.lastName);

            printf("Ingrese salario: ");
            scanf("%f",&newEmployee.salary);

            printf("Ingrese sector: ");
            scanf("%d",&newEmployee.sector);

            list[indice]=newEmployee;
            error=0;
        }
    }

    return error;
}
void printOneEmployee(Employee list)
{
    printf ("  %4d        %10s        %10s       %.2f       %7d \n\n", list.id, list.name, list.lastName, list.salary,list.sector);
}

int printEmployees(Employee list[], int len)
{
    int error=1;
    int flag=0;
    if (list!=NULL && len >0)
    {
        system("cls");
        printf("-----------------------------------------------------------------------------\n");
        printf("    ID             NOMBRE        APELLIDO        SALARIO      SECTOR         \n");
        printf("-----------------------------------------------------------------------------\n");
        for(int i=0; i<len; i++)
        {
            if (list[i].isEmpty==0)
            {
                printOneEmployee(list[i]);
                flag=1;
            }
        }
        if (flag==0)
        {
            printf("No hay empleados en la lista\n");
        }
        error=0;
    }

    return error;
}


int inicEmployee(Employee list[], int len)
{
    int error = 1;
    if (list!=NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

int findEmployeeById (Employee list[],int len, int id)
{
    int indice = -1;
    for(int i = 0; i<len; i++)
    {
        if(list[i].id == id && list[i].isEmpty==0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int changeEmployee(Employee list[],int len)
{
    int error=-1;
    int indice;
    int opcion;
    int id;

    if (list!=NULL && len>0)
    {
        system ("cls");
        printf ("----------------------------------------------------------------\n");
        printf ("           ***MODIFICAR EMPLEADO***                              \n");
        printf ("----------------------------------------------------------------\n");
        printEmployees(list,len);
        printf("Ingrese ID: \n");
        scanf("%d", &id);
        indice = findEmployeeById(list,len,id);
        if (indice ==-1)
        {
            printf("No existe un empleado con ese legajo");
        }
        else
        {
            printOneEmployee(list[indice]);

            printf("Que dato desea modificar?\n");
            printf("1-NOMBRE\n");
            printf("2-APELLIDO\n");
            printf("3-SALARIO\n");
            printf("4-SECTOR\n");
            scanf("%d", &opcion);
            switch (opcion)
            {
            case 1:
                printf("Por favor, ingrese el nuevo nombre: \n");
                fflush(stdin);
                gets(list[indice].name);
                break;
            case 2:
                printf("Por favor, ingrese el nuevo apellido: \n");
                fflush(stdin);
                gets(list[indice].lastName);
                break;
            case 3:
                printf("Por favor, ingrese el nuevo salario: \n");
                scanf ("%f",&list[indice].salary);
                break;

            case 4:
                printf("Por favor, ingrese el nuevo sector: \n");
                scanf ("%d",&list[indice].sector);
                break;
            default:
                printf("Opcion invalida!");
                break;
            }
        }

    }


    return error;
}



int removeEmployee(Employee list[], int len)
{
    int error=1;
    int indice;
    int confirmacion=0;
    int id;

    if (list!=NULL && len>0)
    {
        printf ("----------------------------------------------------------------\n");
        printf ("                 ***BAJA DE EMPLEADOS***                        \n");
        printf ("----------------------------------------------------------------\n");
        printf ("\n\n");
        printf("Ingrese el ID del empleado que desea dar de baja: \n");
        scanf ("%d",&id);

        indice=findEmployeeById(list,len,id);
        if (indice == -1)
        {
            printf ("Error!!! ID inexistente\n");
        }
        else
        {
            printOneEmployee(list[indice]);

            printf ("Confirma la baja del empleado? 1. SI   2. NO \n");
            scanf ("%d",&confirmacion);
            if (confirmacion==1)
            {
                list[indice].isEmpty=1;
                error=0;
            }
            else
            {
                error=-1;
            }
        }
    }
    return error;
}



int sortEmployees(Employee list[], int len)
{
    int error=1;
    Employee aux;

    if (list!=NULL && len >0)
    {
        for (int i=0; i<len-1; i++)
        {
            for (int j=i+1; j<len; j++)
            {
                if (strcmp(list[i].lastName, list[j].lastName)>0){
                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;
                }else if ((strcmp(list[i].lastName,list[j].lastName)==0) && (list[i].sector > list[j].sector)){
                   aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;
                }
            }
            error=0;
        }
    }
    return error;
}



int salary(Employee list[], int len)
{
    int error = 1;
    float acumSalario = 0;
    int contEmpleados = 0;
    int salarioMayorDelpromedio = 0;
    float promedio;

    for (int i=0; i<len; i++)
    {
        if (list[i].isEmpty == 0)
        {
            acumSalario = acumSalario + list[i].salary;
            contEmpleados++;
        }
    }
    promedio=(float)acumSalario/contEmpleados;

    for (int i = 0; i < len; i++)
    {
        if (list[i].salary > promedio)
        {
            salarioMayorDelpromedio++;
        }
        error = 0;
    }
    printf("El promedio del salario de los empleados es : %.2f\n",promedio);
    printf("La cantidad de empleados que superan el promedio del salario es: %d\n",salarioMayorDelpromedio);

    return error;
}

int validInic (Employee list[],int len){

    if(inicEmployee(list, len)==0)
    {
        printf("Empleados inicializados con exito\n");
    }
    else
    {
        printf("Error al inicializar empleados\n");
    }
    return 0;
}
