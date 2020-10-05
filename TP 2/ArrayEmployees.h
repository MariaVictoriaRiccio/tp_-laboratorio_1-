#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

int initEmployees(Employee list[], int len);
/** \brief Verifica la primera posicion vacia del array.
 * \param list[] Employee
 * \param int len  tamanio
 * \return retorna  0 si esta ok, y -1 si hubo algun error.
 */
int addEmployee(Employee list[], int len, int id);
/** \brief Permite el alta de empleados a una lista desde la primera posicion libre.
 * \param array de var de la estructura Employee
 * \param len tamanio
 * \return int id del empleado
 */
int printEmployees(Employee list[], int len);
/** \brief Imprime la lista de empleados
 * \param Employee array de var de la estructura Employee
 * \param tamanio
 * \return retorna la impresion de los empleados si han sido dados de alta
 */

void printOneEmployee(Employee list);
/** \brief Imprime un solo empleado
 * \param Employee array de var de la estructura Employee
 * \param tamanio
 * \return retorna la impresion de un empleado si ha sido dado de alta
 */
int inicEmployee(Employee list[], int len);
/** \brief indica todas las posiciones del array vacias
 * \param Employee array de var de la estructura Employee
 * \param tamanio
 * \return -1 false(error) / 0  true (ok).
 */

int findEmployeeById (Employee list[],int len, int id);
/** \brief Busca empleado a partir de su ID
 * \param Employee array de var de la estructura Employee
 * \param tamanio
 * \ param id
 * \return retorna el empleado en la posicion  o -1 si es null o no ha sido encontrado
 *
 */

int changeEmployee(Employee list[],int len);
/** \brief modifica nombre,sector o salario de un empleado a partir de la busqueda del ID
 * \param Employee array de var de la estructura Employee
 * \param tamanio
 * \return retorna 0 si fue exitoso o -1 si no se ha podido realizar el cambio
 *
 */

int removeEmployee(Employee list[], int len);
/** \brief elimina un empleado de la lista a partir de su ID
 * \param Employee array de var de la estructura Employee
 * \param tamanio
 * \return retorna 0 si se ha podido eliminar el empleado o -1 si es null o no se puede encontrar el empleado
 */

int sortEmployees(Employee list[], int len);
/** \brief ordenamiento descendente segun apellido y sector
 * \param Employee array de var de la estructura Employee
 * \param tamanio
 * \return retorna la lista ordenada dentro de la funcion informar
 */

int salary(Employee list[], int len);
/** \brief promedio del salario de empleados.
 * \param Employee array de var de la estructura Employee
 * \param tamanio
 * \return retorna el promedio del salario de los empleados, y cuantos empleados estan por encima del promedio salarial.
 */

int validInic (Employee list[],int len);
/** \brief Valida si se ha podido inicializar la carga de los empleados o no
 * \param  Employee array de var de la estructura
 * \param tamanio
 * \return retorna el mensaje si fue exitoso o no
 *
 */

#endif // ARRAYEMPLOYEES_H_INCLUDED
