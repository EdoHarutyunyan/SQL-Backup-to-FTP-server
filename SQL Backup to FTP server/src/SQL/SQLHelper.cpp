#include "SQLHelper.h"

#include <stdexcept>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "sqlite3.h"

namespace
{

const std::string CreateTableStatement{
	"CREATE TABLE IF NOT EXISTS Employee("
	"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
	"NAME TEXT NOT NULL, "
	"SURNAME TEXT NOT NULL, "
	"AGE INT NOT NULL );" };

const std::string InsertStatement{ "INSERT INTO Employee(NAME, SURNAME, AGE) VALUES('Eduard', 'Harutyunyan', 22);" };
const std::string QueryAllStatement{ "SELECT * FROM Employee;" };

} // namespace

namespace sqlhelper
{

SQLHelper::SQLHelper(const std::string& dbPath) : m_dbPath(dbPath)
{
}

bool SQLHelper::CreateTable()
{
	const auto status = sqlite3_open(m_dbPath.c_str(), &m_db);

	if (0 != status)
	{
		throw std::invalid_argument{ sqlite3_errmsg(m_db) };
	}

	char* messaggeError;
	const auto exit = sqlite3_exec(m_db, CreateTableStatement.c_str(), NULL, 0, &messaggeError);

	if (exit != SQLITE_OK)
	{
		std::cerr << messaggeError << std::endl;
		sqlite3_free(messaggeError);
		sqlite3_close(m_db);
		return false;
	}

	sqlite3_close(m_db);

	return true;
}

bool SQLHelper::Insert()
{
	const auto status = sqlite3_open(m_dbPath.c_str(), &m_db);

	if (0 != status)
	{
		throw std::invalid_argument{ sqlite3_errmsg(m_db) };
	}

	// Fill DB with test data
	for (size_t i = 0; i < 100; ++i)
	{
		char* messaggeError;
		const auto exit = sqlite3_exec(m_db, InsertStatement.c_str(), NULL, 0, &messaggeError);

		if (exit != SQLITE_OK)
		{
			std::cerr << messaggeError << std::endl;
			sqlite3_free(messaggeError);
			sqlite3_close(m_db);
			return false;
		}
	}

	sqlite3_close(m_db);

	return true;
}

std::vector<std::string> SQLHelper::QueryAll()
{
	const auto status = sqlite3_open(m_dbPath.c_str(), &m_db);

	if (0 != status)
	{
		throw std::invalid_argument{ sqlite3_errmsg(m_db) };
	}

	const auto callback = [](void* data, int argc, char** argv, char** azColName)
	{
		auto* pVec = static_cast<std::vector<std::string>*>(data);

		for (int i = 0; i < argc; ++i)
		{
			pVec->emplace_back(argv[i]);
		}

		return 0;
	};

	std::vector<std::string> result;

	sqlite3_exec(m_db, QueryAllStatement.c_str(), callback, static_cast<void*>(&result), NULL);
	sqlite3_close(m_db);

	return result;
}

} // namespace sqlhelper