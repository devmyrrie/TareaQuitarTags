#include "FileParser.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


FileParser::FileParser(string file)
{
    file_name =file;
}

FileParser::~FileParser()
{
}

FileParser::FileParser()
{
}

void FileParser::set_filename(string filename){

    file_name=filename;

}




void FileParser::begin_parsing()
{
    string line = "";
    const char* filename =  file_name.c_str();
    ifstream xml_file (filename,  ios::in);

    if(xml_file.is_open())
    {
        cout<<"FILE OPENED!"<<endl;
        while(!xml_file.eof())
        {

            getline(xml_file,line);
            line_parser.grab_tag(line);

        }

    }
    xml_file.close();

}


void FileParser::print_tags()
{
    ofstream out("TAGS.txt");
    line_parser.print_map_info(out);
    out.close();



}

void FileParser::save_untagged_text()
{
    ofstream out("TEXT_UNTAGGED.txt");

    const char* filename =  file_name.c_str();
    ifstream xml_file (filename,  ios::in);

    string line ="";
    while(!xml_file.eof())
    {
        getline(xml_file,line);
        line_parser.grab_sentence(line,out);

    }
    xml_file.close();

}




