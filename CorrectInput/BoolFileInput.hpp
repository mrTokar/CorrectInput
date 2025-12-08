#include "BaseFileInput.hpp"
#include "BoolInputStream.h"

class BoolFileInput :
	public virtual BaseFileInput<bool>,
	public virtual BoolInputStream
{
protected:
	bool read(string& var) { return BaseFileInput<bool>::read(var); }
	bool isCorrectType(string const& data) override { return BoolInputStream::isCorrectType(data); }
	void changeType(bool& var, string const& data) override { BoolInputStream::changeType(var, data); }
public:
	BoolFileInput(ifstream& fin) : BaseFileInput<bool>(fin), BoolInputStream() {}
	BoolFileInput(string filename) : BaseFileInput<bool>(filename), BoolInputStream() {}

	using BoolInputStream::get;
};

