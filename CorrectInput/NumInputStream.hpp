#pragma once
#include "BaseInputStream.hpp"

using namespace std;

template<typename T>
concept numbers = integral<T> && !is_same_v<T, bool>;

template<numbers NUM>
class IntInputStream: 
	public BaseInputStream<NUM>
{
protected:
	int min_value = numeric_limits<NUM>::min();
	int max_value = numeric_limits<NUM>::max();

	bool isCorrectType(string const& data) override {
		for (auto& c : data)
		{
			if (!isdigit(c) && c != '-') {
				return false;
			}
		}
		return true;
	}

	void chageType(NUM& var, string const& data) override {
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
	bool get(NUM& var) override {
		return BaseInputStream::get(var) && canUse(NUM& var);
	}

	inline void setMin(int value) { min_value = value; };
	inline void setMax(int value) { max_value = value; };
};

