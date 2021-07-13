#ifndef _BANK_
#define _BANK_
#include "account.cpp"
#include <iostream>

class Bank {
private:
    Account* account;
    int dim;

public:

    Bank(int);
    Bank(const Bank&);
    Bank& operator=(const Bank&);
    ~Bank();
    void updateAccounts();
    void setAccount(int, Account&);
    void setAccount(int, SavingsAccount&);
    void setAccount(int, CurrentAccount&);
    void print();
    const Account& operator[](int k) const;
    Account& operator[](int k);

};

#endif // _BANK_
