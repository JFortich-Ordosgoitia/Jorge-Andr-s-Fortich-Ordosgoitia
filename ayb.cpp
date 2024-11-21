#include <iostream>
#include <list>

int main() {
    // Crear una lista vacía
    std::list<int> myList;

    // Agregar elementos a la lista
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);
    myList.push_back(50);

    // Mostrar la lista inicial
    std::cout << "Lista inicial: ";
    for (const auto& elem : myList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Crear iterador al inicio de la lista
    auto it = myList.begin();
    std::cout << "Iterador al inicio: " << *it << std::endl;

    // Insertar elementos en diversas posiciones
    it = myList.begin(); // Reiniciar iterador al inicio
    ++it; // Mover al segundo elemento (20)
    myList.insert(it, 15); // Insertar 15 antes del segundo elemento
    
    it = myList.begin(); // Reiniciar iterador al inicio
    ++it; // Mover al segundo elemento (15)
    ++it; // Mover al tercer elemento (20)
    myList.insert(it, 25); // Insertar 25 antes del cuarto elemento
    
    it = myList.begin(); // Reiniciar iterador al inicio
    ++it; // Mover al segundo elemento (15)
    ++it; // Mover al tercer elemento (20)
    ++it; // Mover al cuarto elemento (25)
    ++it; // Mover al quinto elemento (30)
    myList.insert(it, 35); // Insertar 35 antes del sexto elemento

    // Mostrar la lista después de las inserciones
    std::cout << "Lista después de inserciones: ";
    for (const auto& elem : myList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Ubicar iterador en la cuarta posición (0-indexado)
    it = myList.begin(); // Reiniciar iterador al inicio
    std::advance(it, 3); // Mover al cuarto elemento (25)

    // Borrar el elemento en la cuarta posición
    it = myList.erase(it);

    // Mostrar la lista después de borrar
    std::cout << "Lista después de borrar el cuarto elemento: ";
    for (const auto& elem : myList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Verificar en qué posición queda el iterador
    std::cout << "El nuevo iterador apunta al elemento: ";
    if (it != myList.end()) {
        std::cout << *it << std::endl;
    } else {
        std::cout << "El iterador está al final de la lista" << std::endl;
    }

    return 0;
}
