/* Butoi Elena- Denisa, 211
CodeBlocks , GNU GCC Compiler
Eduard Gabriel Szmeteanca
*/
#include <iostream>
#include <vector>

using namespace std;

class Vaccin {
    public:
        float price;
        float temperatura;
        vector<string> substante;
        string producator;

        Vaccin() {
        }

        vector<string> getSubstante() {
            return this->substante;
        }

        void addSubstanta(string subst) {
            substante.push_back(subst);
        }

        virtual void afisareSchemaVaccinare() {

        }

        friend istream& operator>> (istream& is, Vaccin& vaccin) {
            is >> vaccin.price >> vaccin.temperatura >> vaccin.producator;
            return is;
        }

};

class VaccinAntigripal : public Vaccin {
    public:
        bool recomandariOMS;
        string tulpina;

        VaccinAntigripal() {
        }

        void afisareSchemaVaccinare() {
            cout << "\nSe administreaza o doza de 0.5ml la adulti. \nPentru copii si adolescenti o doza de 0.3ml. Se repeta din 2 in 2 ani\n";
        }

        friend istream& operator>> (istream& is, VaccinAntigripal& vaccin) {
            is >> vaccin.price >> vaccin.temperatura >> vaccin.producator >> vaccin.tulpina >> vaccin.recomandariOMS;
            return is;
        }

        friend ostream &operator<< (ostream &output, const VaccinAntigripal &vaccin) {
            output << "Vaccin Antigripal\nProducator: " << vaccin.producator
                << "\nPret: " << vaccin.price
                <<"\nTemperatura de depozitare: " << vaccin.temperatura
                <<"\nTulpina: " << vaccin.tulpina
                <<"\nRecomandari OMS respectate: " << vaccin.recomandariOMS << "\n\n";

            return output;
        }

};

class VaccinAntihepatic : public Vaccin {
    public:
        string tipHepatita;
        string modVaccinare;

        VaccinAntihepatic() {
        }

        string getTipHepatita() {
            return this->tipHepatita;
        }

        void afisareSchemaVaccinare() {
            cout << "\nPt hepatita A si B, la copiii < 1an 2 injectari la un interval de 1 luna, a treia injectare la 6 luni dupa prima.\La adulti conform medicului.\nPt hepatita C doar la recomandarea medicului\n";
        }

        friend istream& operator>> (istream& is, VaccinAntihepatic& vaccin) {
            is >> vaccin.price >> vaccin.temperatura >> vaccin.producator >> vaccin.tipHepatita >> vaccin.modVaccinare;

            return is;
        }

        friend ostream &operator<< (ostream &output, const VaccinAntihepatic &vaccin) {
            output << "Vaccin AntiHepatic. \nProducator: " << vaccin.producator
                << "\nPret: " << vaccin.price
                <<"\nTemperatura de depozitare: " << vaccin.temperatura
                <<"\nTip hepatita: " << vaccin.tipHepatita
                <<"\nMod vaccinare: " << vaccin.modVaccinare <<"\n\n";

            return output;
        }
};

class VaccinAntiSarsCov2 : public Vaccin {
    public:
        vector<string> reactiiAdverse;
        float rataEficienta;
        vector<string> medicamenteContra;

        VaccinAntiSarsCov2() {
        }

        void afisareSchemaVaccinare() {
            cout << "\nSe administreaza persoanelor > 16 ani, 2 doze la o perioada de 21 de zile\n";
        }

        friend istream& operator>> (istream& is, VaccinAntiSarsCov2& vaccin) {
            is >> vaccin.price >> vaccin.temperatura >> vaccin.producator >> vaccin.rataEficienta;
            return is;
        }

        friend ostream &operator<< (ostream &output, const VaccinAntiSarsCov2 &vaccin) {
            output << "Vaccin AntiSarsCov2. \nProducator: " << vaccin.producator
                << "\nPret: " << vaccin.price
                <<"\nTemperatura de depozitare: " << vaccin.temperatura
                <<"\nRata eficienta: " << vaccin.rataEficienta;

            return output;
        }
};

class Comanda {
    public:
        int id;
        string data;
        string numeClient;
        string vaccin;
        int cantitate;

        Comanda(string d, string n, string v, int c) {
            this->data = d;
            this->numeClient = n;
            this->vaccin = v;
            this->cantitate = c;
        }

};

class ListaComenzi {
    public:
        Comanda comanda;


};

int main()
{
    VaccinAntigripal a;
    VaccinAntihepatic b;
    VaccinAntiSarsCov2 c;

    cin >> b;
    cin >> c;
    cin >> a;

    cout << a << b << c;

    Vaccin* list[3];
    list[0]= new VaccinAntigripal();
    list[1]= new VaccinAntihepatic ();
    list[2]= new VaccinAntiSarsCov2();

    for(int i=0; i<3; i++)
        list[i]->afisareSchemaVaccinare();

    Comanda com1("20-12-2020", "SpitalX", "AntiSarsCov2",20);

    return 0;
}
