#pragma once

namespace figure {
	
	enum class TypeFigure {
		
		Sphere,
		Cylinder,
		Parallelepiped
	};
	
	class Figure {
		
		TypeFigure type;
         double x1, y1, z1;
		 double x3, y3, z3;
		 double x2, y2, z2;
		
		public:
		
		Figure();
		Figure(TypeFigure type, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);
		
		static Figure create_sphere(double x1, double y1, double z1, double x2, double y2, double z2);
		static Figure create_cylinder(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);
		static Figure create_parallelepiped(double x1, double y1, double z1, double x2, double y2, double z2);
		
		TypeFigure getTypeFigure() const;
		
		double get_x1() const;
		double get_x3() const;
		double get_x2() const;
		double get_y1() const;
		double get_y3() const;
		double get_y2() const;
		double get_z1() const;
		double get_z3() const;
		double get_z2() const;

	    double compute_area() const;
		double compute_volume() const;
	};
	
  
     class Storage{
		private:
		     static const int CAPACITY = 10;
		     Figure figures[CAPACITY];
		     int _size;
			 
		public:
		     Storage();
			 Storage(Figure figures[], int size);
			 
			 int size() const;
	         Figure operator[](int index) const;
			 void add_item(const Figure f);
			 void del_item(int index);
			 void insert_figure(Figure figure1, int index);
			 void remove(int index);
			 int IndexOfMaxVolume(const Storage& figures); 
			 
	 };
	 
}
		