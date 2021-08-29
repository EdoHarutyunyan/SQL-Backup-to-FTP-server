#pragma once

#include <vector>

namespace sqlhelper
{

class ISQLHelper
{
public:
	virtual ~ISQLHelper() = default;

	virtual bool CreateTable() = 0;
	virtual bool Insert() = 0;
	virtual std::vector<std::string> QueryAll() = 0;
};

} // namespace sqlhelper