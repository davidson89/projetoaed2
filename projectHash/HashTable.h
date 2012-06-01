#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Les.h"
#include <string>

class HashTable
{
    public:
        HashTable(int, float);
        int m;
        float c;
        Les *les;
        void addWord(string);
        void functionHash(int);
        int calcValueWord(string);
        int returnPositionValue(string);
        virtual ~addWord();
        virtual ~functionHash();
        virtual ~calcValueWord();
        virtual ~HashTable();
    protected:
    private:
};

#endif // HASHTABLE_H
