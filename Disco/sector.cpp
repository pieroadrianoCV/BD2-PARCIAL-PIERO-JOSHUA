#include "sector.h"
#include "Disco.cpp"

void Sector::crear_sector(string pista_carpeta, int cant_sector) {
    for(int sector = 0; sector < cant_sector; sector++) {
                string sector_carpeta = pista_carpeta + "/" + to_string(sector + 1);
                create_archivo(sector_carpeta);
                //capacidad += 1000;
                }
}