#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <algorithm>

// Función para validar si una expresión aritmética tiene balanceados los paréntesis
bool estanBalanceados(const std::string& expresion) {
    std::stack<char> pila;
    for (char ch : expresion) {
        if (ch == '(') {
            pila.push(ch);
        } else if (ch == ')') {
            if (pila.empty()) {
                return false;
            }
            pila.pop();
        }
    }
    return pila.empty();
}

// Función para evaluar una expresión en notación postfija
int evaluarPostfija(const std::string& expresion) {
    std::stack<int> pila;
    for (char ch : expresion) {
        if (std::isdigit(ch)) {
            pila.push(ch - '0');
        } else {
            int op2 = pila.top(); pila.pop();
            int op1 = pila.top(); pila.pop();
            switch (ch) {
                case '+': pila.push(op1 + op2); break;
                case '-': pila.push(op1 - op2); break;
                case '*': pila.push(op1 * op2); break;
                case '/': pila.push(op1 / op2); break;
            }
        }
    }
    return pila.top();
}

// Función para colocar un elemento en una posición determinada de la cola
void colarElemento(std::queue<int>& cola, int elemento, int posicion) {
    std::queue<int> tempCola;
    int currentPos = 0;

    while (!cola.empty() && currentPos < posicion) {
        tempCola.push(cola.front());
        cola.pop();
        currentPos++;
    }

    tempCola.push(elemento);

    while (!cola.empty()) {
        tempCola.push(cola.front());
        cola.pop();
    }

    cola.swap(tempCola);
}

// Función para simular la atención en un banco
void simularBanco(int& clientesAtendidos, int& clientesEsperando) {
    std::queue<int> cola;
    int tiempo_total = 4 * 3600; // 4 horas en segundos
    int tiempo_llegada = 30; // Cada 30 segundos llega un cliente
    int tiempo_atencion = 40; // Cada 40 segundos se atiende un cliente
    clientesAtendidos = 0;

    for (int tiempo = 0; tiempo <= tiempo_total; tiempo += tiempo_llegada) {
        cola.push(tiempo);
    }

    for (int tiempo = 0; tiempo <= tiempo_total; tiempo += tiempo_atencion) {
        if (!cola.empty()) {
            cola.pop();
            clientesAtendidos++;
        }
    }

    clientesEsperando = cola.size();
}

// Función para verificar si una lista es sublista de otra
bool esSublista(const std::list<int>& lst1, const std::list<int>& lst2) {
    auto it1 = lst1.begin();
    auto it2 = lst2.begin();

    while (it2 != lst2.end()) {
        auto tempIt1 = it1;
        auto tempIt2 = it2;

        while (tempIt1 != lst1.end() && tempIt2 != lst2.end() && *tempIt1 == *tempIt2) {
            ++tempIt1;
            ++tempIt2;
        }

        if (tempIt1 == lst1.end()) {
            return true;
        }

        ++it2;
    }

    return false;
}

// Función para verificar si dos listas son semejantes
bool sonSemejantes(const std::list<int>& lst1, const std::list<int>& lst2) {
    if (lst1.size() != lst2.size()) {
        return false;
    }

    std::list<int> sortedLst1 = lst1;
    std::list<int> sortedLst2 = lst2;

    sortedLst1.sort();
    sortedLst2.sort();

    return sortedLst1 == sortedLst2;
}

int main() {
    // Validación de paréntesis balanceados
    std::string expresionBalanceada = "((a+b)*c)";
    std::string expresionNoBalanceada = "((a+b)*c";
    std::cout << "Expresión \"" << expresionBalanceada << "\" balanceada: " 
              << (estanBalanceados(expresionBalanceada) ? "Sí" : "No") << std::endl;
    std::cout << "Expresión \"" << expresionNoBalanceada << "\" balanceada: " 
              << (estanBalanceados(expresionNoBalanceada) ? "Sí" : "No") << std::endl;

    // Evaluación de expresión en notación postfija
    std::string expresionPostfija = "231*+9-";
    std::cout << "Resultado de la expresión postfija \"" << expresionPostfija << "\": " 
              << evaluarPostfija(expresionPostfija) << std::endl;

    // Colocar elemento en una cola
    std::queue<int> cola;
    cola.push(1);
    cola.push(2);
    cola.push(3);
    colarElemento(cola, 99, 1);

    std::cout << "Cola después de insertar elemento en la posición 1: ";
    while (!cola.empty()) {
        std::cout << cola.front() << " ";
        cola.pop();
    }
    std::cout << std::endl;

    // Simulación de atención en un banco
    int clientesAtendidos, clientesEsperando;
    simularBanco(clientesAtendidos, clientesEsperando);
    std::cout << "Clientes atendidos en 4 horas: " << clientesAtendidos << std::endl;
    std::cout << "Clientes esperando en la cola al cabo de 4 horas: " << clientesEsperando << std::endl;

    // Verificación de sublista
    std::list<int> lst1 = {2, 3, 4};
    std::list<int> lst2 = {1, 2, 3, 4, 5};
    std::cout << "Lista lst1 es sublista de lst2: " 
              << (esSublista(lst1, lst2) ? "Sí" : "No") << std::endl;

    // Verificación de listas semejantes
    std::list<int> lst3 = {1, 2, 3, 4, 5};
    std::list<int> lst4 = {5, 4, 3, 2, 1};
    std::cout << "Las listas lst3 y lst4 son semejantes: " 
              << (sonSemejantes(lst3, lst4) ? "Sí" : "No") << std::endl;

    return 0;
}
