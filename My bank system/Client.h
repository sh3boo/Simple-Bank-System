//
// Created by sh3bo on 8/27/2023.
//

#ifndef MAIN_CPP_CLIENT_H
#define MAIN_CPP_CLIENT_H
#include "BankAcounts.h"

class Client {
private:
    string name ;
    string phone;
    string adress;
    BankAcounts his;
    static int Number_Clients ;
public:
    Client ();

    static int Get_Number_Clients () ;
    void Set_Name(string Name) ;
    void Set_Address(string Address_) ;
    void Set_Phone(string  phone_) ;
    string Get_Name() ;
    string Get_Address() ;
    string Get_Phone() ;

};


#endif //MAIN_CPP_CLIENT_H

