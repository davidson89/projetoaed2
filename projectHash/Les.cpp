#include "Les.h"

Les::Les(string valor, Les *proxLes)
{
    this->valor = valor;
    this->lesProx = proxLes;
}

Les::~Les()
{
    //dtor
}
