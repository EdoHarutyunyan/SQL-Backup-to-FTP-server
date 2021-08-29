#pragma once

#include <iostream>

#include "FileManager/IFileManager.h"
#include "Sender/ISender.h"
#include "SQL/ISQLHelper.h"

namespace db2ftpexporter
{

class DB2FTPExporter
{
public:
	DB2FTPExporter(const std::string& dbPath,
		const std::string& userName,
		const std::string& password,
		const std::string& ftpHost,
		uint8_t ftpPort,
		const std::string& remotePath);

	void Start();

private:
	std::shared_ptr<sqlhelper::ISQLHelper> m_sqlHelper;
	std::shared_ptr<filemanager::IFileManager> m_fileManager;
	std::shared_ptr<sender::ISender> m_sender;
};

} // namespace db2ftpexporter
