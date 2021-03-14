#include <iostream>
#include "stack.h"

using namespace std;

void Fill(Stack* stk, int size) {
	for (int i = 0; i < size; i++) {
		stk->push(rand() % 100 + 0.22);
	}
}


int main() {
	system("chcp 1251>nul");
	Stack stk;
	Fill(&stk, 12);
	cout << stk;
	cout << stk.size() << endl;

	return 0;
}