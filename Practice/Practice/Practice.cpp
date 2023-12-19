#include <iostream>
using namespace std;

static void populate(int myarray[], int x) {    
    for (int i = 0; i < x; i++)
    {
        myarray[i] = i;
    }
}

static void imprime(int myarray[], int x) {    
    for (int i = 0; i < x; i++)
    {
        cout << "Index: " << myarray[i] << "\n";
    }
}

class Rectangulo {
private:
    float base;
    float altura;

public:
    // Constructor de la clase Rectangulo
    Rectangulo(float b, float h) {
        base = b;
        altura = h;
    }

    void setBase(float b) {
        base = b;
    }

    void setAltura(float h) {
        altura = h;
    }  

    float getBase() const {
        return base;
    }
    float getAltura() const {
        return altura;
    }

    // Función para calcular el área del rectángulo
     float calcularArea() {
        return base * altura;
    }
};

int main()
{
    const int x = 10;
    int myarray[x];
    std::cout << "Hello World!\n";
    std::cout << "Valores a generar: " << x << "\n";    
    populate(myarray, x);   // populate the array    
    imprime(myarray, x);    // show the array on screen

    int base, higth;
    cout << "\nGive me the base of the rectangule: ";
    cin >> base;
    cout << "\nGive me the higth of the rectangule: ";
    cin >> higth;
    cout << "The area is: " << (base * higth) << "\n";    

    Rectangulo rectangulo(base, higth); // instatiate class    
    cout << "The area with class is: " << rectangulo.calcularArea() << "\n";
    cout << "The base value is: " << rectangulo.getBase()<< "\n";
    cout << "The higth value is: " << rectangulo.getAltura() << "\n";
    rectangulo.setBase(10);
    rectangulo.setAltura(15);
    cout << "The area with values" << "("
        << rectangulo.getBase() << ","
        << rectangulo.getAltura() << ")"
        << "  is: " << rectangulo.calcularArea() << "\n";
    return 0;
}
