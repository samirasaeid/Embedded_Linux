#include "employeeSystem.h"
Employee::Employee(std::string _name,int _id) : name(_name), id(_id)
{

}
int Employee::getId(){
    return id;
}
void Employee::displayDetails(){
    std::cout<<"Employee Name: "<<name<<std::endl;
    std::cout<<"Employee ID: "<<id<<std::endl;
}

FullTimeEmployee::FullTimeEmployee(std::string _name,int _id,float _baseSalary, float _bonus)
    : Employee(_name,_id), baseSalary(_baseSalary), bonus(_bonus)
{

}
float FullTimeEmployee::calculateSalary(){
    return baseSalary + bonus;
}

PartTimeEmployee::PartTimeEmployee(std::string _name,int _id,float _hourlyRate,int _hourWorked)
    : Employee(_name,_id), hourlyRate(_hourlyRate), hoursWorked(_hourWorked)
{

}
float PartTimeEmployee::calculateSalary(){
    return hourlyRate * hoursWorked;
}

Intern::Intern(std::string _name,int _id,float stipend)
: Employee(_name,_id), stipend(stipend)
{

}

float Intern::calculateSalary(){
    return stipend;
}