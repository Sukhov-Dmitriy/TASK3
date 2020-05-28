#include <iostream>
#include <fstream>
#include <string>
#include "CRatFactory.h"
using namespace std;
class CRatFactory0 : public CRatFactory{
public:
    CRat* create_dat(int d);
};
