#include "Autotest.h"

int autotest() {
	fr arr1[] = { 1, 1, 1, 1 };
	fr arr2[] = { -1, 0, -1, 0 };
	fr arr3[] = { 1, 2, 3, 4 };


	CCVec1 c1(2, arr1, "test1.txt"), c2(2, arr2, "test2.txt");
	CCVec0 c3 = c1 + c2;
	c3.output();
	ifstream file;
	file.open("test1.txt");
	int x;
	int Rl, Im;
	string buf;
	fr mul = c1 * c2;
	//cout << mul.Rl << " + " << mul.Im << "i\n";
	
	for (int i = 0; i < 2; i++) {
		
		//cout << c1.item(i).Rl << " + " << c1.item(i).Im << "i\n";
		if (c1.item(i).Rl != c1.item(i).Im) return 0;
	}

	file.close();
	return mul.Rl == mul.Im;

}