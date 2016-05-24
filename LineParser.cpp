#include "LineParser.h"
#include <iostream>


using namespace std;



LineParser::LineParser()
{
    less_than=greater_than=white_space=false;
    tag_string = "";

}

LineParser::~LineParser()
{
}

//Buscamos etiquetas en la linea y se insertan en un mapa
void LineParser::grab_tag(std::string& line)
{
    for ( std::string::iterator it=line.begin(); it!=line.end(); ++it)
    {
        if(*it == '<') // Si el caracter es '<' entonces se pone en true, para saber que empezamos una etiqueta.
        {
            less_than=true;
        }
        else
        {
            if(*it=='>') // Si el caracter es '>' entonces se pone en true, para saber que terminamos una etiqueta.
            {
                greater_than=true;

            }
            else
            {
                if(*it==' ') //Si el caracter es un espacio en blanco, se pone en true, ya que en un tag esto puede significar el fin de una etiqueta.
                {
                    white_space=true;

                }

            }

        }



        if(greater_than== true && less_than== false) //Para reconocer una etiqueta no  puede estar el '<' como falso y el '>' como verdadero
        {
            greater_than=false; //se pone el '>' como falso
        }

        if(less_than == true && white_space == false && greater_than==false)// si no hemos llegado al final de una etiqueta
        {
            tag_string +=  *it; //se copia caracter al string nuevo, que contendrá el tag por insertar a un mapa.

        }
        else
        {
            if( (white_space == true && less_than == true) ||(greater_than==true && less_than==true) ) //Aqui terminamos con nuestro tag
            {
                tag_string +='>';
                greater_than=true;
            }
            else
            {

                if(white_space == true  && less_than == false)
                {
                    white_space=false;

                }


            }
            if(greater_than==true && less_than==true) //Si tenemos esto: '<  >', se mete en un mapa
            {

                insert(tag_string);
                reset_values(); //reseteamos valores para buscar otra etiqueta en la linea

            }


        }


    }



}

 //Insertamos en el mapa
void LineParser::insert(string& tag)
{
    string  otra_etiqueta = tag;
    Map::iterator it = tag_map.find(otra_etiqueta);
    if(it != tag_map.end()) //Esta en el mapa?
    {
        ++(it->second); //Si esta en el mapa, aumentamos el contador.
    }
    else
    {
        int counter=1;
        tag_map.insert(std::make_pair(otra_etiqueta,counter)); //Insertamos ese tag al mapa

    }

}

//Se resetean los valores

void LineParser::reset_values()
{
    greater_than=false;
    less_than=false;
    white_space=false;
    tag_string="";
    text_string="";
}


//Imprimimos la informacion de cada tag, es decir, el nombre de este y la cantidad de veces presente en el archivo.

void LineParser::print_map_info(ofstream& out)
{

    for (std::map<string,int>::iterator it=tag_map.begin(); it!=tag_map.end(); ++it)
        out<< it->first << " => " << it->second << '\n';

}

//Agarra  el texto de la oración sin los tags
void LineParser::grab_sentence(string& line,ofstream& out)
{

    for ( std::string::iterator it=line.begin(); it!=line.end(); ++it)
    {
        if(*it == '<')
        {
            less_than=true;
        }
        else
        {
            if(*it=='>')
            {
                greater_than=true;

            }
            else
            {
                if(*it==' ')
                {
                    white_space=true;

                }

            }

        }

        if(greater_than == false && less_than==false)
        {
            text_string+=*it;

        }
        else
        {
            if(greater_than == true && less_than==true)
            {
                greater_than=false;
                less_than=false;

            }
        }

    }

    out<<text_string<<endl;
    reset_values();

}



