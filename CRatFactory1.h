#include <iostream>
#include <fstream>
#include <string>
#include "CRatFactory0.h"
using namespace std;
class CRatFactory1 : public CRatFactory{
public:
    CRat* create_dat(int d);
};
