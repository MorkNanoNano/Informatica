#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include "funzioni.h"

using namespace std;

particella *read_load(string const &filename){
    fstream infile;
    infile.open(filename,ios::in);
    if(!infile.good())
        throw runtime_error("ERROR, failed to open file...");
    
    int count = 0; string tmp;
    while(!infile.eof()){
        getline(infile,tmp);
        count++;
    }
    infile.clear(); infile.seekg(0);

    particella *read = new particella[count];
    for(int i = 0; i < count; i++){
        infile >> read[i].p[0]
        >> read[i].p[1]
        >> read[i].p[2]
        >> read[i].p[3]
        >> read[i].carica;
    }

    return read;
}

int length(string const &filename){
    fstream infile;
    infile.open(filename,ios::in);
    if(!infile.good())
        throw runtime_error("ERROR, failed to open file...");
    
    int count = 0; string tmp;
    while(!infile.eof()){
        getline(infile,tmp);
        count++;
    }
    return count;
}

void print_carica(particella *m, int ntot){
    int neg_count = 0;
    int pos_count = 0;
    int neut_count = 0;
    for(int i = 0; i < ntot; i++){
        if(m[i].carica < 0)
            neg_count ++;
        else if(m[i].carica > 0)
            pos_count ++;
        else if(m[i].carica == 0)
            neut_count ++;
    }
    cout << "Numero di particelle con carica positiva: \t" << pos_count << endl;
    cout << "Numero di particelle con carica neutra: \t" << neut_count << endl;
    cout << "Numero di particelle con carica positiva: \t" << neg_count << endl;
}

void eta(particella &m){
    m.eta = 0.5 * log((m.p[0] + m.p[3]) / (m.p[0] - m.p[3]));
}

void print_first(particella *m, int ntot){
    for(int i = 0; i < ntot; i++)
        cout << "Particella  " << i << " campo eta \t" << m[i].eta << endl;
}

void print_last(particella *m, int ntot, int n){
    for(int i = ntot-n; i < ntot; i++)
        cout << "Particella  " << i << " campo eta \t" << m[i].eta << endl;
} 

void sort(particella *m, int ntot){
    for(int i = 0; i < ntot-1; i++){ 
        for(int j = i+1; j < ntot; j++){
            if(m[i].eta > m[j].eta){
                particella tmp = m[i];
                m[i] = m[j];
                m[j] = tmp;
            }
        }
    }
}

double media(particella *m, int ntot){
    double sum = 0;
    for (int i = 0; i < ntot; i++){
        sum += m[i].eta;
    }
    return sum/ntot;
}

double stdev(particella *m, int ntot){
    double sum = 0;
    for (int i = 0; i < ntot; i++){
        sum += m[i].eta;
    }
    double media = sum/ntot;
    
    double scarti = 0;
    for(int i = 0; i < ntot; i++){
        scarti += pow((m[i].eta - media),2);
    }
    return sqrt(scarti/ntot);
}

void print_out(string const &filename, stringstream &ss){
    fstream outfile;
    outfile.open("risultati.dat",ios::out);
    if(!outfile.good())
        throw runtime_error("ERROR, failed to create file...");

    outfile << ss.str();
}

void print_tot(stringstream &ss, particella *m, int ntot){
    ss << "Media di eta: \t" << media(m,ntot) << endl;
    ss << "Stdev di eta: \t" << stdev(m,ntot) << endl;
    ss << "Minimo di eta: \t" << m[0].eta << endl;
    ss << "Massimo di eta: \t" << m[299].eta << endl;
    cout << ss.str();
}

