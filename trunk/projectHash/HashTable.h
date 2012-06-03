#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Les.h"
#include <string>

class HashTable
{
    public:
        HashTable(int, float);
        virtual ~HashTable();
        int m;
        float c;
        Les *les;
        void addWord(string);
        int functionHash(int);
        int calcValueWord(string);
        int getPositionValue(string);
    protected:
    private:
};

#endif // HASHTABLE_H
