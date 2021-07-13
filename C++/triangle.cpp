#include <iostream>
#include "triangle.hpp"

using namespace std;

int main() {
    double X[2];
    double Y[2];
    double Z[2];
    Triangle tri;

    cout << "Enter the coordinate of the vertices:  \n" << endl;
    for (int i = 0; i<2; i++){
        cout << "X" << i << " =  " ;
        cin >> X[i];
    }
    for (int j = 0; j<2; j++){
        cout << "Y" << j << " =  " ;
        cin >> Y[j];
    }
    for (int k = 0; k<2; k++){
        cout << "Z" << k << " =  ";
        cin >> Z[k];
    }
    tri.setX(X[0],X[1]);
    tri.setY(Y[0],Y[1]);
    tri.setZ(Z[0],Z[1]);
    tri.setD();
    cout << "Area = " << tri.getArea() << endl;
    cout << "Perimeter = " << tri.getPerimeter() << endl;
    cout << "Is it Equilateral?  " << tri.isEquilateral() << endl;
    return 0;
}
