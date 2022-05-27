#include "CCVec1.h"

void CCVec1::output() {
	ofstream file;
	file.open(outfile);
	for (int i = 0; i < size; i++) {
		file << vec[i].Rl << " + " << vec[i].Im << "i" << endl;
	}
	file.close();
}


const CCVec1 operator+(const CCVec1& left, const CCVec1& right) {
	if (left.get_size() == 0 || left.get_size() != right.get_size()) {
		perror("Bad sizes");
		CCVec1 error_return;
		return error_return;
	}

	int len = left.get_size();
	fr* buf = new fr[len];

	for (int i = 0; i < len; i++)
		buf[i] = left.item(i) + right.item(i);
	CCVec1 ret(len, buf, left.outfile_name());
	return ret;
}

const CCVec1 operator-(const CCVec1& left, const CCVec1& right) {
	if (left.get_size() == 0 || left.get_size() != right.get_size()) {
		perror("Bad sizes");
		CCVec1 error_return;
		return error_return;
	}

	int len = left.get_size();
	fr* buf = new fr[len];

	for (int i = 0; i < len; i++)
		buf[i] = left.item(i) - right.item(i);



	return CCVec1(len, buf, left.outfile_name());
}

const fr operator*(const CCVec1& left, const CCVec1& right) {
	fr buff_one, buff_two;
	fr ret = { 0, 0 };
	for (int i = 0; i < left.get_size(); i++) {
		buff_one = left.item(i);
		buff_two = right.item(i);
		buff_two.Im = -buff_two.Im;
		ret = ret + buff_one * buff_two;
	}
	return ret;
}



CCVec1::~CCVec1() { }


