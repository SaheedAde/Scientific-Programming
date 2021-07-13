#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

class Customer{
    private:
        string customerName;
        double currentBalance;
        int pinCode;


    public:
        void setCustomerName();
        void setCurrentBalance();
        void setPinCode();
        void printBalance();
        bool checkPIN();
        void drawMoney();
};

void Customer::setCustomerName(){
    customerName = "Elongated Muskrat" ;
}

void Customer::setCurrentBalance(){
    currentBalance = 10000.00;
}

void Customer::setPinCode(){
     pinCode = 3091;
}

void Customer::printBalance(){
    cout << "Current Balance:  " << "EUR " << currentBalance << endl;
}

bool Customer::checkPIN(){
    int p;
    cout << "Enter a PIN code to check if correct:  ";
    cin >> p;

    if (p == pinCode){
        return true;
    }
    else {
        return false;
    }
}

void Customer::drawMoney(){
    int p;
    double amount;
    cout << "Enter a PIN code to draw money:  ";
    cin >> p;
    cout << "Enter amount to draw:  ";
    cin >> amount;

    assert(p==pinCode);
    assert(amount < currentBalance && amount > 0);
    cout <<"Balance after draw:  " << currentBalance - amount << "EUR " << endl;
    if ((currentBalance - amount) < 10.00){
        cout << "Warning, new balance is less than EUR 10.00" << endl;
    }
}

