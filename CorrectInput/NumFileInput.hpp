#pragma once
#include "NumInputStream.hpp"
#include "BaseFileInput.hpp"


template<typename NUM>
class NumFileInput :
	public BaseFileInput<NUM>,
	public NumInputStream<NUM>
{
protected:
	bool read(string& var) { return BaseFileInput<NUM>::read(var); }
	bool isCorrectType(string const& data) override { return NumInputStream<NUM>::isCorrectType(data); }
	void changeType(NUM& var, string const& data) override { NumInputStream<NUM>::changeType(var, data); }
public:
	NumFileInput(ifstream& fin) : BaseFileInput<NUM>(fin), NumInputStream<NUM>() {}
	NumFileInput(string filename) : BaseFileInput<NUM>(filename), NumInputStream<NUM>() {}

	using NumInputStream<NUM>::get;
};