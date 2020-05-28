#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.h"
using namespace std;
int main()
{
    #ifdef _OPENMP
    cout<<"OPENMP has been started\n"<<endl;
    #endif
    setlocale(LC_ALL,"ru");
    char c;
    int n = 1;// количество данных

    string filename("inputfile.txt");//передачи названия файла
    ifstream File(filename.c_str());//c_str //Открытие файла

    if (!File.is_open()) // если файл не открыт
    {
        cout << "File isn't open!\n";
        return 0;
    }
    while (File.get(c)){ // определеие количества данных
        if (c=='\n')
            n++;
    }
    cout<<"number of data equal to "<< n<<endl;
    File.clear();
    File.seekg(0);// флаг переведен на начало файла

    CRatFactory* fab0 = new CRatFactory0;//  фабрики
    CRatFactory* fab1 = new CRatFactory1;
    map<string,CRatFactory*> f = {{"Hory",fab0},{"Vert",fab1}};

    vector<CRat*> arr;// вектор для данных из файла;

    for(int i = 0; i < n; i++){// получение всех данных из файла
        arr.push_back(CreateData(File, f));
    }
    File.close();

    for(int i = 0; i < n; i++){//Вывод всех данных
        arr[i]->output();
    }
    test1();//Прохождение тестов
    test2();
    test3();
    test4();
    //закрытие/очищение
    for(int i = 0; i < n; i++){

    delete arr[i];

    }

    return 0;
}

