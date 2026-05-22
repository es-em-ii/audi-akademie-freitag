#include <string>
#include <iostream>

// --- PARENT Fahrzeug ---
class Fahrzeug{
    
    protected: 
        std::string kennzeichen;
        std::string fahrgestellnr;

    public:
        Fahrzeug(string plate, string vin) : kennzeichen(plate), fahrgestellnr(vin) {};

        void fahren() {
            std::cout << "Das Fahrzeug fährt./n"
        };

        void bremsen() {
            std::cout << "Das Fahezug bremst./n"
        };
};

// --- CHILD Bus | Fahrzeug --- 
class Bus : public Fahrzeug {

};


// --- PARENT Person ---
class Person {

};

// --- CHILD Fahrer | Person ---
class Fahrer : public Person {

};