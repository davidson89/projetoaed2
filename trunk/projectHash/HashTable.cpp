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
	this->c= (sqrt(5)-1)/2;
    this->les = new Les *[size];
    int i = 0;
    this->qtdPosicao = new int[size];
    for(i=0;i<size;i++)
    {
	  this->qtdPosicao[i] = 0; 	 
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

void HashTable::addWord_2(string value){


    // valoeeer da string convertendo em numero
   int  valorDaString = calcValueWord_2(value);
   // calcula o indice pela função hash
   unsigned long indice = functionHash_2(valorDaString);


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

void HashTable::imprimeHistoGrama(string fileName)
{
int i;
int qtd = 0;
// percorremos a lista de endereços da tabela hash
// nesse metodo, procuramos em cada endereço , quantidade de elementos que ele possui
// uma vez calculado, vamos no indice do array qtdPosicao, esse indice tem o mesmo valor da quantidade de elementos calculada
// nessa posição é adicionado +1 ,ex:  se lermos o valor na posição X do array e o resultado for 20
// significa que 20 endereços tem X elementos
 for(i=0;i<this->m;i++)
    {
		 // para cada endereço calculamos a qtd de elementos
     qtd = qtdLinha(this->les[i]);
	 // a qtd de elementos determina a posição do array de histograma que será incrementada
     this->qtdPosicao[qtd]++;
    }
 // cria o arquivo para gravar os dados
  ofstream File (fileName.data());
  if (!File.is_open())
  {
  // se nao foi possivel gerar o arquivo
    cout << "Não foi possível abrir o arquivo";
    return;
  }
  // imprimimos o arquivo com valores separados por virgula
  for(i=0;i<this->m;i++)
  {
    File << i << "," << this->qtdPosicao[i] <<endl ;

  }
}

int HashTable::qtdLinha(Les *celula)
{
 int qtd =0;
 // calcula a quantidade elementos de um dado endereço
 while(celula !=NULL)
  {
   celula = celula->lesProx;
   qtd++;
  }

  return qtd;

}
// calcula o indice para o valor de elemento passado com parametro ( usado na abordagem da soma )
int HashTable::functionHash(int valueCalculated){
    // multiplica o valor passado pela constante c
	double resultParcial = valueCalculated*(this->c);
	// pega a parte inteira do valor
	int parteInteira = (int)resultParcial;
	// usa a parte inteira e o valor original para conseguir a parte fracionaria
	double resultConstant =  resultParcial - parteInteira ;
	// multiplicamos o vamor por m e arredondamos para baixo
    return (abs(floor(resultConstant*this->m)));

}
// calcula o indice para o valor de elemento passado com parametro ( usado na abordagem da multiplicação )
unsigned long HashTable::functionHash_2(int valueCalculated){
	    // multiplica o valor passado pela constante c
    double resultParcial = valueCalculated*(this->c);
		// pega a parte inteira do valor
	int parteInteira = (int)resultParcial;
	// usa a parte inteira e o valor original para conseguir a parte fracionaria
	double resultConstant =  resultParcial - parteInteira ;
	// multiplicamos o vamor por m e arredondamos para baixo
    return (abs(floor(resultConstant*this->m)));

}

int HashTable::calcValueWord(string valueWord){
    int i;
	// soma total
    int soma=0;
	// o total de caracteres da string
    int sizeWord = valueWord.length();
	// para caracter somamos na variavel seu valor
    for(i=0; i<=sizeWord; i++){
        int numero = static_cast<char>(valueWord[i]);
        soma=soma + numero;
    }
    return soma;

}

int HashTable::calcValueWord_2(string valueWord){
    int i;
	// variavel usada para armazenar a multiplicação
    int multiplicacao=1;
	
    
    int sizeWord = valueWord.length();
	// para caracter multiplicamos na variavel seu valor
    for(i=0; i<=sizeWord; i++){
        int numero = static_cast<char>(valueWord[i]);
		// para o caso de caracters com valor 0 , nao ocorrer de zerar o valor total
		if(numero > 0) multiplicacao=multiplicacao * numero;
    }
    return abs (multiplicacao);

}

void HashTable::imprime(){
    int i = 0;
   // para cada endereço da tabela
	for(i=0;i<this->m;i++)
    {
       if(this->les[i] ==NULL)
       {
         // se for vazio o endereço 
		   cout << "linha " << i << ": \n"<<  endl ;
            continue;
       }
      // referencia o endereço
	   Les *celula = this->les[i];
	   // inicia a impressao da lista encadeada simples
        cout << "linha " << i << ": ";
      // enquanto não encontrar o fim
		while(celula!=NULL)
       {
		   // imprime o valor
        cout << celula->valor << " | " ;
		// parte para o proximo elemento
        celula=celula->lesProx;
       }
      cout << "\n" << endl ;
    }

}

void HashTable::imprimeTxt(string fileName)
{
	// cria o arquivo utilizado para armazenar os valores
   ofstream File (fileName.data());
  if (!File.is_open())
  {
	  // caso nao consiga abrir o arquivo ,retorna o erro
    cout << "Não foi possível abrir o arquivo";
    return;
  }

    int i = 0;
	// para cada endereço da tabela
     for(i=0;i<this->m;i++)
    {
       if(this->les[i] ==NULL)
       {  // se for vazio o endereço 
            File << "linha " << i << ": \n"<<  endl ;
            continue;
       }
	    // referencia o endereço
       Les *celula = this->les[i];
	     // inicia a impressao da lista encadeada simples
       File  << "linha " << i << ": ";
	      // enquanto não encontrar o fim
       while(celula!=NULL)
       {
		   	   // imprime o valor
        File << celula->valor << " | " ;
			// parte para o proximo elemento
        celula=celula->lesProx;
       }
       File << "\n" << endl;
    }
	 // fecha o arquivo
	 File.close();


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

void HashTable::removeWord(string word){
    int valorDaString = calcValueWord(word);
   // calcula o indice pela função hash
    int indice = functionHash(valorDaString);
    
    if(this->les[indice]==NULL){
    	return;
    }

    Les *anterior = this->les[indice];
    Les *atual = this->les[indice]->lesProx;
    for (atual; atual!=NULL; atual=atual->lesProx){
        if (word==atual->valor){
            anterior->lesProx = atual->lesProx;
            free(atual);
        }
        anterior=atual;
    }
    if(this->les[indice]->valor==word){
        Les *aux = this->les[indice];
        //free(aux);
        this->les[indice] = this->les[indice]->lesProx;
    }
}

HashTable::~HashTable()
{
    //dtor
}
