#pragma once
#include "Cliente.hpp"
#include <iostream>
#include <string>

using namespace std;

class Reservas {  
public:
  Reservas();
  enum class paquetes { Paquete1=1, Paquete2, Paquete3 };

private:
  int dias;
  double precioNormal = 50.0;
  double precioVip = 75.0;
  double precioSuperVip = 100.0;
  int costoTotal;
  Cliente cliente;
  paquetes tipoPaquetes;

public:
  Reservas(Cliente& cliente, int dias, paquetes tipoPaquetes);
  double getPrecio(paquetes paqueteTipo);
  void calcularCosto();
  double getCostoTotal() const;
  void mostrarReserva();
  void setCliente( Cliente &cliente);
  void setDias(int dias);
  void setTipoPaquete(paquetes tipoPaquetes);
};
