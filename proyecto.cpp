// istream::get example
#include <iostream>     // std::cin, std::cout
#include <fstream>      // std::ifstream
#include <string>
#include <set>

using namespace std;

bool num = false;
bool cadena = false;

char simbolos[] = {' ', '\n', '(', ')', ';', '.', '{', '}'};
string palabras[] = {"startPrevebot", "endPrevebot", "turn", "right", "left",
                    "straight", "stop", "wait", "back", "detect", "Door", "Battery",
                    "Colision", "openDoor", "transport", "medicine", "cloth", "sample", "alert",
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
    
    
  char str[256];

  cout << "Enter the name of an existing text file: ";
  cin.get (str,256);    // get c-string

  ifstream is(str);     // open file

  char c;
    string aux;
    string numero;
    int pos=1;
    int col=1;
    int estado = 0;
    int proceso=1;
  while (is.get(c))          // loop getting single characters
  {
      if(num)
      {
          if(c >= '0' && c <= '9') // Juntar numeros
          {
              num = true;
              cadena = false;
              aux += c;
          }else // Iniciar string
          {
              num = false;
              cadena = true;
              //cout << "Num["<< aux << "]\n";
              aux = c;
          }
      }else
      {
          if(c >= '0' && c <= '9') // Numeros
          {
              if(cadena) // Error de string
              {
                  cout <<  "Col: "<< col << "|Pos:" << pos << " La instruccion < " << aux << " > no existe\n";
                  estado = 1;
              }
              
              num = true;
              cadena = false;
              aux = c;
          }else if(dic_palabras.count(aux)) // Palabras
          {
              if(cadena) // Error de string
              {
                  cout <<  "Col: "<< col << "|Pos:" << pos << " La instruccion < " << aux << " > no existe\n";
                  estado = 1;
              }
              
              num = false;
              cadena = false;
              //cout << "Pal[" << aux << "]\n";
              aux = "";
          }else if(dic_simbolos.count(c)) // Simbolos
          {
              if(cadena) // Error de string
              {
                  cout <<  "Col: "<< col << "|Pos:" << pos << " La instruccion < " << aux << " > no existe\n";
                  estado = 1;
              }
              
              if(c == '\n')
              {
                  col++;
                  pos = 1;
              }
              
              num = false;
              cadena = false;
              //cout << "Sim[" << c << "]\n";
              aux = "";
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