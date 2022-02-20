#include <iostream>
#include <fstream>
#include <sstream>
#include "funzioni.h"

using namespace std;

int main(){

    particella *data = read_load("particelle.dat");
    int dim = length("particelle.dat");
   
    cout << "Numero di particelle lette: \t" << dim << endl;
    print_carica(data,dim);
    for(int i = 0; i < dim; i++)
        eta(data[i]);

    stringstream ss;
    print_first(data,10); sort(data,dim);  print_first(data,4);  print_last(data,dim,4);
    print_tot(ss,data,dim); print_out("risultati.dat",ss);

    return 0;
}
