#include "Client.h"
#include "BankAcounts.h"
#include <iostream>
using namespace std;

int Client::Number_Clients = 0; // Definition of the static member
//
// Created by sh3bo on 8/27/2023.
//


Client::Client()
{
    name="";
    phone="";
    adress="";


}

int Client::Get_Number_Clients()
{
    Number_Clients++;
    return Number_Clients;
}


void Client::Set_Name( string  Name) {
    name = Name ;
}

void Client::Set_Address(string  Address_) {
    adress = Address_ ;
}

void Client::Set_Phone(string  phone_) {
    phone = phone_ ;
}

string Client::Get_Name() {
    return name ;
}

string Client::Get_Address() {
    return adress ;
}

string Client::Get_Phone() {
    return phone ;
}