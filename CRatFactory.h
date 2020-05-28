#include <iostream>
#include <fstream>
#include <string>
#include "CRat.h"
#include "CRat0.h"
#include "CRat1.h"
using namespace std;
class CRatFactory {
public:
    virtual CRat* create_dat(int d)=0;
    virtual ~CRatFactory(){}
};



