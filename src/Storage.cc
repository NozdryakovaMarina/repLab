#include <functions/functions.h>

#include <stdexcept>

using namespace figure;
using namespace std;


Storage::Storage() :
    _figures(nullptr),
    _size(0) {}

int Storage::get_size() const {
    return _size;
}

Storage::~Storage() {
    for (int i = 0; i < _size; i++) {
        delete _figures[i];
    }
    delete[] _figures;;
}

void Storage::swap(Storage& other) {
    std::swap(_size, other._size);
    std::swap(_figures, other._figures);
}

Storage::Storage(const Storage& other) :
    _figures(new Figure* [other._size]),
    _size(other._size)
{
    for (int i = 0; i < _size; ++i) {
        _figures[i] = other[i]->clone();
    }
}

Storage& Storage::operator=(Storage& other)
{
    Storage new_figure(other);
    swap(other);
    return *this;
}

Figure* Storage::operator[](const int index) const
{
    if (index < 0 || _size <= index) {
        throw out_of_range("[FigureList::operator[]] Index is out of range. ");
    }
    return _figures[index];
}

Figure* Storage::get_figure_by_index(int index)
{
    if (index < 0 || _size <= index)
        throw 0;
    return _figures[index];
}

void Storage::add(Figure* const f)
{
    auto new_figure = new Figure * [_size + 1];
    for (int i = 0; i < _size; ++i) {
        new_figure[i] = _figures[i];
    }
    new_figure[_size] = f;
    delete[] _figures;
    _figures = new_figure;
    ++_size;
}

void Storage::insert_figure(Figure* figure, int index)
{
    if (index < 0 || _size < index) {
        throw out_of_range("[FigureList::operator[]] Index is out of range. ");
    }
    auto new_figure = new Figure * [_size + 1];
    for (int i = 0; i < _size; i++) {
        if (i < index) new_figure[i] = _figures[i];
        else new_figure[i + 1] = _figures[i];
    }
    new_figure[index] = figure;
    delete[] _figures;
    _figures = new_figure;
    _size++;
}

Figure* Storage::get_index(int index) {
    if (index < 0 || _size <= index) {
        throw 0;
    }
    return _figures[index];
}

void Storage::install_figure(Figure* figure, int index)
{
    if (index < 0 || index > _size) {
        throw out_of_range("[FigureList::operator[]] Index is out of range. ");
    }
    else {
        _figures[index] = figure;
    }
}

void Storage::remove(int index)
{
    if (index < 0 || _size <= index)
        throw runtime_error("[FigureList::remove] FigureList is empty");
    delete _figures[index];
    for (int i = index; i < _size - 1; i++)
        _figures[i] = _figures[i + 1];
    --_size;
}

void Storage::del_item(int index)
{
    if (index < 0 || _size < index) {
        throw out_of_range("[FigureList::operator[]] Index is out of range. ");
    }
    auto new_figure = new Figure * [_size - 1];
    for (int i = 0; i < _size; ++i) {
        if (index > i) new_figure[i] = _figures[i];
        else new_figure[i] = _figures[i + 1];
    }
    delete[] _figures;
    _figures = new_figure;
    _size--;
}

void Storage::print() {
    for (int i = 0; i < _size; ++i) {
        cout << i << ") ";
        switch (_figures[i]->getTypeFigure()) {
        case 0: {
            cout << "Sphere" << " ";
            for (int j = 0; j < 2; ++j) {
                cout << _figures[i]->get_x(j) << " " << _figures[i]->get_y(j) << " " << _figures[i]->get_z(j) << " ";
            }
            break;
        }
        case 1: {
            cout << "Cylinder" << " ";
            for (int j = 0; j < 3; ++j) {
                cout << _figures[i]->get_x(j) << " " << _figures[i]->get_y(j) << " " << _figures[i]->get_z(j) << " ";
            }
            break;
        }
        case 2: {
            cout << "Parallelepiped" << " ";
            for (int j = 0; j < 2; ++j) {
                cout << _figures[i]->get_x(j) << " " << _figures[i]->get_y(j) << " " << _figures[i]->get_z(j) << " ";
            }
            break;
        }
        }
        cout << "\n";
    }
}

Figure Storage::IndexOfMaxVolume()
{
    if (_size <= 0)
        throw 0;
    Figure max_figure(*_figures[0]);
    for (int i = 0; i < _size; i++) {
        if (max_figure.compute_volume() < (*_figures[i]).compute_volume())
            max_figure = *_figures[i];
    }
   /*int max_index = 0;
    double maxVolume = _figures[0]->compute_volume();
    for (int i = 1; i < _size; i++) {
        double volume = _figures[i]->compute_volume();
        if (volume > maxVolume) {
            max_index = i;
            maxVolume = volume;
        }
    }*/
   
    return max_figure;
}