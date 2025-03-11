// Meter todos los menus y opciones aqui para que el codigo sea mas legible y el
// main no este lleno

#pragma once
#include "Cliente.hpp"
#include "Reservas.hpp"
#include <iostream>
#include <string>

const int maxClientes = 100;
const int maxReservas = 100;

class GestorMenu {
private:
  Cliente clientes[maxClientes];
  Reservas reservas[maxReservas];
  int numClientes;
  int numReservas;

public:
  GestorMenu();
  GestorMenu(int numClientes, int numReservas);
  void mostrarMenu();
  void registrarClientes();
  void actualizarCliente();
  void listarClientes();
  void crearReserva();
};
