#include <iostream>
#include "storage_factory.h"

int main() {
    try {
        // Создаем хранилища через фабрику
        Storage* memory_storage = new_storage("memory");
        Storage* postgres_storage = new_storage("postgres");

        // Работаем с MemoryStorage
        memory_storage->save("username", "john_doe");
        std::string value = memory_storage->get("username");
        std::cout << "Got value: " << value << std::endl;

        // Пробуем получить несуществующий ключ
        try {
            memory_storage->get("nonexistent");
        }
        catch (const std::exception& e) {
            std::cout << "Expected error: " << e.what() << std::endl;
        }

        // Работаем с PostgresStorage
        postgres_storage->save("email", "example@example.com");
        value = postgres_storage->get("email");
        std::cout << "Got value: " << value << std::endl;

        // Тестируем ошибку фабрики
        Storage* unknown = new_storage("redis");

        // Освобождаем память
        delete memory_storage;
        delete postgres_storage;

    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}