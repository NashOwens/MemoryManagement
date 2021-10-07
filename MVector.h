#pragma once
class MVector
{
public:
	MVector(int size);
	~MVector();

private:
	int size;
	double* data;
};

