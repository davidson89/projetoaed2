#ifndef LES_H
#define LES_H
#include <string>

using namespace std;

class Les
{

    public:
        Les();
        virtual ~Les();
        string valor;
        Les *lesProx;
        void setValor(string valor);
        void setProxLes(Les *proxLes);
    protected:
    private:
};

#endif // LES_H
