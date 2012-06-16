#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "HashTable.h"
#include "Les.h"

using namespace std;

HashTable::HashTable(int size, float c)
{
    this->m = size;
    this->c = c;
    this->les = new Les[m];
}

void HashTable::addWord(string value){
    int valorDaString = calcValueWord(value);
    int indice = functionHash(valorDaString);
    Les *lesNew = new Les();
    lesNew->setValor(value);
    lesNew->setProxLes(NULL);
    if(this->les[indice] == NULL){
        this->les[indice] == lesNew;
    }else{
        Les aux = this->les[indice];
        while(aux->lesProx!= NULL){
            aux = aux->lesProx;
        }
        aux->lesProx = lesNew;
    }

}

int HashTable::functionHash(int valueCalculated){
    float resultParcial = valueCalculated*(this->c);
    float resultConstant = resultParcial - (float)((int)resultParcial);

    return (roundf(resultConstant*this->m));

}

int HashTable::calcValueWord(string valueWord){
    int i;
    int soma=0;
    char valueLetra;
    int sizeWord = valueWord.length();
    for(i=0; i<=sizeWord; i++){
        valueLetra = static_cast<char>(valueWord[0]);
        soma=soma + atoi(&valueLetra);
    }

    return soma;

}


int HashTable::getPositionValue(string value){
}

HashTable::~HashTable()
{
    //dtor
}
