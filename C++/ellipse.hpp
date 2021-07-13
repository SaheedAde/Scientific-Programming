#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

class Ellipse {
    private:
        double center[2];
        double a;
        double b;

    public:
        void setCenter(double, double);
        void setSemiAxis(double, double);
        void isInside(double, double);
        bool isCircle();
        void printFocalPoints();
        double getEccentricity();
};

void Ellipse::setCenter(double x0, double y0){
    center[0] = x0;
    center[1] = y0;
}

void Ellipse::setSemiAxis(double a0, double b0){
        a = a0;
        b = b0;
}

// Help function to calculate power
int powCal(int base, int power){

    for(int i=1;i<power; i++){
        base = base * base;
    }
    return base;
}

void Ellipse::isInside(double x, double y){
    double LHS = (powCal((x-center[0]), 2)/ (a*a)) + (powCal((y-center[1]), 2)/ (b*b));
    if (LHS < 1.0){
        cout << "Is the point inside? true" << endl;
    }
    else if (LHS<1.0){
        cout << "Is the point inside? false" << endl;

    }
    else{
        cout << "Is the point inside? true, but the point lie exactly on the ellipse" << endl;
    }

}

bool Ellipse::isCircle(){
    if (a==b){
        return true;
    }
    else{
        return false;
    }
}

void Ellipse::printFocalPoints(){
    double c = sqrt((a*a) - (b*b));
    if (a>b){
        cout << "The Foci are: (" << center[0]-c<< ","<< center[1]<< "), " << "("<<center[0]-c<< ","<< center[1]<< ")"<<endl;
    }
    else if (a<b){
        cout << "The Foci are: (" << center[0]<< ","<< center[1]-c << "), " << "("<<center[0]<< ","<< center[1]+c<< ")"<<endl;
    }
    else{
        cout << "The Foci are: (" << center[0]<< ","<< center[1]<< "), " << "("<<center[0]<< ","<< center[1]<< ")"<<endl;
    }
}

double Ellipse::getEccentricity(){
    double nMin = min(a, b);
    double nMax = max(a, b);
    return sqrt(1-powCal(nMin/nMax, 2));
}

//The position of the focal points of a circle are the centres of the ellipse.
// The eccentricity of a circle is 0, since a=b in the case of a circle.

