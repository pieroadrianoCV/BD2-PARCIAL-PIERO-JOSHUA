#ifndef DISK_MANAGER_H
#define DISK_MANAGER_H

#include <string>

class DiskManager {
public:
    static bool checkSpace(const std::string& sectorPath, const std::string& newRecord);
    static void createNewRecord(const std::string& sectorPath, const std::string& newRecord);
};

#endif // DISK_MANAGER_H
