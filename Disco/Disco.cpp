#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <chrono>
#include <ctime>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

void create_carpeta(string r_carpeta) {
    filesystem::create_directories(r_carpeta);
    cout << "Directorio" << r_carpeta << "creado" <<endl;
}
void create_archivo(string r_archivo) {
    ofstream archivo(r_archivo);
    cout << "Archivo creado:" << r_archivo <<endl; 
}

void create_disco(int cant_platos, int cant_pistas, int cant_sector) {
    int capacidad = 0;
    string carpeta_nombre = "Disco";
    create_carpeta(carpeta_nombre);
    for(int plato = 0; plato < cant_platos; plato++) {
        string plato_carpeta = carpeta_nombre + "/" + to_string(plato + 1);
        create_carpeta(plato_carpeta);
        for(int superficies = 0; superficies < 2; superficies++) {
            string superficie_carpeta = plato_carpeta + "/" + to_string(superficies + 1);
            create_carpeta(superficie_carpeta);
            for(int pista = 0; pista < cant_pistas; pista++) {
                string pista_carpeta = superficie_carpeta + "/" + to_string(pista + 1);
                create_carpeta(pista_carpeta);
                for(int sector = 0; sector < cant_sector; sector++) {
                    string sector_carpeta = pista_carpeta + "/" + to_string(sector + 1);
                    create_archivo(sector_carpeta);
                    capacidad += 1000;
                }
            }
        }
    }
    double bytes = capacidad / 8.0;
    double gigabytes= bytes / pow(2, 30);
    cout << "Capacidad en GB del disco: " << gigabytes;
    ofstream archivo("../megatron2/data_disco");
    archivo << cant_platos << endl;
    archivo << 2 << endl;
    archivo << cant_pistas << endl;
    archivo << cant_sector << endl;
    archivo.close();
}

// class Disco {
//     public:
//         Disco(int cant_platos, int cant_pistas, int cant_sector) {
//             create_disco(cant_platos, cant_pistas, cant_sector);
//         }
//         int cant_platos;
//         int cant_pistas;
//         int cant_sector;
//         void create_disco();
// };

vector<string> split(string str, char delimiter) {
    vector<string> res;
    istringstream ss(str);
    string tok;
  
    while(getline(ss, tok, delimiter)) {
        if (tok != "") res.push_back(tok);
    } 
    return res;
}

int calcular_peso(vector<string> elementos) {
    int peso = 0;
    for (int i = 0; i < elementos.size(); i++) {
        peso += elementos[i].size();
    }
    return peso * 8; // 8 bits
}

int peso_sector(string sector_archivo) {
    ifstream archivo(sector_archivo);
    string linea;
    vector<string> elementos;
    while(getline(archivo, linea)) {
        vector<string> palabras = split(linea, '#');
        for (int i = 0; i < palabras.size(); i++) {
            elementos.push_back(palabras[i]);
        }
    }
    return calcular_peso(elementos);
}

// El peso máximo de un sector será de 10000 bits
bool verificar_peso(string sector_archivo) {
    return peso_sector(sector_archivo) <= 10000;
} 

int main() {
    int cant_platos;
    int cant_pistas;
    int cant_sector;
    cout << "Numero de platos: "; cin >> cant_platos;
    cout << "Pistas por superficie: "; cin >> cant_pistas;
    cout << "Sectores por pista: "; cin >> cant_sector;

    create_disco(cant_platos, cant_pistas, cant_sector);
}