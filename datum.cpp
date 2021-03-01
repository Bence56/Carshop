#include "datum.h"
bool Datum::operator==(const Datum& d)const{
    if(Ev==d.GetEv()&&Honap==d.GetHonap()&&Nap==d.GetNap())
        return true;
    return false;
}
std::ostream& operator<<(std::ostream& os,const Datum& d){
    os<<d.GetEv()<<"."<<d.GetHonap()<<"."<<d.GetNap()<<".";
    return os;
}
