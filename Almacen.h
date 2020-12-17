#ifndef ALMACEN_H
#define ALMACEN_H
#include <string>
#include "ProductoAlmacen.h"
using namespace std;

class Almacen{
private:
    ProductoAlmacen productos[20];
    int size;
public:
    Almacen();
    void agregar();
    void show(Almacen A);
    ProductoAlmacen& getProducto(string ID);
    void removeProductos(string ID,int cantidad);
    
};

#endif