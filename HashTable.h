#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <string>
#include <stdexcept>
#include <iostream>

template <typename V>
class HashTable {
private:
    std::vector<std::list<std::pair<std::string, V>>> table; // Tabla hash
    int n;   // Número de elementos almacenados
    int max; // Capacidad máxima de la tabla

    int h(std::string key) const; // Función hash

public:
    // Constructor
    HashTable(int size);

    // Destructor
    ~HashTable();

    // Devuelve la capacidad de la tabla
    int capacity() const;

    // Sobrecarga del operador de salida <<
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const HashTable<U>& th);

    // Sobrecarga del operador []
    V operator[](std::string key) const;
};

#endif // HASHTABLE_H

