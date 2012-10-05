#include <iostream>
#include "HashTable.h"
#define  M 49157
#include <cstdlib>
#include <fstream>
#include <stdio.h>

using namespace std;
using std::string;

void createMenu(char* fileName);
void imprimeMenu();

int main(int argc, char** argv)
{


    if(argc == 0){
        cout << "Falta de argumentos!" << endl;
    }
    createMenu(argv[1]);

    return 0;
}

/**
 * createMenu - Método usado para criar o menu com as opções de munipulação que serão fornecidas ao usuário.
 * @param fileName nome do arquivo contendo as palavras a serem carregadas na Hash Table
**/
void createMenu(char* fileName){
    bool opt = true;
    int valor;
    string line = "";
    char *word = new char[50];
    char *fileNameOut = new char[50];
    FILE *arq;
    HashTable *hashTable = new HashTable(M);
    ifstream myfile(fileName);

    arq = fopen(fileName, "r");
    if(arq == NULL){
        cout << "Arquivo com as palavras a serem carregadas nao encontrado!\n" << endl;
        return;
    }
    char *str = new char[100];
    while(!feof(arq)){
        fscanf(arq, "%s", str);
        line = str;
        hashTable->addWord(line);
    }

    while(opt){
        imprimeMenu();
        scanf("%d", &valor);
        switch(valor){
            case 0: hashTable->imprime();
                    break;
            case 1: cout << "Digite o nome do arquivo a ser gerado: " << endl;
                    scanf("%s", fileNameOut);
                    hashTable->imprimeTxt(string(fileNameOut));
		    cout << "O arquivo "<< fileNameOut << " foi gerado com sucesso e encontra-se no diretorio raiz!" << endl;
                    break;
            case 2: hashTable->imprimeHistoGrama("saidaHistograma.txt");
		    cout << "O arquivo saidaHistograma.txt foi gerado com sucesso e encontra-se no diretorio raiz!" << endl;
                    break;
            case 3: cout << "Digite a palavra a ser procurada: " << endl;
                    scanf("%s", word);
                    hashTable->imprimePositionValue(string(word));
                    break;
            case 4: cout << "Digite o nome do arquivo que contem as palavras a serem procuradas na Hash table: " << endl;
                    scanf("%s", word);
                    arq = fopen(word, "r");
                    if(arq == NULL){
                        cout << "Arquivo nao encontrado!\n" << endl;
                        break;
                    }
                    while(!feof(arq)){
                        fscanf(arq, "%s", str);
                        line = str;
                        hashTable->imprimePositionValue(line);
                    }
                    break;
            case 5: cout << "Digite o nome do arquivo que contem as palavras a serem excluidas da Hash table: " << endl;
            	    scanf("%s", word);
                    arq = fopen(word, "r");
                    if(arq == NULL){
                        cout << "Arquivo nao encontrado!\n" << endl;
                        break;
                    }
                    while(!feof(arq)){
                        fscanf(arq, "%s", str);
                        line = str;
                        hashTable->removeWord(line);
                    }
                    break;
            case 6: opt = false;
                    break;
        }
    }
}

/**
 *imprimeMenu - Método usado para ficar imprimir o menu com as opções para rodar o manipular o sistema como um todo.
 *
**/
void imprimeMenu(){
    cout << "************************MENU************************\n"
    "Digite: \n"
    "0 - Para imprimir na tela a tabela hash gerada\n"
    "1 - Para direcionar a saida da tabela hash num arquivo\n"
    "2 - Para gerar um arquivo com os dados para o histograma \n"
    "3 - Para imprimir na tela a posicao de uma palavra\n"
    "4 - Para imprimir na tela as posicoes das palavras contidas num arquivo\n"
    "5 - Para excluir as palavras contidas num arquivo\n"
    "6 - Para sair\n" << endl;
}
