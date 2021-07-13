/*Exercise 8.8. According to the lecture, the private members of a class can only be accessed indirectly
via mutator methods. What is the output of the following C++ program? Why is this possible? Explain
why this is a bad programming style.
*/

/* Solutions
1. Output of the program:

 5
0x6dfef8
10

2. The result (output) is possible because the methods defined in public scope
    are accompanied with explicit definitions.

3. Te given program is not a good programming style due to the following:

    i) The header file is not separated from the methods and the main file.
    ii) The inclusion of "using std::cout;" and "using std::endl;" at the beginning
         of the code is inappropriate in the file containing the class definition.
    iii) There is no proper indentation and spacing in the code, thus making it difficult
         to  understand and not readable.
    iv) There is no any comment to explain to some critical lines and thus again making the code
        difficult to comprehend.
*/


#include <iostream>
using std::cout;
using std::endl;
class Test{
private:
int N;
public:
void setN(int N_in) { N = N_in; };
int getN(){ return N; };
int* getptrN(){ return &N; };
};
int main(){
Test A;
A.setN(5);
int* ptr = A.getptrN();
cout << A.getN() << endl;
*ptr = 10;
cout << ptr << endl;
cout << A.getN() << endl;
return 0;
}
