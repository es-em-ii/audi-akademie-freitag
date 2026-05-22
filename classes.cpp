#include <string>
#include <iostream>
#include <algorithm>

// --- PARENT Fahrzeug ---
class Fahrzeug{
    
    protected: 
        std::string kennzeichen;
        std::string fahrgestellNr;
        int sitzplaetze;

    public:
        Fahrzeug(std::string plate, std::string vin, int plaetze) : kennzeichen(plate), fahrgestellNr(vin), sitzplaetze(plaetze) {};

        void fahren() {
            std::cout << "Das Fahrzeug fährt.\n";
        };

        void bremsen() {
            std::cout << "Das Fahrzeug bremst.\n";
        };
};

// --- PARENT Person ---
class Person {
    protected:
        std::string name;
        std::string geburtsdatum;
    
    public:

        Person (std::string n, std::string dob) : name(n), geburtsdatum(dob) {};

        void anzeigen(){
            std::cout << "Name: " << name << std::endl;
            std::cout << "Geburtsdatum: " << geburtsdatum << std::endl;
        };
};

// --- CHILD Fahrer | Person ---
class Fahrer : public Person {
    private:
        int fuehrerscheinNr;
    
    public:
        Fahrer (std::string name, std::string dob, int licenseNr) : Person(name, dob), fuehrerscheinNr(licenseNr){};

        void fahrerInfo(){
            anzeigen();
            std::cout << "Fuehrerscheinnummer: " << fuehrerscheinNr << std::endl;
        };
};

// --- CHILD Bus | Fahrzeug --- 
class Bus : public Fahrzeug {

        private:
            int busNr;
            std::string start;
            std::string ziel;
            int fahrgaeste;
            int rest;

            Fahrer* fahrer;

        public:
            Bus(std::string plate, std::string vin, int nr, std::string start, std::string stop, int passengers, Fahrer* driver)
            : Fahrzeug(plate, vin, passengers), busNr(nr), start(start), ziel(stop), fahrgaeste(0), fahrer(driver) {};

            void halten() {
                std::cout << "Der Bus hält an der nächsten Haltestelle.\n";
            };

            void einsteigen(int anzahl) {
                if (fahrgaeste == sitzplaetze) {
                    std::cout << "Der Bus ist voll.\n";
                }
                else if (anzahl == 0) {
                    std::cout << "Es ist kein Fahrgast eingestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                }
                else {
                    if (anzahl == 1) {
                        fahrgaeste += anzahl;
                        std::cout << "Es ist " << anzahl << " Fahrgast eingestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                    }
                    else if (anzahl > 1 && (anzahl + fahrgaeste <= sitzplaetze)) {
                        fahrgaeste += anzahl;
                        std::cout << "Es sind " << anzahl << " Fahrgäste eingestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                    }
                    else if (anzahl > 1 && (anzahl + fahrgaeste > sitzplaetze)) {
                        fahrgaeste += std::max(sitzplaetze, fahrgaeste);
                        rest = -1*(sitzplaetze - fahrgaeste - anzahl);
                        std::cout << "Es sind " << anzahl << " Fahrgäste eingestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << ". Es konnten " << rest << " Personen nicht mitgenommen werden."<< std::endl;
                    }
                    else if (anzahl < 0) {
                        std::cerr << "Falsche Eingabe. Es sind nur positive Zahlen erlaubt.\n";
                    };
                };
            };

            void aussteigen(int anzahl) {
                if (fahrgaeste == 0) {
                    std::cout << "Der Bus ist leer.\n";
                }
                else if (anzahl == 0) {
                    std::cout << "Es ist kein Fahrgast ausgestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                }
                else {
                    if (anzahl == 1) {
                        fahrgaeste -= anzahl;
                        std::cout << "Es ist " << anzahl << " Fahrgast ausgestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                    }
                    else if (anzahl > 1 && anzahl <= fahrgaeste) {
                        fahrgaeste -= anzahl;
                        std::cout << "Es sind " << anzahl << " Fahrgäste ausgestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                    }
                    else if (anzahl > 1 && anzahl > fahrgaeste) {
                        fahrgaeste -= std::min(anzahl, fahrgaeste);
                        std::cout << "Es sind " << std::min(anzahl, fahrgaeste) << " Fahrgäste ausgestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                    }
                    else if (anzahl < 0) {
                        std::cerr << "Falsche Eingabe. Es sind nur positive Zahlen erlaubt.\n";
                    };
                };
            };

            void busInfo() {
                std::cout << std::endl;
                std::cout << "| Informationen zum Bus |\n";
                std::cout << "Busnummer: " << busNr << std::endl;
                std::cout << "Kennzeichen: " << kennzeichen << std::endl;
                std::cout << "Fahrgestellnummer: " << fahrgestellNr << std::endl;
                std::cout << "Start: " << start << std::endl;
                std::cout << "Ziel: " << ziel << std::endl;
                std::cout << "Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                std::cout << "Anzahl Sitzplätze: " << sitzplaetze << std::endl;
                std::cout << "\n";
                std::cout << "| Informationen zum Fahrer |\n";
                fahrer->fahrerInfo();
            };
};

int main() {
    // Fahrer anlegen
    Fahrer fahrer01 (
        "Will Riker",
        "01.01.1910",
        1234567890
    );
    Bus bus01 (
        "B-US 0101", 
        "WAUZZZ129484901C12887", 
        710, 
        "Ingolstadt", 
        "München", 
        0, 
        &fahrer01
    );
    bus01.busInfo();
    bus01.einsteigen(5);
    bus01.aussteigen(2);
    bus01.busInfo();
    
    return 0;
};