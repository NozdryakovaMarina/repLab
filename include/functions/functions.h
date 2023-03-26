#pragma once

namespace figure {
	
	enum class TypeFigure {
		
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
	};		
	
	class Figure {
		
		TypeFigure type;
		Coordinate pos[6];
		
		public:
		
		Figure();
		Figure(TypeFigure type, Coordinate pos[6]);
		
		TypeFigure getTypeFigure();
		Coordinate getCoordinateIndex(int i);
		void setTypeFigure(TypeFigure type);
		void setCoordinateIndex(int i, Coordinate coordinate);

		
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
			 void attItem(int index, Figure fig);
			 void delItem(int index);
			 void rid();
			 int IndexOfMaxVolume(Figure Figures[]); 
			 
	 };
	 
}
		