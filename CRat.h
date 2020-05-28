#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;
class CRat{//базовый класс, который хранит данныйе для одного вектора
protected:
public:
   int dim;
    vector<int> data;
   string outfile;
   CRat(){}
   void show();
   virtual ~CRat(){}
   virtual int output()=0;
   void operator = (const CRat& other);
};

