#include "problemas.h"
#include "validaciones.h"
#include <iostream>

using namespace std;

int main()
{

    while(true){
        cout << "=========Bienvenido al menú=========" << endl;
        cout << "1. Problema 1" << endl;
        cout << "3. Problema 3" << endl;
        cout << "5. Problema 5" << endl;
        cout << "7. Problema 7" << endl;
        cout << "9. Problema 9" << endl;
        cout << "11.Problema 11" << endl;
        cout << "13.Problema 13" << endl;
        cout << "Inrgese una opción: ";
        int opcion = validarEntero();

        if(opcion == 1){
            problema1();
        }else if(opcion == 3){
            problema3();
        }else if(opcion == 5){
            problema5();
        }else if(opcion == 7){
            problema7();
        }else if(opcion == 9){
            problema9();
        }else if(opcion == 11){
            problema11();
        }else if(opcion == 13){
            problema13();
        }else if(opcion == 15){
            problema15();
        }
    }


    return 0;
}


