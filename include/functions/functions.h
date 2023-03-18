#pragma once

namespace figure{
	
	const double PI = 3,141592;
	
	enum class Type{
		
		Sphere,
		
		Cylinder,
		
		Parallelepiped
	};
	
	class Figure{
		
		private:
		
		Type _type;
		double _x;
		double _x0;
		double _y;
		double _y0;
		double _z;
		double _z0;
		
		Figure(Type type, double x, double x0, double y, double y0, double z, double z0);
		
		public:
		
		/*double GetRadius() const;
		double GetHeight() const;*/
		
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
