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
		// variavel que indica o tamanho da lista de endereços, tambem é usada no calculo da função de hash
        int m;
		// constante utilizada no calculo da função de hash
        double c;
		// ponteiro para a lista de endereços, aonde serão armazenados os elementos ( Les = lista encadeada simples )
        Les** les;
		// array utilizado para armazenar os valores gerados pela função de histograma
        int *qtdPosicao;
		// função principal que adiciona um elemento string á tabela hash ( nessa função é usada a abordagem da soma )
        void addWord(string);
		// função principal que adiciona um elemento string á tabela hash ( nessa função é usada a abordagem da multiplicação )
        void addWord_2(string);
		// função utilizada para se imprimir na tela a tabela hash gerada
        void imprime();
		// imprime em um arquivo txt a tabela gerada
        void imprimeTxt(string fileName);
		// imprime um arquivo com valores separados por virgula , esses valores são utilizados para gerar o grafico do histograma
        void imprimeHistoGrama(string fileName);
		// imprime na tela a posição de um elemento da tabela
        void imprimePositionValue(string);
		// remove um elemento na tabela 
        void removeWord(string word);
    
    private:
    // funçada usada internamente para auxiliar a função de gerar histograma , calculando a quantidade de elementos em um endereço
    int qtdLinha(Les *celula);
	// Retorna o indice de um elemento na tabela
    int getIndiceValue(string);
	// aplica a função de hash em um elemento recebendo como parametro o valor inteiro relativo a string que se quer armazenar ( nessa função é usada a abordagem da soma )
    int functionHash(int);
	// aplica a função de hash em um elemento recebendo como parametro o valor inteiro relativo a string que se quer armazenar ( nessa função é usada a abordagem da multiplicação )
	unsigned long functionHash_2(int); 
	// retorna o valor em inteiro de uma string passada como paramtero ( nessa função é usada a abordagem da soma )
    int calcValueWord(string);
	// retorna o valor em inteiro de uma string passada como paramtero ( nessa função é usada a abordagem da multiplicação )
    int calcValueWord_2(string);
};

#endif // HASHTABLE_H
