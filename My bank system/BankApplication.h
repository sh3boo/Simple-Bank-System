#include <iostream>
#include <fstream>
#include <string>
#include "BankAcounts.h"
#include "Client.h"
#include "SavingBankAccount.h"
#include <vector>
#include <sstream> // Add this line to include <sstream>
static int id = 0 ;
class BankApplication {
private:
    BankAcounts ba;
    Client cl;
public:
    void add_client() {
       // Client cc;
        string n, p, a;
        cout << "Enter your Name: ";
        cin >> n;
        cout << "Enter your Phone Number: ";
        cin >> p;
        cout << "Enter your Address: ";
        cin >> a;
        cl.Set_Phone(p);
        cl.Set_Name(n);
        cl.Set_Address(a);

        ofstream newstore("newsto.txt", ios::app); // Open for appending
        if (!newstore.is_open()) {
            cerr << "Error: Could not open the file." << endl;
            return; // Exit the function
        }

        // Serialize the Client object
        newstore << "Client\n";
        newstore << "Name: " << cl.Get_Name() << "\n";
        newstore << "Phone: " << cl.Get_Phone() << "\n";
        newstore << "Address: " << cl.Get_Address() << "\n";

        newstore.close();
    }

    void add_account(int t) {
        if (t == 1) {
            int b;
            //BankAcounts hh;
            cout << "Enter your Starting Balance: ";
            cin >> b;
            ba.set_balance(b);
            ba.set_acount_id(id);
            id++;

            ofstream newstore("newsto.txt", ios::app); // Open for appending
            if (!newstore.is_open()) {
                cerr << "Error: Could not open the file." << endl;
                return; // Exit the function
            }
            // Serialize the BankAcounts object
            newstore << "BankAcounts\n";
            newstore << "Account ID: " << ba.get_acount_id() << "\n";
            newstore << "Balance: " << ba.get_balance() << "\n";
            newstore.close();
        } else if (t == 2) {
            int b;
            SavingBankAccount hh(10000000000000000, 999999999999);
            cout << "Enter your Starting Balance: ";
            cin >> b;
            hh.set_balance(b);
            hh.set_acount_id(id);
            id++;
            ofstream newstore("newsto.txt", ios::app); // Open for appending
            if (!newstore.is_open()) {
                cerr << "Error: Could not open the file." <<endl;
                return; // Exit the function
            }

            // Serialize the SavingBankAccount object
            newstore << "SavingBankAccount\n";
            newstore << "Account ID: " << hh.get_acount_id() << "\n";
            newstore << "Balance: " << hh.get_balance() << "\n";
            newstore.close();
        }
    }
    int printinfo() {
        string line;
        ifstream newstore("newsto.txt");
        if (!newstore.is_open()) {
            cerr << "Error: Could not open the file." << endl;
            return 1; // Exit with an error code
        }
        while (getline(newstore, line)) {
           cout << line << endl;
        }
        newstore.close();
        return 0; // Success
    }
    int withdraw() {
        cout << "Enter your Name : ";
        string name;
        cin >> name;
        string line;
        int lineNumber = 0;
        ifstream input("newsto.txt");
        ofstream tempFile("temp.txt");

        if (!input.is_open() || !tempFile.is_open()) {
            cerr << "Error: Could not open the files." << endl;
            return 1;
        }

        bool clientFound = false;

        while (getline(input, line)) {
            lineNumber++;
            if (line.find(name) != string::npos) {
                cout << "Here is your data : " << endl;
                for (int i = 0; i < 5; i++) {
                    // Read and write the selected client data
                    getline(input, line);
                    tempFile << line << endl;
                    cout << line << endl;
                }

                string targetSubstring = "Balance: ";
                size_t pos = line.find(targetSubstring);
                if (pos != string::npos) {
                    int oldBalance = 0; // Initialize oldBalance
                    try {
                        oldBalance = stoi(line.substr(pos + targetSubstring.length()));
                    } catch (const std::invalid_argument& e) {
                        cerr << "Error: Invalid balance value." << endl;
                        return 1;
                    }

                    cout << "Enter the amount that you want to withdraw: ";
                    int withdrawalAmount;
                    cin >> withdrawalAmount;

                    int newBalance = oldBalance - withdrawalAmount;
                    string sub = to_string(newBalance);
                    cout << "Your new balance: " << newBalance << endl;

                    // Replace the old balance with the new balance in the temporary file
                    tempFile << "Balance: " << sub << endl;
                } else {
                    cerr << "Error: Balance not found in data." << endl;
                }

                // Mark the client as found
                clientFound = true;
            } else {
                // Write other lines to the temporary file
                tempFile << line << endl;
            }
        }

        input.close();
        tempFile.close();

        if (remove("newsto.txt") != 0) {
            cerr << "Error: Could not remove the original file." << endl;
            return 1;
        }
        if (rename("temp.txt", "newsto.txt") != 0) {
            cerr << "Error: Could not rename the temporary file." << endl;
            return 1;
        }

        if (!clientFound) {
            cerr << "Error: Client not found." << endl;
            return 1;
        }

        return 0;
    }
    int deposit() {
        cout << "Enter your Name : ";
        string name;
        cin >> name;
        string line;
        int lineNumber = 0;
        ifstream input("newsto.txt");
        ofstream tempFile("temp.txt");

        if (!input.is_open() || !tempFile.is_open()) {
            cerr << "Error: Could not open the files." << endl;
            return 1;
        }

        bool clientFound = false;

        while (getline(input, line)) {
            lineNumber++;
            if (line.find(name) != string::npos) {
                cout << "Here is your data : " << endl;
                for (int i = 0; i < 5; i++) {
                    // Read and write the selected client data
                    getline(input, line);
                    tempFile << line << endl;
                    cout << line << endl;
                }

                string targetSubstring = "Balance: ";
                size_t pos = line.find(targetSubstring);
                if (pos != string::npos) {
                    int oldBalance = 0; // Initialize oldBalance
                    try {
                        oldBalance = stoi(line.substr(pos + targetSubstring.length()));
                    } catch (const std::invalid_argument& e) {
                        cerr << "Error: Invalid balance value." << endl;
                        return 1;
                    }

                    cout << "Enter the amount that you want to deposit: ";
                    int depositAmount;
                    cin >> depositAmount;

                    int newBalance = oldBalance + depositAmount;
                    string sub = to_string(newBalance);
                    cout << "Your new balance: " << newBalance << endl;

                    // Replace the old balance with the new balance in the temporary file
                    tempFile << "Balance: " << sub << endl;
                } else {
                    cerr << "Error: Balance not found in data." << endl;
                }

                // Mark the client as found
                clientFound = true;
            } else {
                // Write other lines to the temporary file
                tempFile << line << endl;
            }
        }

        input.close();
        tempFile.close();

        if (remove("newsto.txt") != 0) {
            cerr << "Error: Could not remove the original file." << endl;
            return 1;
        }
        if (rename("temp.txt", "newsto.txt") != 0) {
            cerr << "Error: Could not rename the temporary file." << endl;
            return 1;
        }

        if (!clientFound) {
            cerr << "Error: Client not found." << endl;
            return 1;
        }

        return 0;
    }


//    int withdraw()
//    {
//        cout <<"Enter your Name : ";
//        string name;
//        cin>>name;
//        string line;
//        int lineNumber = 0;
//        ifstream newstore("newsto.txt");
//        if (!newstore.is_open()) {
//            cerr << "Error: Could not open the file." << endl;
//            return 1; // Exit with an error code
//        }
//        while (getline(newstore, line)) {
//            lineNumber++;
//            if (line.find(name) != string::npos) {
//                cout <<"Here is your data : "<<endl;
//                for (int i = 0; i < 5 ; i++ )
//                {
//                    getline(newstore, line);
//                    cout <<line<<endl;
//                }
//                string bbaa = "Balance: ";
//                getline(newstore,bbaa);
//                string sub=line.substr(8);
//                int su= stoi(sub);
//                cout <<"Enter the amount that you want to withdra :"<<endl;
//                int am;
//                cin>>am;
//                int finalbalance=su-am;
//                string fi = to_string(finalbalance);
//                cout <<"there is your new balance : "<<finalbalance<<endl;
//                line.erase();
//                line.append("");
//            }
//        }
//
//    }
};