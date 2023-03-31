#pragma once

namespace figure {
	
	enum TypeFigure {
		Sphere,
		Cylinder,
		Parallelepiped
	};
	
	class Figure {
	private:
		TypeFigure _type;
         double _x1, _y1, _z1;
		 double _x3, _y3, _z3;
		 double _x2, _y2, _z2;
		 Figure(TypeFigure type, double x1, double y1, double z1, double x2, double y2, double z2);
		 Figure(TypeFigure type, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);
		
	public:
		Figure();
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

	    double compute_area();
		double compute_volume();

		double calc_of_area_sphere();
		double calc_of_area_cylinder();
		double calc_of_area_parallelepiped();
		double calc_of_volume_sphere();
		double calc_of_volume_cylinder();
		double calc_of_volume_parallelepiped();

	};
	
  
     class Storage{
		 
		public:
			static const int CAPACITY = 10;
		     Storage();
			 Storage(Figure figures[], int size);
			 int size() const;
	         Figure operator[](int index) const;
			 void add(const Figure f);
			 void del_item(int index);
			 void insert_figure(Figure figure1, int index);
			 void remove(int index);
	 private:
		 Figure _figures[CAPACITY];
		 int _size;

	 };

	 int IndexOfMaxVolume(const Storage& figures);
}