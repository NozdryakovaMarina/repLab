#include <functions/functions.h>
#include <cassert>
#include <cmath>
#include <stdexcept>
#define PI 3.14159265
#define fig_get_coordinate fig->getCoordinateIndex

using namespace figure;
using namespace std;
 

TypeFigure Figure::getTypeFigure() { return type; }

void Figure::setTypeFigure(TypeFigure type) {this->type = type;}

	
double Figure::get_x1() {return x1;}

double Figure::get_x0() {return x0;}
	
double Figure::get_y1() {return y1;}

double Figure::get_y0() {return y0;}
	
double Figure::get_z1() {return z1;}

double Figure::get_z0() {return z0;}


Figure Figure::compute_volume() {
	switch (_type) {
		case Type::Sphere:
		double x = fabs(x1 - x0);
		double y = fabs(y1 - y0);
		double z = fabs(z1 - z0);
		r = sqrt(x*x + y*y + z*z);
		     return (4*PI*r*r*r)/3;
		case Type::Cylinder:
		double x = x1 - x0;
		double y = y1 - y0;
		double z = z1 - z0;
		h = sqrt(x*x + y*y + z*z);
		     return PI*h*r*r;
		case Type::Parallelepiped:
		double a = fabs(x1 - x0);
		double b = fabs(y1 - y2);
		double c = fabs(z1 - z0);
		     return a*b*c;
	     default:
	         throw runtime_error("Invalid function type.");
	}
}

Figure Figure::compute_area() { 
	switch (_type) {
		case Type::Sphere:
		double x = x1 - x0;
		double y = y1 - y0;
		double z = z1 - z0);
		r = sqrt(x*x + y*y + z*z);
		     return 4*PI*r*r;
	    case Type::Cylinder:
		
		     return 2*PI*r(r+h);
		case Type::Parallelepiped:
		double a = fabs(x1 - x0);
		double b = fabs(y1 - y0);
		double c = fabs(z1 - z0);
		     return 2*(a*b+b*c+a*c);
		default:
		    throw runtime_error("Invalid function type.");
	}
}

