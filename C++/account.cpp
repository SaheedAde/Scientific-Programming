#include <iostream>
#include <cmath>
#include <cassert>
#include "account.hpp"

using std::cout;
using std::endl;

// Base class: Account
Account::Account(){
    //cout << "Base class: Account()" << endl;
}
Account::Account(int acc_num, double curr_bal, double f){
    account_number = acc_num;
    current_balance = curr_bal;
    fee = f;
}
Account::~Account() {
    //cout << "Base class: ~Account()" << endl;
}
// Copy Constructor
Account::Account(const Account& x){
    account_number = x.getAccNum();
    current_balance = x.getCurrBal();
    fee = x.getFee();
}
// Assignment Operator
Account& Account::operator=(const Account& x){
    account_number = x.getAccNum();
    current_balance = x.getCurrBal();
    fee = x.getFee();
}
void Account::setAccNum(int acc_num){
    account_number = acc_num;
}
int Account::getAccNum() const {
    return account_number;
}
void Account::setCurrBal(double curr_bal){
    current_balance = curr_bal;
}
double Account::getCurrBal() const{
    return current_balance;
}
void Account::setFee(double f) {
    fee = f;
}
double Account::getFee() const {
     return fee;
}
void Account::deposit(double sum) {
    current_balance = getCurrBal() + sum;
}
void Account::withdraw(double sum) {
    assert(fabs(getCurrBal()-sum) > 1e-10);
    current_balance = getCurrBal() - sum;
}
void Account::chargeFee() {
    current_balance = getCurrBal() - fee;
}
void Account::print() {
    cout << "Account information:  \n";
    cout << "Account number: " << getAccNum() << "\n";
    cout << "Balance: EUR " << getCurrBal() << "\n";
}
//void Account::update() {
 //   chargeFee();
//}


// Derived class: SavingsAccount
SavingsAccount::SavingsAccount(){
    //cout << "Derived class: SavingsAccount() \n";
}
SavingsAccount::SavingsAccount(int accountNumber, double currentBalance, double chFee, double int_rt){
    interest_rate = int_rt;
    setAccNum(accountNumber);
    setCurrBal(currentBalance);
    setFee(chFee);
}
// Copy Constructor
SavingsAccount::SavingsAccount(const SavingsAccount &x){
    setCurrBal(x.getCurrBal());
    setAccNum(x.getAccNum());
    setFee(x.getFee());
    interest_rate=x.getIntRate();
}
SavingsAccount::~SavingsAccount(){
    //cout << "Derived class: ~SavingsAccount() \n";
}
void SavingsAccount::setIntRate(double int_rt){
    interest_rate = int_rt;
}
double SavingsAccount::getIntRate() const{
    return interest_rate;
}
void SavingsAccount::addInterest(){
    double interest = interest_rate * getCurrBal();
    setCurrBal(interest + getCurrBal());
}
void SavingsAccount::print(){
    cout << "Savings Account information:  \n";
    cout << "Account number: " << getAccNum() << "\n";
    cout << "Balance: EUR " << getCurrBal() << "\n";
    cout << "Interest rate: " << getIntRate() << endl;
}
//void SavingsAccount::update() {
    //chargeFee();
    //addInterest();
//}

// Derived Class: CurrentAccount
CurrentAccount::CurrentAccount() {
    //cout << "Derived class: CurrentAccount() \n";
}

CurrentAccount::CurrentAccount(double overdraft, int accountNumber, double currentBalance, double chFee){
    overdraft_limit = overdraft;
    setAccNum(accountNumber);
    setCurrBal(currentBalance);
    setFee(chFee);
}
// Copy Constuctor
CurrentAccount::CurrentAccount(const CurrentAccount &x){
    setCurrBal(x.getCurrBal());
    setAccNum(x.getAccNum());
    setFee(x.getFee());
    overdraft_limit=x.getOverdraft();
}


CurrentAccount::~CurrentAccount() {
     //cout << "Derived class: ~CurrentAccount() \n";
}

void CurrentAccount::setOverdraft(double overdraft){
    overdraft_limit = overdraft;
}

double CurrentAccount::getOverdraft() const {
    return overdraft_limit;
}

void CurrentAccount::printMessage() {

    if (getOverdraft()-getCurrBal() < 0){

        cout << "Warning: You are in overdraft! \n";
    }
}

void CurrentAccount::print(){

    cout << "Current Account information:  \n";
    cout << "Account number: " << getAccNum() << "\n";
    cout << "Balance: EUR " << getCurrBal() << "\n";
    cout << "Overdraft limit: EUR " << getOverdraft() << endl;


}
//void CurrentAccount::update(){
    //chargeFee();
    //printMessage();

//}
