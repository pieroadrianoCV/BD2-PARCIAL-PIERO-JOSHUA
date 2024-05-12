#ifndef PESO_H
#define PESO_H
#include "data_manager.h"
#include "pesos.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int Peso::calcular_peso(vector<string> elementos) {
    int peso = 0;
    for (int i = 0; i < elementos.size(); i++) {
        peso += elementos[i].size();
    }
    return peso * 8; // 8 bits
}

int Peso::peso_sector(string sector_archivo) {
    ifstream archivo(sector_archivo);
    string linea;
    vector<string> elementos;
    while(getline(archivo, linea)) {
        vector<string> palabras = DataManager::split(linea, '#');
        for (int i = 0; i < palabras.size(); i++) {
            elementos.push_back(palabras[i]);
        }
    }
    return calcular_peso(elementos);
}

// El peso máximo de un sector será de 1000 bits
bool Peso::verificar_peso(string sector_archivo, string nuevo_registro) {
    vector<string> elementos = DataManager::split(nuevo_registro, '#');
    int tamanio_registro = calcular_peso(elementos);
    return peso_sector(sector_archivo) + tamanio_registro <= tamanio_sector;
}
#endif
