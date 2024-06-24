//20.06.24
//ЗАвдання 2 
//#include <iostream>
//#include <Windows.h>
//#include <fstream>
//#include<string>
//#include <algorithm>
//using namespace std;
//int main()
//{
    //SetConsoleCP(1251);/*
    //SetConsoleOutputCP(1251);*/
    
    /*ifstream F;
    F.open("1.txt");
    if (!F.is_open())
    {
        cout << "File not found"<<endl;
        return 1;
    }*/
   
    

    //task 1,2
    /*ofstream W("2.txt");
    if (!W)
    {
        cout << "File Error" << endl;
        return 1;
    }
    string line;
    string mas[50];
    int index_mas = 0;
    while (getline(F, line)) {
        W << line << endl;
        mas[index_mas] = line;
        index_mas++;
    }
    reverse(mas, mas + (index_mas + 1));
    
    
    ofstream W2("3.txt");
    if (!W2)
    {
        cout << "File error" << endl;
        return 1;
    }
    for (int i = 0; i < index_mas + 1; i++) {
        W2 << mas[i] << endl;
    }
    cout << "overwriting done";
    F.close();
    W.close();
    W2.close();*/


    //task 3
//    ofstream F;
//    F.open("1.txt",ios::app);
//    if (!F.is_open())
//    {
//        cout << "File not found" << endl;
//        return 1;
//    }
//    string line="------------";
//    F <<line;
//    F.close();
//    cout << "overwriting done" << endl;
//    return 0;
//}

//task 1 
#include <iostream>
#include <Windows.h>
#include <fstream>
#include<string>
#include <algorithm>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream F("1.txt");
    ifstream W("2.txt");//НЕприйнятні слова 
    string mas[20];
    
    int index_mas=0;
    if (!F.is_open() || !W.is_open())
    { 
        cout << "File not found" << endl;
        return 1;
    }
    while (W>>mas[index_mas]){
        index_mas++;
        //cout << line;
    }
    W.close();
    cout << "Zchytuvania sliv vykonano"<<endl;
    /*for (int i = 0; i < index_mas; i++) {
        cout << mas[i] << " ";
    }*/
    ofstream W2("3.txt");
    if (!W2)
    {
        cout << "File error" << endl;
        return 1;
    }
    string line;
    string word;
    bool ex = false;
    while (getline(F, line)) {
        for (char i : line) {
            if (i != ' ') {
                word += i;
            }
            if (i == ' ') {
               /* word = "\n";*/
                
                for (int j = 0; j < index_mas; j++) {
                    if (word == mas[j]) {
                        ex == true;
                        //break;
                    }
                }
                if (!ex) {
                    W2 << word<<" ";
                    cout << word;
                }
                word = " ";
            }
        }
    }
    cout << "overwriting done"<<endl;
    F.close();
    W2.close();
}
