#ifndef LES_H
#define LES_H
#include <string>

using namespace std;

class Les
{

    public:
        Les(string valor,Les *proxLes);
        virtual ~Les();
        string valor;
        Les *lesProx;
    protected:
    private:
};

#endif // LES_H
