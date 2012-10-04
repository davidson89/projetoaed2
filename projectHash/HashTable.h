#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Les.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class HashTable
{
    public:
        // Atibutos p�blicos
        int m;
        double c;
        // Ponteiro para a lista de endere�os onde ser�o armazenados os elementos (Les = lista encadeada simples)
        Les **les;

        // M�todos p�blicos
        HashTable(int size);
        virtual ~HashTable();
        // Adiciona um elemento string na tabela hash (nesse m�todo � usado a abordagem da soma dos caracteres ascii)
        void addWord(string);
        // Adiciona um elemento string na tabela hash (nesse m�todo � usado a abordagem da multiplica��o dos caracteres ascii)
        void addWord_2(string);
        void imprime();
        void imprimeTxt(string fileName);
        void imprimeHistoGrama(string fileName);
        void imprimePositionValue(string);
        void removeWord(string word);
    protected:
    private:
        // Atributos privados
        // Array utilizado para armazenar os valores gerados pela fun��o de histograma
        int *qtdPosicao;

        // M�todos privados
        // Usado internamente para auxiliar a fun��o de gerar histograma, calculando a quantidade de elementos em um endere�o
        int qtdLinha(Les *celula);
        int getIndiceValue(string);
        int functionHash(int);
        int calcValueWord(string);
        int calcValueWord_2(string);
};

#endif // HASHTABLE_H
