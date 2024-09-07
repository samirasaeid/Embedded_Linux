#include <iostream>
#include "bank_account.h"

int main(){
    CheckingAccount account(256431,"Samira Saeid",55.5);
    account.deposite(10);
    account.withdraw(5);
    account.getBalance();
    account.display();



    return 0;
}