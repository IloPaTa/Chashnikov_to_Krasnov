#ifndef STORAGE_FACTORY_H
#define STORAGE_FACTORY_H

#include "storage.h"
#include "memory_storage.h"
#include "postgres_storage.h"
#include <stdexcept>

Storage* new_storage(const std::string& storage_type) {
    if (storage_type == "memory") {
        return new MemoryStorage();
    }
    else if (storage_type == "postgres") {
        return new PostgresStorage();
    }
    else {
        throw std::invalid_argument("unknown storage type");
    }
}

#endif