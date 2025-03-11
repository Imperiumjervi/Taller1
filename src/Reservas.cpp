#include "../include/Reservas.hpp"
#include <iostream>
#include <string>

using namespace std;

Reservas::Reservas()
    : dias(0), fecha(""), costoTotal(0), tipoPaquete(paquetes::Paquete1) {}

Reservas::Reservas(int dias, string fecha, paquetes tipoPaquete)
    : dias(dias), fecha(fecha), tipoPaquete(tipoPaquete) {
  costoTotal = getPrecio(tipoPaquete) * dias;
}

Reservas &Reservas::operator=(const Reservas &otra) {
  if (this != &otra) { // Evitar auto-asignación
    dias = otra.dias;
    fecha = otra.fecha;
    tipoPaquete = otra.tipoPaquete;
    costoTotal = otra.costoTotal;
  }
  return *this;
}

double Reservas::getPrecio(paquetes tipoPaquete) {
  switch (tipoPaquete) {
  case paquetes::Paquete1:
    return precioNormal;
  case paquetes::Paquete2:
    return precioLarge;
  case paquetes::Paquete3:
    return precioRoyal;
  default:
    return 0.0;
  }
}

void Reservas::setDias(int nuevoDias) { dias = nuevoDias; }
int Reservas::getDias() { return dias; }
void Reservas::setFecha(string nuevaFecha) { fecha = nuevaFecha; }
string Reservas::getFecha() const { return fecha; }

void Reservas::mostarReserva() {
  cout << "Dias de reserva: " << getDias() << endl;
  cout << "Fecha de reserva: " << getFecha() << endl;
  cout << "precio del paquete: " << getPrecio(tipoPaquete) << endl;
}
