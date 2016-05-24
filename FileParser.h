#ifndef FILEPARSER_H
#define FILEPARSER_H
#include "LineParser.h"
#include <string>
#include <map>
/*La clase FileParser itera sobre el archivo linea por linea, en cada linea
se utilizan metodos propios de la clase LineParser, apra parsear la linea*/

class FileParser
{
    public:
        FileParser(std::string file_name);
        ~FileParser();
        FileParser();
        void begin_parsing(); //Empieza a iterar
        void print_tags(); //Imprime los tags y su contador
        void save_untagged_text(); //Guarda el texto sin los tags
        void set_filename(std::string filename);
    public:
        LineParser line_parser; //Objeto que tiene como funcion parsear una linea
        std::string  file_name; //nombre del archivo

};

#endif //FILEPARSER_H
