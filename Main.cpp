#include <iostream>
#include <crtdbg.h>
#include <time.h>
#include "MVector.h"
using namespace std;


int main() {
#ifdef _DEBUG
//	 _CrtSetBreakAlloc(83);
	_onexit(_CrtDumpMemoryLeaks);
#endif

//	MVector* vec1 = new MVector(10);

//	delete vec1;

	// start coding here
	srand(time(nullptr));
	
	int ballNum, lvlNum;


	cout << "Enter the number of balls you want: \n";
	cin >> ballNum;
	cout << "Enter the number of levels you want: \n";
	cin >> lvlNum;

	int* bucketBallLoc = (int*)malloc(sizeof(int) * ballNum);

	for (int i = 0; i < ballNum; i++) {
		bucketBallLoc[i] = 0;
		for (int l = 0; l < lvlNum; l++) {
			if (rand() > (RAND_MAX / 2))
				++bucketBallLoc[i];
		}
		
		cout << "Ball number " << i << " is in bucket index " << bucketBallLoc[i] << "\n";
	}

	int* bucketCounts = (int*) malloc(sizeof(int) * (lvlNum + 1) * ballNum);
	
	for (int i = 0; i <= lvlNum; i++)
		bucketCounts[i] = 0;

	for (int i = 0; i < ballNum; i++) {
		int bucketindex = bucketBallLoc[i];
		++bucketCounts[bucketindex];
	}

	for (int i = 0; i <= lvlNum; i++)
		if (bucketCounts[i] != 0) {
			cout << " " <<  bucketBallLoc[i] << "     " << bucketCounts[i] << "\n";
		}
		//cout << "Bucket #" << i << " contains " << bucketCounts[i] << " Balls " << "\n";

	free(bucketCounts);
	free(bucketBallLoc);

	return 0;
}

void NomialDis(int bucket, int numofballs) {

}