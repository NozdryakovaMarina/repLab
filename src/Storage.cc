#include <functions/functions.h>

#include <stdexcept>

using namespace figure;
using namespace std;


Storage::Storage() : _size(0) {}

int Storage::size() const{
	return _size;
} 

Figure Storage::operator[](int index) const
{
	if (index < 0 || _size <= index) 
	{
		throw out_of_range("[Storage::operator[]]Index is out of range.");
	}

	return _figures[index];
}

void Storage::add(const Figure f) 
{
	if(_size == CAPACITY) 
	{
		throw runtime_error("[Storage::add]Capacity is reached.");
	}
	_figures[_size] = f;
	++_size;
}

void Storage::insert_figure(Figure figure1, int index)
{
	if (index < 0 || _size <= index) {
        throw out_of_range("[Storage::operator[]] Index is out of range. ");
    }
    else {
        for (int i = _size - 1; i != index; i--) {
            _figures[i + 1] = _figures[i];
        }
    }
    _figures[index] = figure1;
    _size++;
}

void Storage::remove(int index) { _size=0; }

void Storage::del_item(int index)
{
	if(index < 0 || _size <= index)
	{
		throw out_of_range("[Storage::operator[]]Index is out of range.");
	}
	{
		Figure figure1;
	    for(int i = index; i != CAPACITY-1 ; ++i) {_figures[i] = _figures[i+1];}
    }
	_size--;
}


int figure::IndexOfMaxVolume(const Storage& _figures) 
{
	int max_index = -1;
	double maxVolume = 0;
	const auto n = _figures.size();
	for(int i=0; i < n; ++i) 
	{   const auto volume = _figures[i].compute_volume();
		if (max_index == -1 || maxVolume < volume) {
			max_index = i;
			maxVolume = volume;
		}
	}
	
	return max_index;
}
