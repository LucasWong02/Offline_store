#ifndef CARRITO_H
#define CARRITO_H
#include <string>
#include "ProductoAlmacen.h"
#include "ProductoCarrito.h"
#include "Almacen.h"

using namespace std;

class Carrito{
private:
    string usuario;
    ProductoCarrito producto[10];
    int size;

public:
    Carrito();
    int setCompra(string id, string nombre, double precio, int cantidad);
    void setUsuario(string usuario);
    string showUsuario();
    double total(int cantidad);
    void showCarrito();
    void editarCarro(string pin,int cantidad);
    void eraseCarrito();
    string ID(int i);
    int cant(int i);
  
};

#endif