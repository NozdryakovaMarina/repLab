#include <function/function.h>

#include <stdexcept>

using namespace figure;
using namespace std;


Storage::Storage() : _size(0) {}

int Storage::size() const {
	return _size;
}

void Storage::add(const Figure f) {
	if(_size == CAPACITY) {
		throw runtime_error("[Storage::add] Capacity is reached.");
	}
	
	_storage[_size] = f;
	++_size;
}