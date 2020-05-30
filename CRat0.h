#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;
class CRat0 : public CRat{
private:

public:
    CRat0(const CRat0 &other);// êîíñòðóêòîð êîïèðîâàíèÿ
    CRat0(const CRat &other);// êîíñòðóêòîð êîïèðîâàíèÿ
    CRat0(int d);
    CRat0();
    ~CRat0();
    double operator * (const CRat &B);//Ñêàëÿðíîå óìíîæåíèå
    int output();
    using CRat::operator =;
};

