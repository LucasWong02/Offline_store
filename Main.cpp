#include "ProductoAlmacen.h"
#include "Almacen.h"
#include "ProductoCarrito.h"
#include "Carrito.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;
ProductoAlmacen::ProductoAlmacen(){
    this->id="";
    this->nombre="";
    this->precio=0;
    this->existencia=0;
}

ProductoAlmacen::ProductoAlmacen(string id,string nombre,double precio,int existencia){
    this->id=id;
    this->nombre=nombre;
    this->precio=precio;
    this->existencia=existencia;
}

void ProductoAlmacen::set_id(string id){
    this->id=id;
}

void ProductoAlmacen::set_nombre(string nombre){
    this->nombre=nombre;
}

void ProductoAlmacen::set_precio(double precio){
    this->precio=precio;
}

void ProductoAlmacen::set_existencia(int existencia){
    this->existencia=existencia;
}

string ProductoAlmacen::get_id(){
    return this->id;
}

string ProductoAlmacen::get_nombre(){
    return this->nombre;
}

double ProductoAlmacen::get_precio(){
    return this->precio;
}

int ProductoAlmacen::get_existencia(){
    return this->existencia;
}

string ProductoAlmacen::toString(){
    string x1=this->id;
    string y1=this->nombre;
    string x2=to_string(this->precio);
    string y2=to_string(this->existencia);

    return "("+x1+","+y1+","+x2+","+y2+")";
}
Almacen::Almacen(){
    this->size=0;
    ProductoAlmacen A;
    ifstream lector("Productos.txt");
    string line;
    while (getline(lector,line))
    {
        string id, nombre, mp, me;
        double precio;
        int existencia;
        stringstream ss(line);
        getline(ss,id,',');
        getline(ss,nombre,',');
        getline(ss,mp,',');
        precio = stoi(mp);
        getline(ss,me,',');
        existencia = stoi(me);
        this->productos[this->size]= ProductoAlmacen(id,nombre,precio,existencia);
        this->size+=1;
    }
    
}

void Almacen::show(Almacen A){
    for(int i=0;i<=this->size;i++){
        string y = this->productos[i].toString();
        cout<< y <<endl;
    }
}
ProductoAlmacen& Almacen::getProducto(string ID){
    for(int i=0;i<this->size;i++){
        if(this->productos[i].get_id() == ID){
            return this->productos[i];
        }
    }
    ProductoAlmacen A("","",0.0,0);
    return A;
}

void Almacen::removeProductos(string ID,int cantidad){
    for(int i=0;i<this->size;i++){
        if(this->productos[i].get_id() == ID){
            this->productos[i].set_existencia(this->productos[i].get_existencia()-cantidad);
        }
    }
}
ProductoCarrito::ProductoCarrito(string id,string nombre,double precio,int cantidad){
    this->id=id;
    this->nombre=nombre;
    this->precio=precio;
    this->cantidad=cantidad;
}
ProductoCarrito::ProductoCarrito(){
    this->id="";
    this->nombre="";
    this->precio=0;
    this->cantidad=0;
}
string ProductoCarrito::get_id(){
    return this->id;
}

string ProductoCarrito::get_nombre(){
    return this->nombre;
}

double ProductoCarrito::get_precio(){
    return this->precio;
}

int ProductoCarrito::get_existencia(){
    return this->cantidad;
}

void ProductoCarrito::set_cantidad(int cantidad){
    this->cantidad=cantidad;
}
string ProductoCarrito::toString(){
    string x1=this->id;
    string y1=this->nombre;
    string x2=to_string(this->precio);
    string y2=to_string(this->cantidad);

    return "("+x1+","+y1+","+x2+","+y2+")";
}

Carrito::Carrito(){
    string id="", nombre="";
    double precio = 0.0;
    int cantidad = 0;
    this->size = 0;
    this->usuario = "";
    this->producto[this->size] = ProductoCarrito(id,nombre,precio,cantidad);
}
    
int Carrito::setCompra(string id, string nombre, double precio, int cantidad){
    double sum = 0.0;
    this->producto[this->size]=ProductoCarrito(id,nombre,precio,cantidad);
    sum+=(producto[this->size].get_precio())*cantidad;
    cout<<"El precio total seria: "+to_string(sum)<<endl;
    this ->size+=1;
    return sum;
}

