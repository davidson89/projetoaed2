#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "HashTable.h"
#include "Les.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * HashTable - Construtor da classe usada para guardar strings
 * @param size tamanho da tabela Hash, é a constante M definida na classe main
**/
HashTable::HashTable(int size)
{
    this->m = size;
	this->c = (sqrt(5)-1)/2;
    this->les = new Les *[size];
    this->qtdPosicao = new int[size];
    for(int i = 0; i < size; i++){
        this->qtdPosicao[i] = 0;
        this->les[i] = NULL;
    }
}

/**
 * addWord - Método usado para armazenar strings na Hash table
 * Usa-se a soma dos caracteres ASCII da string para calcular o Hash
 * @param value string a ser armazenada na Hash table
**/
void HashTable::addWord(string value){
    // valor da string convertendo em numero
    int valorDaString = calcValueWord(value);
    // calcula o indice pela função hash
    int indice = functionHash(valorDaString);
    // cria uma nova celula com a string passada
    Les *newCel = new Les(value);
    // se o indice de destino tiver a primeira posição nula entao newcel se torna o primeiro
    if(this->les[indice] == NULL){
        this->les[indice] = newCel;
    } else {
        // caso contrario percorremos a lista até chegar no ultimo
        Les *Cel = this->les[indice];
        while (Cel->lesProx != NULL){
            Cel = Cel->lesProx;
        }
        Cel->lesProx = newCel;
    }
}

/**
 * addWord2 - Método usado para armazenar strings na Hash table
 * Usa-se a multiplicação dos caracteres ASCII da string para calcular o Hash
 * @param value string a ser armazenada na Hash table
**/
void HashTable::addWord_2(string value){
    // valor da string convertendo em numero
    int valorDaString = calcValueWord_2(value);
    // calcula o indice pela função hash
    unsigned long indice = functionHash(valorDaString);
    // cria uma nova celula com a string passada
    Les *newCel = new Les(value);
    // se o indice de destino tiver a primeira posiçao nula entao newcel se torna o primeiro
    if(this->les[indice] == NULL){
        this->les[indice] = newCel;
    } else {
        // caso contrario percorremos a lista até chegar no ultimo
        Les *Cel = this->les[indice];
        while (Cel->lesProx != NULL){
            Cel = Cel->lesProx;
        }
        Cel->lesProx = newCel;
    }
}

/**
 * imprimeHistoGrama - Método usado para gerar um arquivo externo contendo a quantidade de índices que possuem uma determinada quantidade de elementos
 * Exemplo: 3, 200
 * Significa que 200 índices possuem 3 elementos cada.
 * @param fileName nome do arquivo de saída
**/
void HashTable::imprimeHistoGrama(string fileName){
    // percorremos a lista de endereços da tabela hash
    // nesse metodo, procuramos em cada endereço , quantidade de elementos que ele possui
    // uma vez calculado, vamos no indice do array qtdPosicao, esse indice tem o mesmo valor da quantidade de elementos calculada
    // nessa posição é adicionado +1 ,ex:  se lermos o valor na posição X do array e o resultado for 20
    // significa que 20 endereços tem X elementos
    int qtd = 0;
    for(int i = 0; i < this->m; i++){
        // para cada endereço calculamos a qtd de elementos
        qtd = qtdLinha(this->les[i]);
        // a qtd de elementos determina a posição do array de histograma que será incrementada
        this->qtdPosicao[qtd]++;
    }
    // cria o arquivo para gravar os dados
    ofstream File(fileName.data());
    if(!File.is_open()){
        // se nao foi possivel gerar o arquivo
        cout << "Não foi possível abrir o arquivo";
        return;
    }
    // imprimimos o arquivo com valores separados por virgula
    for(int i = 0; i < this->m; i++){
        File << i << "," << this->qtdPosicao[i] << endl;
    }
}

/**
 * qtdLinha - Método usado para contar a quantidade de elementos dentro de determinado índice
 * @param celula ponteiro para o índice de Les
 * @return retorna a quantidade de elementos dentro do índice
**/
int HashTable::qtdLinha(Les *celula){
    int qtd =0;
    // calcula a quantidade elementos de um dado endereço
    while(celula != NULL){
        celula = celula->lesProx;
        qtd++;
    }
    return qtd;
}

/**
 * functionHash - Método usado para determinar o índice para uma string na Hash table
 * @param valueCalculated valor da palavra previamente calculado pelo método calcValueWord
 * @return retorna um número inteiro que será usado como índice para a string na Hash table
**/
int HashTable::functionHash(int valueCalculated){
    double resultParcial = valueCalculated * (this->c);
	int parteInteira = (int) resultParcial;
	double resultConstant = resultParcial - parteInteira;
    return (abs(floor(resultConstant*this->m)));
}

