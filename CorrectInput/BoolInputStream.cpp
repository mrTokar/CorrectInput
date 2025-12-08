#include "pch.h"
#include "BoolInputStream.h"

BoolInputStream::BoolInputStream(istream& in): BaseInputStream<bool>(in)
{
}

void BoolInputStream::changeType(bool& var, string const& data)
{
	if (data.size() == 1) {
		var = stoi(data);
	}
	var = (data == "true");
}

bool BoolInputStream::isCorrectType(string const& data)
{
	if (data.size() == 1) {
		return (data == "1" || data == "0");
	}
	return (data == "true" || data == "false");
}