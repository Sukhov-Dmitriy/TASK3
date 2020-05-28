#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;
class CRat0 : public CRat{
private:

public:
    CRat0(const CRat0 &other);// конструктор копировани€
    CRat0(int d);
    CRat0();
    ~CRat0();
    double operator * (const CRat &B);//—кал€рное умножение
    int output();
    using CRat::operator =;
};

