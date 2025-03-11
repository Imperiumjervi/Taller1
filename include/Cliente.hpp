#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cliente {
public:
  Cliente();
  enum class tipoMembresia { Normal, Vip, superVip };

private:
  /*Al Cliente no le veo la necesidad de tener mas atributos personales
  debido a que, estos en si llegan a ser irrelevantes*/

  string nombre;
  string id;
  tipoMembresia membresia;

public:
  Cliente(string nombre, string id, tipoMembresia membresia);
  void setMembresia(tipoMembresia nuevoTipo);
  tipoMembresia getMembresia() const;
  double getDescuento() const;
  void setNombre(string nuevoNombre);
  string getNombre() const;
  void setId(string nuevoId);
  string getId() const;
  void mostrarInfo();
};
