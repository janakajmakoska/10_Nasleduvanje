#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Vraboten {
public:
    Vraboten(char ime, char prezime, int godina_na_vrabotuvanje) {
        this->ime = ime;
        this->prezime = prezime;
        this->godina_na_vrabotuvanje = godina_na_vrabotuvanje;
    }

    void postavi(char ime, char prezime, int godina_na_vrabotuvanje) {
        this->ime = ime;
        this->prezime = prezime;
        this->godina_na_vrabotuvanje = godina_na_vrabotuvanje;
    }

    void prikazi_podatoci() {
        cout << "Ime: " << ime << endl;
        cout << "Prezime: " << prezime << endl;
        cout << "Godina na vrabotuvanje: " << godina_na_vrabotuvanje << endl;
    }

private:
    char ime;
    char prezime;
    int godina_na_vrabotuvanje;
};

// Profesor inherits from Vraboten
class Profesor : public Vraboten {
public:
    Profesor(char ime, char prezime, int godina_na_vrabotuvanje, char zvanje, char oblast, int br_predmeti)
        : Vraboten(ime, prezime, godina_na_vrabotuvanje) {
        this->zvanje = zvanje;
        this->oblast = oblast;
        this->br_predmeti = br_predmeti;
    }

    void postavi(char ime, char prezime, int godina_na_vrabotuvanje, char zvanje, char oblast, int br_predmeti) {
        Vraboten::postavi(ime, prezime, godina_na_vrabotuvanje);
        this->zvanje = zvanje;
        this->oblast = oblast;
        this->br_predmeti = br_predmeti;
    }

    void prikazi_podatoci() {
        Vraboten::prikazi_podatoci();
        cout << "Zvanje: " << zvanje << endl;
        cout << "Oblast: " << oblast << endl;
        cout << "Broj na predmeti: " << br_predmeti << endl;
    }

private:
    char zvanje;
    char oblast;
    int br_predmeti;
};

// Demonstrator inherits from Vraboten
class Demonstrator : public Vraboten {
public:
    Demonstrator(char ime, char prezime, int godina_na_vrabotuvanje, char rabotno_vreme[]) 
        : Vraboten(ime, prezime, godina_na_vrabotuvanje) {
        strcpy(this->rabotno_vreme, rabotno_vreme);
    }

    void postavi(char ime, char prezime, int godina_na_vrabotuvanje, char rabotno_vreme[]) {
        Vraboten::postavi(ime, prezime, godina_na_vrabotuvanje);
        strcpy(this->rabotno_vreme, rabotno_vreme);
    }

    void prikazi_podatoci() {
        Vraboten::prikazi_podatoci();
        cout << "Rabotno vreme: " << rabotno_vreme << endl;
    }

private:
    char rabotno_vreme[];
};

// Profesor inherits from Vraboten
class Asistent : public Vraboten {
public:
    Asistent(char ime, char prezime, int godina_na_vrabotuvanje, char zvanje, char mentor, int br_predmeti)
        : Vraboten(ime, prezime, godina_na_vrabotuvanje) {
        this->zvanje = zvanje;
        this->mentor = mentor;
        this->br_predmeti = br_predmeti;
    }

    void postavi(char ime, char prezime, int godina_na_vrabotuvanje, char zvanje, char mentor, int br_predmeti) {
        Vraboten::postavi(ime, prezime, godina_na_vrabotuvanje);
        this->zvanje = zvanje;
        this->mentor = mentor;
        this->br_predmeti = br_predmeti;
    }

    void prikazi_podatoci() {
        Vraboten::prikazi_podatoci();
        cout << "Zvanje: " << zvanje << endl;
        cout << "Mentor: " << mentor << endl;
        cout << "Broj na predmeti: " << br_predmeti << endl;
    }

private:
    char zvanje;
    char mentor;
    int br_predmeti;
};



int main() {
    vector<Vraboten*> vraboteni;

    int izbor;
    do {
        cout << "Izberete opcija:" << endl;
        cout << "1. Dodavanje na nov vraboten" << endl;
        cout << "2. Prikaz na listata na vraboteni" << endl;
        cout << "3. Kraj" << endl;
        cin >> izbor;

        switch (izbor) {
            case 1: {
                int tip;
                cout << "Izberete tip na vraboten (1-Profesor, 2-Asistent, 3-Demonstrator): ";
                cin >> tip;

                char ime, prezime;
                int godina_na_vrabotuvanje;
                cout << "Vnesete ime: ";
                cin >> ime;
                cout << "Vnesete prezime: ";
                cin >> prezime;
                cout << "Vnesete godina na vrabotuvanje: ";
                cin >> godina_na_vrabotuvanje;

                if (tip == 1) {
                    char zvanje, oblast;
                    int br_predmeti;
                    cout << "Vnesete zvanje: ";
                    cin >> zvanje;
                    cout << "Vnesete oblast: ";
                    cin >> oblast;
                    cout << "Vnesete broj na predmeti: ";
                    cin >> br_predmeti;

                    vraboteni.push_back(new Profesor(ime, prezime, godina_na_vrabotuvanje, zvanje, oblast, br_predmeti));
                } else if (tip == 2) {
                    char zvanje, mentor;
                    int br_predmeti;
                    cout << "Vnesete zvanje: ";
                    cin >> zvanje;
                    cout << "Vnesete mentor: ";
                    cin >> mentor;
                    cout << "Vnesete broj na predmeti: ";
                    cin >> br_predmeti;

                    vraboteni.push_back(new Asistent(ime, prezime, godina_na_vrabotuvanje, zvanje, mentor, br_predmeti));
                } else if (tip == 3) {
                    char rabotno_vreme[100];
                    cout << "Vnesete rabotno vreme: ";
                    cin >> rabotno_vreme;

                    vraboteni.push_back(new Demonstrator(ime, prezime, godina_na_vrabotuvanje, rabotno_vreme));
                }

                break;
            }
            case 2: {
                for (Vraboten* vraboten : vraboteni) {
                    vraboten->prikazi_podatoci();
                }
                break;
            }
            case 3: {
                break;
            }
            default: {
                cout << "Nevalidna opcija, obidete povtorno" << endl;
            }
        }
    } 

return 0;
}
