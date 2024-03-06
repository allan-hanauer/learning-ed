#include <iostream>
#include <vector>



template<typename K, typename V>
class HashTable {
private:
    std::vector<std::pair<K, V>> table;
    size_t size;

public:
    HashTable() : size(0) {}

    void insert(const K& key, const V& value) {
        table.push_back(std::make_pair(key, value));
        size++;
    }

    bool remove(const K& key) {
        for (auto it = table.begin(); it != table.end(); ++it) {
            if (it->first == key) {
                table.erase(it);
                size--;
                return true;
            }
        }
        return false;
    }
    V* find(const K& key) {
        for (auto& entry : table) {
            if (entry.first == key) {
                return &entry.second;
            }
        }
        return nullptr;
    }
    size_t getSize() const {
        return size;
    }
};

int main() {
    HashTable<int, int> ht;

    ht.insert(5, 10);
    ht.insert(15, 20);
    ht.insert(25, 30);

    std::cout << "Tamanho: " << ht.getSize() << std::endl;

    int* val = ht.find(15);
    if (val) {
        std::cout << "Valor da chave 15: " << *val << std::endl;
    } else {
        std::cout << "Chave 15 não encontrada" << std::endl;
    }

    ht.remove(15);
    std::cout << "Tamanho depois de remover: " << ht.getSize() << std::endl;

    return 0;
}
