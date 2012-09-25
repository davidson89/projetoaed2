#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "HashTable.h"
#include "Les.h"
#include <iostream>
#include <fstream>
using namespace std;

/**
 * HashTable - Classe usada para guardar palavras
 * @param  size tamanho da tabela hash
 * @param c fator de carga da tabela
 *
**/
HashTable::HashTable(int size, float c)
{
    this->m=size;
    this->c=c;
    this->les = new Les *[size];
    int i = 0;
    this->qtdPosicao = new int[size];
    for(i=0;i<size;i++)
    {
     this->les[i] = NULL;
    }
}

void HashTable::addWord(string value){


    // valoeeer da string convertendo em numero
    int valorDaString = calcValueWord(value);
   // calcula o indice pela função hash
    int indice = functionHash(valorDaString);

   // cria uma nova celula com a string passada
    Les *newCel = new Les(value);
    // se o indice de destino tiver a primeira posiçao nula entao newcel se torna o primeiro
    if( this->les[indice] == NULL)
    {
    // cout << "indice vazio " << indice << endl;
     this->les[indice] = newCel;

    } else
    {
        // caso contrario percorremos a lista até chegar no ultimo
    Les *Cel = this->les[indice];
    while (Cel->lesProx != NULL)
        {
            Cel = Cel->lesProx;
        }
        Cel->lesProx = newCel;
    }

    return;

}

void HashTable::imprimeHistoGrama()
{
int i;
int qtdLinha = 0;
 for(i=0;i<this->m;i++)
    {
     qtdLinha = QtdLinha(this->les[i]);
     this->qtdPosicao[qtdLinha]++;
    }

  ofstream File (fileName.data());
  if (!File.is_open())
  {
    cout << "Não foi possível abrir o arquivo";
    return;
  }

  for(i=0;i<this->m;i++)
  {
    File << i << "," << this->qtdPosicao[i] <<endl ;

  }
}

int HashTable::QtdLinha(Les *celula)
{
 int qtd =0;
  while(celula !=NULL)
  {
   celula = celula->lesProx;
   qtd++;
  }

  return qtd;

}
int HashTable::functionHash(int valueCalculated){
    float resultParcial = valueCalculated*(this->c);
    float resultConstant = resultParcial - (float)((int)resultParcial);
    return (roundf(resultConstant*this->m));

}

int HashTable::calcValueWord(string valueWord){
    int i;
    int soma=0;
    int sizeWord = valueWord.length();
    for(i=0; i<=sizeWord; i++){
        int numero = static_cast<char>(valueWord[i]);
        soma=soma + numero;
    }
    return soma;

}

void HashTable::imprime(){
    int i = 0;
     for(i=0;i<this->m;i++)
    {
       if(this->les[i] ==NULL)
       {
            cout << "linha " << i << ": \n"<<  endl ;
            continue;
       }
       Les *celula = this->les[i];

        cout << "linha " << i << ": ";
       while(celula!=NULL)
       {
        cout << celula->valor << " | " ;

        celula=celula->lesProx;
       }
      cout << "\n" << endl ;
    }

}
void HashTable::imprimeTxt(string fileName)
{
   ofstream File (fileName.data());
  if (!File.is_open())
  {
    cout << "Não foi possível abrir o arquivo";
    return;
  }

    int i = 0;
     for(i=0;i<this->m;i++)
    {
       if(this->les[i] ==NULL)
       {
            File << "linha " << i << ": \n"<<  endl ;
            continue;
       }
       Les *celula = this->les[i];

       File  << "linha " << i << ": ";
       while(celula!=NULL)
       {
        File << celula->valor << " | " ;

        celula=celula->lesProx;
       }
       File << "\n" << endl;
    }


}

void HashTable::imprimePositionValue(string value){
    int indice = getIndiceValue(value);
    int count = 0;
    Les *auxLes = this->les[indice];
    if(auxLes==NULL){
        cout << "Palavra não encontrada";
        return;
    }
    while(auxLes!=NULL){
        if(auxLes->valor==value){
            cout << value << ": " << indice << " " << count << endl;
            return;
        }
        count ++;
        auxLes = auxLes->lesProx;
    }
    cout << value << ": " << indice << " -1" << endl;
}

int HashTable::getIndiceValue(string value) {
    int valorDaString = calcValueWord(value);
    return functionHash(valorDaString);
}

HashTable::~HashTable()
{
    //dtor
}
