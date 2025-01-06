#include <unordered_map>
#include <stdexcept>
#include <string>

template <typename V>
class Dict {
private:
    std::unordered_map<std::string, V> data;

public:
    // Inserta el par key->value en el diccionario.
    // Lanza std::runtime_error si key ya existe.
    void insert(std::string key, V value) {
        if (data.find(key) != data.end()) {
            throw std::runtime_error("Key already exists in the dictionary");
        }
        data[key] = value;
    }

    // Busca el valor correspondiente a key.
    // Devuelve el valor asociado si key existe, o lanza std::runtime_error si no.
    V search(std::string key) {
        auto it = data.find(key);
        if (it == data.end()) {
            throw std::runtime_error("Key not found in the dictionary");
        }
        return it->second;
    }

    // Elimina el par key->value si se encuentra en el diccionario.
    // Lanza std::runtime_error si key no se encuentra.
    V remove(std::string key) {
        auto it = data.find(key);
        if (it == data.end()) {
            throw std::runtime_error("Key not found in the dictionary");
        }
        V value = it->second;
        data.erase(it);
        return value;
    }

    // Devuelve el número de elementos en el diccionario.
    int entries() {
        return data.size();
    }
};

