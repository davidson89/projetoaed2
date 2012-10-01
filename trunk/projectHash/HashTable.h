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
        void addWord_2(string);
        void imprime();
        void imprimeTxt(string fileName);
        void imprimeHistoGrama(string fileName);
        void imprimePositionValue(string);
        void removeWord(string word);
    protected:
    private:
    int qtdLinha(Les *celula);
    int getIndiceValue(string);
    int functionHash(int);
    int calcValueWord(string);
    int calcValueWord_2(string);
};

#endif // HASHTABLE_H
