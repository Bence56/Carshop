#include "szemely.h"
    Szemely& Szemely::operator=(Szemely& sz)
    {
        if(this!=&sz)
        {
            Nev=sz.getNev();
            SzulIdo=sz.getSzulIdo();
            Email=sz.getEmail();
        }
        return *this;
    }
    Szemely Szemely::operator=(const Szemely& sz)
    {
        if(this!=&sz)
        {
            Nev=sz.getNev();
            SzulIdo=sz.getSzulIdo();
            Email=sz.getEmail();
        }
        return *this;
    }
    std::ostream& operator<<(std::ostream& os,Szemely& sz)
    {
        os<<sz.getNev()<<"   "<<sz.getSzulIdo()<<"    "<<sz.getEmail();
        return os;
    }
