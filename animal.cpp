// Apartado de librerias
#include <iostream>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Se inicia con la clase animal
class Animal {

    // Atributos privados de la clase Animal
    private:
        int patas;
        float peso;
        float altura;
        float velocidad;
    // Atributos necesarios en funciones de subclases
    protected:
        bool genero;
        bool crias = false;  
    public:
    // Constructor de la clase animal
    Animal(int NumPatas, float Peso, float Altura, float Velocidad, bool Genero)
    : patas(NumPatas), peso(Peso), altura(Altura), velocidad(Velocidad), genero(Genero) {}
   
    // Métodos de la clase animal

    void comer() { // Método destinado a la capacidad de comer del animal
        setlocale (LC_ALL, ""); // Apoyo de carácteres especiales de Unicode
        char Aacento = 225;

        int exitoComer = rand() % 3; // Se genera una probabilidad de fallo a través de un randomizador
        if (exitoComer == 0 || exitoComer == 1) {
            cout << "\nEl animal est" << Aacento << " comiendo." << endl;
        }
        else { // En caso de que el randomizador genere el caso de fallo, el amimal no comerá
            cout << "\nEl animal no ha encontrado que comer." << endl;
        }
    }

    void reproducirse() { // Método destinado a la capacidad de reproducirse del animal

        int exitoReproduccion = rand() % 5; // Se genera una probabilidad de fallo a través de un randomizador
        if (exitoReproduccion == 0)
        {
            cout << "\nEl animal ha encontrado una pareja para reproducirse." << endl;
            crias = true; // En caso de éxito, se le asigna un atributo nuevo
        }
        else { // En caso de que el randomizador genere el caso de fallo, el animal no se reproducirá
            cout << "\nEl animal no ha encontrado una pareja." << endl;
        }
    }

    void moverse() { // Método destinado a la capacidad de moverse del animal
        setlocale (LC_ALL, ""); // Apoyo de carácteres especiales de Unicode
        char Oacento = 243;

        // Se genera un número aleatorio del movimiento en posiciones x, y directamente proporcional a 
        // la velocidad del animal
        float posicionX = static_cast<float>(rand()) / RAND_MAX * velocidad;
        float posicionY = static_cast<float>(rand()) / RAND_MAX * velocidad;

        // Se le da la oportunidad de que el animal pueda dirigirse para atras, como para adelante
        int direccionX = rand() % 2;
        if (direccionX == 1){
            posicionX = -posicionX;
        }

        int direccionY = rand() % 2;
        if (direccionY == 1){
            posicionY = -posicionY;
        }

        // Se actualiza la posición del animal
        posicionX++;
        posicionY++;

        cout << "\nEl animal se movi" << Oacento << " hacia la posici" << Oacento << "n (";
        cout << posicionX << ", " << posicionY << ") en un lapso de una hora." << endl;
    }

};

// Se genera una subclase de un animal mamífero
class Mamifero : public Animal {
    
    public: 
    // Constructor de un animal mamífero
    Mamifero(int NumPatas, float Peso, float Altura, float Velocidad, bool Genero)
    : Animal(NumPatas, Peso, Altura, Velocidad, Genero) {}

    void cazar() { // Método que le da al mamífero, la oportunidad de cazar
        cout << "\nEl animal se encuentra cazando." << endl;
    }

    void amamantando() { // Método que le da al mamífero, la oportunidad de amamantar a sus crias

        // Si el animal se reprodujo con éxito, y ademas es una hembra, podrá amamantar        
        if (crias && genero == true) {

            setlocale (LC_ALL, ""); // Apoyo de carácteres especiales de Unicode
            char Oacento = 243; 
            
            cout << "\nEl animal amamant" << Oacento << " a sus crias." << endl;
        }
    }
};

// Se genera una subclase de un animal reptil
class Reptil : public Animal {
    
    public: 
    // Constructor de un animal reptil
    Reptil(int NumPatas, float Peso, float Altura, float Velocidad, bool Genero)
    : Animal(NumPatas, Peso, Altura, Velocidad, Genero) {}

    void tomandoSol() { // Método que le da al reptil, la oportunidad de tomar el sol
        setlocale (LC_ALL, ""); // Apoyo de carácteres especiales de Unicode
        char Aacento = 225;

        cout << "\nEl reptil est" << Aacento << " tomando el sol." << endl;
    }

    void mudandoPiel() { // Método que le da al reptil, la oportunidad de mudar
        int muda = rand() % 5;
        if (muda == 0) {
            cout << "\nEl reptil mudo de piel." << endl;
        }
        else { // En caso de que el randomizador genere el caso de fallo, el reptil no mudara
            cout << "\nEl reptil no necesita mudar." << endl;
        }
    }
};

int main (void) {
    setlocale (LC_ALL, ""); // Apoyo de carácteres especiales de Unicode
    char Eacento = 233;
    char Oacento = 243; 
    char Iacento = 237; 
    char Uacento = 250; 

    int eleccionCrear;
    int eleccionFinal;
    
    // Menú de selección
    cout << "\nBienvenido, eliga una opci" << Oacento << "n: " << endl;
    cout << "1. Crear mam" << Iacento << "fero." << endl;
    cout << "2. Crear reptil." << endl;
    cout << "3. Salir." << endl;
    cin >> eleccionCrear;

    if (eleccionCrear >= 3 || eleccionCrear < 1) // Se cierra el programa
    {
        std::exit(1);
    }

    // Variables asignables por el usuario
    string nombreAnimal;
    int patasA;
    float pesoA;
    float alturaA;
    float velocidadA;
    bool generoA;

    // Se le solicita al usuario asignar las variables
    cout << "\nIntroduzca el nombre: ";
    cin >> nombreAnimal;

    cout << "\nIntroduzca el n" << Uacento << "mero de patas, el peso, la altura y la velocidad (km/h). Separado por espacios." << endl;
    cin >> patasA >> pesoA >> alturaA >> velocidadA;

    cout << "\nIntroduzca el g" << Eacento << "nero del animal (0 hembra, >1 macho)" << endl;
    cin >> generoA;
    if (generoA <= 0) {
        generoA = true;
    }
    else {
        generoA = false;
    }

    Animal* animal; // Puntero para la clase animal

    switch (eleccionCrear) { // Se crea la subclase, dependiendo la selección del usuario
        case 1:
            animal = new Mamifero(patasA, pesoA, alturaA, velocidadA, generoA);
            break;
        case 2:
            animal = new Reptil(patasA, pesoA, alturaA, velocidadA, generoA);
            break;
        default:
            NULL;
    }
    
    bool i = true;
    while (i == true) // Ciclo que repite el menú de acciones
    {
        // Menú de acciones
        cout << "\nEliga una opci" << Oacento << "n para que el animal lo haga: " << endl;
        cout << "1. Comer." << endl;
        cout << "2. Reproducirse." << endl;
        cout << "3. Moverse." << endl;
        cout << "4. Exclusivas." << endl;
        cout << "5. Salir." << endl;
        cin >> eleccionFinal;

        switch (eleccionFinal) {

            case 1:
            animal->comer();
            break;

            case 2:
            animal->reproducirse();
            break;

            case 3:
            animal->moverse();
            break;

            case 4:
            cout << "\nAun no disponible." << endl;
            break;

            case 5: // Se cierra el ciclo
            i = false;
            break;
        }

    }

    delete animal;
    return 0;  
}
