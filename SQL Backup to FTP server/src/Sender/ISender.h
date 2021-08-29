#pragma once
#include <string>

namespace sender
{

class ISender
{
public:
	virtual ~ISender() = default;

	virtual void Start(const std::string& path) = 0;
};

} // namespace sender