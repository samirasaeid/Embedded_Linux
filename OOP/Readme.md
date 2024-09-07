-------------------------------------------------------OOP --------------------------------------
Exercise 1: Bank Account (Beginner)
------------------------------------
#OOP Concepts Covered: Abstraction, Encapsulation

● Objective: Implement a simple class to represent a bank account with basic operations.

Requirements:

    ● Create a class BankAccount with private attributes: accountNumber,
    accountHolderName, and balance.
    ● Implement the following public methods:
        ○ A constructor to initialize the account.
        ○ deposit(float amount) - to add money to the balance.
        ○ withdraw(float amount) - to subtract money if balance permits.
        ○ display() - to print account details and balance.
    ● Encapsulation: Ensure that all data members are private and accessed only through
    public methods.
    Bonus: Add a method getBalance() to return the current balance and demonstrate how
    private data can be securely accessed.
###################################################################
Exercise 2: Shape Hierarchy (Intermediate)
--------------------------------------------
OOP Concepts Covered: Abstraction, Inheritance, Polymorphism

● Objective: Implement a shape hierarchy with inheritance and virtual functions for
calculating area.

Requirements:

    ● Create an abstract base class Shape with the following:
        ○ A pure virtual method float getArea().
        ○ A protected member name to store the shape’s name.
    ● Derive the following classes from Shape:
        ○ Circle(float radius) that overrides getArea().
        ○ Rectangle(float width, float height) that overrides getArea().
        ○ Triangle(float base, float height) that overrides getArea().
    Bonus: Add a printShapeInfo() method to Shape to display the shape's name and use this
    in derived classes.
####################################################################
Exercise 3: Employee Management System (Advanced)
---------------------------------------------------
OOP Concepts Covered: Abstraction, Inheritance, Encapsulation, Polymorphism

● Objective: Build an employee management system where different types of employees
    have specific salary structures.

Requirements:

    ● Create a base class Employee with private attributes: name and id. It should have the
    following:
        ○ A constructor to initialize the attributes.
        ○ A public method void displayDetails() to print the employee's name and
        ID.
        ○ A pure virtual method float calculateSalary() for calculating salary.
    ● Derive the following classes:
        ○ FullTimeEmployee: Has additional attributes baseSalary and bonus.
            Overrides calculateSalary() to return baseSalary + bonus.
        ○ PartTimeEmployee: Has attributes hourlyRate and hoursWorked.
            Overrides calculateSalary() to return hourlyRate * hoursWorked.
        ○ Intern: Has a stipend attribute and overrides calculateSalary() to return
            the stipend.

    ● Polymorphism: Create a function that takes an Employee pointer/reference and prints
        the salary for different employee types.
    Bonus: Add a list to store multiple employees and create methods to add and remove
employees.
