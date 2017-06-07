#include "podatnik.h"

/**
* Non-parameter constructor
*/
Podatnik::Podatnik() {
    NIP="";
    nazwa_podatnika="";
}

/**
* Constructor with one parameter. Sets variables value
*/
Podatnik::Podatnik(std::string _NIP, std::string _nazwa_podatnika) {
    NIP=_NIP;
    nazwa_podatnika=_nazwa_podatnika;
    department_number=NIP.substr(0,3);
}

/**
* Returns taxpayer name
*/
std::string Podatnik::getNazwaPodatnika() const {
    return nazwa_podatnika;
}

/**
* Returns department number - 3 first digits from NIP number
*/
std::string Podatnik::getDepartmentNumber() const {
    return department_number;
}

/**
* return NIP number
*/
std::string Podatnik::getNIP() const {
    return NIP;
}

/**
* equal operator
*/

Podatnik& Podatnik::operator=(Podatnik& p) {
    NIP=p.getNIP();
    nazwa_podatnika=p.getNazwaPodatnika();
    department_number=p.getDepartmentNumber();
    return *this;
}
