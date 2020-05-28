#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <omp.h>
#include <chrono>
#include "functions.h"
using namespace std;
CRat *CreateData(ifstream &input, std::map<string,CRatFactory*>  f){
    string I;
    int d = 2;
    string filename;
    CRat *rat = NULL;
    input >> I;
    input >> filename;
    input >> d;
    rat = f[I]->create_dat(d);
    for(int j = 0; j < d*2; j++){
        input >> rat->data[j];
        if(j%2 == 1 && rat->data[j]== 0){
            cout <<"Warning! You try to divide by zero!";
        }
    }
    rat->dim = d;
    rat->outfile = filename;

    return rat;
}

CRat1 operator + (const CRat &A, const CRat &B){
        CRat1 rat(B.dim);
        auto begin = std::chrono::steady_clock::now();
        #pragma omp parallel for
        for(int i = 0; i< (B.dim*2);i+=2){
            if(B.data[i+1] == A.data[i+1]){
                rat.data[i] = A.data[i]+B.data[i];
                rat.data[i+1] = A.data[i+1];
            }
            else{
            rat.data[i] = ((A.data[i])*(B.data[i+1]))+((B.data[i])*(A.data[i+1]));
            rat.data[i+1] = A.data[i+1]*B.data[i+1];
        }
        }
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        cout << "The time: " << elapsed_ms.count() << " ms\n";
        rat.dim = B.dim;
        return rat;
}
CRat1 operator - (const CRat &A, const CRat &B){
        CRat1 rat(B.dim);
        auto begin = std::chrono::steady_clock::now();
       #pragma omp parallel for
        for(int i = 0; i< (B.dim*2);i+=2){
            if(B.data[i+1] == A.data[i+1]){
                rat.data[i] = A.data[i]-B.data[i];
                rat.data[i+1] = A.data[i+1];
            }
            else{
            rat.data[i] = ((A.data[i])*(B.data[i+1]))-((B.data[i])*(A.data[i+1]));
            rat.data[i+1] = A.data[i+1]*B.data[i+1];
        }
        }
        auto end = std::chrono::steady_clock::now();

        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        cout << "The time: " << elapsed_ms.count() << " ms\n";
        rat.dim = B.dim;
        return rat;
}
void test1(){//оператор присваивания
    CRat0 k(2);
    for(int i = 0; i < 4; i++)
        k.data[i] = i;
    CRat0 p(2);
    p = k;
    k.data[1] = 20;
    if(p.data[1] == 1){
       cout<< "Test 1 passed saccessfully"<<endl;
    }
}
void test2(){// оператор сложения
    CRat0 k(10000000);
    CRat1 l(10000000);
    for(int i = 0; i < k.dim*2; i++){
        k.data[i] = i+1;
        l.data[i] = i+2;
    }
    CRat1 p(2);
    p = k + l;
    if(p.data[2] == 31 && p.data[3] == 20){
       cout<< "Test 2 passed saccessfully"<<endl;
    }
}
void test3(){// оператор скалярного умножения
    CRat1 k(1000000);
    double p = 0;
    for(int i = 0; i < 4; i++)
        k.data[i] = i+1;
    k.data[2] = 4;
    p = k*k;
    if(p == 1.25){
       cout<< "Test 3 passed saccessfully"<<endl;
    }
}
void test4(){//конструктор копирования
    CRat0 k(2);
    for(int i = 0; i < 4; i++)
        k.data[i] = i;
    CRat0 p = k;
    k.data[1] = 20;
    if(p.data[1] == 1){
       cout<< "Test 4 passed saccessfully"<<endl;
    }
}
