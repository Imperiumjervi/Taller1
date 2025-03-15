#include "../include/Reservas.hpp"
#include <iostream>
#include <string>

using namespace std;

Reservas::Reservas() : cliente(Cliente()) {
  dias = 0;
  tipoPaquetes = paquetes::Paquete1;
  costoTotal = 0;
}

Reservas::Reservas( Cliente& cliente, int dias, paquetes tipoPaquetes)
    : cliente(cliente), dias(dias), tipoPaquetes(tipoPaquetes), costoTotal(0) {
      calcularCosto();
    }

double Reservas::getPrecio(paquetes tipoPaquetes) {
  switch (tipoPaquetes) {
  case paquetes::Paquete1:
    return precioNormal;
  case paquetes::Paquete2:
    return precioVip;
  case paquetes::Paquete3:
    return precioSuperVip;
  default:
    return 0.0;
  }
}

void Reservas::calcularCosto() {
  double descuento = cliente.getDescuento();
  double precioBase = getPrecio(tipoPaquetes);
  costoTotal = precioBase * dias * descuento;
}

double Reservas::getCostoTotal() const { return costoTotal; }

void Reservas::mostrarReserva() {
  cout << "Cliente: " << cliente.getNombre() << endl;
  cout << "Dias: " << dias << endl;
  cout << "Costo total: " << costoTotal << endl;
}

void Reservas::setCliente( Cliente& cliente) { this->cliente = cliente; }
void Reservas::setDias(int dias) { this->dias = dias; }
void Reservas::setTipoPaquete(paquetes tipoPaquetes) { this->tipoPaquetes = tipoPaquetes; }
