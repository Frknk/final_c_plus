#include <iostream>

using namespace std;

class Repuesto
{
protected:
    // Atributos
    string codigo, descripcion, fecha_registro, categoria;
    int precio, stock, tiempo_demora;

    // Metodos
public:
    // Constructor
    Repuesto(string _codigo, string _descripcion, string _fecha_registro, int _precio, int _stock, string _categoria)
    {
        codigo = _codigo;
        descripcion = _descripcion;
        fecha_registro = _fecha_registro;
        precio = _precio;
        stock = _stock;
        categoria = _categoria;
    }

    // Getters
    string getDescripcion()
    {
        return descripcion;
    }

    string getCodigo()
    {
        return codigo;
    }

    string getFechaRegistro()
    {
        return fecha_registro;
    }

    string getCategoria()
    {
        return categoria;
    }

    int getPrecio()
    {
        return precio;
    }

    int getStock()
    {
        return stock;
    }

    // Setters
    void setPrecio(int _precio)
    {
        precio = _precio;
    }

    void setStock(int _stock)
    {
        stock = _stock;
    }

    string getDatos(){
        return "Codigo: " + codigo + "\nDescripcion: " + descripcion + "\nFecha de registro: " + fecha_registro + "\nPrecio: " + to_string(precio) + "\nStock: " + to_string(stock) + "\nCategoria: " + categoria;
    }
};