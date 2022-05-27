#ifndef CCVEC
#define CCVEC
#include "main.h"
using namespace std;


struct fr {
	int Rl;
	int Im;
	friend const fr operator+(const fr& left, const fr& right);
	friend const fr operator-(const fr& left, const fr& right);
	friend const fr operator*(const fr& left, const fr& right);
};



class CCVec {
protected:
	fr* vec;
	int size;
	string outfile;

public:
	CCVec();
	CCVec(int);
	CCVec(int input_size, fr* arr, const string FileName);
	CCVec(const CCVec& old_one);
	CCVec(int input_size, fr* arr);

	
	virtual void output() = 0;
	fr item(int i = 0) const;
	int get_size() const;
	string outfile_name() const;
	CCVec& operator=(const CCVec& oke);
	virtual ~CCVec();
};

#endif