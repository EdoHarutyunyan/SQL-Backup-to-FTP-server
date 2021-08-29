#pragma once

#include "IFileManager.h"

namespace filemanager
{

class FileManager : public IFileManager
{
public:
	~FileManager() override = default;

	std::vector<std::string> ReadFromFile(const std::string& path) override;
	void WriteToFile(const std::string& path, const std::vector<std::string>& lines) override;

private:
	std::fstream m_file;
};

} // namespace filemanager