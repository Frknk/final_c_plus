#include <iostream>

using namespace std;

class Moto{
    private:
    // Atributos
    string codigo, marca, modelo, color, ano_fabricacion, cc;
    int kilometraje, precio;

    // Metodos
    public:
    // Constructor
    Moto (string _codigo, string _marca, string _modelo, string _color, string _ano_fabricacion, string _cc, int _kilometraje, int _precio) {
        codigo = _codigo;
        marca = _marca;
        modelo = _modelo;
        color = _color;
        ano_fabricacion = _ano_fabricacion;
        cc = _cc;
        kilometraje = _kilometraje;
        precio = _precio;
    }

    // Getters

    string getCodigo(){
        return codigo;
    }

    string getMarca(){
        return marca;
    }

    string getModelo(){
        return modelo;
    }

    string getColor(){
        return color;
    }

    string getAnoFabricacion(){
        return ano_fabricacion;
    }

    string getCc(){
        return cc;
    }

    int getKilometraje(){
        return kilometraje;
    }

    int getPrecio(){
        return precio;
    }

    // Setters

    void setPrecio(int _precio){
        precio = _precio;
    }

    void setKilometraje(int _kilometraje){
        kilometraje = _kilometraje;
    }

    void setCodigo(string _codigo){
        codigo = _codigo;
    }

    void setMarca(string _marca){
        marca = _marca;
    }

};