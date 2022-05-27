#pragma once
#ifndef FACTORY
#define FACTORY

#include "CCVec.h"
#include "CCVec0.h"
#include "CCVec1.h"

class Factory
{
public:
	virtual CCVec* create() = 0;
	virtual CCVec* create(int inp_size, fr* arr, const string filename) = 0;
	virtual CCVec* create(const CCVec& other) = 0;
};

class Factory_0: public Factory
{
public:
	CCVec* create() override { return new CCVec0(); }
	CCVec* create(int inp_size, fr* arr, const string filename) override { return new CCVec0(inp_size, arr, filename); }
	CCVec* create(const CCVec& other) override { return new CCVec0(other); }
};

class Factory_1 : public Factory
{
public:
	CCVec* create() override { return new CCVec1(); }
	CCVec* create(int inp_size, fr* arr, const string filename) override { return new CCVec1(inp_size, arr, filename); }
	CCVec* create(const CCVec& other) override { return new CCVec1(other); }
};


#endif 