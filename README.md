# Simple-Bank-System
this is a simple bank system developed using c++ language 
Banking Application
This is a simple console-based banking application written in C++. The application allows users to create bank accounts, list clients and accounts, withdraw money, deposit money, and exit the program.

Features
Create a new account: Users can create either a basic or a saving account.

List clients and accounts: Users can view the details of all clients and their associated accounts.

Withdraw money: Users can withdraw money from their accounts.

Deposit money: Users can deposit money into their accounts.

Getting Started
To run the application, follow these steps:

Clone the repository to your local machine.

Compile the C++ code using your preferred C++ compiler. For example, you can use g++:

shell
Copy code
g++ main.cpp BankApplication.cpp Client.cpp BankAcounts.cpp SavingBankAccount.cpp -o bank_app
Run the compiled executable:

shell
Copy code
./bank_app
Follow the on-screen instructions to interact with the banking application.

Usage
The application provides the following options in the main menu:

Create a New Account: Users can create a new bank account by entering their details and selecting the account type (Basic or Saving).

List Clients and Accounts: Users can view the details of all clients and their associated accounts.

Withdraw Money: Users can withdraw money from their accounts. The application will display the current balance and prompt the user to enter the withdrawal amount.

Deposit Money: Users can deposit money into their accounts. The application will display the current balance and prompt the user to enter the deposit amount.

Exit: Users can exit the application.

Code Structure
main.cpp: Contains the main function that drives the application and handles user interactions.

BankApplication.h and BankApplication.cpp: Define and implement the BankApplication class, which manages client and account operations.

Client.h and Client.cpp: Define and implement the Client class, which represents bank clients and their information.

BankAcounts.h and BankAcounts.cpp: Define and implement the BankAcounts class, which represents bank accounts and their operations.

SavingBankAccount.h and SavingBankAccount.cpp: Define and implement the SavingBankAccount class, which is a specialized type of bank account.

Contributing
Feel free to contribute to this project by submitting pull requests or opening issues. If you encounter any bugs or have suggestions for improvements, please let us know.

License
This project is open-source and available under the MIT License.
