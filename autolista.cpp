#include "autolista.h"
#include "auto.h"
#include <iostream>

    AutoLista::~AutoLista()
    {
        delete[] Emberek;
        delete[] Lista;
    }
    AutoLista::AutoLista(const AutoLista& masolando)
    {
        meret=masolando.meret;
        Lista=new Auto[meret];
        Emberek=new Szemely[meret];
        for(int i=0;i<meret;i++)
        {
            Lista[i]=masolando.Lista[i];
            Emberek[i]=masolando.Emberek[i];
        }
    }


    AutoLista& AutoLista::operator=(AutoLista& masolando)
    {
        if(this!=&masolando)
        {
            meret=masolando.meret;
            delete[] Lista;
            delete[] Emberek;
            Lista=new Auto[meret];
            Emberek=new Szemely[meret];
            for(int i=0;i<meret;i++){
                Lista[i]=masolando.Lista[i];
                Emberek[i]=masolando.Emberek[i];
            }
        }
        return *this;
    }


    AutoLista& AutoLista::hozzaad(Auto& ujauto,Szemely& ujszemely)
    {
        AutoLista tmp=AutoLista(meret);
        //tmp.Lista=new Auto[meret];
        //tmp.Emberek=new Szemely[meret];

        //tmp.meret=meret;
        for(int i=0;i<meret;i++){
            tmp.Lista[i]=Lista[i];
            tmp.Emberek[i]=Emberek[i];
        }

        delete[] Lista;
        delete[] Emberek;

        Lista=new Auto[meret+1];
        Emberek=new Szemely[meret+1];

        for(int i=0;i<meret;i++){
            Lista[i]=tmp.Lista[i];
            Emberek[i]=tmp.Emberek[i];
        }

        Lista[meret]=ujauto;
        Emberek[meret]=ujszemely;
        meret+=1;

        //delete[] tmp.Lista;
        //delete[] tmp.Emberek;
        ///tmp.~AutoLista();  --> Remelhetoleg ez lefut es nem lesz a program memory leak-es;
//        std::cout<<"Foglaltam helyet"<<std::endl;
        return *this;
    }

    AutoLista& AutoLista::kivesz(int idx)
    {
        if(idx>=meret||idx<0)
            throw "Tessék egy konst kar csillag kivétel";
        AutoLista tmp=AutoLista(meret);
        for(int i=0;i<meret;i++){
            tmp.Lista[i]=Lista[i];
            tmp.Emberek[i]=Emberek[i];
        }
        delete[] Lista;
        delete[] Emberek;

        Lista=new Auto[meret-1];
        Emberek=new Szemely[meret-1];
        int counter=0;
        int szamozo=0;
        while(counter<meret)
        {
            if(counter==idx)
            {

            }
            else
            {
                Lista[szamozo]=tmp.Lista[counter];
                Emberek[szamozo]=tmp.Emberek[counter];
                szamozo++;
            }
            counter++;
        }
        meret-=1;
        ///Remelhetoleg itt is lefut a tmp dtor es nem lesz memory leak
        return *this;
    }
    std::ostream& operator<<(std::ostream& os,AutoLista& a)
    {
        if(a.getmeret()==0)
            os<<"A lista ures."<<std::endl;
        else{
            for(int i=0;i<a.getmeret();i++)
            {
                Auto tmpauto=a.getLista(i);
                Szemely tmpember=a.getEmberek(i);
                os<<tmpauto<<std::endl;
                os<<tmpember;
                os<<std::endl<<std::endl;
            }
        }
        return os;
    }

