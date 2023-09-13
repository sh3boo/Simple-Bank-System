#include <iostream>
#include "BankApplication.h"
#include "Client.h"
#include "BankAcounts.h"
#include "SavingBankAccount.h"
using namespace std;
int main() {
    BankApplication ba;
    while (true) {
        int choice;
        cout << "Welcome to FCI Banking Application \n"
                "1. Create a New Account \n"
                "2. List Clients and Accounts \n"
                "3. Withdraw Money \n"
                "4. Deposit Money \n"
                "5. Exit\n";
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting the program.\n";
            break;  // Exit the loop
        } else if (choice>5)
            cout <<"please Enter a valid number";

        switch (choice) {
            case 1:
                int type;
                cout << "What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2";
                cin >> type;
                switch (type) {
                    case 1:
                        ba.add_client();
                        ba.add_account(type);
                        cout << "Your account is created successfully.\n";
                        break;
                    case 2:
                        ba.add_client();
                        ba.add_account(type);
                        cout << "Your account is created successfully.\n";
                        break;
                }
                break;
            case 2:
                ba.printinfo();
                break;
            case 3:
                ba.withdraw();
                break;
            case 4:
                ba.deposit();
                break;
        }
    }

    return 0;



}
