#include <map>
#include <string>

using namespace std;

class Utilidades{
    public:
        static void iniciarMapa(map<string,int> *transiciones);
        static void iniciarErrores(string *errores, map<int, int> &err_proceso);
};

void Utilidades::iniciarMapa(map<string,int> *transiciones)
{
    transiciones[1] = {{" ", 2}, {"\n", 3}, {"startPrevebot", 4}};
    transiciones[2] = {{" ", 2}, {"\n", 3}, {"startPrevebot", 4}};
    transiciones[3] = {{"\n", 3}, {"startPrevebot", 4}};
    transiciones[4] = {{" ", 5}, {"\n", 6}, {"{", 7}};
    transiciones[5] = {{" ", 5}, {"\n", 6}, {"{", 7}};
    transiciones[6] = {{"\n", 6}, {"{", 7}};
    transiciones[7] = {{" ", 8}, {"\n", 9}, {"endPrevebot", 10}, {"detect", 11}};
    transiciones[8] = {{" ", 8}, {"\n", 9}, {"endPrevebot", 10}, {"turn", 12}, 
                       {"straight", 13}, {"stop", 14}, {"detect", 11}, {"openDoor", 15}, {"alert", 16}};
    transiciones[9] = {{" ", 8}, {"\n", 9}, {"endPrevebot", 10}, {"turn", 12}, 
                       {"straight", 13}, {"stop", 14}, {"detect", 11}, {"openDoor", 15}, {"alert", 16}};
    transiciones[10] = {{";", 17}};
    transiciones[11] = {{".", 18}};
    transiciones[12] = {{".", 19}};
    transiciones[13] = {{"(", 20}};
    transiciones[14] = {{"(", 21}};
    transiciones[15] = {{";", 22}, {"endPrevebot", 10}, {"turn", 12}, {"straight", 13}, {"stop", 14},
                        {"detect", 11}, {"openDoor", 15}, {"alert", 16}};
    transiciones[16] = {{".", 23}};
    transiciones[17] = {{" ", 24}, {"\n", 25}, {"}", 26}};
    transiciones[18] = {{"Door", 27}, {"Battery", 28}, {"Colision", 29}};
    transiciones[19] = {{"right", 30}, {"left", 31}};
    transiciones[20] = {{"3", 32}};
    transiciones[21] = {{")", 33}};
    transiciones[22] = {{"0", 34}, {"1", 35}};
    transiciones[23] = {{"lowBattery", 36}};
    transiciones[24] = {{" ", 24}, {"\n", 25}, {"}", 26}};
    transiciones[25] = {{"\n", 25}, {"}", 26}};
    transiciones[26] = {};
    transiciones[27] = {{"(", 37}};
    transiciones[28] = {{"(", 38}};
    transiciones[29] = {{"(", 39}};
    transiciones[30] = {{"(", 20}};
    transiciones[31] = {{"(", 20}};
    transiciones[32] = {{")", 40}};
    transiciones[33] = {{" ", 8}, {"\n", 9}, {";", 41}, {"detect", 11}};
    transiciones[34] = {{")", 42}};
    transiciones[35] = {{")", 42}};
    transiciones[36] = {{"(", 43}};
    transiciones[37] = {{")", 44}};
    transiciones[38] = {{")", 45}};
    transiciones[39] = {{")", 46}};
    transiciones[40] = {{";", 47}};
    transiciones[41] = {{" ", 8}, {"\n", 9}, {"endPrevebot", 10}, {"turn", 12},
                        {"straight", 13}, {"stop", 14}, {"detect", 11}, {"openDoor", 15}};
    transiciones[42] = {{";", 48}};
    transiciones[43] = {{")", 49}};
    transiciones[44] = {{";", 50}};
    transiciones[45] = {{";", 51}};
    transiciones[46] = {{";", 52}};
    transiciones[47] = {{" ", 8}, {"\n", 9}, {"detect", 11}};
    transiciones[48] = {{" ", 53}, {"\n", 54}, {"closeDoor", 55}};
    transiciones[49] = {{";", 56}};
    transiciones[50] = {{" ", 53}, {"\n", 54}, {"closeDoor", 55}, {"transport", 57}};
    transiciones[51] = {{" ", 8}, {"\n", 9}, {"turn", 12}, {"straight", 13}, {"stop", 14},
                        {"openDoor", 15}, {"alert", 16}};
    transiciones[52] = {{" ", 8}, {"\n", 9}, {"endPrevebot", 10}, {"turn", 12}, {"straight", 13},
                        {"stop", 14}, {"openDoor", 15}};
    transiciones[53] = {{" ", 53}, {"\n", 54}, {"closeDoor", 55}, {"transport", 57}};
    transiciones[54] = {{" ", 53}, {"\n", 54}, {"closeDoor", 55}, {"transport", 57}};
    transiciones[55] = {{"(", 58}};
    transiciones[56] = {{" ", 8}, {"\n", 9}, {"endPrevebot", 10}, {"detect", 11}, {"openDoor", 15}};
    transiciones[57] = {{".", 59}};
    transiciones[58] = {{"0", 60}, {"1", 61}};
    transiciones[59] = {{"medicine", 62}, {"cloth", 63}, {"sample", 64}};
    transiciones[60] = {{")", 65}};
    transiciones[61] = {{")", 65}};
    transiciones[62] = {{"(", 66}};
    transiciones[63] = {{"(", 66}};
    transiciones[64] = {{"(", 66}};
    transiciones[65] = {{";", 67}};
    transiciones[66] = {{"asd", 68}};
    transiciones[67] = {{" ", 8}, {"\n", 9}, {"endPrevebot", 10}, {"detect", 11}};
    transiciones[68] = {{")", 69}};
    transiciones[69] = {{";", 70}};
    transiciones[70] = {{" ", 8}, {"\n", 9}, {"detect", 11}};
}

