#ifndef STORAGE_H
#define STORAGE_H

#include <string>

class Storage {
public:
    virtual ~Storage() {}
    virtual void save(const std::string& key, const std::string& value) = 0;
    virtual std::string get(const std::string& key) = 0;
};

#endif