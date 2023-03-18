#include <function/function.h>

#include <stdexcept>

using namespace figure;
using namespace std;


Storage::Storage() : _size(0) {}

int Storage::size() const {
	return _size;
}

Figure Storage::operator[](const int index) const{
	if (index < 0 || _size <= index) {
		throw (""[Storage::operator[]] Index is out of range.");
	}
	
	return _storage[index];
}

void Storage::add(const Figure f) {
	if(_size == CAPACITY) {
		throw runtime_error("[Storage::add] Capacity is reached.");
	}
	
	_storage[_size] = f;
	++_size;
}


int figure::index_of_max_volume(const Storage& storage, const double ) {
	for(int i=0; i<n; ++i) {
		const auto volume = storage[i].compute_volume();
		if (max_index == -1 || max_volume < volume) {
			max_index = i;
			max_volume = volume;
		}
	}
	
	return max_index;
}