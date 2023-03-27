#include <function/function.h>
#include <stdexcept>

using namespace figure;
using namespace std;


Storage::Storage() : size(0) {}

int Storage::size() const{
	return size;
} 

Figure Storage::operator[](int index) const
{
	if (index < 0 || size <= index) 
	{
		throw runtime_error("Index is out of range.");
	}

	return figure[index];
}

Figure& Storage::operator[](int index)
{
	if(index < 0 || index >= size)
	{
		throw runtime_error("Index is out of rounge.");
	}
	return figure[index];
}

void Storage::att(int index, Figure fig) 
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
	figure[index] = fig;
	++size;
}

void Storage::rid() {size=0;}

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
