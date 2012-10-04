#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Les.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
// classe que representa a tabela hash e suas propriedades
class HashTable
{
    public:
		// construtor
        HashTable(int size, float c);
		// destrutor
        virtual ~HashTable();
		// variavel que indica o tamanho da lista de endere�os, tambem � usada no calculo da fun��o de hash
        int m;
		// constante utilizada no calculo da fun��o de hash
        double c;
		// ponteiro para a lista de endere�os, aonde ser�o armazenados os elementos ( Les = lista encadeada simples )
        Les** les;
		// array utilizado para armazenar os valores gerados pela fun��o de histograma
        int *qtdPosicao;
		// fun��o principal que adiciona um elemento string � tabela hash ( nessa fun��o � usada a abordagem da soma )
        void addWord(string);
		// fun��o principal que adiciona um elemento string � tabela hash ( nessa fun��o � usada a abordagem da multiplica��o )
        void addWord_2(string);
		// fun��o utilizada para se imprimir na tela a tabela hash gerada
        void imprime();
		// imprime em um arquivo txt a tabela gerada
        void imprimeTxt(string fileName);
		// imprime um arquivo com valores separados por virgula , esses valores s�o utilizados para gerar o grafico do histograma
        void imprimeHistoGrama(string fileName);
		// imprime na tela a posi��o de um elemento da tabela
        void imprimePositionValue(string);
		// remove um elemento na tabela 
        void removeWord(string word);
    
    private:
    // fun�ada usada internamente para auxiliar a fun��o de gerar histograma , calculando a quantidade de elementos em um endere�o
    int qtdLinha(Les *celula);
	// Retorna o indice de um elemento na tabela
    int getIndiceValue(string);
	// aplica a fun��o de hash em um elemento recebendo como parametro o valor inteiro relativo a string que se quer armazenar ( nessa fun��o � usada a abordagem da soma )
    int functionHash(int);
	// aplica a fun��o de hash em um elemento recebendo como parametro o valor inteiro relativo a string que se quer armazenar ( nessa fun��o � usada a abordagem da multiplica��o )
	unsigned long functionHash_2(int); 
	// retorna o valor em inteiro de uma string passada como paramtero ( nessa fun��o � usada a abordagem da soma )
    int calcValueWord(string);
	// retorna o valor em inteiro de uma string passada como paramtero ( nessa fun��o � usada a abordagem da multiplica��o )
    int calcValueWord_2(string);
};

#endif // HASHTABLE_H
