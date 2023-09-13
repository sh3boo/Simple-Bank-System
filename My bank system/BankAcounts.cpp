//
// Created by sh3bo on 8/29/2023.
//
#include "BankAcounts.h"


BankAcounts::BankAcounts(int t,int i)
{
    cout <<"this is the constructor "<<endl;
    acount_id=i;
    balancel= t ;
}
BankAcounts::BankAcounts()
{
    //cout <<"this is the empty constructor "<<endl;
    balancel= 0 ;

}

void BankAcounts::set_balance(int s)
{
    balancel=s;
}

void BankAcounts::set_acount_id(int s)
{
    acount_id =s;
}

int BankAcounts::get_balance()
{
    return balancel;
}

int BankAcounts::get_acount_id()
{
    return acount_id;
}

int BankAcounts::withdrow(int w)
{
    if (balancel>=w)
    {
        balancel-=w;
        return balancel;
    } else
    {
        cout <<"can't do this operation because whithdraw is biggger than balance ";
        return 0;
    }

}

int BankAcounts::deposite(int d)
{
    balancel+=d;
    return balancel;
}