#include <cmath>
class Triangle {
    private:
        double x[2];
        double y[2];
        double z[2];
        double d1;
        double d2;
        double d3;

    public:
        void setX(double, double);
        void setY(double, double);
        void setZ(double, double);
        void setD();
        double getArea();
        double getPerimeter();
        bool isEquilateral();
};

void Triangle::setX(double x0, double x1) {
       x[0] = x0; x[1] = x1;
}

void Triangle::setY(double y0, double y1) {
       y[0] = y0; y[1] = y1;
}

void Triangle::setZ(double z0, double z1) {
       z[0] = z0; z[1] = z1;
}

void Triangle::setD(){
    d1 = sqrt(pow((x[0]-y[0]), 2) + pow((x[1]-y[1]), 2));
    d2 = sqrt(pow((x[0]-z[0]), 2) + pow((x[1]-z[1]), 2));
    d3 = sqrt(pow((y[0]-z[0]), 2) + pow((y[1]-z[1]), 2));
}

double Triangle::getArea() {
    return 0.5*fabs( (y[0]-x[0])*(z[1]-x[1]) - (z[0]-x[0])*(y[1]-x[1]) );
}

double Triangle::getPerimeter(){
    return d1 + d2 + d3;
}

bool Triangle::isEquilateral(){
    if (d1==d2 && d2==d3 && d1==d3){
        return 1;
    }
    else{
        return 0;
    }
}

