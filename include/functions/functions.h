#pragma once

namespace figure {
	
	const double PI = 3,141592;
	
	enum class Type {
		
		Sphere,
		Cylinder,
		Parallelepiped
	};
	
	class Coordinate {
		
		double x, y, z;
		
		public:
		Coordinate();
		Coordinate(double x, double y, double z);
		double getX();
		double getY();
		double getZ();
		void setX(double x);
		void setY(double y);
		void setZ(double z);
		
	
	class Figure {
		
		TypeFigure type;
		Coordinate pos[6];
		
		public:
		
		Figure();
		Figure(TypeFigure type, Coordinate pos[6]);
		
		TypeFigure getTypeFigure();
		static Figure create_shpere(double x0, double x, double y0, double y, double z0, double z);
		static Figure create_cylinder(double x, double y, double z);
		static Figure creare_parallelepiped(double x, double y, double z);
		
		Figure();
		
 		Type GetType() const;
		double GetX() const;
		double GetY() const;
		double GetZ() const;
		
	    Figure compute_area() const;
		Figure compute_volume() const;
	};
	
  
     class Storage{
		 public:
		     static const int CAPACITY = 10;
			 
		private:
		     Figure _storage[CAPACITY];
			 
		     int _size;
			 
		public:
		     Storage();
			 
			 int size() const;
	operator[](int index) const;
			 
	 };
	 
	 int index_of_max_volume(const Storage& storage, );
	 
}
		
		
	
/*int sum_stub(int lhs, int rhs);
        void SetX(int x) {_x=x;}
		void SetY(int y) {_y=y;}
		void SetZ(int z) {_z=z;}
		
*/
