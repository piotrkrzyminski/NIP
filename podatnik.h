#ifndef PODATNIK_H_INCLUDED
#define PODATNIK_H_INCLUDED

#include <string>

struct Podatnik {
    private:
        std::string NIP;
        std::string nazwa_podatnika;
        std::string department_number;

        void split(std::string data);
    public:
        Podatnik();
        Podatnik(std::string _NIP, std::string _nazwa_podatnika);
        std::string getNazwaPodatnika() const;
        std::string getDepartmentNumber() const;
        std::string getNIP() const;
        Podatnik& operator=(Podatnik& p);
};

#endif // PODATNIK_H_INCLUDED
