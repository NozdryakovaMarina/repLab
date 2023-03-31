#include <functions/functions.h>
#include <cassert>
#include <cmath>
#include <stdexcept>
#define PI 3.14159265

using namespace figure;
using namespace std;
 

TypeFigure Figure::getTypeFigure() const { return _type; }

Figure::Figure(): _type(TypeFigure::Sphere), _x1(0), _y1(0), _z1(0), _x2(1), _y2(1), _z2(1) {}

Figure::Figure(const TypeFigure type, const double x1, const double y1, const double z1, const double x2, const double y2, const double z2) : _type(type), _x1(x1), _y1(y1), _z1(z1), _x2(x2), _y2(y2), _z2(z2) {}

Figure::Figure(const TypeFigure type, const double x1, const double y1, const double z1, const double x2, const double y2, const double z2, const double x3, const double y3, const double z3): _type(type), _x1(x1), _y1(y1), _z1(z1), _x2(x2), _y2(y2), _z2(z2), _x3(x3), _y3(y3), _z3(z3) {}

Figure Figure::create_sphere(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2) {
	return Figure(TypeFigure::Sphere, x1, y1, z1, x2, y2, z2);
}

Figure Figure::create_cylinder(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2, const double x3, const double y3, const double z3) {
	return Figure(TypeFigure::Cylinder, x1, y1, z1, x2, y2, z2, x3, y3, z3);
}

Figure Figure::create_parallelepiped(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2) {
	return Figure(TypeFigure::Parallelepiped, x1, y1, z1, x2, y2, z2);
}
	
double Figure::get_x1() const {return _x1;}

double Figure::get_x2() const {return _x2;}

double Figure::get_x3() const {return _x3;}
	
double Figure::get_y1() const {return _y1;}

double Figure::get_y2() const {return _y2;}

double Figure::get_y3() const {return _y3;}
	
double Figure::get_z1() const {return _z1;}

double Figure::get_z2() const {return _z2;}

double Figure::get_z3() const {return _z3;}

double Figure:: calc_of_volume_sphere()
{
	double x = _x2 - _x1;
	double y = _y2 - _y1;
	double z = _z2 - _z1;
    double r = sqrt(x*x + y*y + z*z);
    return (4*PI*r*r*r)/3;
}

double Figure::calc_of_volume_cylinder()
{
	double x = _x2 - _x1;
	double y = _y2 - _y1;
	double z = _z2 - _z1;
	double h = sqrt(x*x + y*y + z*z);
	double x0 = _x3 - _x2;
	double y0 = _x3 - _x2;
	double z0 = _z3 - _z2;
	double r = sqrt(x0*x0 + y0*y0 + z0*z0);
	return PI*h*r*r;
}

double Figure::calc_of_volume_parallelepiped()
{
	double a = fabs(_x2 - _x1);
	double b = fabs(_y2 - _y1);
	double c = fabs(_z2 - _z1);
	return a*b*c; 
}

double Figure::compute_volume() {
	switch (_type) {
		case TypeFigure::Sphere: 
		{
		     return calc_of_volume_sphere();
		}
		case TypeFigure::Cylinder: 
		{
		     return calc_of_volume_cylinder();
		}
		case TypeFigure::Parallelepiped: 
		{
		     return calc_of_volume_parallelepiped(); 
		}
	     default:
	         throw runtime_error("[Figure::compute_volume]Invalid function type.");
	}
}

double Figure::calc_of_area_sphere()
{
	double x = _x2 - _x1;
	double y = _y2 - _y1;
	double z = _z2 - _z1;
	double r = sqrt(x*x + y*y + z*z);
	return 4*PI*r*r;
}
double Figure::calc_of_area_cylinder()
{
	double x = _x2 - _x1;
	double y = _y2 - _y1;
	double z = _z2 - _z1;
	double h = sqrt(x*x + y*y + z*z);
	double x0 = _x3 - _x2;
	double y0 = _x3 - _x2;
	double z0 = _z3 - _z2;
	double r = sqrt(x0*x0 + y0*y0 + z0*z0);
	return 2*PI*r*(r+h);
}

double Figure::calc_of_area_parallelepiped()
{
	double a = fabs(_x2 - _x1);
	double b = fabs(_y2 - _y1);
	double c = fabs(_z2 - _z1);
	return 2*(a*b+b*c+a*c);
}

double Figure::compute_area(){ 
	switch (_type) {
		case TypeFigure::Sphere: 
		{
		     return calc_of_area_sphere();
		}
	    case TypeFigure::Cylinder:
		{
		     return calc_of_area_cylinder();
		}
		case TypeFigure::Parallelepiped: 
		{
		     return calc_of_area_parallelepiped();
		}
		default:
		    throw runtime_error("[Figure::compute_area]Invalid function type.");
	}
}

