#include <functions/functions.h>
#include <cassert>
#include <cmath>
#include <stdexcept>
#define PI 3.14159265

using namespace figure;
using namespace std;
 

TypeFigure Figure::getTypeFigure() const { return type; }

Figure::Figure(): type(Sphere), x1(0), y1(0), z1(0), x2(1), y2(1), z2(1) {}

Figure::Figure(const TypeFigure type, const double x1, const double y1, const double z1, const double x2, const double y2, const double z2, const double x3, const double y3, const double z3): type(type), x1(x1), y1(y1), z1(z1), x2(x2), y2(y2), z2(z2), x3(x3), y3(y3), z3(z3) {}

Figure Figure::create_sphere(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2) {
	return Figure(TypeFigure::Sphere, x1, y1, z1, x2, y2, z2);
}

Figure Figure::create_cylinder(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2, const double x3, const double y3, const double z3) {
	return Figure(TypeFigure::Cylinder, x1, y1, z1, x2, y2, z2, x3, y3, z3);
}

Figure Figure::create_parallelepiped(const double x1, const double y1, const double z1, const double x2, const double y2, const double z2) {
	return Figure(TypeFigure::Parallelepiped, x1, y1, z1, x2, y2, z2);
}
	
double Figure::get_x1() const {return x1;}

double Figure::get_x2() const {return x2;}

double Figure::get_x3() const {return x3;}
	
double Figure::get_y1() const {return y1;}

double Figure::get_y2() const {return y2;}

double Figure::get_y3() const {return y3;}
	
double Figure::get_z1() const {return z1;}

double Figure::get_z2() const {return z2;}

double Figure::get_z3() const {return z3;}

double cacl_of_volume_sphere() 
{
	double x = x2 - x1;
	double y = y2 - y1;
	double z = z2 - z1;
    r = sqrt(x*x + y*y + z*z);
    return (4*PI*r*r*r)/3;
}

double cacl_of_volume_cylinder()
{
	double x = x2 - x1;
	double y = y2 - y1;
	double z = z2 - z1;
	h = sqrt(x*x + y*y + z*z);
	double x0 = x3 - x2;
	double y0 = x3 - x2;
	double z0 = z3 - z2;
	r = sqrt(x0*x0 + y0*y0 + z0*z0);
	return PI*h*r*r;
}

double calc_of_volume_parallelepiped()
{
	double a = fabs(x2 - x1);
	double b = fabs(y2 - y1);
	double c = fabs(z2 - z1);
	return a*b*c; 
}

double Figure::compute_volume() const {
	switch (type) {
		case TypeFigure::Sphere: 
		{
		     return cacl_of_volume_sphere();
		}
		case TypeFigure::Cylinder: 
		{
		     return cacl_of_volume_cylinder();
		}
		case TypeFigure::Parallelepiped: 
		{
		     return calc_of_volume_parallelepiped(); 
		}
	     default:
	         throw runtime_error("[Figure::compute_volume]Invalid function type.");
	}
}

double calc_of_area_sphere()
{
	double x = x2 - x1;
	double y = y2 - y1;
	double z = z2 - z1;
	r = sqrt(x*x + y*y + z*z);
	return 4*PI*r*r;
}
double calc_of_area_cylinder()
{
	double x = x2 - x1;
	double y = y2 - y1;
	double z = z2 - z1;
	h = sqrt(x*x + y*y + z*z);
	double x0 = x3 - x2;
	double y0 = x3 - x2;
	double z0 = z3 - z2;
	r = sqrt(x0*x0 + y0*y0 + z0*z0);
	return 2*PI*r(r+h);
}

double calc_of_area_parallelepiped()
{
	double a = fabs(x2 - x1);
	double b = fabs(y2 - y1);
	double c = fabs(z2 - z1);
	return 2*(a*b+b*c+a*c);
}

double Figure::compute_area() const { 
	switch (type) {
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

