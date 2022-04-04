/*Hacer un programa que simule un cajero automático con un saldo inicial de 5000000 Gs.
y que tenga todas las funcionalidades del menú que tiene un cajero normal */

#include <iostream>
#include <vector>     //"Vectores".
#include <windows.h>  //"Sleep" function
using namespace std;


//Variables
long double saldo = 5000000;
int opcion_menu = 0, pin_nro = 1912, pin_usuar = 0, tar_nro = 12345, tar_usuar = 0, mes_nac = 2, mes_usuar = 0, saldo_disp = -420, saldo_usuar = 0;

//Vector albergando meses para posterior impresión.
vector<string> meses_array = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
"Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};


//Function Declaration
void pantalla_menu();
void extraccion_saldo();
void consulta_cuenta();
void salir_cuenta();


int main(){


	cout << "\n\t\tBanco Central del Paraguay '(BCP)'." << endl;
	cout << "\t\tPor favor ingrese su tarjeta." 		 << endl; cin>> tar_usuar;


	if(tar_usuar == tar_nro){

        system("cls");
		cout << "\n\t\tPor favor ingrese su pin" << endl; cin >> pin_usuar;
		if(pin_usuar == pin_nro){

            system("cls");
			cout << "\n\t\tSeleccione su mes de nacimiento." << endl;
			for(int i = 0; i < meses_array.size(); i++){

				//Sumamos "1" para que el menú se muestre de manera correcta.
				cout << "\t\t" << i + 1<< ". " << meses_array[i] << ".\n";
			}
			cin >> mes_usuar;


			if (mes_usuar == mes_nac) {
                system("cls");
                pantalla_menu();
			} else {
                cout << "\n\t\tMes incorrecto.";
			}
		}else{

			cout<<"\n\t\tPin incorrecto";
		}

	}else{

		cout<<"\n\t\tError al leer la tarjeta"<<endl;
	}
	return 0;
}


//Function Definition
void pantalla_menu(){

    //Reseteamos el valor del menu.
    opcion_menu = 0;
	cout << "\n\t\t1. Extraccion"       << endl;
	cout << "\t\t2. Consulta de cuenta" << endl;
	cout << "\t\t3. Pago de servicio"   << endl;
	cout << "\t\t4. Deposito"           << endl;
	cout << "\t\t5. Giro de dinero"     << endl;
	cout << "\t\t6. Cambio de pin"      << endl;
	cout << "\t\t7. Salir"              << endl;
	cin >> opcion_menu;

	/*Al ser un servicio Nacional/Paraguayo, varias opciones están fuera de servicio
	y las funcionales son de gran lentitud*/
	switch(opcion_menu) {
        case 1:
            cout << "\n\t\tCargando...";
            extraccion_saldo();
            break;
        case 2:
            cout << "\n\t\tCargando...";
            consulta_cuenta();
            break;
        case 7:
            cout << "\n\t\tCargando...";
            salir_cuenta();
            break;
        default:
            cout << "\n\t\tServicio no disponible.";
            break;
	}
}

void extraccion_saldo(){
    Sleep(10000);
    cout << "\n\t\tExtraer saldo:" << endl;
    cout << "\t\tIngrese el monto que desea extraer: " << endl; cin >> saldo_usuar;
    (saldo_disp - saldo_usuar) > saldo_disp ? cout << "\nExtraccion efectiva." : cout << "\nTransaccion no exitosa. Demasiadas deudas.";
}

void consulta_cuenta(){
    Sleep(10000);
    cout << "\nDemasiadas deudas.";
}

void salir_cuenta(){
    Sleep(10000);
    cout << "\nPague sus deudas.";
}
