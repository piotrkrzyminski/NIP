#include <iostream>
#include <fstream>

#include "podatnik.h"
#include "queue.h"

#define N 3

using namespace std;

int main() {
    const string input_file_name="nipy.txt"; ///Name of file with NIP numbers
    const string department_numbers[N]={"771","772","773"}; ///Department numbers: [0]-Piotrkow Trybunalski, [1]-Radomsko, [2]-Tomaczow Mazowiecki
    const string output_file_names[N]={"piotrkow.txt","radomsko.txt","tomaszow.txt"};

    Queue q[3]; ///[0]-Piotrkow Trybunalski, [1]-Radomsko, [2]-Tomaczow Mazowiecki

    ifstream input_file;

    input_file.open(input_file_name.c_str());

    /**
    * Check if file is opened properly. If not end program
    */
    if(input_file.bad()) {
        cout<<"Plik o nazwie "<<input_file_name<<" nie zostal otwarty. Sprawdz czy plik o podanej nazwie istnieje."<<endl;
        return 0;
    } else {
        cout<<"Plik o nazwie "<<input_file_name<<" zostal otwarty."<<endl;
    }

    /**
    * Get NIP number and taxpayer name from file and save them to string variables
    */

    while(!input_file.eof()) {
        string NIP, taxpayer_name;

        getline(input_file, NIP, ' ');
        getline(input_file, taxpayer_name);

        Podatnik p(NIP, taxpayer_name);

        for(int i=0; i<N; i++) {
            if(department_numbers[i].compare(p.getDepartmentNumber())==0) {
                q[i].insert(p);
                break;
            }
        }
    }

    input_file.close(); /// close nipy.txt

    /**
    * in loop open file and save taxpayers names in proper file
    */
    ofstream output_files[N];

    for(int i=0; i<N; i++) {
        output_files[i].open(output_file_names[i].c_str());

        while(!q[i].isEmpty()) {
            output_files[i]<<q[i].pop().getNazwaPodatnika()<<endl;
        }

        output_files[i].close();
        cout<<"Dane zostaly zapisane w pliku "<<output_file_names[i]<<endl;
    }


    return 0;
}
