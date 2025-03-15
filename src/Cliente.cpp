#include "../include/Cliente.hpp"
#include <iomanip>  
#include <iostream>
#include <string>

using namespace std;

Cliente::Cliente() {}

Cliente::Cliente(string nombre, string id, tipoMembresia membresia)
    : nombre(nombre), id(id), membresia(membresia) {}

void Cliente::setMembresia(tipoMembresia nuevaMembresia) {
  membresia = nuevaMembresia;
}

Cliente::tipoMembresia Cliente::getMembresia() const { return membresia; }

double Cliente::getDescuento() const {
  switch (membresia) {
  case tipoMembresia::Vip:
    return 0.90; // 10% de descuento
  case tipoMembresia::superVip:
    return 0.70; // 30% de descuento
  default:
    return 1.0;
  }
}

void Cliente::setNombre(string nuevoNombre) { nombre = nuevoNombre; }

string Cliente::getNombre() const { return nombre; }

void Cliente::setId(string nuevaId) { id = nuevaId; }

string Cliente::getId() const { return id; }

void Cliente::mostrarInfo() {
  cout << "Su nombre es: " << getNombre() << endl;
  cout << "Su ID es: " << getId() << endl;
  cout << "Su tipo es: ";

  switch (membresia) {
  case tipoMembresia::Normal:
    cout << "Normal \n";
    break;
  case tipoMembresia::Vip:
    cout << "Vip \n";
    break;
  case tipoMembresia::superVip:
    cout << "SuperVip \n";
    break;
  }
}
