#include "include/Cliente.hpp"
#include "include/GestorMenu.hpp"
#include "include/Reservas.hpp"
#include <array>
#include <iostream>
#include <string>

using namespace std;

int main() {
  GestorMenu menu;
  int opcion;
  
  do{
    menu.mostrarMenu();
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
    case 1:
      menu.registrarClientes();
      break;
    case 2:
      menu.actualizarCliente();
      break;
    case 3:
      menu.listarClientes();
      break;
    case 4:
      menu.hacerReservas();
      break;
    case 6:
      menu.listarReservas();
      break;
    case 7:
      cout << "Saliendo del programa\n";
      break;
    default:
      cout << "Opcion no valida\n";
      break;
    }
  }while(opcion != 7);
  return 0;}
