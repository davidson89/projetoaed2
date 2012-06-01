#ifndef LES_H
#define LES_H
#include <string>

using namespace std;

class Les
{

    public:
        Les();
        int n;
        string valor;
        Les *lesProx;
        virtual ~Les();
    protected:
    private:
};

#endif // LES_H
