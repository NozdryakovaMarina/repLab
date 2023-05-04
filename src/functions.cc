#include <functions/functions.h>

#include <cassert>
#include <cmath>
#include <stdexcept>

#define PI 3.14

using namespace figure;
using namespace std;

TypeFigure Figure::getTypeFigure() const { return _type; }

Figure::Figure() {
    _type = Sphere;
    for (int i = 0; i < 2; i++) {
        _point[i] = { 0,0,0 };
    }
}

Figure::Figure(TypeFigure type, Point* points) {
    _type = type;
    for (int i = 0; i < 3; ++i) {
        _point[i] = points[i];
    }
}

double Figure::get_x(int i) {
    return _point[i].x;
}

double Figure::get_y(int i) {
    return _point[i].y;
}

double Figure::get_z(int i) {
    return _point[i].z;
}

Figure* Figure::create(TypeFigure type, Point* points) {
    return new Figure(type, points);
}

Figure* Figure::create_sphere(Point* s_points) {
    return new Figure(TypeFigure::Sphere, s_points);
}

Figure* Figure::create_cylinder(Point* c_points) {
    return new Figure(TypeFigure::Cylinder, c_points);
}

Figure* Figure::create_parallelepiped(Point* p_points) {
    return new Figure(TypeFigure::Parallelepiped, p_points);
}

bool Figure::operator==(const Figure figure1) {
    for (int i = 0; i < 3; i++) {
        if (_point[i].x != figure1._point[i].x || _point[i].y != figure1._point[i].y || _point[i].z != figure1._point[i].z) return false;
    }
    return true;
}

bool Figure::chek_points() 
{
    switch (_type) {
    case Sphere: {
        if (_point[0].x == _point[1].x && _point[0].y == _point[1].y && _point[0].z == _point[1].z) return false;
    }
    case Cylinder: {
        if ((_point[0].x == _point[1].x && _point[0].y == _point[1].y && _point[0].z == _point[1].z) || (_point[0].x == _point[2].x && _point[0].y == _point[2].y && _point[0].z == _point[2].z) || (_point[2].x == _point[1].x && _point[2].y == _point[1].y && _point[2].z == _point[1].z)) return false;
    }
    case Parallelepiped: {
        if (_point[0].x == _point[1].x && _point[0].y == _point[1].y && _point[0].z == _point[1].z) return false;
    }
    }
    return true;
}

void Figure::print() {
    switch (_type) {
    case 0: {
        cout << "Sphere" << " ";
        for (int i = 0; i < 2; ++i) {
            cout << _point[i].x << " " << _point[i].y << " " << _point[i].z << " ";
        }
        break;
    }
    case 1: {
        cout << "Cylinder" << " ";
        for (int i = 0; i < 3; ++i) {
            cout << _point[i].x << " " << _point[i].y << " " << _point[i].z << " ";
        }
        break;
    }
    case 2: {
        cout << "Parallelepiped" << " ";
        for (int i = 0; i < 2; ++i) {
            cout << _point[i].x << " " << _point[i].y << " " << _point[i].z << " ";
        }
        break;
    }
    }
    cout << "\n";
}

Figure* Figure::clone() {
    return new Figure(_type, _point);
}


double Figure::compute_volume() {
    double h, r, a, b, c, x, y, z, x0, y0, z0, x1, y1, z1;
    switch (_type) {
    case TypeFigure::Sphere:
    {
        x = pow(_point[0].x - _point[1].x, 2);
        y = pow(_point[0].y - _point[1].y, 2);
        z = pow(_point[0].z - _point[1].z, 2);
        r = sqrt(x + y + z);
        return (4 * PI * r * r * r) / 3;
    }
    case TypeFigure::Cylinder:
    {
        x = _point[0].x - _point[1].x;
        y = _point[0].y - _point[1].y;
        z = _point[0].z - _point[1].z;
        h = sqrt(x * x + y * y + z * z);
        x0 = _point[2].x - _point[1].x;
        y0 = _point[2].y - _point[1].y;
        z0 = _point[2].z - _point[1].z;
        r = sqrt(x0 * x0 + y0 * y0 + z0 * z0);
        x1 = _point[2].x - _point[0].x;
        y1 = _point[2].y - _point[0].y;
        z1 = _point[2].z - _point[0].z;
        if ((h * h + r * r) == x1 * x1 + y1 * y1 + z1 * z1)
            return PI * h * r * r;
        else {
            throw runtime_error("[Figure::calc_of_area_cylinder]Invalid settings of cylinder");
        }
    }
    case TypeFigure::Parallelepiped:
    {
        a = fabs(_point[0].x - _point[1].x);
        b = fabs(_point[0].y - _point[1].y);
        c = fabs(_point[0].z - _point[1].z);
        return a * b * c;
    }
    default:
        throw runtime_error("[Figure::compute_volume]Invalid function type.");
    }
}


double Figure::compute_area() {
    double h, r, a, b, c, x, y, z, x0, y0, z0, x1, y1, z1;
    switch (_type) {
    case TypeFigure::Sphere:
    {
        x = pow(_point[0].x - _point[1].x, 2);
        y = pow(_point[0].y - _point[1].y, 2);
        z = pow(_point[0].z - _point[1].z, 2);
        r = sqrt(x + y + z );
        return 4 * PI * r * r;
    }
    case TypeFigure::Cylinder:
    {
        x = _point[0].x - _point[1].x;
        y = _point[0].y - _point[1].y;
        z = _point[0].z - _point[1].z;
        h = sqrt(x * x + y * y + z * z);
        x0 = _point[2].x - _point[1].x;
        y0 = _point[2].y - _point[1].y;
        z0 = _point[2].z - _point[1].z;
        r = sqrt(x0 * x0 + y0 * y0 + z0 * z0);
        x1 = _point[2].x - _point[0].x;
        y1 = _point[2].y - _point[0].y;
        z1 = _point[2].z - _point[0].z;
        if ((h * h + r * r) == x1 * x1 + y1 * y1 + z1 * z1)
            return 2 * PI * r * (r + h);
        else {
            throw runtime_error("[Figure::calc_of_area_cylinder]Invalid settings of cylinder");
        }
    }
    case TypeFigure::Parallelepiped:
    {
        a = fabs(_point[0].x - _point[1].x);
        b = fabs(_point[0].y - _point[1].y);
        c = fabs(_point[0].z - _point[1].z);
        return 2 * (a * b + b * c + a * c);
    }
    default:
        throw runtime_error("[Figure::compute_area]Invalid function type.");
    }
}
