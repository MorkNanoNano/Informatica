struct particella {
double p[4]; // energia-momento (E, px, py, pz)
int carica; // carica elettrica
double eta; // pseudo-rapidita’
};

particella *read_load(std::string const &filename);
int length(std::string const &filename);
void print_carica(particella *m, int ntot);
void eta(particella &m);
void print_first(particella *m, int ntot);
void sort(particella *m, int ntot);
void print_last(particella *m, int ntot, int n);
double media(particella *m, int ntot);
double stdev(particella *m, int ntot);
void print_out(std::string const &filename, std::stringstream &ss);
void print_tot(std::stringstream &ss, particella *m, int ntot);
