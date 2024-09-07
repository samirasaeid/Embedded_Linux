#ifndef BANK_ACCOUNT
#define BANk_ACCOUNT

#include <iostream>
#include <string>


class BankAccount{
    private:
        int accountNumber;
        std::string accountHolderName;
        float balance;

    public:
        BankAccount(int account_num,std::string name,float _balance);
        int getAccountNumber();
        std::string getAccountHolderName();
        float getAccountBalance();
        virtual void deposite(float amount)=0;
        virtual void withdraw(float amount)=0;
        virtual void display()=0;
        
};

class CheckingAccount : public BankAccount{
    float checkingAccountBalance;
    public:
        CheckingAccount(int account_num,std::string name,float _balance);
        void deposite(float amount) override;
        void withdraw(float amount) override;
        void display() override;
        float getBalance();
};


#endif