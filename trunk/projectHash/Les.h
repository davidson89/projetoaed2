#ifndef LES_H
#define LES_H
#include <string>

using namespace std;
// classe que represeta um elemento de lista encadeada
class Les
{

    public:
		// construtor
        Les(string valor);
		// destrutor
        virtual ~Les();
		// valor armazenado no elemento
        string valor;
		// ponteiro para o proximo elemento
        Les *lesProx;
		// set para o valor do elemento
        void setValor(string valor);
		// seta o proximo elemento
        void setProxLes(Les *proxLes);
    protected:
    private:
};

#endif // LES_H
