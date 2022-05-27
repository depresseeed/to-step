#ifndef CCVEC0
#define CCVEC0
#include "main.h"
#include "CCVec.h"
class CCVec0 : public CCVec {
public:
    CCVec0() : CCVec() {};
    CCVec0(int i) : CCVec(i) {};
    CCVec0(int inp_size, fr* arr, const string filename) : CCVec(inp_size, arr, filename) {};
    CCVec0(int inp_size, fr* arr) : CCVec(inp_size, arr) {};
    CCVec0(const CCVec& other_one) : CCVec(other_one) {};
    void output() override final;

    friend const CCVec0 operator+ (const CCVec& left, const CCVec& right);
    friend const CCVec0 operator- (const CCVec& left, const CCVec& right);
    friend const fr operator*(const CCVec& left, const CCVec& right);
    using CCVec:: operator=;
    ~CCVec0();
};

#endif // !CCVec1


