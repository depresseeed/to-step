#include "CCVec0.h"


void CCVec0::output() {	
	ofstream file;
	file.open(outfile);
	for (int i = 0; i < size; i++) {
		file << vec[i].Rl << " + " << vec[i].Im << "i ";
	}
	file.close();
}



const CCVec0 operator+(const CCVec& left, const CCVec& right) {
	if (left.get_size() == 0 || left.get_size() != right.get_size()) {
		perror("Bad sizes");
		CCVec0 error_return;
		return error_return;
	}

	int len = left.get_size();
	fr* buf = new fr[len];

	for (int i = 0; i < len; i++)
		buf[i] = left.item(i) + right.item(i);
	CCVec0 ret(len, buf, left.outfile_name());
	return ret;
}

const CCVec0 operator-(const CCVec& left, const CCVec& right) {
	if (left.get_size() == 0 || left.get_size() != right.get_size()) {
		perror("Bad sizes");
		CCVec0 error_return;
		return error_return;
	}

	int len = left.get_size();
	fr* buf = new fr[len];

	for (int i = 0; i < len; i++)
		buf[i] = left.item(i) - right.item(i);



	return CCVec0(len, buf, left.outfile_name());
}
 
const fr operator*(const CCVec& left, const CCVec& right) {
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

CCVec0::~CCVec0() {  }

