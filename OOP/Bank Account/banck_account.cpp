#include "bank_account.h"

BankAccount::BankAccount(int account_num,std::string name,float _balance) : accountNumber{account_num}, accountHolderName{name}, balance{_balance}
{
}
int BankAccount::getAccountNumber(){
    return accountNumber;
}
std::string BankAccount::getAccountHolderName(){
    return accountHolderName;
}
float BankAccount::getAccountBalance(){
    return balance;
}

CheckingAccount::CheckingAccount(int account_num,std::string name,float _balance):BankAccount(account_num,name,_balance) {
    checkingAccountBalance = getAccountBalance();
}
void CheckingAccount::deposite(float amount){
    if(amount > 0){
        checkingAccountBalance += amount;
    }else{
        std::cout<<"Not desposite found"<<std::endl;
    }
}
void CheckingAccount::withdraw(float amount){
    checkingAccountBalance -= amount;
}
float CheckingAccount::getBalance(){
    return checkingAccountBalance;
}
void CheckingAccount::display(){
    std::cout<<"Account Number: "<<getAccountNumber()<<std::endl;
    std::cout<<"Account Owner Name: "<<getAccountHolderName()<<std::endl;
    std::cout<<"Account Balance: $ "<<getBalance()<<std::endl;
}
