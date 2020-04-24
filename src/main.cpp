#include <iostream>
#include <string>
#include <cstring>

#include "Stack.h"

using namespace std;

struct DelimMap {
	string delim;
	int encoding;
};

DelimMap delim_encodings[] = {
  {"(", 1},
  {")", -1},
  {"<", 2},
  {">", -2},
  {"[", 3},
  {"]", -3},
  {"{", 4},
  {"}", -4} };

static int lookup_encodings(string input) {
	for (int i = 0; i < sizeof(delim_encodings) / sizeof(delim_encodings[0]); i++) {
		if (delim_encodings[i].delim == input) {
			return i;
		}
	}
	return -1;
}

void exit_err(int position) {
	cout << "unbalanced at argument " << position << endl;
	exit(EXIT_FAILURE);
}


int main(int argc, char* argv[]) {
	int i;
	Stack<int>* s = new Stack<int>();
	for (i = 1; i < argc; i++) {
		int map_index = lookup_encodings(argv[i]);
		if (map_index == -1) {
			exit_err(i - 1);
		}
		if (delim_encodings[map_index].encoding > 0) {
			s->push(delim_encodings[map_index].encoding);
		}
		if (delim_encodings[map_index].encoding < 0) {
			if (s->is_empty()) {
				exit_err(i - 1);
			}
			else if (delim_encodings[map_index].encoding != s->peek() * -1) {
				exit_err(i - 1);
			}
			else {
				s->pop();
			}
		}
	}
	if (!s->is_empty()) {
		exit_err(i - 1);
	}
}