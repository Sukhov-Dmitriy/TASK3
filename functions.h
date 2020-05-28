#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "CRatFactory1.h"
using namespace std;
CRat *CreateData(ifstream &input, std::map<string,CRatFactory*> f);
CRat1 operator + (const CRat &A, const CRat &B);
void test1();
void test2();
void test3();
void test4();
