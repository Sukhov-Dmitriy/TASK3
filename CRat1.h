#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;
class CRat1 : public CRat{
private:

public:
    CRat1(const CRat1 &other);// ����������� �����������
    CRat1(int d);
    CRat1();
    ~CRat1();
    double operator * (const CRat &B);//��������� ���������
    int output();
    using CRat::operator =;
};
