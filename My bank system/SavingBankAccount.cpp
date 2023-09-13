//
// Created by sh3bo on 8/29/2023.
//

#include "SavingBankAccount.h"
#include "BankAcounts.h"
#include <iostream>
using namespace std;

SavingBankAccount::SavingBankAccount(int amount, int Id)
{
    if (amount>=Minimum_Balance)
        set_balance(amount);
    else
    {cout<<"amount is less than minimum balance"<<endl;
        return;}
    set_acount_id(Id);
}
int SavingBankAccount::withdrow(int amount)
{
    if (get_balance()-amount<Minimum_Balance)
        cout<<"can't withdraw as balalnce will be smaller than minimum balance"<<endl;
    else{
        set_balance(get_balance() - amount);

    }
}

int SavingBankAccount::deposite(int amount)
{
    if (amount<100)
        cout<<"can't withdraw as balalnce will be smaller than minimum balance";
    else{
        set_balance( get_balance() + amount);
    }
}