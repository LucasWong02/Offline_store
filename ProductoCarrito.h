#ifndef PRODUCTOCARRITO_H
#define PRODUCTOCARRITO_H
#include <string>
#include "ProductoAlmacen.h"
#include "Almacen.h"
using namespace std;

class ProductoCarrito{
    private:
        string id;
        string nombre;
        double precio;
        int cantidad;
    public:
        ProductoCarrito();
        ProductoCarrito(string id,string nombre,double precio,int cantidad);
        string get_id();
        string get_nombre();
        double get_precio();
        int get_existencia();
        void set_cantidad(int cantidad);
        string toString();
};


#endif