#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Les.h"
#include <string>

class HashTable
{
    public:
        HashTable(int size, float c);
        virtual ~HashTable();
        int m;
        float c;
        Les* les;
        void addWord(string value);
        int functionHash(int valueCalculated);
        int calcValueWord(string valueWord);
        int getPositionValue(string value);
    protected:
    private:
};

#endif // HASHTABLE_H
