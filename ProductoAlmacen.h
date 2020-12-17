#ifndef PRODUCTOALMACEN_H
#define PRODUCTOALMACEN_H
#include <string>
using namespace std;

class ProductoAlmacen{
    private:
        string id;
        string nombre;
        double precio;
        int existencia;
public:
    ProductoAlmacen();
    ProductoAlmacen(string id,string nombre,double precio,int existencia);
    void set_id(string id);
    void set_nombre(string nombre);
    void set_precio(double precio);
    void set_existencia(int existencia);
    string get_id();
    string get_nombre();
    double get_precio();
    int get_existencia();
    string toString();
};

#endif
