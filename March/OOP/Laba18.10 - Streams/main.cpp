#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Pair.h"

using namespace std;


void Print(vector<Pair> collection)
{
    for (int i = 0; i < collection.size(); i++) {
        cout << "(" << collection[i].getFirst() << ";" << collection[i].getSecond() << ")" << endl;
    }
}

vector<Pair> ReadFile(string fileName)
{
    vector<Pair> res;
    ifstream streamR;
    streamR.open(fileName);

    while (!streamR.eof()) {
        Pair element;
        streamR >> element;
        if (element != Pair())
            res.push_back(element);
    }
    streamR.close();
    return res;
}

void AddElements(char* fileName, vector<Pair> newElements, int position)
{
    ifstream streamR;
    streamR.open(fileName);
    ofstream streamW;
    streamW.open("temp.txt");

    int count = 0;
    if (0 == position) {
        for (int i = 0; i < newElements.size(); i++) {
            streamW << newElements[i];
        }
    }
    while (!streamR.eof())
    {
        Pair element;
        streamR >> element;
        if (element != Pair()) {
            streamW << element;
            count++;
            if (count == position) {
                for (int i = 0; i < newElements.size(); i++) {
                    streamW << newElements[i];
                }
            }
        }
    }
    streamR.close();
    streamW.close();
    remove(fileName);
    rename("temp.txt", fileName);
}

void IncreaseElement(char* fileName, int valueFirst, double valueSecond, int L)
{
    ifstream streamR;
    streamR.open(fileName);
    ofstream streamW;
    streamW.open("temp.txt");

    while (!streamR.eof()) {
        Pair element;
        streamR >> element;
        if (element != Pair()) {
            // проверка элемента на условия для увеличения
            if (element.getFirst() == valueFirst && element.getSecond() == valueSecond)
            {
                element.setFirst(element.getFirst() + L);
                element.setSecond(element.getSecond() + L);
            }
            streamW << element;
        }
    }
    streamR.close();
    streamW.close();
    remove(fileName);
    rename("temp.txt", fileName);
}

void DeleteSmallerElements(char* fileName, int minFirst, double minSecond)
{
    ifstream streamR;
    streamR.open(fileName);
    ofstream streamW;
    streamW.open("temp.txt");

    while (!streamR.eof()) {
        Pair element;
        streamR >> element;
        if (element != Pair()) {
            if (element.getFirst() >= minFirst || element.getSecond() >= minSecond) {
                streamW << element;
            }
        }
       
    }
    streamR.close();
    streamW.close();
    remove(fileName);
    rename("temp.txt", fileName);
}

int main()
{
	system("chcp 1251>nul");
    string input = " ";
    while (input[0] != '0')
    {
        cout << "1 - Чтение файла" << endl;
        cout << "2 - Чтение с удалением" << endl;
        cout << "3 - Чтение с изменением" << endl;
        cout << "4 - Чтение с добавлением" << endl;
        cout << "0 - Выход" << endl;
        cin >> input;

        char path[] = "input.txt";
        vector<Pair> pairs;
        switch (input[0])
        {
        case '1':
        {
            cout << "Чтение из файла без изменений" << endl;
            pairs = ReadFile(path);
            break;
        }
        case '2':
        {
            cout << "Чтение из файла с удалением элементов меньше 3" << endl;
            DeleteSmallerElements(path, 3, 3);
            pairs = ReadFile(path);
            break;
        }
        case '3':
        {
            int f;
            double s;
            cout << "Введите пару, которую нужно увеличить" << endl;
            cin >> f >> s;
            cout << "Чтение из файла с увеличением элементов на 2" << endl;
            IncreaseElement(path, f, s, 2);
            pairs = ReadFile(path);
            break;
        }
        case '4':
        {
            int f1, f2, ind = -1;
            double s1, s2;
            cout << "Введите 2 пары чисел: " << endl;
            cin >> f1 >> s1 >> f2 >> s2;
            pairs = ReadFile(path);
            while (ind < 0 || ind > pairs.size()) {
                cout << "Введите индекс" << endl;
                cin >> ind;
            }
            cout << "Чтение из файла с добавлением 2 элементов" << endl;
            vector<Pair> newElements = { Pair(f1, s1), Pair(f2, s2) };
            AddElements(path, newElements, ind);
            pairs = ReadFile(path);
            break;
        }
        }
        Print(pairs);
    }

    return 0;
}