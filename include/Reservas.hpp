#pragma once
#include "Cliente.hpp"
#include <iostream>
#include <string>

using namespace std;

class Reservas {
public:
  Reservas();
  enum class paquetes { Paquete1, Paquete2, Paquete3 };

  //usar 

  Reservas &operator=(const Reservas &otra);

private:
  int dias;
  string fecha;
  const double precioNormal = 50.0;
  const double precioLarge = 75.0;
  const double precioRoyal = 100.0;
  int costoTotal;
  paquetes tipoPaquete;

  // enum tipoMembresia && enum paquetes = precioTotal del paquete con
  // o sin descuentos

  // P && Q = true para que esto aplique el descuento

public:
  Reservas(int dias, string fecha, paquetes tipoPaquete);
  double getPrecio(paquetes tipoPaquete);
  void setDias(int nuevoDias);
  int getDias();
  void setFecha(string nuevaFecha);
  string getFecha() const;
  void mostarReserva();
};
