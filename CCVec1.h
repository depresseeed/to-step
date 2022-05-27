#ifndef CCVEC1
#define CCVEC1
#include "main.h"
#include "CCVec.h"
class CCVec1 : public CCVec {
public:
    CCVec1() : CCVec() {};
    CCVec1(int i) : CCVec(i) {};
    CCVec1(int inp_size, fr* arr, const string filename) : CCVec(inp_size, arr, filename) {};
    CCVec1(int inp_size, fr* arr) : CCVec(inp_size, arr) {};
    CCVec1(const CCVec& other_one) : CCVec(other_one) {};
    void output() override final;

    friend const CCVec1 operator+ (const CCVec1& left, const CCVec1& right);
    friend const CCVec1 operator- (const CCVec1& left, const CCVec1& right);
    friend const fr operator*(const CCVec1& left, const CCVec1& right);
    using CCVec:: operator=;
    ~CCVec1();
};

#endif // !CCVec1


