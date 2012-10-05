#include "Les.h"

/**
 * Esta classe será ultilizada para compor a estrutura da HashTable, montando uma estrutura de lista ligada simples.
 * @param valor string que sera armazenada na estrutura.
**/
Les::Les(string valor)
{
    this->valor = valor;
    this->lesProx = NULL;
}

Les::~Les()
{
    //dtor
}
