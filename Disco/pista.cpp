#include "pista.h"
#include <sys/stat.h> 
#include "Disco.cpp"
#include "sector.h"
void Pista::crear_pista(string superficie_carpeta, int cant_pistas, int cant_sector) {
    for(int pista = 0; pista < cant_pistas; pista++) {
            string pista_carpeta = superficie_carpeta + "/" + to_string(pista + 1);
            create_carpeta(pista_carpeta);
            Sector::crear_sector(pista_carpeta, cant_sector);
    }
}