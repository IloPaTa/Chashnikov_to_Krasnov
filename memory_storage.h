#ifndef MEMORY_STORAGE_H
#define MEMORY_STORAGE_H

#include "storage.h"
#include <unordered_map>

class MemoryStorage : public Storage {
private:
    std::unordered_map<std::string, std::string> data;

public:
    void save(const std::string& key, const std::string& value) override {
        data[key] = value;
        std::cout << "[MEMORY] Saved " << key << "=" << value << std::endl;
    }

    std::string get(const std::string& key) override {
        auto it = data.find(key);
        if (it == data.end()) {
            throw std::runtime_error("key not found");
        }
        std::cout << "[MEMORY] Retrieved " << key << "=" << it->second << std::endl;
        return it->second;
    }
};

#endif