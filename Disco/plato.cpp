#include "plato.h"
#include "pista.h"
#include <sys/stat.h> 
#include "Disco.cpp"
using namespace std;

void Plato::crear_plato(int cant_platos, int cant_pista, int cant_sector) {
    int capacidad = 0;
    string carpeta_nombre = "Disco";
    create_carpeta(carpeta_nombre);
    for(int plato = 0; plato < cant_platos; plato++) {
        string plato_carpeta = carpeta_nombre + "/" + to_string(plato + 1);
        create_carpeta(plato_carpeta);
        for(int superficies = 0; superficies < 2; superficies++) {
            string superficie_carpeta = plato_carpeta + "/" + to_string(superficies + 1);
            create_carpeta(superficie_carpeta);
            Pista::crear_pista(superficie_carpeta,cant_pista, cant_sector);
        }
        
    }
}