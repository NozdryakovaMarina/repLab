#include <functions/functions.h>
#include <cassert>
#include <cmath>
#include <stdexcept>
#define PI 3.14159265
#define fig_get_coordinate fig->getCoordinateIndex

using namespace figure;
using namespace std;

struct Index
{
	int index_max_x=0;
	int index_max_y=0;
	int index_max_z=0;
	int index_min_x=0;
	int index_min_y=0;
	int index_min_z=0;
};

Index comp_extreme_vol(Figure* fig)
{
     Index value;
     for(int i = 1; i < 6; ++i)
	 {
         if(fig_get_coordinate(i).getX() > fig_get_coordinate(value.index_max_x).getX())
		 {
             value.index_max_x = i;
		 }
         if(fig_get_coordinate(i).getY() > fig_get_coordinate(value.index_max_y).getY())
		 {
             value.index_max_y = i;
		 }
         if(fig_get_coordinate(i).getZ() > fig_get_coordinate(value.index_max_z).getZ())
		 {
             value.index_max_z = i;
		 }
         if(fig_get_coordinate(i).getX() < fig_get_coordinate(value.index_min_x).getX())
		 {
             value.index_min_x = i;
		 }
         if(fig_get_coordinate(i).getY() < fig_get_coordinate(value.index_min_y).getY())
		 {
             value.index_min_y = i;
		 }
         if(fig_get_coordinate(i).getY() < fig_get_coordinate(value.index_min_z).getZ())
		 {
             value.index_min_z = i;
		 }
	 }
     return value;
}

Coordinate::Coordinate() : x(0), y(0), z(0) {};	 

TypeFigure Figure::getTypeFigure() { return type; }
	
double Coordinate::getX() { return x; }
	
double Coordinate::getY() { return y; }
	
double Coordinate::getZ() { return z; }
	
	
/*Figure Figure::compute_volume() {
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

Figure Figure::compute_area() const {
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
Figure Storage::getFigureIndex(int i) {return figure[i];}
int Storage::getSize() {return size;}
void Storage::setSize(int size) {this->size = size;}

Figure Storage::operator[](int index) const
{
	if (index < 0 || size <= index) 
	{
		throw runtime_error("Index is out of range.");
	}
	
	return figure[index];
}

void Storage::attItem(int index, Figure fig) 
{
	if(size == CAPACITY) 
	{
		throw runtime_error("Capacity is reached.");
	}
	if(index < 0 || index >= size)
	{
	throw runtime_error("Index is out of range.");
	}
	
	for(int i = size-1; i >= index; --i) {figure[i] = figure[i-1];}
	figure[index] = fig;
	++size;
}

void Storage::rid() {size=0;}

void Storage::delItem(int index)
{
	if(size<=0)
	{
		throw runtime_error("Storage is empty.");
	}
	for(int i = index; i < size - 1; ++i) {figure[i] = figure[i+1];}
	--size;
}


int Storage::IndexOfMaxVolume(Figure figures[]) 
{
	int index = 0;
	double maxVolume = figures[0].compute_volume();
	for(int i=0; i<size-1; ++i) 
	{
		double curVolume = figures[i].compute_volume();
		if (curVolume > maxVolume) {
			index = i;
			maxVolume = curVolume;
		}
	}
	
	return index;
}