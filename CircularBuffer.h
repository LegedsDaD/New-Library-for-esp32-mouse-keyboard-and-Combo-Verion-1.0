#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H


#include <stddef.h>


template<typename T, size_t N>
class CircularBuffer {
public:
	CircularBuffer() : head(0), tail(0), count(0) {}
	bool push(const T& item) {
		if (count == N) return false;
		data[head] = item;
		head = (head + 1) % N;
		++count;
		return true;
	}
	bool pop(T& item) {
		if (count == 0) return false;
		item = data[tail];
		tail = (tail + 1) % N;
		--count;
		return true;
	}
	void clear() { head = tail = count = 0; }
	size_t size() const { return count; }
	bool empty() const { return count == 0; }
private:
	T data[N];
	size_t head, tail, count;
};


#endif // CIRCULARBUFFER_H
