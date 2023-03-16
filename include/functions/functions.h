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
		double _y;
		double _z;
		
		Figure(Type type, double x, double y, double z);
		
		public:
		
		/*double GetRadius() const;
		double GetHeight() const;
		double compute_area() const;
		double compute_volume() const;*/
		
		static Figure create_shpere(double x, double y, double z);
		static Figure create_cylinder(double x, double y, double z);
		static Figure creare_parallelepiped(double x, double y, double z);
		
		Figure();
		
 		Type GetType() const;
		double GetX() const;
		double GetY() const;
		double GetZ() const;
		
	
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
			 
	 };
	 
	 int index_of_max_
	 
}
		
		
	
/*int sum_stub(int lhs, int rhs);
        void SetX(int x) {_x=x;}
		void SetY(int y) {_y=y;}
		void SetZ(int z) {_z=z;}
		
*/