/**
 * calcValueWord - Método usado para somar os caracteres ASCII da string
 * @param valueWord a própria string
 * @return retorna a soma dos caracteres ASCII
**/
int HashTable::calcValueWord(string valueWord){
    int soma=0;
    int sizeWord = valueWord.length();
    for(int i = 0; i <= sizeWord; i++){
        int numero = static_cast<char>(valueWord[i]);
        soma += numero;
    }
    return soma;
}

/**
 * calcValueWord_2 - Método usado para multiplicar os caracteres ASCII da string
 * @param valueWord a própria string
 * @return retorna a multiplicação dos caracteres ASCII
**/
int HashTable::calcValueWord_2(string valueWord){
    int mult = 1;
    int sizeWord = valueWord.length();
    for(int i = 0; i <= sizeWord; i++){
        int numero = static_cast<char>(valueWord[i]);
		if(numero > 0) mult *= numero;
    }
    return abs(mult);
}

/**
 * imprime - Método usado para imprimir na tela toda estrutura da Hash table
**/
void HashTable::imprime(){
    for(int i = 0; i < this->m; i++){
        if(this->les[i] == NULL){
            cout << "linha " << i << ": \n" <<  endl;
            continue;
        }
        Les *celula = this->les[i];
        cout << "linha " << i << ": ";
        while(celula != NULL){
            cout << celula->valor << " | ";
            celula = celula->lesProx;
        }
        cout << "\n" << endl;
    }
}

/**
 * imprimeTxt - Método usado para gerar um arquivo externo contendo toda estrutura da Hash table
 * @param fileName nome do arquivo a ser criado
**/
void HashTable::imprimeTxt(string fileName){
    // cria o arquivo utilizado para armazenar os valores
    ofstream File(fileName.data());
    if(!File.is_open()){
        // caso nao consiga abrir o arquivo ,retorna o erro
        cout << "Não foi possível abrir o arquivo";
        return;
    }

    for(int i = 0; i < this->m; i++){
        if(this->les[i] == NULL){
            File << "linha " << i << ": \n" <<  endl;
            continue;
        }
        Les *celula = this->les[i];
        File  << "linha " << i << ": ";
        while(celula != NULL){
            File << celula->valor << " | ";
            celula = celula->lesProx;
        }
        File << "\n" << endl;
    }
    File.close();
}

/**
 * imprimePositionValue - Método usado para imprimir a string, o índice e a posição da string na Hash table, imprime o índice seguido de -1 caso a string não exista
 * @param value a própria string a ser procurada
 * Exemplo: apache 32 3
**/
void HashTable::imprimePositionValue(string value){
    int indice = getIndiceValue(value);
    int count = 0;
    Les *auxLes = this->les[indice];
    if(auxLes == NULL){
        cout << value << " " << indice << " -1" << endl;
        return;
    }
    while(auxLes != NULL){
        if(auxLes->valor == value){
            cout << value << " " << indice << " " << count << endl;
            return;
        }
        count++;
        auxLes = auxLes->lesProx;
    }
    cout << value << " " << indice << " -1" << endl;
}

/**
 * getIndiceValue - Método usado para retornar o índice onde a string deveria estar na Hash table
 * @param value a própria string a ser procurada
 * @return índice onde a string deveria estar na Hash table
**/
int HashTable::getIndiceValue(string value){
    int valorDaString = calcValueWord(value);
    return functionHash(valorDaString);
}

/**
 * removeWord - Método usado para remover a string da Hash table. Não faz nada caso a string não exista na Hash table.
 * @param word a string a ser removida
**/
void HashTable::removeWord(string word){
    int valorDaString = calcValueWord(word);
    // calcula o indice pela função hash
    int indice = functionHash(valorDaString);
    // caso o índice não contenha string alguma, não há o que remover
    if(this->les[indice] == NULL){
        return;
    }
    Les *elemento = this->les[indice];
    Les *elementoAnterior;

    if(elemento->valor == word){
        this->les[indice] = elemento->lesProx;
        delete elemento;
        return;
    }

    while (elemento != NULL){
        if(elemento->valor == word){
            elementoAnterior->lesProx = elemento->lesProx;
            delete elemento;
        return;
        }
        elementoAnterior = elemento;
        elemento = elemento->lesProx;
    }
}

HashTable::~HashTable(){
    // inicia a limpeza na tabela
    int tamanho = this->m;
    for(int i = 0; i < tamanho; i++){
        Les *elemento = this->les[i];
        Les *prox_elemento = NULL;
        while(elemento != NULL){
            prox_elemento = elemento->lesProx;
            delete elemento;
            elemento = prox_elemento;
            prox_elemento = NULL;
        }
    }
    // deleta o array de histograma
    delete[] qtdPosicao;
    // deleta o array de elementos
    delete[] this->les;
}
