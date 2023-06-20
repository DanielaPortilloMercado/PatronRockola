#pragma once
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include "Cancion.h"
#include <vector>
class ArchivoJSON {
public:
    ArchivoJSON() = default;
    std::list<cancion> leerCanciones() {
        std::list<cancion> canciones;
        return canciones;
    }

    void processJSON(const std::string& filename) {
        // Leer el contenido del archivo JSON
        std::string json = ReadJSONFile(filename);

        // Vectores para almacenar los datos
        std::vector<std::string> nombres;
        std::vector<std::string> procedencias;
        std::vector<std::string> generos;

        // Analizar el contenido del archivo JSON y extraer los datos
        ParseJSON(json, nombres, procedencias, generos);

        // Imprimir los datos extraídos
        for (size_t i = 0; i < nombres.size(); i++) {
            std::cout << "Artista " << i + 1 << ":" << std::endl;
            std::cout << "Nombre: " << nombres[i] << std::endl;
            std::cout << "Procedencia: " << procedencias[i] << std::endl;
            std::cout << "Género: " << generos[i] << std::endl;
            std::cout << std::endl;
        }
    }
private:
    // Función para leer el contenido del archivo JSON y devolverlo como una cadena
    std::string ReadJSONFile(const std::string& filename) {
        std::ifstream file(filename);
        std::string json((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        return json;
    }

    // Función para analizar el contenido del archivo JSON y extraer los datos
    void ParseJSON(const std::string& json, std::vector<std::string>& nombres, std::vector<std::string>& procedencias, std::vector<std::string>& generos) {
        size_t pos = json.find('{');
        while (pos != std::string::npos) {
            pos = json.find("\"nombre\":", pos);
            if (pos == std::string::npos)
                break;

            // Obtener el nombre del artista
            size_t start = json.find("\"", pos + 9) + 1;
            size_t end = json.find("\"", start);
            std::string nombre = json.substr(start, end - start);
            nombres.push_back(nombre);

            // Obtener la procedencia del artista
            pos = json.find("\"procedencia\":", end);
            start = json.find("\"", pos + 14) + 1;
            end = json.find("\"", start);
            std::string procedencia = json.substr(start, end - start);
            procedencias.push_back(procedencia);

            // Obtener el género del artista
            pos = json.find("\"genero\":", end);
            start = json.find("\"", pos + 9) + 1;
            end = json.find("\"", start);
            std::string genero = json.substr(start, end - start);
            generos.push_back(genero);

            pos = end;
        }
    }
};
