#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
using namespace std;
CRat* CRatFactory0::create_dat(int d)
{
    return new CRat0(d);
}
