#pragma once
class MVector
{
public:
	MVector(int size);
	~MVector();

	double getValue1() {
		return value1;
	}
	double getValue2() {
		return value2;
	}
	void setValue1(double value) {
		this->value1 = value;
	}
	void setValue2(double value) {
		this->value2 = value;
	}

private:
	int size;
	double value1=0;
	double value2=0;
	double* data;
};

