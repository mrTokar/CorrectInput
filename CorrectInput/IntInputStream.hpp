#pragma once
#include "pch.h"

using namespace std;


template<integral NUM>
class IntInputStream {
private:
	istream* in = nullptr;
	vector<bool> logger;

protected:
	int min_value = numeric_limits<NUM>::min();
	int max_value = numeric_limits<NUM>::max();

	IntInputStream(): logger(log::CNTLOG, true) {};
	void setStream(istream& in) { this->in = &in; };

	virtual bool read(string& var)
	{
		if (*in >> var) {
			return true;
		}
		return false;
	}

	bool isInt(string const& input)
	{
		for (auto& c : input)
		{
			if (!isdigit(c) && c != '-') {
				return false;
			}
		}
		return true;
	}
	
	bool canUse(NUM num)
	{
		if (num < min_value) {
			if (logger[log::INT_SIZE]) clog << "The value should be more than " << min_value << endl;
			return false;
		}
		if (num > max_value) {
			if (logger[log::INT_SIZE]) clog << "The value should be less than " << max_value << endl;
			return false;
		}
		return true;
	}
public:
	IntInputStream(istream& in): IntInputStream() { this->in = &in; };

	bool getInt(NUM& variable)
	{
		string input;
		if (read(input)) {
			if (isInt(input)) {
				variable = stoi(input);
				return canUse(variable);
			}
			else {
				if (logger[log::NOT_INT]) clog << "Invalid symbol " << input << endl;
				return false;
			}
		}
		else {
			if (logger[log::WITHOUT_DATA]) clog << "Not enought data" << endl;
			return false;
		}
		return true;
	}
	bool getVector(size_t cnt, vector<NUM>& array)
	{
		size_t cnt_read = 0;
		NUM input;
		array.clear();
		while (cnt_read < cnt && getInt(input)) {
			cnt_read++;
			array.push_back(input);
		}
		return (cnt_read == cnt);
	}
	bool getMatrix(size_t cnt_row, size_t cnt_col, vector<vector<NUM>>& matrix)
	{
		matrix.clear();
		vector<NUM> row;
		size_t cnt_read = 0;

		while (cnt_read < cnt_row && getVector(cnt_col, row))
		{
			cnt_read++;
			matrix.push_back(row);
		};
		return (cnt_read == cnt_row);
	}

	void setMin(NUM value) { min_value = value; };
	void setMax(NUM value) { max_value = value; };

	void disable_log(log::log type) { logger[type] = false; };
	void enable_log(log::log type) { logger[type] = true; }

};

