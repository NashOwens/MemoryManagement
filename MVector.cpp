
#include "MVector.h"
#include <stdlib.h>

MVector::MVector(int size) {
	this->size = size;
	data = (double*) malloc(sizeof(double) * size);
}
MVector::~MVector() {
	free(data);
}