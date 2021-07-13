#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cassert>

using namespace std;

string int2roman(int n){
    assert (n>= 1 && n<=3999);
    int numArray[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1}; //base values
    string strArray[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};  //roman symbols
    string convStr = " ";
    int i = 0;

    while(n){    //repeat process until n is not 0
        while(n/numArray[i]){
            convStr = convStr + strArray[i];
            n -= numArray[i];
        }
        i++;
    }
    return convStr;
}

// helper function for roman2int(string s)
int eqNum(char c){

    switch(c){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
}

int roman2int(string s){
    int rmLen, i;
    int crRmValue = 0;
    int crAns = 0;

    rmLen = s.length()-1;   // length of the the roman numeral-1
    // loop the roman numeral string from the back
    for (i=rmLen; i>=0; i--){
		if (eqNum(s[i])>=crRmValue){
			crAns += eqNum(s[i]);
		}
		else {
			crAns -= eqNum(s[i]);
		}
        crRmValue = eqNum(s[i]);
    }
    return crAns;
}

int main()
{
    int n;
    string s;
    cout << "Enter a number n,  1 <= n <= 3999:  ";
    cin >> n;
    cout << n << " in Roman numeral is "<< int2roman(n) << endl;

    cout << "Enter a Roman numeral between I and MMMCMXCIX:  " << endl;
    cin >> s;
    cout << s << " in decimal is " << roman2int(s) << endl;

    return 0;
}
