#include "CCVec.h"

const fr operator*(const fr& left, const fr& right) {
	fr ret;
	ret.Rl = (left.Rl * right.Rl - left.Im * right.Im);
	ret.Im = (left.Rl * right.Im + left.Im * right.Rl);
	return ret;
}

const fr operator+(const fr& left, const fr& right) {
	fr ret{ left.Rl + right.Rl, left.Im + right.Im };
	return ret;
}

const fr operator-(const fr& left, const fr& right) {
	fr ret{ left.Rl - right.Rl, left.Im - right.Im };
	return ret;
}

CCVec::CCVec() {
	vec = NULL;
	outfile = "buffer.txt";
	size = 0;
}

CCVec::CCVec(int inp_size) {
	vec = (fr*)malloc(sizeof(fr) * inp_size);
	outfile = "buffer.txt";
	size = inp_size;
}


CCVec::CCVec(int input_size, fr* arr) {
	size = input_size;
	vec = new fr[input_size];
	for (int i = 0; i < size; i++) {
		vec[i].Rl = arr[i].Rl;
		vec[i].Im = arr[i].Im;
	}

	outfile = "Standart_Output.txt";
}


CCVec::CCVec(int input_size, fr* arr, const string FileName) {
	size = input_size;
	vec = new fr[input_size];
	for (int i = 0; i < size; i++) {
		vec[i].Rl = arr[i].Rl;
		vec[i].Im = arr[i].Im;
	}

	outfile = FileName;
}

CCVec::CCVec(const CCVec& old_one) {
	size = old_one.get_size();
	vec = new fr[size];
	for (int i = 0; i < size; i++) {
		vec[i].Rl = old_one.item(i).Rl;
		vec[i].Im = old_one.item(i).Im;
	}
	outfile = old_one.outfile_name(); 
}

CCVec& CCVec::operator=(const CCVec& oke) {
	delete[] vec;
	size = oke.get_size();
	outfile = oke.outfile_name();
	if (size == 0) vec = NULL;
	else {
		vec = new fr[size];
		for (int i = 0; i < size; i++) {
			vec[i].Rl = oke.item(i).Rl;
			vec[i].Im = oke.item(i).Im;
		}
	}
	return *this;
}

fr CCVec::item(int i) const{
	return vec[i];
}
int CCVec::get_size() const{
	return size;
}
string CCVec::outfile_name() const{
	return outfile;
}



CCVec::~CCVec() {
	delete[] vec;
}


