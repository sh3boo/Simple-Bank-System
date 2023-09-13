//
// Created by sh3bo on 8/27/2023.
//

#ifndef MAIN_CPP_BANKACOUNTS_H
#define MAIN_CPP_BANKACOUNTS_H
#include <iostream>
using namespace std;
class BankAcounts {
private:
    int acount_id;
    int balancel;

public:
    BankAcounts(int t ,int i);
    BankAcounts();
    void set_balance (int s);
    void set_acount_id (int s);
    int get_balance();
    int get_acount_id();
    virtual int withdrow (int w );
    virtual int deposite (int d);

};


#endif //MAIN_CPP_BANKACOUNTS_H
