#ifndef EMPLOYEE_SYSTEM
#define EMPLOYEE_SYSTEM
#include <iostream>
#include <string>

class Employee {
    private: 
        std::string name;
        int id;
    
    public:
        Employee(std::string _name,int _id);
        int getId();
        void displayDetails();
        virtual float calculateSalary()=0;
};

class FullTimeEmployee  : public Employee{
    private:
        float baseSalary;
        float bonus;

    public:
        FullTimeEmployee(std::string _name,int _id,float _baseSalary, float _bonus);
        float calculateSalary() override;

};

class PartTimeEmployee : public Employee {
    private: 
        float hourlyRate;
        int hoursWorked;

    public:
        PartTimeEmployee(std::string _name,int _id,float _hourlyRate,int _hourWorked);
        float calculateSalary() override;
};

class Intern : public Employee
{
    private: 
        float stipend;

    public:
        Intern(std::string _name,int _id,float stipend);
        float calculateSalary() override;
};



#endif