#ifndef SZEMELY_H_INCLUDED
#define SZEMELY_H_INCLUDED
#include<string>
using std::string;
#include "datum.h"
class Szemely{
    string Nev;
    Datum SzulIdo;
    string Email;
public:
    Szemely(string _nev="",Datum _SzulIdo=Datum(),string _email=""):Nev(_nev),SzulIdo(_SzulIdo),Email(_email){}
    Szemely(const Szemely& sz):Nev(sz.Nev),SzulIdo(sz.SzulIdo),Email(sz.Email){}
    string getNev(){return Nev;}
    string getEmail(){return Email;}
    Datum getSzulIdo(){return SzulIdo;}
    string getNev()const{return Nev;}
    string getEmail()const{return Email;}
    Datum getSzulIdo()const{return SzulIdo;}
    Szemely& operator=(Szemely& sz);
    Szemely operator=(const Szemely& sz);
    ~Szemely(){}
};
    std::ostream& operator<<(std::ostream& os,Szemely& sz);


#endif // SZEMELY_H_INCLUDED
