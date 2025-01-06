#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V>
class TableEntry {
private:
    std::string key;
    V value;
    bool hasValue;

public:
    // Constructor con clave y valor
    TableEntry(std::string key, V value) : key(key), value(value), hasValue(true) {}

    // Constructor solo con clave
    TableEntry(std::string key) : key(key), hasValue(false) {}

    // Constructor por defecto
    TableEntry() : key(""), hasValue(false) {}

    // Sobrecarga del operador ==
    friend bool operator==(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key == te2.key;
    }

    // Sobrecarga del operador !=
    friend bool operator!=(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return !(te1 == te2);
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& out, const TableEntry<V>& te) {
        if (te.hasValue) {
            out << te.key << " -> " << te.value;
        } else {
            out << te.key << " -> [No Value]";
        }
        return out;
    }

    // Métodos adicionales (opcionales)
    std::string getKey() const { return key; }
    V getValue() const { 
        if (!hasValue) {
            throw std::runtime_error("No value associated with this entry");
        }
        return value; 
    }
    bool valueExists() const { return hasValue; }
};

#endif // TABLEENTRY_H

