#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} Employee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int initEmployees(Employee* list, int len);

/** \brief to indicate if there is space available to add an employee
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int 1 ok 0 error
 */
int checkSpace(Employee* list, int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (0) if Error [Invalid length or NULL pointer or without free space] - (1) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary, int sector);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief Modify a Employee by Id
 * \param list Employee*
 * \param len int
 * \param index int
 * \param employeeId int
 * \return int 1 ok/ 0 error
 */
int modifyEmployee(Employee* list, int len, int index,  int employeeId);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (0) if Error [Invalid length or NULL pointer or if can't find a employee] - (1) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief function to get the corresponding reports done
 *
 * \param list Employee*
 * \param len int
 * \return int 1 ok/ 0 error
 */
int getReports(Employee* list, int len);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
  * \return int 1 ok/ 0 error
 *
 */
int printEmployees(Employee* list, int length);

/** \brief prints each employee info
 *
 * \param index int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return void
 */
void printEmployee(int id, char name[], char lastName[], float salary, int sector);

#endif
