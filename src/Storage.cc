#include <function/function.h>
#include <stdexcept>

using namespace figure;
using namespace std;


Storage::Storage() : _size(0) {}

int Storage::size() const{
	return get_size;
} 

Figure Storage::operator[](int index) const
{
	if (index < 0 || _size <= index) 
	{
		throw runtime_error("Index is out of range.");
	}

	return figure[index];
}

void Storage::add(int index, Figure f) 
{
	if(size == CAPACITY) 
	{
		throw runtime_error("Capacity is reached.");
	}
	if(index < 0 || index >= size)
	{
	throw runtime_error("Index is out of range.");
	}
	
	for(int i = size-1; i >= index; --i) {figure[i] = figure[i-1];}
	figure[index] = f;
	++size;
}

void Storage::remove() { size=0; }

void Storage::del(int index)
{
	if(size<=0)
	{
		throw runtime_error("Storage is empty.");
	}
	for(int i = index; i < size - 1; ++i) {figure[i] = figure[i+1];}
	--size;
}


int Storage::IndexOfMaxVolume(Figure figures[]) 
{
	int index = 0;
	double maxVolume = figures[0].compute_volume();
	for(int i=0; i<size-1; ++i) 
	{
		double curVolume = figures[i].compute_volume();
		if (curVolume > maxVolume) {
			index = i;
			maxVolume = curVolume;
		}
	}
	
	return index;
}
