#ifndef LINEPARSER_H
#define LINEPARSER_H
#include <map>
#include <string>
#include <fstream>


class LineParser
{
public:
    typedef  std::map<std::string, int > Map;
    Map tag_map;

public:
    LineParser();
    ~LineParser();
    void insert(std::string& tag);
    void grab_tag(std::string& line);
    void grab_sentence(std::string& line, std::ofstream& out);
    void reset_values();
    void print_map_info(std::ofstream& out);
private:
    bool greater_than;
    bool less_than;
    bool white_space;
    std::string tag_string;
    std::string text_string;


};

#endif // PARSEADOR_DE_LINEA_H
