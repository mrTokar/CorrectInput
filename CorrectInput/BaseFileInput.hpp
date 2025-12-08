#include "BaseInputStream.hpp"

template<typename T>
class BaseFileInput :
	public: BaseInputStream<T>
{
private:
	ifstream & fin;

protected:
	using BaseFileInput<T>::logger;

	bool read(string& var) override
	{
		if (fin.is_open())
		{
			if (fin >> var) {
				return true;
			}
		}
		else {
			if (logger[logs::CLOSE_FILE]) clog << "File is close\n";
		}
		return false;
	}

public:
	BaseFileInput(ifstream& in) : fin(in) {}
	BaseFileInput(string filename) : fin(*(new ifstream(filename))) {}

	inline bool is_open() { return fin.is_open(); }

	~BaseFileInput() 
	{
		fin.close();
		ifstream* ptrfin = &fin;
		delete ptrfin;
	}
};