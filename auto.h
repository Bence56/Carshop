#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include<string>
using std::string;

class Auto{
    string Gyarto;
    string Tipus;
    double Fogyasztas;
    string Meghajtas;
    int Evjarat;
    int Ferohely;
    string Szin;
    long Ar;
public:
    //string getGyarto()const{return Gyarto;}
    //string getTipus()const{return Tipus;}
    //string getMeghajtas()const{return Meghajtas;}
//    //string getSzin()const{return Szin;}
//    double getFogyasztas()const{return Fogyasztas;}
//    int getFerohely()const{return Ferohely;}
//    int getEvjarat()const{return Evjarat;}
//    long getAr()const{return Ar;}
    long getAr(){return Ar;}
    string getGyarto(){return Gyarto;}
    string getTipus(){return Tipus;}
    string getMeghajtas(){return Meghajtas;}
    string getSzin(){return Szin;}
    double getFogyasztas(){return Fogyasztas;}
    int getFerohely(){return Ferohely;}
    int getEvjarat(){return Evjarat;}
    Auto(string _Gyarto="",string _Tipus="",double _Fogyasztas=0.0,string _Meghajtas="",int _Evjarat=0,int _Ferohely=0,string _Szin="",long _Ar=0):Gyarto(_Gyarto),Tipus(_Tipus),Fogyasztas(_Fogyasztas),Meghajtas(_Meghajtas),Evjarat(_Evjarat),Ferohely(_Ferohely),Szin(_Szin),Ar(_Ar){}
    Auto(const Auto& masolando):Gyarto(masolando.Gyarto),Tipus(masolando.Tipus),Fogyasztas(masolando.Fogyasztas),Meghajtas(masolando.Meghajtas),Evjarat(masolando.Evjarat),Ferohely(masolando.Ferohely),Szin(masolando.Szin),Ar(masolando.Ar){}
    Auto operator=(const Auto& masolando);
    Auto& operator=( Auto& masolando);
    ~Auto(){}
};

    std::ostream& operator<<(std::ostream& os,Auto& a);



#endif // AUTO_H_INCLUDED
