// Meter todos los menus y opciones aqui para que el codigo sea mas legible y el
// main no este lleno

#include "../include/GestorMenu.hpp"

GestorMenu::GestorMenu() {}

GestorMenu::GestorMenu(int numClientes, int numReservas)
    : numClientes(numClientes), numReservas(numReservas) {}

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

void GestorMenu::crearReserva() {
  if (numClientes == 0) {
    cout << "No hay clientes registrados\n";
    return;
  }

  string idBuscar;
  cout << "Ingrese el ID del cliente a hacer la reserva: ";
  getline(cin, idBuscar);

  bool encontrado = false;

  for (int i = 0; i < numClientes; i++) {
    if (clientes[i].getId() == idBuscar) {
      encontrado = true;

      cout << "Cliente encontrado. Ingrese los datos de la reserva:\n";

      int dias;
      string fecha;
      int tipoPaquete;

      cout << "Ingrese la cantidad de días: ";
      cin >> dias;
      cin.ignore();
      cout << "Ingrese la fecha de la reserva: ";
      getline(cin, fecha);

      do {
        cout << "ingrese el paquete que desea: \n";
        cout << "0 - Paquete normal \n";
        cout << "1 - Paquete Large \n";
        cout << "2 - Paquete Royal \n";
        cin >> tipoPaquete;
        cin.ignore();

        if (tipoPaquete < 0 || tipoPaquete > 2) {
          cout << "Error: Paquete inválido, intente de nuevo\n";
        }

      } while (tipoPaquete < 0 || tipoPaquete > 2);

      reservas[numReservas] =
          Reservas(dias, fecha, static_cast<Reservas::paquetes>(tipoPaquete));
      numReservas++;

      cout << "Reserva creada\n";
      break;
    }
  }
}
