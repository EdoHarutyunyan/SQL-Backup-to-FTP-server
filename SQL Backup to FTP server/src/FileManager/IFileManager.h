#pragma once

#include <vector>
#include <string>
#include <fstream>

namespace filemanager
{

class IFileManager
{
public:
	virtual ~IFileManager() = default;

	virtual std::vector<std::string> ReadFromFile(const std::string& path) = 0;
	virtual void WriteToFile(const std::string& path, const std::vector<std::string>& lines) = 0;
};

} // namespace filemanager