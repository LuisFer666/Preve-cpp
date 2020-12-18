// istream::get example
#include <iostream>     // std::cin, std::cout
#include <fstream>      // std::ifstream
#include <string>
#include <set>
#include <map>

#include "utilidades.cpp"

using namespace std;

bool num = false;
bool cadena = false;
bool _str = false;
string _string;

map<string,int> transiciones[71];
string errores[11];
map<int, int> err_proceso;
char simbolos[] = {' ', '\n', '(', ')', ';', '.', '{', '}'};
string palabras[] = {"startPrevebot", "endPrevebot", "turn", "right", "left",
                    "straight", "stop", "wait", "back", "detect", "Door", "Battery",
                    "Colision", "openDoor", "closeDoor", "transport", "medicine", "cloth", "sample", "alert",
                    "clean", "lowBattery"};


int main () {
    set<string> dic_palabras;
    set<char> dic_simbolos;
    
    for(string a : palabras)
    {
        dic_palabras.insert(a);
    }
    
    for(char a : simbolos)
    {
        dic_simbolos.insert(a);
    }
    
    Utilidades::iniciarMapa(transiciones);
    Utilidades::iniciarErrores(errores, err_proceso);
    
  char str[256];

  cout << "Enter the name of an existing text file: ";
  cin.get (str,256);    // get c-string

  ifstream is(str);     // open file

    char c;
    string aux;
    string numero;
    int pos=1;
    int fila=1;
    int estado = 0; // 0 si no hay errores, 1 si hay errores
    int proceso=1;
    
  while (is.get(c))          // loop getting single characters
  {
      if(proceso == 26)
      {
          break;
      }
      if(num)
      {
          if(c >= '0' && c <= '9') // Juntar numeros
          {
              num = true;
              cadena = false;
              _str = false;
              aux += c;
          }else // Iniciar string
          {
              num = false;
              cadena = false;
              _str = false;
              //cout << "Num["<< aux << "]\n";
              
              if(transiciones[proceso].count("3")) // Transiciones de numeros
              {
                  cout << aux << " "<< proceso << "->"<< transiciones[proceso]["3"] <<"\n";
                  proceso = transiciones[proceso]["3"];
              }else
              {
                  cout <<  "Fila: " << fila << "|Pos:" << pos << " "<< errores[err_proceso[proceso]] << ". Se encontro: '" << aux << "'\n";
                  estado = 1;
              }
              
              aux = c;
              if(transiciones[proceso].count(aux)) // Transicion de simbolos
                  {
                      cout << aux << " "<< proceso << "->"<< transiciones[proceso][aux] <<"\n";
                      proceso = transiciones[proceso][aux];
                  }else
                  {
                      cout <<  "Fila: " << fila << "|Pos:" << pos << " "<< errores[err_proceso[proceso]] << ". Se encontro: '" << aux << "'\n";
                        estado = 1;
                }
          }
      }else
      {
          if(c >= '0' && c <= '9') // Numeros
          {
              if(cadena) // Error de string
              {
                  cout <<  "Fila: " << fila << "|Pos:" << pos << " "<< errores[err_proceso[proceso]] << ". Se encontro: '" << aux << "'\n";
                  estado = 1;
              }
              
              num = true;
              cadena = false;
              aux = c;
          }else if(dic_palabras.count(aux)) // Palabras
          {
              if(cadena) // Error de string
              {
                  cout <<  "Fila: " << fila << "|Pos:" << pos << " "<< errores[err_proceso[proceso]] << ". Se encontro: '" << aux << "'\n";
                  estado = 1;
              }
              
              num = false;
              cadena = false;
              if(transiciones[proceso].count(aux)) // Transicion de palabras
              {
                  cout << aux << " "<< proceso << "->"<< transiciones[proceso][aux] <<"\n";
                  proceso = transiciones[proceso][aux];
              }else
              {
                  cout <<  "Fila: " << fila << "|Pos:" << pos << " "<< errores[err_proceso[proceso]] << ". Se encontro: '" << aux << "'\n";
                  estado = 1;
              }
              //cout << "Pal[" << aux << "]\n";
              aux = "";
          }else if(dic_simbolos.count(c)) // Simbolos
          {
              if(cadena) // Error de string
              {
                  if(aux[0] == '\"')
                  {
                      _str = true;
                      _string = aux; // Guardar string para que no se pierda en la linea "aux = c"
                  }else
                  {
                      _str = false;
                      cout <<  "Fila: " << fila << "|Pos:" << pos << " "<< errores[err_proceso[proceso]] << ". Se encontro: '" << aux << "'\n";
                      estado = 1;
                  }
              }
              
              if(c == '\n')
              {
                  fila++;
                  pos = 1;
              }
              
              num = false;
              cadena = false;
              //cout << "Sim[" << c << "]\n";
              aux = c;
              if(_str)
              {
                  if(transiciones[proceso].count("asd")) // Transicion de strings
                  {
                      cout << _string << " "<< proceso << "->"<< transiciones[proceso]["asd"] <<"\n";
                      proceso = transiciones[proceso]["asd"];
                  }else
                  {
                      cout <<  "Fila: " << fila << "|Pos:" << pos << " "<< errores[err_proceso[proceso]] << ". Se encontro: '" << aux << "'\n";
                      estado = 1;
                  }
              }else if(transiciones[proceso].count(aux)) // Transicion de simbolos
              {
                  cout << aux << " "<< proceso << "->"<< transiciones[proceso][aux] <<"\n";
                  proceso = transiciones[proceso][aux];
              }else
              {
                  cout <<  "Fila: " << fila << "|Pos:" << pos << " "<< errores[err_proceso[proceso]] << ". Se encontro: '" << aux << "'\n";
                  estado = 1;
              }
              
              if(_str)
              {
                  if(transiciones[proceso].count(aux)) // Transicion de simbolos
                  {
                      cout << aux << " "<< proceso << "->"<< transiciones[proceso][aux] <<"\n";
                      proceso = transiciones[proceso][aux];
                  }else
                  {
                      cout <<  "Fila: " << fila << "|Pos:" << pos << " "<< errores[err_proceso[proceso]] << ". Se encontro: '" << aux << "'\n";
                      estado = 1;
                  }
                  _str = false;
              }else
              {
                  aux = "";
              }
          }else // Juntar strings
          {
              num = false;
              cadena = true;
              aux += c;
              //cout << ">> = " << aux << "\n"; // Mostrar cada caracter leido
              
              if(dic_palabras.count(aux)) // Palabras al final
              {
                  num = false;
                  cadena = false;
                  
                  if(transiciones[proceso].count(aux)) // Transicion de palabras
                  {
                      cout << aux << " "<< proceso << "->"<< transiciones[proceso][aux] <<"\n";
                      proceso = transiciones[proceso][aux];
                  }else
                  {
                      cout <<  "Fila: " << fila << "|Pos:" << pos << " "<< errores[err_proceso[proceso]] << ". Se encontro: '" << aux << "'\n";
                      estado = 1;
                  }
                  
                  // cout << "Pal[" << aux << "]\n";
                  aux = "";
              }
          }
      }
      pos++;
  }

  is.close();                // close file

    if(estado == 1)
    {
        cout << "Ejecucion con errores\n";
    }else if(estado == 0)
    {
        cout << "Ejecucion exitosa\n";
    }
    
  return 0;
}