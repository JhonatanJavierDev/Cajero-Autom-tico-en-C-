#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    
    const string PIN = "050210";//Pin de la cuenta
    const int SALDO_CUENTA = 10000;//Saldo inicial de tu cuenta
    int saldo = SALDO_CUENTA;// saldo actual de tu cuenta
    string  cuenta_destino;// Cuenta de destino a transferir
    int monto_transferencia;// Cantidad a enviar
    int opcion;// Opcion que escogio el usuario
    int intentos = 0;// Contador para los errores con el PIN
    vector <string> operaciones;// Este vector almacena las operaciones que se hagan.

    cout << "Banco Nacional" << endl << endl;
    cout << "Bienvenido al Banco Nacional" << endl << endl;

    //Aca comienza el login en tu cuenta

    //Haremos sun While

    while (intentos < 3){
          
        string pin_ingreado;
        cout << "Ingresa el PIN de seguridad: ";
        cin >> pin_ingreado;
        cout << endl;

        //Condicional para ver si el pin es correcto xd
        if(pin_ingreado == PIN){
            cout << "PIN Correcto" << endl << endl;
            break;
        }else {

            cout << "PIN Incorrecto" << endl << endl;
            intentos++;
            if (intentos == 5){
                cout << "Cuenta Bloqueada" << endl;
                return 0;
            }

        }

    }


    //Ciclo para mostrar el menú al usuario y procesar opciones(seleccionadas)

    while(true){

        cout << "Selecciona una Opción" << endl;
        cout << "1 Consultar saldo" << endl;
        cout << "2 Transferir" << endl;
        cout << "3 Retirar dinero" << endl;
        cout << "4 Operaciones" << endl;
        cout << "5 Salir" << endl << endl;
        cin >> opcion;
        cout << endl;

        
        if(opcion == 5){
            break;
        } else if (opcion ==1){
            cout << "Saldo de la cuenta: $" << saldo << endl << endl;
            operaciones.push_back("Consulta de saldo");
        } else if (opcion == 2){

            while(true){
                cout << "Ingrese el número de cuenta a transferir: ";
                cin >> cuenta_destino;
                cout << endl;
                if (cuenta_destino.length() ==6){
                    break;
                }else {
                    cout << "La cuenta no es correcta" << endl << endl;
                }

            }

            cout << "INgrese la cantidad a transferir: $";
            cin >> monto_transferencia;
            cout << endl;
            if (saldo >= monto_transferencia){
                saldo -= monto_transferencia;
                cout << "Has transferido: $" << monto_transferencia << "a la cuenta: " << cuenta_destino << endl << endl;
                operaciones.push_back("Transferencia de $" + to_string(monto_transferencia) + "a la cuenta " + cuenta_destino);

            }else {
                cout << "Saldo insuficiente" << endl << endl;
            }
      
        } else if (opcion ==3){

            int monto_retiro;
            cout << "Ingrese el monto a retirar: $";
            cin >> monto_retiro;
            cout << endl;
            if( saldo >= monto_retiro){
                saldo -= monto_retiro;
                cout << "Has retirado: $" << monto_retiro << endl;
                cout << "Saldo restante: $" << saldo << endl << endl;
                operaciones.push_back("Retiro de $" + to_string(monto_retiro));

            }
            else {
                cout << "Saldo insuficiente" << endl << endl;
                
                
            }
            }else if (opcion == 4){
                cout << "Operaciones realizadas: " << endl;
                for (int i = 0; i < operaciones.size(); i++){
                    cout << "- " << operaciones[i] << endl;
                }
                cout << endl;
            } else {
                cout << "Opción inválida" << endl << endl;
            }

        }
        return 0;
 


    }
