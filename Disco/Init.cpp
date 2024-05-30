#include "Init.h"

void init() {
    int cant_platos;
    int cant_pistas;
    int cant_sector;
    cout << "Numero de platos: "; cin >> cant_platos;
    cout << "Pistas por superficie: "; cin >> cant_pistas;
    cout << "Sectores por pista: "; cin >> cant_sector;

    Plato::crear_plato(cant_platos, cant_pistas, cant_sector);

    ofstream archivo("../megatron2/data_disco");
    archivo << cant_platos << endl;
    archivo << 2 << endl;
    archivo << cant_pistas << endl;
    archivo << cant_sector << endl;
    archivo.close();
}