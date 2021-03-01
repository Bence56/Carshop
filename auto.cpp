#include "auto.h"
#define MEMTRACEs
#include <iostream>
Auto Auto::operator=(const Auto& masolando)
{
    Auto tmp=Auto(masolando);
    *this=tmp;
    return *this;
}
Auto& Auto::operator=(Auto& masolando)
{
    Gyarto=masolando.Gyarto;
    Tipus=masolando.Tipus;
    Fogyasztas=masolando.Fogyasztas;
    Meghajtas=masolando.Meghajtas;
    Evjarat=masolando.Evjarat;
    Ferohely=masolando.Ferohely;
    Szin=masolando.Szin;
    Ar=masolando.Ar;
    return *this;
}
 std::ostream& operator<<(std::ostream& os,Auto& a){
    os<<a.getGyarto()<<"  "<<a.getTipus()<<"  "<<a.getFogyasztas()<<"  "<<a.getMeghajtas()<<"  "<<a.getEvjarat()<<"  "<<a.getFerohely()<<"  "<<a.getSzin()<<"  "<<a.getAr();
    return os;
}
