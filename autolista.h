#ifndef AUTOLISTA_H_INCLUDED
#define AUTOLISTA_H_INCLUDED
#include "auto.h"
#include "szemely.h"
#include <stdexcept>
class AutoLista{
    Auto* Lista;
    int meret;
    Szemely* Emberek;
    public:
    AutoLista(int _meret=0):meret(_meret){
        Lista=new Auto[meret];
        Emberek=new Szemely[meret];
    }
    int getmeret(){return meret;}
    Szemely& getEmberek(int idx){return Emberek[idx];}
    Auto& getLista(int idx){return Lista[idx];}
    ~AutoLista();
    AutoLista(const AutoLista& masolando);
    AutoLista& operator=(AutoLista& masolando);
    AutoLista& hozzaad(Auto& ujauto,Szemely& ujszemely);
//    void kiir()
//    {
//        std::cout<<"Meret:"<<meret<<std::endl;
//        for(int i=0;i<meret;i++)
//        {
//            std::cout<<Lista[i]<<std::endl;
//            std::cout<<Emberek[i];
//            std::cout<<std::endl<<std::endl;
//        }
//    }
    AutoLista& kivesz(int idx);
};
    std::ostream& operator<<(std::ostream& os,AutoLista& a);


#endif // AUTOLISTA_H_INCLUDED
