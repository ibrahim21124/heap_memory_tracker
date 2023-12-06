/********************************************************************************************
 ** $File: main.cpp
 ** $Version: #1.3
 ** $Date: 24/09/2022
 ** $Description: Manual Test File for the Executable
 ** $Author: Ronak Vavwala, Divyarajsinh Rana & Ibrahim Koicha
********************************************************************************************/
#include <iostream>
#include <typeinfo>
#include <string>
#include "./include/heaptracker.h"

using namespace std;

/**********************************************************************************
 ** $Class Name: Employee
 ** $Description: The class has following members:
                    1. string employee_name
***********************************************************************************/
class Employee
{
    public:
        string employee_name;
        Employee()
        {
            //Default Constructor
        }

        Employee(string name)
        {
            this->employee_name = name;
        }

        string getName()
        {
            return employee_name;
        }    
};

/**********************************************************************************
 ** $Class Name: Supervisor
 ** $Description: The class has following members:
                    1. string supervisor_name
***********************************************************************************/
class Supervisor
{
    public:
        string supervisor_name;

        Supervisor()
        {
            //Default Constructor
        }

        Supervisor(string name)
        {
            this->supervisor_name = name;
        }

        string getName()
        {
            return supervisor_name;
        }    
};

int main()
{
    heap_tracker_init();

    Employee *e1 = new Employee;
    cout << "Type Defined: " << typeid(e1).name() << endl;
    Employee *e2 = new Employee("Ibrahim");
    cout << "Type Defined: " << typeid(e2).name() << endl;
    Employee *e3 = new Employee("Dixit");
    cout << "Type Defined: " << typeid(e3).name() << endl;
    Employee *e4 = new Employee("Ronak");
    cout << "Type Defined: " << typeid(e4).name() << endl;
    Supervisor *s1 = new Supervisor("Atul");
    cout << "Type Defined: " << typeid(s1).name() << endl;
    float *f = new float;
    cout << "Type Defined: " << typeid(f).name() << endl;
    int *i = new int;
    cout << "Type Defined: " << typeid(i).name() << endl;
    char *c = new char;
    cout << "Type Defined: " << typeid(c).name() << endl;
    string *s = new string;
    cout << "Type Defined: " << typeid(s).name() << endl;

    delete e1;
    delete e2;
    delete e3;
    //  delete f;    
    heap_tracker_stats();
    return 0;
}
