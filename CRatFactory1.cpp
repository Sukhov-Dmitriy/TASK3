#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
using namespace std;
CRat* CRatFactory1::create_dat(int d)
{
   return new CRat1(d);
}
