#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using std::string;
using std::time;
using std::rand;
using std::cout;

class mRandArray
{
public:
	string * RandNumGen(int cArg, char * vArg[]);

	mRandArray();
	~mRandArray();
};

