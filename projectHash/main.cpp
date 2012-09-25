#include <iostream>
#include "HashTable.h"
#define  M 49157
#define  C 0.618
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
        cout << "Falta de arumentos!" << endl;
    }
    createMenu(argv[1]);

    return 0;
}

void createMenu(char* fileName) {
    bool opt = true;
    int valor;
    string line="";
    char *word = new char[50];
    char *fileNameOut = new char[50];
    FILE *arq;
    HashTable *hashTable = new HashTable(M,C);
    ifstream myfile (fileName);

    arq=fopen(fileName,"r");
    char *str = new char[100];
    while(!feof(arq)){
        fscanf(arq,"%s",str); //Le  a linha e grava e em str
        line  = str;
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
                    break;

            case 2: hashTable->imprimeHistoGrama("saidaHistograma.txt");
                    break;
            case 3: cout << "Digite a palavra a ser procurada: " << endl;
                    scanf("%s", word);
                    hashTable->imprimePositionValue(string(word));
                    break;
            case 4: opt = false;
                    break;
        }
    }
}

void imprimeMenu(){
    cout << "************************MENU************************\n"
    "Digite: \n"
    "0 - Para imprimir a tabela hash gerada\n"
    "1 - Para direcionar a saída da tabela hash a um arquivo\n"
    "2 - Para imprimir histograma \n"
    "3 - Para procurar a posiçaõ de uma palavra\n"
    "4 - Para sair\n" << endl;
}
