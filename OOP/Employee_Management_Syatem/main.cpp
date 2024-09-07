#include <iostream>
#include <list>
#include "employeeSystem.h"


void getEmployee(Employee *emp){
    std::cout<<emp->calculateSalary()<<std::endl;
}

void addEmployee(std::list<Employee*>&list, Employee *emp){
    list.push_back(emp);
}

void deleteEmployee(std::list<Employee*>&list,int id){
   for(auto it=list.begin();it != list.end();it++){
    if((*it)->getId() == id){
        delete *it;
        it = list.erase(it);
    }
   }
}

int main(){
    Employee * emp1;
    FullTimeEmployee f1("Ahmed",11,2000,500);

    PartTimeEmployee p1("Mohamed",133,50,12);

    Intern I1("Shimaa",05,300);

    getEmployee(&f1);
    getEmployee(&p1);
    getEmployee(&I1);

    std::list<Employee*> employeeList;

    addEmployee(employeeList,new FullTimeEmployee(f1));
    addEmployee(employeeList,new PartTimeEmployee(p1));
    addEmployee(employeeList,new Intern(I1));

    for(const auto & employee: employeeList){
        employee->displayDetails();
    }


    deleteEmployee(employeeList,11);  

    for(const auto & employee: employeeList){
        employee->displayDetails();
    } 

    return 0;
}