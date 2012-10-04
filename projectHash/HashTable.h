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
        // Atibutos públicos
        int m;
        double c;
        // Ponteiro para a lista de endereços onde serão armazenados os elementos (Les = lista encadeada simples)
        Les **les;

        // Métodos públicos
        HashTable(int size);
        virtual ~HashTable();
        // Adiciona um elemento string na tabela hash (nesse método é usado a abordagem da soma dos caracteres ascii)
        void addWord(string);
        // Adiciona um elemento string na tabela hash (nesse método é usado a abordagem da multiplicação dos caracteres ascii)
        void addWord_2(string);
        void imprime();
        void imprimeTxt(string fileName);
        void imprimeHistoGrama(string fileName);
        void imprimePositionValue(string);
        void removeWord(string word);
    protected:
    private:
        // Atributos privados
        // Array utilizado para armazenar os valores gerados pela função de histograma
        int *qtdPosicao;

        // Métodos privados
        // Usado internamente para auxiliar a função de gerar histograma, calculando a quantidade de elementos em um endereço
        int qtdLinha(Les *celula);
        int getIndiceValue(string);
        int functionHash(int);
        int calcValueWord(string);
        int calcValueWord_2(string);
};

#endif // HASHTABLE_H
