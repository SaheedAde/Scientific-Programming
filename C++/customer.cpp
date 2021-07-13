#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cassert>
#include "customer.hpp"

using namespace std;

int main(){
    Customer cus;
    cus.setCurrentBalance();
    cus.setCustomerName();
    cus.setPinCode();
    cus.drawMoney();

    return 0;
}
