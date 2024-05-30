#include "Disco.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <sys/stat.h> // para usar mkdir
#include <chrono>
#include <ctime>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;
/*
void create_carpeta(string r_carpeta) {
    filesystem::create_directories(r_carpeta);
    cout << "Directorio" << r_carpeta << "creado" <<endl;
}*/

void create_carpeta(string r_carpeta) {
    int resultado = mkdir(r_carpeta.c_str(), 0777); // Crear la carpeta con permisos de lectura, escritura y ejecución
    if (resultado == 0) {
        cout << "Directorio " << r_carpeta << " creado exitosamente." << endl;
    } else {
        cerr << "Error al crear el directorio " << r_carpeta << "." << endl;
    }
}

void create_archivo(string r_archivo) {
    ofstream archivo(r_archivo);
    cout << "Archivo creado:" << r_archivo <<endl; 
}

