#include "DB2FTPExporter.h"

#include "FileManager/FileManager.h"
#include "Sender/Sender.h"
#include "SQL/SQLHelper.h"

namespace db2ftpexporter
{

DB2FTPExporter::DB2FTPExporter(const std::string& dbPath,
	const std::string& userName,
	const std::string& password,
	const std::string& ftpHost,
	const uint8_t ftpPort,
	const std::string& remotePath)
	: m_sqlHelper{std::make_shared<sqlhelper::SQLHelper>(dbPath)}
	, m_fileManager{ std::make_shared<filemanager::FileManager>() }
	, m_sender{std::make_shared<sender::Sender>(userName, password, ftpHost, ftpPort, remotePath)}
{
}

void DB2FTPExporter::Start()
{
	if (!m_sqlHelper->CreateTable())
	{
		// Nothing to do if table creation failed
		return;
	}

	if (!m_sqlHelper->Insert())
	{
		// Nothing to do if insertion failed
		return;
	}

	const auto result = m_sqlHelper->QueryAll();

	// File-path is hardcoded here but can be also adjusted to receive as an input parameter
	const std::string path {"FileToSend.txt"};
	m_fileManager->WriteToFile(path, result);

	m_sender->Start(path);
}

} // namespace db2ftpexporter
