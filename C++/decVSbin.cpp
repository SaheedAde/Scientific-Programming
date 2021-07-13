#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include<bits/stdc++.h>
#include <cassert>

using namespace std;

string dec2bin(int n){

    assert(n>=0 && n<=65535);

    string strBin = "";  // empty string
    int k = n;
    int c;

    while(k!=0){

        c = k % 2;
        if (c == 0){
            strBin = '0' + strBin;
        } else {
            strBin = '1' + strBin;
        }
        k = (k-c)/2;
    }

    return strBin;

}

int bin2dec(string s){
    int i = s.length();
    int j;
    int c = 0;
    int k;
    int sumDec;
    int resDec = 0;
    for (j = 0 ;j < i; j++){

        if (s.at(i-j-1) == '1' ){
            k = c;
            if(k == 0){
                sumDec = 1;
            } else {
                sumDec = 1;
                for(k = 1; k < c+1 ; k++){
                    sumDec = sumDec * 2;
                }
            }
        } else {
            sumDec=0;
        }
        resDec=resDec+sumDec;
        c++;
    }

    return resDec;
}

int main(){
    int n;
    cout << "Enter a number, n: ";
    cin >> n;
    string s=dec2bin(n);
    int num = bin2dec(s);
    cout << "Binary representation: " << s << endl;
    cout << "Decimal representation: "<< num << endl;

    return 0;
}
