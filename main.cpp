#include "fuggvenyek.hpp"
#include <stdlib.h>
#include "autolista.h"
#include "datum.h"
using namespace std;
int main()
{
    AutoLista Eladva;
    AutoLista Kinalat;
    try{
    Filebololvas("Eladva.txt",Eladva);
    Filebololvas("Kinalat.txt",Kinalat);
    int beker=-1;
    Fomenuvalasztkiir();
    while(beker!=0&&std::cin>>beker)
    {


        switch(beker)
        {
        case 0:
            clearscreen();
            std::cout<<"Koszonjuk hogy hasznalta a programot!"<<std::endl;
            break;
        case 1:
            clearscreen();
            std::cout<<"\tEladott autok kilistazasa:"<<std::endl;
            std::cerr<<Eladva<<std::endl;
        ///PAUSE
            break;
        case 2:
            clearscreen();
            std::cout<<"\tKinalat kilistazasa:"<<std::endl;
            std::cout<<Kinalat<<std::endl;
        ///PAUSE
            break;
        case 3:
            clearscreen();
            Kinalat=AdatBeker(Kinalat);
            break;
        case 4:
            clearscreen();
            Jarmueladasa(Eladva,Kinalat);
            break;
        case 5:
            clearscreen();
            kereses(Kinalat);
            break;
        case 6:
            clearscreen();
            std::cout<<"Az eddigi bevetel: "<<bevetelszamolo(Eladva)<<std::endl;
            break;
        default:
            clearscreen();
            std::cout<<"Rossz gomb"<<std::endl;
            break;
        }
        Fomenuvalasztkiir();

    }
        Filebair(Eladva,"Eladva.txt");
        Filebair(Kinalat,"Kinalat.txt");
    }catch(...)
    {
        if("Rossz az index az eladasnal")
            std::cerr<<"Rossz az index az eladasnal"<<std::endl;
    }
    //Tesztelofuggvney();
    Filebair(Eladva,"Eladva.txt");
    Filebair(Kinalat,"Kinalat.txt");
    return 0;
}
