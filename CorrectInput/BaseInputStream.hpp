#pragma once
#include "pch.h"

using namespace std;


template<typename T>
class BaseInputStream {
private:
	istream* in = nullptr;

protected:
	vector<bool> logger;

	BaseInputStream() : logger(logs::CNTLOG, true) {};
	void setStream(istream& in) { this->in = &in; };

	virtual bool isCorrectType(string const& data) = 0;
	virtual void changeType(T& var, string const& data) = 0;

	virtual bool read(string& var)
	{
		if (*in >> var) {
			return true;
		}
		return false;
	}

public:
	BaseInputStream(istream& in) : BaseInputStream() { this->in = &in; };

	virtual bool get(T& variable)
	{
		string input;
		if (read(input)) {
			if (isCorrectType(input)) {
				changeType(variable, input);
				return true;
			}
			else {
				if (logger[logs::NOT_INT]) clog << "Invalid symbol " << input << endl;
				return false;
			}
		}
		else {
			if (logger[logs::WITHOUT_DATA]) clog << "Not enought data" << endl;
			return false;
		}
		return true;
	}

	bool getVector(size_t cnt, vector<T>& array)
	{
		size_t cnt_read = 0;
		T input;
		array.clear();
		while (cnt_read < cnt && get(input)) {
			cnt_read++;
			array.push_back(input);
		}
		return (cnt_read == cnt);
	}
	bool getMatrix(size_t cnt_row, size_t cnt_col, vector<vector<T>>& matrix)
	{
		matrix.clear();
		vector<T> row;
		size_t cnt_read = 0;

		while (cnt_read < cnt_row && getVector(cnt_col, row))
		{
			cnt_read++;
			matrix.push_back(row);
		};
		return (cnt_read == cnt_row);
	}

	void disable_log(logs::log type) { logger[type] = false; };
	void enable_log(logs::log type) { logger[type] = true; }

};
