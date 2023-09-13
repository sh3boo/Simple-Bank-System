// SavingAccount.h
#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include "BankAcounts.h" // Include the parent class header
#include <iostream>
class SavingBankAccount : public BankAcounts{
private:
    int Minimum_Balance = 1000 ;
public:
    SavingBankAccount(int amount, int Id) ;
    int withdrow(int amount) override ;
    int deposite(int amount) override ;
};

#endif // SAVINGACCOUNT_H
