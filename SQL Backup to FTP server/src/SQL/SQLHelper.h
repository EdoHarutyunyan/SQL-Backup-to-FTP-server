#pragma once

#include <string>
#include <functional>
#include <vector>

#include "ISQLHelper.h"

struct sqlite3;

namespace sqlhelper
{

class SQLHelper : public ISQLHelper
{
public:
	explicit SQLHelper(const std::string& dbPath);
	~SQLHelper() override = default;

	bool CreateTable() override;
	bool Insert() override;
	std::vector<std::string> QueryAll() override;

private:
	sqlite3* m_db{ nullptr };
	std::string m_dbPath;
};

} // namespace sqlhelper
