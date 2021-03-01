#include "autolista.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
void clearscreen(){
    for(int i=0;i<40;i++)
        std::cout<<std::endl;
}
void Fomenuvalasztkiir()
{
    std::cout<<"FOMENU"<<std::endl;
    std::cout<<"\t0--->Kilepes"<<std::endl;
    std::cout<<"\t1--->Eladott jarmuvek kilistazasa"<<std::endl;
    std::cout<<"\t2--->Kinalat kilistazasa"<<std::endl;
    std::cout<<"\t3--->Uj auto a kinalatba(bekeres)"<<std::endl;
    std::cout<<"\t4--->Auto eladasa"<<std::endl;
    std::cout<<"\t5--->Kereses a kinalatban"<<std::endl;
    std::cout<<"\t6--->Bevetel szamolo"<<std::endl;

}
void Filebair(AutoLista& a,const char* filename)
{
    std::ofstream iras;
    iras.open(filename);
    for(int i=0;i<a.getmeret();i++)
    {   Auto tmpcar=a.getLista(i);
        Szemely tmpperson=a.getEmberek(i);
        //iras<<i<<";";
        iras<<tmpcar.getGyarto()<<";";
        iras<<tmpcar.getTipus()<<";";
        iras<<tmpcar.getFogyasztas()<<";";
        iras<<tmpcar.getMeghajtas()<<";";
        iras<<tmpcar.getEvjarat()<<";";
        iras<<tmpcar.getFerohely()<<";";
        iras<<tmpcar.getSzin()<<";";
        iras<<tmpcar.getAr()<<";";
        iras<<tmpperson.getNev()<<";";
        iras<<tmpperson.getSzulIdo()<<";";
        iras<<tmpperson.getEmail()<<";\n";
    }
    iras.close();
}
string elejerolvag(string szoveg, unsigned n)
{
    string vissza="";
    int cnt=0;
    for(unsigned int i=0;i<szoveg.length();i++){
        if(i<=n){

        }
        else{
            vissza+=szoveg[i];
            cnt++;
        }
    }
    return vissza;
}
Datum strtodate(string& str)
{
    int found=str.find(".");
    std::stringstream ssev;
    std::stringstream sshonap;
    std::stringstream ssnap;
    string ev=str.substr(0,found);
    ssev<<ev;
    //std::cout<<"Ev:  "<<ev<<std::endl;
    int _ev;
    ssev>>_ev;
    str=str.erase(0,found+1);
    found=str.find(".");
    string honap=str.substr(0,found);
    //std::cout<<"Honap:  "<<honap<<std::endl;
    sshonap<<honap;
    int _honap;
    sshonap>>_honap;
    str=str.erase(0,found+1);
    found=str.find(".");
    string nap=str.substr(0,found);
    //std::cout<<"Nap:  "<<nap<<std::endl;
    ssnap<<nap;
    int _nap;
    ssnap>>_nap;
    return Datum(_ev,_honap,_nap);
}
void Filebololvas(const char* filename,AutoLista& ret)
{
    std::ifstream olvas;
    olvas.open(filename);
    string sor;
    while(getline(olvas,sor))
    {
        string tomb[11];
        int cnt=0;
        int found=0;
        std::cout<<sor<<std::endl;
        while(sor!="\0")
        {
            found=sor.find(";");
            for(int j=0;j<found;j++){
                tomb[cnt]+=sor[j];
            }
            sor=elejerolvag(sor,found);
            cnt++;
        }
        std::stringstream ssfogyasztas;
        std::stringstream ssferohely;
        std::stringstream ssevjarat;
        std::stringstream ssar;
        int _ferohely,_evjarat;
        long _ar;
        double _fogyasztas;
        ssfogyasztas<<tomb[2];
        ssfogyasztas>>_fogyasztas;
        ssevjarat<<tomb[4];
        ssevjarat>>_evjarat;
        ssferohely<<tomb[5];
        ssferohely>>_ferohely;
        ssar<<tomb[7];
        ssar>>_ar;
        Datum date=strtodate(tomb[9]);
        Auto autore=Auto(tomb[0],tomb[1],_fogyasztas,tomb[3],_evjarat,_ferohely,tomb[6],_ar);
        Szemely szemelyre=Szemely(tomb[8],date,tomb[10]);
        ret.hozzaad(autore,szemelyre);
    }
    olvas.close();
    std::cout<<std::endl;
}
void Tesztelofuggvney()
{
    AutoLista Kinalat;
    AutoLista Eladva;
    std::cout<<"Kinalat: "<<std::endl<<Kinalat<<std::endl;
    std::cout<<"Teszek bele 2 elemet"<<std::endl;
    Auto Model3=Auto("Tesla","Model 3 P100D",10,"Elektromos",2019,5,"Feher",18000000);
    Szemely ElonMusk=Szemely("Elon Musk",Datum(1971,6,28),"CEO@teslamotors.com");
    Auto Nikol=Auto("Volkwagen","Passat B05",7,"Benzin",1996,5,"Vilagoskek",400000);
    Szemely Beno=Szemely("Somogyi Bence",Datum(1999,11,6),"bence.somogyi56@gmail.com");
    Auto Janaprius=Auto("Toyota","Prius",8,"Hibrid",2015,5,"Feher",2000000);
    Szemely Jana=Szemely("Wisztercill Janos",Datum(1999,9,20),"jana0920@gmail.com");
    Kinalat.hozzaad(Janaprius,Jana);
    Kinalat.hozzaad(Nikol,Beno);
    Eladva.hozzaad(Model3,ElonMusk);
    std::cout<<"Kinalat: "<<std::endl<<Kinalat<<std::endl;
    std::cout<<"Eladva: "<<std::endl<<Eladva<<std::endl;
    std::cout<<"Kiveszem a nullas elemet"<<std::endl;
    Eladva.kivesz(0);
    std::cout<<"Eladva: "<<std::endl<<Eladva<<std::endl;

    //Filebair(Eladva,"Eladva.txt");
}
AutoLista& AdatBeker(AutoLista& a)
{
    string _gyarto;
    std::cout<<"Adja meg az auto markajat:";
    std::getline(std::cin,_gyarto);
    std::getline(std::cin,_gyarto);
    string _tipus;
    std::cout<<"Adja meg az auto tipusat:";
    std::getline(std::cin,_tipus);
    double _fogyasztas;
    std::cout<<"Az auto fogyasztasa:";
    std::cin>>_fogyasztas;
    int beker;
    string _meghajtas;
    std::cout<<"Adja meg az auto meghajtasat(1--Benzin  2--Dizel  3--Elektromos  4--Hibrid):";
    std::cin>>beker;
    switch(beker){
        case 1:_meghajtas="Benzin";
        break;
        case 2:_meghajtas="Dizel";
        break;
        case 3:_meghajtas="Elektromos";
        break;
        case 4:_meghajtas="Hibrid";
        break;
        default:_meghajtas="Egyeb";
        break;
    }
    int _evjarat;
    std::cout<<"Az auto evjarata:";
    std::cin>>_evjarat;
    int _ferohely;
    std::cout<<"Az hanyferohelyes:";
    std::cin>>_ferohely;
    string _szin;
    std::cout<<"Adja meg az auto szinet:";
    std::getline(std::cin,_szin);
    std::getline(std::cin,_szin);
    long _ar;
    std::cout<<"Adja meg az auto arat(araink forintban ertendoek):";
    std::cin>>_ar;
    string _nev;
    std::cout<<"Na es kollega Ont hogy hivjak:";
    std::getline(std::cin,_nev);
    std::getline(std::cin,_nev);
    int _ev,_honap,_nap;
    std::cout<<"Szuletesi ev:";
    std::cin>>_ev;
    std::cout<<"Szuletesi honap:";
    std::cin>>_honap;
    std::cout<<"Szuletesi nap:";
    std::cin>>_nap;
    string _email;
    std::cout<<"Mi az email cime:";
    std::getline(std::cin,_email);
    std::getline(std::cin,_email);
    Auto recar=Auto(_gyarto,_tipus,_fogyasztas,_meghajtas,_evjarat,_ferohely,_szin,_ar);
    Szemely reperson=Szemely(_nev,Datum(_ev,_honap,_nap),_email);
    a.hozzaad(recar,reperson);
    return a;
}
void Jarmueladasa(AutoLista& Eladva,AutoLista& Kinalat){
    int siz=0;
    for(int i=0;i<Kinalat.getmeret();i++)
    {
        siz++;
    }
    siz--;
    std::cout<<"siz:"<<siz<<std::endl;
    std::cout<<"Most ki fogom listazni az eladasra varo autokat.\n Az elso rekordban talalhato indexet kerem!\n Ezt fogja eladni.\n\n";
    for(int i=0;i<Kinalat.getmeret();i++)
    {
        std::cout<<i<<"       "<<Kinalat.getLista(i);
        std::cout<<std::endl;
    }
    int idx;
    std::cout<<std::endl<<"Melyik sorszamu autot szeretne eladni: ";
    std::cin>>idx;
    if(idx<0){
        std::cout<<"Rossz az index"<<std::endl;
        throw "Rossz az index az eladasnal";
    }
    else if(idx>siz)
    {
        std::cout<<"Rossz az index"<<std::endl;
        throw "Rossz az index az eladasnal";
    }
    else if(idx>=0&&idx<=siz){
    Auto cartosell=Kinalat.getLista(idx);
    Szemely personwhoowns=Kinalat.getEmberek(idx);
    Kinalat=Kinalat.kivesz(idx);
    Eladva=Eladva.hozzaad(cartosell,personwhoowns);
    }
}
void kereses(AutoLista& Kinalat)
{
    int beker;
    std::cout<<"Kerem szepen a szamot mi alapjan szeretne keresni:"<<std::endl<<std::endl;
    std::cout<<"Gyarto--------0"<<std::endl;///string
    std::cout<<"Tipus---------1"<<std::endl;///string
    std::cout<<"Fogyasztas----2"<<std::endl;///double
    std::cout<<"Meghajtas-----3"<<std::endl;///string
    std::cout<<"Evjarat-------4"<<std::endl;///int
    std::cout<<"Ferohely------5"<<std::endl;///int
    std::cout<<"Szin----------6"<<std::endl;///string
    std::cout<<"Ar------------7"<<std::endl;///long
    std::cin>>beker;
    string substring;
    double fogy;
    int integer;
    long hosszu;
    switch(beker)
    {
        case 0:
            std::cout<<"Adja meg a szovegreszletet ami alapjan keresne a Gyartora:"<<std::endl;
            std::cin>>substring;
            for(int i=0;i<Kinalat.getmeret();i++)
            {
                Auto tmpauto=Kinalat.getLista(i);
                if(int(tmpauto.getGyarto().find(substring))!=-1)
                    std::cout<<tmpauto<<std::endl;
            }
        break;
    case 1:
            std::cout<<"Adja meg a szovegreszletet ami alapjan keresne a Tipusra:"<<std::endl;
            std::cin>>substring;
            for(int i=0;i<Kinalat.getmeret();i++)
            {
                Auto tmpauto=Kinalat.getLista(i);
                if(int(tmpauto.getTipus().find(substring))!=-1)
                    std::cout<<tmpauto<<std::endl;
            }
        break;
    case 2:
            std::cout<<"Mennyi a maximális fogyasztás:"<<std::endl;
            std::cin>>fogy;
            for(int i=0;i<Kinalat.getmeret();i++)
            {
                Auto tmpauto=Kinalat.getLista(i);
                if(double(tmpauto.getFogyasztas())<=fogy)
                    std::cout<<tmpauto<<std::endl;
            }
        break;
    case 3:
            std::cout<<"Adja meg a szovegreszletet ami alapjan keresne a Meghajtasra(Benzin||Dizel||Hibryd||Elektromos):"<<std::endl;
            std::cin>>substring;
            for(int i=0;i<Kinalat.getmeret();i++)
            {
                Auto tmpauto=Kinalat.getLista(i);
                if(int(tmpauto.getMeghajtas().find(substring))!=-1)
                    std::cout<<tmpauto;
            }
        break;
    case 4:
            std::cout<<"Mennyi a minimalis evjarat:"<<std::endl;
            std::cin>>integer;
            for(int i=0;i<Kinalat.getmeret();i++)
            {
                Auto tmpauto=Kinalat.getLista(i);
                if(int(tmpauto.getEvjarat())>=integer)
                    std::cout<<tmpauto<<std::endl;
            }
        break;
    case 5:
        std::cout<<"Mennyi a pontos ferohely:"<<std::endl;
            std::cin>>integer;
            for(int i=0;i<Kinalat.getmeret();i++)
            {
                Auto tmpauto=Kinalat.getLista(i);
                if(int(tmpauto.getFerohely())==integer)
                    std::cout<<tmpauto<<std::endl;
            }
        break;
    case 6:
            std::cout<<"Adja meg a szovegreszletet ami alapjan keresne a Szinre:"<<std::endl;
            std::cin>>substring;
            for(int i=0;i<Kinalat.getmeret();i++)
            {
                Auto tmpauto=Kinalat.getLista(i);
                if(int(tmpauto.getSzin().find(substring))!=-1)
                    std::cout<<tmpauto<<std::endl;
            }
        break;
    case 7:
            std::cout<<"Mennyi a maximalis ar:(Araink Forintban ertendoek)"<<std::endl;
            std::cin>>hosszu;
            for(int i=0;i<Kinalat.getmeret();i++)
            {
                Auto tmpauto=Kinalat.getLista(i);
                if(long(tmpauto.getEvjarat())<=hosszu)
                    std::cout<<tmpauto<<std::endl;
            }
        break;
    }
}
long bevetelszamolo(AutoLista& Eladva)
{
    long ret=0;
    for(int i=0;i<Eladva.getmeret();i++)
    {
        Auto tmpauto=Eladva.getLista(i);
        ret+=tmpauto.getAr();
    }
    return ret;
}
