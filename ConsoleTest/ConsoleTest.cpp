#include "../CorrectInput/BoolInputStream.h"

int main() {
	BoolInputStream nsi(cin);
	bool data;
	nsi.get(data);
	cout << data;

	return 0;
}