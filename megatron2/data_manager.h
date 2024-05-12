#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H
using namespace std;
#include <string>
#include <vector>

class DataManager {
public:
    static string determinarTipoDato(const string& valor);
    static string toLowercase(string str);
    static string capitalize(string& str);
    static vector<string> get_type_from_line(string line);
    static vector<string> split(string str, char delimiter);
    static void consultas_datos(string nombre_relacion);
    template <typename... Args>
    static vector<string> consultar_columnas(string nombre_columna,Args... args);
    static vector<string> consultas_tablas(string nombre_relacion, string columna);
    static void mezclar_data(vector<vector<string>> data);
    static void consultas_tablas_final(string nombre_relacion, vector<string> columnas);
    static void where(string relacion, string data_string,string simbolo, int compare);
    static void where_condition(string relacion, string data_string,string simbolo, int compare, string sign, string name_new_relation);
};

#endif // DATA_MANAGER_H
