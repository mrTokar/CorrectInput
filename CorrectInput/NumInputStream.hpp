#pragma once
#include "pch.h"
#include "BaseInputStream.hpp"

using namespace std;

namespace template_num{
	template<typename T>
	concept numbers = integral<T> && !is_same_v<T, bool>;
}

template<template_num::numbers NUM>
class NumInputStream: 
	public BaseInputStream<NUM>
{
protected:
	using BaseInputStream<NUM>::logger;
	int min_value = numeric_limits<NUM>::min();
	int max_value = numeric_limits<NUM>::max();

	NumInputStream() : BaseInputStream<NUM>() {}

	bool isCorrectType(string const& data) override {
		for (auto& c : data)
		{
			if (!isdigit(c) && c != '-') {
				return false;
			}
		}
		return true;
	}

	void changeType(NUM& var, string const& data) override {
		var = stoi(data);
	}

	bool canUse(NUM& num)
	{
		if (num < min_value) {
			if (logger[logs::INT_SIZE]) clog << "The value should be more than " << min_value << endl;
			return false;
		}
		if (num > max_value) {
			if (logger[logs::INT_SIZE]) clog << "The value should be less than " << max_value << endl;
			return false;
		}
		return true;
	}

public:
	NumInputStream(istream& in) : BaseInputStream<NUM>(in) {};

	bool get(NUM& var) override {
		return BaseInputStream<NUM>::get(var) && canUse(var);
	}

	inline void setMin(int value) { min_value = value; };
	inline void setMax(int value) { max_value = value; };
};
