#include "HashTable.h"
#include "Les.h"


HashTable::HashTable(int size)
{
    this.size=size;
    this->les=new Les[this.size]();
}

HashTable::~HashTable()
{
    //dtor
}
