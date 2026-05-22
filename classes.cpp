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
        Fahrzeug(string plate, string vin, int plaetze) : kennzeichen(plate), fahrgestellNr(vin), sitzplaetze(seats) {};

        void fahren() {
            std::cout << "Das Fahrzeug fährt./n"
        };

        void bremsen() {
            std::cout << "Das Fahezug bremst./n"
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
            halten() {
                std::cout << "Der Bus hält an der nächsten Haltestelle./n"
            };

            einsteigen(int anzahl) {
                if (fahrgaeste == sitzplaetze) {
                    std::cout << "Der Bus ist voll./n"
                }
                else if (anzahl = 0) {
                    std::cout << "Es ist kein Fahrgast eingestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                }
                else {
                    if (anzahl = 1) {
                        fahrgaeste += anzahl;
                        std::cout << "Es ist " << anzahl << " Fahrgast eingestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                    }
                    else if (anzahl > 1 && (anzahl + fahrgaeste <= sitzplaetze)) {
                        fahrgaeste += anzahl;
                        std::cout << "Es sind " << anzahl << " Fahrgäste eingestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                    }
                    else if (anzahl > 1 && (anzahl + fahrgaeste > sitzplaetze)) {
                        fahrgaeste += std::max(sitzplaetze, fahrgaeste);
                        rest = -1*(sitzplaetze - fahrgaeste - anzahl) 
                        std::cout << "Es sind " << anzahl << " Fahrgäste eingestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << ". Es konnten " rest << " Personen nicht mitgenommen werden."<< std::endl;
                    }
                    else if (anzahl < 0) {
                        std::cerr << "Falsche Eingabe. Es sind nur positive Zahlen erlaubt./n"
                    };
                };
            };

            aussteigen(int anzahl) {
                if (fahrgaeste == 0) {
                    std::cout << "Der Bus ist leer./n"
                }
                else if (anzahl = 0) {
                    std::cout << "Es ist kein Fahrgast ausgestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                }
                else {
                    if (anzahl = 1) {
                        fahrgaeste -= anzahl;
                        std::cout << "Es ist " << anzahl << " Fahrgast ausgestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                    }
                    else if (anzahl > 1 && anzahl <= fahrgaeste) {
                        fahrgaeste -= anzahl;
                        std::cout << "Es sind " << anzahl << " Fahrgäste ausgestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                    }
                    else if (anzahl > 1 && anzahl > fahrgaeste) {
                        fahrgaeste -= min(anzahl, fahrgaeste);
                        std::cout << "Es sind " << min(anzahl, fahrgaeste) << " Fahrgäste ausgestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                    }
                    else if (anzahl < 0) {
                        std::cerr << "Falsche Eingabe. Es sind nur positive Zahlen erlaubt./n"
                    };
                };
            };

            busInfo() {
                std::endl;
                std::cout << "| Informationen zum Bus |/n";
                std::cout << "Busnummer: " << busNr << std::endl;
                std::cout << "Kennzeichen: " << kennzeichen << std::endl;
                std::cout << "Fahrgestellnummer: " << fahrgestellNr << std::endl;
                std::cout << "Start: " << start << std::endl;
                std::cout << "Ziel: " << ziel << std::endl;
                std::cout << "Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                std::cout << "Anzahl Sitzplätze: " << sitzplaetze << std::endl;

            };
};


// --- PARENT Person ---
class Person {

};

// --- CHILD Fahrer | Person ---
class Fahrer : public Person {

};