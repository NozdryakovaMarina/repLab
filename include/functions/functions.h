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
		 double x0, y0, z0;
		
		public:
		
		Figure();
		Figure(TypeFigure type, double x1, y1, z1, double x0, y0, z0);
		
		TypeFigure getTypeFigure();
		
		double get_x1();
		double get_x0();
		double get_y1();
		double get_y0();
		double get_z1();
		double get_z0();

	    double compute_area();
		double compute_volume();
	};
	
  
     class Storage{
		private:
		     static const int CAPACITY = 10;
		     Figure figure[CAPACITY];
		     int size;
			 
		public:
		     Storage();
			 Storage(Figure figures[], int size);
			 
			 Figure getFigureIndex(int i);
			 void setSize(int size);
			 int getSize();
	         Figure operator[](int index) const;
			 Figure& operator[](int index);
			 void att(int index, Figure fig);
			 void del(int index);
			 void rid();
			 int IndexOfMaxVolume(Figure Figures[]); 
			 
	 };
	 
}
		