#include <function/function.h>
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

void Storage::add_item(const Figure f) 
{
	if(size == CAPACITY) 
	{
		throw runtime_error("[Storage::add]Capacity is reached.");
	}
	figures[index] = f;
	++_size;
}

void Storage::insert_figure(Figure figure1, int index)
{
	if (index < 0  _size <= index) {
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
	if(int i = index; i != CAPACITY - 1; ++i)
	{
		throw out_of_range("[Storage::operator[]]Index is out of range.");
	}
	{
		Figure figure1;
	    for(int i = index; i != CAPACITY-1 ; ++i) {_figures[i] = _figures[i+1];}
    }
	_size--;
}


int Storage::IndexOfMaxVolume(const Storage& _figures) 
{
	int max_index = -1;
	double maxVolume = 0;
	const auto n = _figures.size();
	for(int i=0; i < n; ++i) 
	{   const auto volume = _figures[i].compute_volume();
		if (max_index == -1 || max_volume < volume) {
			max_index = i;
			max_volume = volume;
		}
	}
	
	return max_index;
}
