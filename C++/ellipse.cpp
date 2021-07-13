#include <cmath>
#include <cstdio>
#include "ellipse.hpp"

using namespace std;
int main() {
    double C[2], a0, b0;
    double P[2];
    Ellipse elp;

    cout << "Enter the coordinate of the center:  " << endl;
    for (int i = 0; i<2; i++){
        cout << "C" << i << " =  " ;
        cin >> C[i];
    }

    cout << "Enter the coordinate of the test point:  " << endl;
    for (int j = 0; j<2; j++){
        cout << "P" << j << " =  " ;
        cin >> P[j];
    }

    cout << "Enter first axis-length, a:  ";
    cin >> a0;
    cout << "Enter second axis-length, b:  ";
    cin >> b0;
    cout <<"--------------------------------------------"<< endl;
    elp.setCenter(C[0], C[1]);
    elp.setSemiAxis(a0, b0);

    elp.isInside(P[0], P[1]);
    elp.printFocalPoints();
    cout << "Is it a circle?  " << elp.isCircle() << endl;
    cout << "Eccentricity:  " << elp.getEccentricity() << endl;
    return 0;
}
