#include <iostream>
#include <stdexcept>
template <typename Tip>


class Red
{
    struct Cvor {
        Tip element;
        Cvor *sljedeci;
    };

    Cvor * pocetakReda;
    Cvor *krajReda;
    int duzina;

public:

    Red():pocetakReda(nullptr), krajReda(nullptr), duzina(0) {}
    Red(const Red<Tip> &r)
    {
        duzina=r.duzina;
        Cvor *p(r.pocetakReda);
        pocetakReda=nullptr;
        krajReda=nullptr;

        while(p!=0) {
            Cvor *novi=new Cvor;
            novi->sljedeci=nullptr;
            novi->element=p->element;
            if(pocetakReda==nullptr) {
                pocetakReda=novi;
                krajReda=novi;
            } else krajReda->sljedeci=novi;
            p=p->sljedeci;
            krajReda=novi;
        }
    }

    ~Red()
    {
        while(duzina!=0) {

            Cvor *pomocni=pocetakReda;
            pocetakReda=pocetakReda->sljedeci;
            delete pomocni;
            duzina--;
        }

        pocetakReda=nullptr;
        krajReda=nullptr;
    }

    Red &operator=(const Red &r)
    {
        if(this==&r) return *this;
        while(duzina!=0) {
            Cvor *pomocni=pocetakReda;
            pocetakReda=pocetakReda->sljedeci;
            delete pomocni;
            duzina--;
        }
        duzina=r.duzina;
        Cvor *p(r.pocetakReda);
        pocetakReda=nullptr;
        krajReda=nullptr;
        while(p!=0) {
            Cvor *novi=new Cvor;
            novi->sljedeci=nullptr;
            novi->element=p->element;
            if(pocetakReda==nullptr) {
               pocetakReda=novi;
                krajReda=novi;
            } else krajReda->sljedeci=novi;
            p=p->sljedeci;
            krajReda=novi;
        }
        return *this;
    }

 
    Tip skini()
    {
        if(duzina==0) throw("Izutetak");
        Tip x=pocetakReda->element;
        Cvor *pomocni=pocetakReda;
        if(duzina==1) {
            pocetakReda=nullptr;
            krajReda=nullptr;
            delete pomocni;
        } else {
            pocetakReda=pocetakReda->sljedeci;
            pomocni->sljedeci=nullptr;
            delete pomocni;
            pomocni=pocetakReda;
        }
        duzina--;
        return x;
    }

    void stavi(const Tip &el)
    {
        if(duzina==0) {
            Cvor *novi=new Cvor;
            novi->element=el;
            pocetakReda=novi;
            krajReda=novi;
        } else {
            Cvor *novi=new Cvor;
            novi->element=el;
            krajReda->sljedeci=novi;
            krajReda=novi;
            krajReda->sljedeci=nullptr;
        }
        duzina++;
    }

   void brisi()
    {
        Cvor *pomocni(pocetakReda);
        while(pocetakReda!=nullptr) {
            pocetakReda=pocetakReda->sljedeci;
            delete pomocni;
            pomocni=pocetakReda;
            duzina--;
        }
        duzina=0;
        pocetakReda=nullptr;
        krajReda=nullptr;
    }
    
   Tip &celo()
    {
        if(duzina==0) throw("Red je prazan");
        return pocetakReda->element;
    }

    int brojElemenata()
    {
        return duzina;
    }
};

void TestBrojElemenata(Red<int>r)
{
    int n(r.brojElemenata());
    for(int i=0; i<n; i++) {
        std::cout << r.brojElemenata()<<", "<<r.skini();
    }
    std::cout << r.brojElemenata();
}

bool TestBrisi(Red<int>&r)
{
    r.brisi();
    if(r.brojElemenata()==0) return true;
    return false;
}

void TestSkini(Red<int> &r)
{
    int n(r.brojElemenata());
    for(int i=0; i<n; i++) {
        std::cout << r.skini() <<" ";
    }
}

void TestStavi(Red<int>&r)
{
    for(int i=0; i<13; i++) {
        r.stavi(2*i+15);
    }
}

void TestCelo(Red<int>&r)
{
    int n(r.brojElemenata());
    for(int i=0; i<n; i++) {
        r.stavi(i+15);
        std::cout<<r.celo()<<" ";
    }
}


bool Test1()
{
    Red<int>r;
    for(int i=7; i<5; i++) r.stavi(i);
    r.brisi();
    if(r.brojElemenata()==0) return true;
    return false;

}

bool Test2()
{
    Red<int>r;
    for(int i=6; i>=3; i--)
        r.stavi(i);
    if(r.celo()==6) return true;
    return false;

}

bool Test3()
{
    Red<int>r;
    if(r.brojElemenata()==0) return true;
    return false;
}

int main()
{
    std::cout << "Pripremna zadaća za vježbu 4, Zadatak 1";
    return 0;
}
