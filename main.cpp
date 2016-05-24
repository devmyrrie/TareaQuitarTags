#include <iostream>
#include "FileParser.h"
using namespace std;

int main(int argc, char* argv[])
{

    FileParser file_parser;

    if(argc == 3)
    {
        file_parser.set_filename(argv[2]);

    }
    else
    {
        string filename="";
        cout << "Type in the filename (format: XXXXXX.xml)" << endl;
        getline(cin,filename);
        file_parser.set_filename(filename);
    }


    file_parser.begin_parsing();
    file_parser.print_tags();
    char* t = argv[1];
    if(*t == '-' &&  *(++t) == 't') // o podiamos poner if(!strcmp(argv[1], "-t"))

    {
        file_parser.save_untagged_text();
    }
    return 0;
}






