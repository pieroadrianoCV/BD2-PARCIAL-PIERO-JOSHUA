#ifndef DISCO_H
#define DISCO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <sys/stat.h> 

using namespace std;
#define tamanio_sector 1000


class Disco {
public:
    static void create_carpeta(string r_carpeta);
    static void create_archivo(string r_archivo);

};

#endif // SCHEMA_MANAGER_