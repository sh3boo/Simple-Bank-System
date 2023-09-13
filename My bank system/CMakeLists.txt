cmake_minimum_required(VERSION 3.23)
project(My_bank_system_)

set(CMAKE_CXX_STANDARD 14)

add_executable(My_bank_system_ main.cpp BankAcounts.h SavingBankAccount.cpp SavingBankAccount.h BankAcounts.cpp Client.cpp Client.h)
