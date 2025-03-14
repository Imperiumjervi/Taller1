// Meter todos los menus y opciones aqui para que el codigo sea mas legible y el
// main no este lleno

#pragma once
#include "Reservas.hpp"
#include "Cliente.hpp"
#include <iostream>
#include <string>

const int maxClientes = 100;
const int maxReservas = 100;

class GestorMenu {
  public:
    GestorMenu();

private:
  Cliente clientes[maxClientes];
  Reservas reservas[maxReservas];
  int numClientes;
  int numReservas;

public: 
  void mostrarMenu();
  void registrarClientes();
  void actualizarCliente();
  void listarClientes();
  void hacerReserva();
  void listarReservas();
};
