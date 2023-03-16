#include <functions/functions.h>

#include <cassert>
#include <cmath>
#include <stdexcept>

using namespace figure;
using namespace std;

Type Figure::GetType() const {
	return _type;
	}
	
double Figure::GetX() const {
	return _x;
	}
	
double Figure::GetY() const {
	return _y;
	}
	
double Figure::GetZ() const {
	return _z;
	}
	
/*double Figure::GetRadius() const {
		 return sqrt(pow((x-x0),2)+pow((y-y0),2)+pow((z-z0),2));
	}
	
double Figure::GetHeight() const {
	     return sqrt(pow(x-x0,2)+pow(y-y0,2));
     }
	
	
double Figure::compute_volume() const {
	switch (_type) {
		case Type::Sphere:
		     return (4*PI*pow(R,3))/3;
		case Type::Cylinder:
		     return PI*h*pow(r,2);
		case Type::Parallelepiped:
		     return a*b*c;
	     default:
	         throw runtime_error("[Figure::compute_area] Invalid function type.");
	}
}

double Figure::compute_area() const {
	switch (_type) {
		case Type::Sphere:
		     return 4*PI*pow(R,2);
	    case Type::Cylinder:
		     return 2*PI*r(r+h);
		case Type::Parallelepiped:
		     return 2*(a*b+b*c+a*c);
		default:
		    throw runtime_error("[Figure::compute_volume] Invalid function type.");
	}
}*/

/*int sum_stub(int lhs, int rhs) {
    return lhs + rhs;
}*/
