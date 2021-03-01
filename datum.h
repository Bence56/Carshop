#ifndef DATUM_H_INCLUDED
#define DATUM_H_INCLUDED
#include <iostream>
class Datum{
    int Ev;
    int Honap;
    int Nap;
public:
    int GetEv()const{return Ev;}
    int GetHonap()const{return Honap;}
    int GetNap()const{return Nap;}
    Datum(int _ev=0,int _honap=0,int _nap=0):Ev(_ev),Honap(_honap),Nap(_nap){}
    ~Datum(){}
    bool operator==(const Datum& d)const;
};
    std::ostream& operator<<(std::ostream& os,const Datum& d);

#endif // DATUM_H_INCLUDED
