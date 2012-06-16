#include "Les.h"

Les::Les()
{

}

void Les::setValor(string valor){
    this->valor = valor;
}

void Les::setProxLes(Les *proxLes){
    this->lesProx = proxLes;
}

Les::~Les()
{
    //dtor
}
