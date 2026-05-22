#include <string>
#include <iostream>

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

            Fahrer* fahrer;

        public:
            halten() {
                std::cout << "Der Bus hält an der nächsten Haltestelle./n"
            };

            einsteigen(int anzahl) {
                if (anzahl = 0) {
                    std::cout << "Es ist kein Fahrgast eingestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                else if (anzahl = 1) {
                    fahrgaeste += anzahl;
                    std::cout << "Es ist " << anzahl << " Fahrgast eingestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                }
                else if (anzahl > 1) {
                    fahrgaeste += anzahl;
                    std::cout << "Es sind " << anzahl << " Fahrgäste eingestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
                }
                else if (anzahl < 0) {
                    std::cerr << "Falsche Eingabe. Es sind nur positive Zahlen erlaubt./n"
                };
            };

            aussteigen(int anzahl) {
                fahrgaeste -= anzahl;
                std::cout << "Es sind " << anzahl << " Fahrgäste eingestiegen. Aktuelle Anzahl Fahrgäste: " << fahrgaeste << std::endl;
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