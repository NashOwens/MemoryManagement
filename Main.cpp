#include <iostream>
#include <crtdbg.h>
#include <time.h>
#include <string>
#include "MVector.h"
#include <cmath>
using namespace std;


char convertX(int bucketCounts) {
	if (bucketCounts != 0) {
		for (int i = 0; i < bucketCounts; i++) {
			cout << 'X';
		}
	}
	else {
		cout << 'X';
	}
	return '\n';
}

void BeanMachine() {

//	srand(time(nullptr));
	
	int ballNum, lvlNum;

	cout << "Welcome to the Bean Machine\n-------------------------------\n" << "Enter the number of balls you want: ";
	cin >> ballNum;
	cout << "\nEnter the number of levels you want: ";
	cin >> lvlNum;
	cout << "\n";
	int* bucketBallLoc = (int*)malloc(sizeof(int) * ballNum);

	for (int i = 0; i < ballNum; i++) {
		bucketBallLoc[i] = 0;
		for (int l = 0; l < lvlNum; l++) {
			if (rand() > (RAND_MAX / 2))
				++bucketBallLoc[i];
		}
		
		//cout << "Ball number " << i << " is in bucket index " << bucketBallLoc[i] << "\n";
	}

	int* bucketCounts = (int*) malloc(sizeof(int) * (lvlNum + 1) * ballNum);
	
	for (int i = 0; i <= lvlNum; i++) {
		bucketCounts[i] = 0;
	}
	for (int i = 0; i < ballNum; i++) {
		int bucketindex = bucketBallLoc[i];
		++bucketCounts[bucketindex];
	}

	for (int i = 0; i <= lvlNum; i++)
		cout << convertX(bucketCounts[i]) << bucketBallLoc[i]   << "     ";
		//cout << "Bucket #" << i << " contains " << bucketCounts[i] << " Balls " << "\n";

	free(bucketCounts);
	free(bucketBallLoc);
}

void VectorWork() {

	double v1, v2, Magnitude, MagofVec1, MagofVec2, dotProduct, angle;

	MVector* vec1 = new MVector(2);
	cout << "\nPlease enter the first value for the first vector: ";
	cin >> v1;
	cout << "\nPlease enter the second value for the first vector: ";
	cin >> v2;
	vec1->setValue1(v1);
	vec1->setValue2(v2);

	MVector* vec2 = new MVector(2);

	cout << "\nPlease enter the first value for the second vector: ";
	cin >> v1;
	cout << "\nPlease enter the second value for the second vector: ";
	cin >> v2;
	vec2->setValue1(v1);
	vec2->setValue2(v2);

	cout << "\nFinally, please enter the angle: ";
	cin >> angle;
	
	cout << "\nVector 1 : " << vec1->getValue1() << " , " << vec1->getValue2() << "\n\n";
	cout << "Vector 2 : " << vec2->getValue1() << " , " << vec2->getValue2() << "\n\n";

	MVector* vec3 = new MVector(4);

	vec3->setValue1((vec1->getValue1() - vec2->getValue1()));
	vec3->setValue2((vec1->getValue2() - vec2->getValue2()));

	cout << "SUM of both Vectors being: " << vec3->getValue1() << " , " << vec3->getValue2() << "\n\n";

	vec3->setValue1((vec3->getValue1() * vec3->getValue1()));
	vec3->setValue2((vec3->getValue2() * vec3->getValue2()));

	MagofVec1 = vec3->getValue1();
	MagofVec2 = vec3->getValue2();

	Magnitude = sqrt(vec3->getValue1() + vec3->getValue2());

	cout << "Magnitude of final vector : " << Magnitude << "\n\n"; 

	dotProduct = (MagofVec1 * MagofVec2 * cos(angle));

	cout << "Dot product of vec1 and vec2: " << dotProduct << "\n";

	delete vec1;
	delete vec2;
}

int main() {
#ifdef _DEBUG
//	 _CrtSetBreakAlloc(83);
	_onexit(_CrtDumpMemoryLeaks);
#endif
	int x = 0;
	do {
		cout << "\nMemory management menu: \n --------------------------\n1. Bean Machine\n2. Vector Work\n9. Exit\n";
		cin >> x;
		switch (x) {
		case 1: BeanMachine();
			break;
		case 2: VectorWork();
			break;
		case 9: break;
		default:
			break;
		}
	} while (x != 9);

	return 0;
}
