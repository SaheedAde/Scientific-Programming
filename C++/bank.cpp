#include <iostream>
#include <cassert>
#include "bank.hpp"

using namespace std;

Bank::Bank(int dim) {
    this -> dim = dim;
    assert (dim>0);
    account = new Account[dim];
}
Bank::~Bank(){

    if (dim!=0){
        delete[] account;
    }
}

void Bank::setAccount(int i, Account &obj){
    assert(i>=0);
    account[i] = Account(obj.getAccNum(), obj.getCurrBal(), obj.getFee());
}

void Bank::setAccount(int i, SavingsAccount &obj){
    assert(i>=0);
    account[i] = SavingsAccount(obj.getAccNum(), obj.getCurrBal(), obj.getFee(), obj.getIntRate());
}

void Bank::setAccount(int i, CurrentAccount &obj){
    assert(i>=0);
    account[i] = CurrentAccount(obj.getAccNum(), obj.getCurrBal(), obj.getFee(), obj.getOverdraft());
}

Bank::Bank(const Bank& rhs) {
     dim = rhs.dim;
     if (dim == 0) {
            account = (Account*) new Account;
     }
     else {
             account = new Account[dim];

             for (int j=0; j<dim; ++j) {
                       account[j] = rhs[j];
              }
     }
     // just for demonstration purposes
     cout << "copy constructor, length " << dim << "\n";
}

Bank& Bank::operator=(const Bank& rhs) {
    if (this != &rhs) {
          if (dim != rhs.dim) {
               if (dim > 0) {
                  delete[] account;
                }
           dim = rhs.dim;
           if (dim > 0) {
                 account = new Account[dim];
           }
           else {
                 account = (Account*) 0;
            }
         }
             for (int j=0; j<dim; ++j) {

                  account[j] = rhs[j];
        }
    }
    // just for demonstration purposes
    cout << "deep copy, length " << dim << "\n";
    return *this;
}

const Account& Bank::operator[](int k) const {
    assert(k>=0 && k<dim);
    return account[k];
}

Account& Bank::operator[](int k) {
    assert(k>=0 && k<dim);
    return account[k];
}


void Bank::updateAccounts(){

    for (int j=0; j<dim; j++){

            account[j].update();

    }
}

void Bank::print(){

    for (int j=0; j<dim; j++){

            account[j].print();

    }
}
