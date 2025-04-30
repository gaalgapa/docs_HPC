#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <set>

void analyze_document(const std::string & fname);

int main(int argc, char **argv)
{
    const std::string FNAME = argv[1];      //llama al libro

    analyze_document(FNAME);                //Función analisis

    return 0;
}

void analyze_document(const std::string & fname){
    //Asegurarse de que el documento existe
    std::ifstream file(fname);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fname << std::endl;
        return;
    }

    // Leer todo el contenido del archivo en un solo string
    std::stringstream buffer;
    buffer << file.rdbuf(); // lee el archivo completo
    std::string text = buffer.str();

    // Convertir a minúsculas y quita la puntacion
    std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) {
        if (std::ispunct(c)) return ' ';        // sustituye puntuación por espacio
        return std::tolower(c);                 // convierte a minúscula
        });

    //declarar variables de map
    std::map<std::string, int> word_count;
    std::string word;

    while (file >> word) {
        word_count[word]++;
        }
    

    for(n = 0, n <= 20, ++n){
    }
}