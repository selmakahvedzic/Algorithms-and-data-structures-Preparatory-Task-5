#include <iostream>
using namespace std;

int fib_petlja(int n) {
    int pretprosli(0), prosli(1), rezultat;
    
    for(int i=2; i<=n; i++) {
        rezultat=pretprosli+prosli;
       pretprosli=prosli;
        prosli=rezultat;
    }
    return rezultat;
}

int fib2_0(int n, int pretprosli=0, int prosli=1, int rez=0) {
    if(n==0) return 0; 
    else if(n==1) return prosli;
    rez=prosli+pretprosli;
    return fib2_0(n-1,prosli,rez);
}

int nzd(int x, int y) {
    if(y==0) return x; 
    return nzd(y, x%y);
}

void Test1() {
    std::cout << fib2_0(20);
}

void Test2() {
    std::cout <<nzd(6,561);
}

int main() {
    std::cout << "Pripremna Zadaca Za Vjezbu 5, Zadatak 1";
    return 0;
}