void Carrito::editarCarro(string pin,int cantidad){
    for(int i=0;i<=this->size;i++){
        if(this->producto[i].get_id()==pin){
            if(this->producto[i].get_existencia()>cantidad){
                this->producto[i].set_cantidad(cantidad);
            }
            else{
                cout<<"El almacen no tiene tantos elementos."<<endl;
            }
        }
    }
}

void Carrito::showCarrito(){
    for(int i=0;i<=this->size;i++){
        string y = this->producto[i].toString();
        cout<< y <<endl;
    }
}

string Carrito::showUsuario(){
    return this->usuario;
}

void Carrito::setUsuario(string usuario){
    this->usuario = usuario;
}

void Carrito::eraseCarrito(){
    for(int i=0;i<=this->size;i++){
        this->producto[i]=ProductoCarrito("","",0.0,0);
    }
    this->size = 0;
}

string Carrito::ID(int i){
    return this->producto[i].get_id();
}
int Carrito::cant(int i){
    return this->producto[i].get_existencia();
}

void Menu(Almacen A, Carrito B, string usuario){  
    int contador = 0;
    int x;
    int sum;
    int total=0;
    while(x!=6){
        cout<<"Bienvenido a la Tienda Offline"<<endl;
        cout<<"1) Ver productos"<<endl;
        cout<<"2) Comprar"<<endl;
        cout<<"3) Ver carrito"<<endl;
        cout<<"4) Editar"<<endl;
        cout<<"5) Pagar"<<endl;
        cout<<"6) Salir"<<endl;
        cout <<"Que desea hacer? Escoger un numero: ";
        cin >> x;

        if(x==1){
            A.show(A);
            B.setUsuario(usuario);
            cout<<""<<endl;
        }
        if(x==2){
            string id;
            int cant;
            cout<<"Introduzca el ID y la cantidad que desee: ";
            cin>>id>>cant;
            ProductoAlmacen p;
            p=A.getProducto(id);
            string id2 = p.get_id();
            string nombre = p.get_nombre();
            double precio = p.get_precio();
            int cantidad = p.get_existencia();
            if(id2 == id){
                if(cantidad>=cant){
                    sum = B.setCompra(id2, nombre, precio, cant);
                    total += sum;
                    contador+=1;
                }
                else{
                    cout<<"El almacen no tiene tantos elementos."<<endl;
                }
            }
            else{
                cout<<"No hay ningun producto con ese ID"<<endl;
            }
            
            cout<<""<<endl;
            
            //return Menu(); 
        }
        if(x==3){
            cout<<"Carrito de compras de: " + B.showUsuario()<<endl;
            cout<<"       MI CARRITO"<<endl;
            B.showCarrito();
            cout<<""<<endl;
            //return Menu();
        }
        if(x==4){
            string id2;
            int cant2;
            ProductoAlmacen p2;
            cout<<"Introduzca el ID y la cantidad que desee cambiar: ";
            cin>>id2>>cant2;
            p2=A.getProducto(id2);
            string id3 = p2.get_id();
            if(id3 != ""){
                B.editarCarro(id3,cant2);
            } 
            else{
                cout<<"No hay ningun producto con ese ID"<<endl;
            }
            cout<<""<<endl;
        }
        if(x==5){
            string respuesta;
            int cantidad;
            string ID;
            cout<<"Estas seguro/a que desea pagar?(Si/No): ";
            cin >> respuesta;
            if(respuesta =="Si"){
                cout<<"El monto total a pagar es de: ";
                cout<<total<<endl;
                for(int i = 0;i<contador;i++){
                    ID = B.ID(i);
                    cantidad = B.cant(i);
                    A.removeProductos(ID,cantidad);
                }
                B.eraseCarrito();
                cout<<"Muchas gracias por su compra!!!"<<endl;
            }
            else if(respuesta == "No"){
                //return Menu();
            }
            cout<<""<<endl;
        }
        if(x==6){
            
        }
    }
}

int main(){
    Almacen A;
    Carrito B;
    string usuario;
    cout<<"Cual es su nombre?: ";
    cin>>usuario;
    Menu(A,B,usuario);
}
