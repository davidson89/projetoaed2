#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Les.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class HashTable
{
    public:
        HashTable(int size, float c);
        virtual ~HashTable();
        int m;
        float c;
        Les** les;
        int *qtdPosicao;
        void addWord(string);
        int functionHash(int);
        int calcValueWord(string);
        int getPositionValue(string);
        void imprime();
        void imprimeTxt(string fileName);
        void imprimeHistoGrama();
        int QtdLinha(Les *celula);
    protected:
    private:
};

#endif // HASHTABLE_H
