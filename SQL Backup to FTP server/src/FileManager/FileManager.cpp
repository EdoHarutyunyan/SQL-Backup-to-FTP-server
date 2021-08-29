#include "FileManager.h"

#include <iostream>

namespace filemanager
{

std::vector<std::string> FileManager::ReadFromFile(const std::string& path)
{
	std::ifstream fin(path);
	std::vector<std::string> file;
	std::string line;

	if (!fin.is_open())
	{
		std::cerr << "FileManager::ReadFromFile(): Problem during open " << path.c_str() << " file." << std::endl;
	}

	while (getline(fin, line))
	{
		file.push_back(line);
	}

	fin.close();
	return file;
}

void FileManager::WriteToFile(const std::string& path, const std::vector<std::string>& lines)
{
	std::ofstream fout(path);

	if (!fout.is_open())
	{
		std::cerr << "FileManager::WriteToFile(): Problem during open " << path.c_str() << " file." << std::endl;
	}

	for (const auto& line : lines)
	{
		fout << line << std::endl;
	}

	fout.close();
}

} // namespace filemanager