#include <iostream>
#include "Les.h"
#include "HashTable.h"
#define  M 49157
#define  C 0.618
#include <cstdlib>
#include <fstream>
#include <stdio.h>

using namespace std;
using std::string;
int main()
{
   HashTable *hashTable = new HashTable(M,C);
   hashTable->addWord("abcdefgij");
   hashTable->addWord("alpenstock");
   hashTable->addWord("alpenstock");
   string line="";
   ifstream myfile ("words.txt");




  FILE *arq;


  arq=fopen("words.txt","r");
    char *str = new char[100];
    while(!feof(arq)){

    fscanf(arq,"%s",str); //Le  a linha e grava e em str
    line  = str;
    hashTable->addWord(line);

    }


  hashTable->imprimeTxt("saida.txt");
  hashTable->imprimeHistoGrama("saidaHistograma.txt");






    return 0;
}