void Utilidades::iniciarErrores(string *errores, map<int, int> &err_proceso){
    errores[1] = "Se esperaba sentencia de inicio";
    errores[2] = "Se esperaba llave de apertura";
    errores[3] = "Se esperaba llave de cierre";
    errores[4] = "Se esperaba un parentesis de apertura";
    errores[5] = "Se esperaba un parentesis de cierre";
    errores[6] = "Se esperaba un punto y coma";
    errores[7] = "Se esperaba un punto";
    errores[8] = "Se esperaba un String cualquiera";
    errores[9] = "Se esperaba un numero";
    errores[10] = "Se esperaba una palabra reservada";
    
    err_proceso[1] = 1;
    err_proceso[2] = 1;
    err_proceso[3] = 1;
    err_proceso[4] = 2;
    err_proceso[5] = 2;
    err_proceso[6] = 2;
    err_proceso[7] = 10;
    err_proceso[8] = 10;
    err_proceso[9] = 10;
    err_proceso[10] = 6;
    err_proceso[11] = 7;
    err_proceso[12] = 7;
    err_proceso[13] = 4;
    err_proceso[14] = 4;
    err_proceso[15] = 10;
    err_proceso[16] = 7;
    err_proceso[17] = 3;
    err_proceso[18] = 10;
    err_proceso[19] = 10;
    err_proceso[20] = 9;
    err_proceso[21] = 5;
    err_proceso[22] = 9;
    err_proceso[23] = 10;
    err_proceso[24] = 3;
    err_proceso[25] = 3;
    err_proceso[27] = 4;
    err_proceso[28] = 4;
    err_proceso[29] = 4;
    err_proceso[30] = 4;
    err_proceso[31] = 4;
    err_proceso[32] = 5;
    err_proceso[33] = 10; // asdfsfd
    err_proceso[34] = 5;
    err_proceso[35] = 5;
    err_proceso[36] = 4;
    err_proceso[37] = 5;
    err_proceso[38] = 5;
    err_proceso[39] = 5;
    err_proceso[40] = 6;
    err_proceso[41] = 10;
    err_proceso[42] = 6;
    err_proceso[43] = 5;
    err_proceso[44] = 6;
    err_proceso[45] = 6;
    err_proceso[46] = 6;
    err_proceso[47] = 10;
    err_proceso[48] = 10;
    err_proceso[49] = 6;
    err_proceso[50] = 10;
    err_proceso[51] = 10;
    err_proceso[52] = 10;
    err_proceso[53] = 10;
    err_proceso[54] = 10;
    err_proceso[55] = 4;
    err_proceso[56] = 10;
    err_proceso[57] = 7;
    err_proceso[58] = 9;
    err_proceso[59] = 10;
    err_proceso[60] = 5;
    err_proceso[61] = 5;
    err_proceso[62] = 4;
    err_proceso[63] = 4;
    err_proceso[64] = 4;
    err_proceso[65] = 6;
    err_proceso[66] = 8;
    err_proceso[67] = 10;
    err_proceso[68] = 5;
    err_proceso[69] = 6;
    err_proceso[70] = 10;
}



