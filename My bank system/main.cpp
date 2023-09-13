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
                // Add code for listing clients and accounts
                break;
            case 3:
                ba.withdraw();

                // Add code for withdrawing money
                break;
            case 4:
                ba.deposit();
                // Add code for depositing money
                break;
        }
    }

    return 0;

//    BankApplication a;
//    SavingBankAccount ff(100,8);
//    a.add_client("ahmed","0123456","elsaf");
//    a.add_account(ff);
//    a.printinfo();


}