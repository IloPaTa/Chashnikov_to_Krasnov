#ifndef POSTGRES_STORAGE_H
#define POSTGRES_STORAGE_H

#include "storage.h"
#include <iostream>
#include <unordered_map>

class PostgresStorage : public Storage {
private:
    std::unordered_map<std::string, std::string> data;
    
public:
    void save(const std::string& key, const std::string& value) override {
        data[key] = value;
        std::cout << "[POSTGRES] INSERT INTO storage (key, value) VALUES ('" 
                  << key << "', '" << value << "')" << std::endl;
    }
    
    std::string get(const std::string& key) override {
        if (data.count(key) == 0) {
            throw std::runtime_error("key not found");
        }
        std::cout << "[POSTGRES] SELECT value FROM storage WHERE key='" 
                  << key << "'" << std::endl;
        return data[key];
    }
};

#endif#pragma once
