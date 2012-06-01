#include "HashTable.h"
#include "Les.h"


HashTable::HashTable(int size, float c)
{
    this.m=size;
    this.c=c;
    this->les=new Les[this.size]();
}

void HashTable::addWord(string value){
}

void HashTable::functionHash(int valueCalculated){
}

int HashTable::calcValueWord(string valueWord){
}

int HashTable::returnPositionValue(string value){
}

HashTable::~HashTable()
{
    //dtor
}
