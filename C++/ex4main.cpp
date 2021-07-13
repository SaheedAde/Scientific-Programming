#include <iostream>
#include <cmath>
#include "bank.cpp"

using std::cout;

int main(){

    Account account(1234567, 1200.55, 0.50);
    SavingsAccount savings(220209000, 3200.00, 2.00, 0.05);
    CurrentAccount current(400, 220209000, 3200.00, 2.00);
    Bank bank(3);
    bank.setAccount(0, account);
    bank.setAccount(1, savings);
    bank.setAccount(2, current);
    account.print();
    savings.print();
    current.print();

    // Update account
    account.update();
    savings.update();
    current.update();
    cout <<"---------------------------------------------------------------------------------------------------------\n";
    account.print();
    savings.print();
    current.print();



    return 0;
}

