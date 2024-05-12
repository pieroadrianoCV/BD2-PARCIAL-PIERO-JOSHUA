#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <string>

class FileManager {
public:
    static std::string readFile(const std::string& fileName);
    static void writeFile(const std::string& fileName, const std::string& data);
};

#endif // FILE_MANAGER_H
