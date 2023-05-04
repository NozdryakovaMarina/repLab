#pragma once

#include<iostream>

namespace figure {

    enum TypeFigure {
        Sphere,
        Cylinder,
        Parallelepiped
    };

    struct Point {
        double x;
        double y;
        double z;
    };

    class Figure {
    private:
        TypeFigure _type;
        Point _point[3];
        

    public:
        Figure();
        Figure(TypeFigure type, Point* points);

        TypeFigure getTypeFigure() const;
        double get_x(int i);
        double get_y(int i);
        double get_z(int i);
        bool chek_points(); 
        Figure* create(TypeFigure type, Point* points);
        Figure* create_sphere(Point* s_points);
        Figure* create_cylinder(Point* c_points);
        Figure* create_parallelepiped(Point* p_points);
        bool operator==(const Figure figure1);
        void print();
        friend std::ostream& operator<< (std::ostream& out, Figure& point);
        Figure* clone();
        double compute_area();
        double compute_volume();

    };
    inline std::ostream& operator<< (std::ostream& out, Figure& point) {
        point.print();
        return out;
    }

    class Storage {

    public:
        Storage();
        Storage(const Storage& other);
        int get_size() const;
        Figure* operator[](int index) const;
        Storage& operator=(Storage& rhs);
        Figure* get_figure_by_index(int i);
        void add(Figure* f);
        void del_item(int index);
        void insert_figure(Figure* figure, int index);
        void install_figure(Figure* figure1, int index);
        void remove(int index);
        void print();
        Figure* get_index(int index);
        void swap(Storage& other);
        friend std::ostream& operator<< (std::ostream& out, Storage& point);

        ~Storage();

        Figure IndexOfMaxVolume();
    private:
        Figure** _figures;
        int _size = 0;

    };
    inline std::ostream& operator<< (std::ostream& out, Storage& point) {
        point.print();
        return out;
    }
}