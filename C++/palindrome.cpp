#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

bool isPalindrome(string word){
    int fCounter, bCounter;
    fCounter = 0;
    bCounter = word.length()-1;

    while (fCounter<bCounter){
        if(tolower(word[fCounter]) != tolower(word[bCounter])){
            return false;
        }
        else{
            fCounter++;
            bCounter--;
        }
    }
    return true;
}

int main(){
    string word;
    bool checkWord;

    cout << "Enter a word:  ";
    cin >> word;
    checkWord = isPalindrome(word);
    if (checkWord == true){
        cout << word << " is a Palindrome!" << endl;
    }
    else{
        cout << word << "is NOT a Palindrome!" << endl;
    }

   return 0;
}
