// Meter todos los menus y opciones aqui para que el codigo sea mas legible y el
// main no este lleno

#include "../include/GestorMenu.hpp"
#include <iostream>
#include <string>

using namespace std;

GestorMenu::GestorMenu() { numClientes = 0; numReservas = 0; }

void GestorMenu::mostrarMenu() {
  cout << "\n";
  cout << "---------- << Tridentus Resort >> ----------\n";
  cout << "Seleccione una de las siguientes opciones \n";
  cout << "1. Crear Clientes\n";
  cout << "2. Actualizar su cliente\n";
  cout << "3. Listar clientes\n";
  cout << "4. Hacer una reserva\n";
  cout << "5. Actualizar reserva\n";
  cout << "6. Listar las reservas\n";
  cout << "7. Salir\n";
}

void GestorMenu::registrarClientes() {
  cout << "Ingrese la cantidad de clientes que desea registrar: ";
  int cantidad;
  cin >> cantidad;
  cin.ignore();

  if (numClientes + cantidad > maxClientes) {
    cout << "El número de clientes excede el límite\n";
    return;
  }

  for (int i = 0; i < cantidad; i++) {
    string nombre, id;
    int tipo;

    cout << "Ingrese el nombre del cliente " << numClientes + 1 << ": ";
    getline(cin, nombre);
    cout << "Ingrese el ID del cliente " << numClientes + 1 << ": ";
    getline(cin, id);
    cout << "Ingrese el tipo de cliente (0 para normal, 1 para VIP, 2 para "
            "SuperVip): ";
    cin >> tipo;
    cin.ignore();

    // Aqui tuve que usar un casteo para poder asignar un valor entero a la
    // membresia Y mostrarla en el metodo de mostrar info para que no tuviera
    // ningn problema

    Cliente::tipoMembresia membresia =
        static_cast<Cliente::tipoMembresia>(tipo);

    clientes[numClientes] = Cliente(nombre, id, membresia);
    numClientes++;
  }
}

void GestorMenu::actualizarCliente() {
  if (numClientes == 0) {
    cout << "No hay clientes registrados\n";
    return;
  }

  string idBuscar;
  cout << "Ingrese el ID del cliente a actualizar: ";
  getline(cin, idBuscar);

  bool encontrado = false;

  for (int i = 0; i < numClientes; i++) {
    if (clientes[i].getId() == idBuscar) {
      encontrado = true;

      cout << "\nCliente encontrado. Ingrese los nuevos datos:\n";

      string nuevoNombre, nuevoId;
      int nuevoTipo;
      cout << "Ingrese el nuevo nombre: ";
      getline(cin, nuevoNombre);
      cout << "Ingrese el nuevo ID: ";
      getline(cin, nuevoId);

      do {
        cout << "Ingrese el nuevo tipo de cliente (0 para normal, 1 para VIP, "
                "2 para SuperVip): ";
        cin >> nuevoTipo;
        cin.ignore();

        if (nuevoTipo < 0 || nuevoTipo > 2) {
          cout << "Error: cliente inválido, intente de nuevo\n";
        }
      } while (nuevoTipo < 0 || nuevoTipo > 2);

      clientes[i].setNombre(nuevoNombre);
      clientes[i].setId(nuevoId);
      clientes[i].setMembresia(static_cast<Cliente::tipoMembresia>(nuevoTipo));

      cout << "Cliente actualizado\n";
      break;
    }
  }
  if (!encontrado) {
    cout << "Error: Cliente no encontrado\n";
  }
}

void GestorMenu::listarClientes() {
  if (numClientes == 0) {
    cout << "No hay clientes registrados\n";
    return;
  }

  for (int i = 0; i < numClientes; i++) {
    cout << "Cliente " << i + 1 << ":\n";
    clientes[i].mostrarInfo();
    cout << "--------------------------\n";
  }
}
void GestorMenu::hacerReservas(){
  if(numClientes == 0){
    cout << "No hay clientes registrados\n";
    return;
  }
  int cantidad;
  std::cout << "cuantas reservas deseas hacer" << std::endl;
  cin >> cantidad;
  cin.ignore();

  if(numReservas + cantidad > maxReservas){
    cout << "El número de reservas excede el límite\n";
    return;
  }
  while (cantidad > 0){
    hacerReserva();
    cantidad--;
  }
}

void GestorMenu::hacerReserva(){
  cout << "Ingrese el nombre del cliente que hara la reserva: \n";
  for(int i = 0; i < numClientes; i++){
    cout << i + 1 << ". " << clientes[i].getNombre() << "ID: "<< clientes[i].getId() << endl;
  }

  int indiceCliente;
  cout << "Ingrese el número del cliente: ";
  cin >> indiceCliente;
  cin.ignore();

  if(indiceCliente < 1 || indiceCliente > numClientes){
    cout << "Error: Cliente inválido\n";
    return;
  }

  int dias;
  cout << "Ingrese el número de días de la reserva: ";
  cin >> dias;
  cin.ignore();

  int tipoPaquete;
  cout << "Los paquetes disponibles son: \n";
  cout << "1. Paquete Normal  Precio: 50\n";
  cout << "2. Paquete VIP  Precio 75\n";
  cout << "3. Paquete SuperVip()  100\n";
cout << "Ingrese el número del paquete: ";
  cin >> tipoPaquete;
  cin.ignore();

  if(tipoPaquete < 0 || tipoPaquete > 3){
    cout << "Error: Paquete inválido\n";
    return;
  }

  Reservas::paquetes paqueteSeleccionado = static_cast<Reservas::paquetes>(tipoPaquete);
  std::cout << "clientes" << clientes[indiceCliente - 1].getNombre() << std::endl;
  std::cout << "dias: " << dias << std::endl;
  std::cout << "paquete: " << (int) paqueteSeleccionado << std::endl;
  reservas[numReservas] = Reservas(clientes[indiceCliente - 1], dias, paqueteSeleccionado);
  reservas[numReservas].calcularCosto();

  cout << "Reserva almacenada: Cliente ID " << clientes[indiceCliente - 1].getId()
          << ", Dias: " << dias 
          << ", Costo Total: " << reservas[numReservas].getCostoTotal() << "\n";

  cout << "Reserva realizada\n";
  numReservas++;
}

void GestorMenu::listarReservas(){
  if(numReservas == 0){
    cout << "No hay reservas realizadas\n";
    return;
  }

  for(int i = 0; i < this->numReservas; i++){
    std::cout << this->numReservas << std::endl;
    cout << "Reserva " << i + 1 << ":\n";
    reservas[i].mostrarReserva();
    cout << "--------------------------\n";
  }
}

void GestorMenu::actualizarReserva(){
  this->listarReservas();
  int indiceReserva;
  std::cout << "ingrese el numero de la reserva que deseas actualizar:";
  cin >> indiceReserva;
  cin.ignore();
  indiceReserva--;
  if(indiceReserva < 0 || indiceReserva > this->numReservas){
    std::cout << "reserva a actualizar ingresada esta mal";
    return;
  }
  // ya tienes el indice entonces haz operaciones para setear
}
