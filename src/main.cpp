#include <iostream>
#include <string>
#include <cstring>

#include "Stack.h"
#include "DelimiterMap.h"

using namespace std;

static int lookup_encodings(string input, DelimiterMap * delim_encodings, int size) {
	for (int i = 0; i < size; i++) {
		if (delim_encodings[i].delim == input) {
			return i;
		}
	}
	return -1;
}

static void exit_err(int position) {
	cout << "unbalanced at argument " << position << endl;
	exit(EXIT_FAILURE);
}


int main(int argc, char* argv[]) {
	if (argc == 1) {
		std::cout << "Usage: ./delim [delimiters...]" << std::endl;
	}
	DelimiterMap delim_encodings[] = {
		{"(", 1},
		{")", -1},
		{"<", 2},
		{">", -2},
		{"[", 3},
		{"]", -3},
		{"{", 4},
		{"}", -4}
	};
	int delim_encodings_size = sizeof(delim_encodings) / sizeof(delim_encodings[0]);
	int i;
	Stack<int>* s = new Stack<int>();
	for (i = 1; i < argc; i++) {
		int map_index = lookup_encodings(argv[i], delim_encodings, delim_encodings_size);
		if (map_index == -1) {
			exit_err(i - 1);
		}
		if ((int)delim_encodings[map_index].encoding > 0) {
			s->push(delim_encodings[map_index].encoding);
		}
		if ((int)delim_encodings[map_index].encoding < 0) {
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
	else {
		std::cout << "Balanced!" << endl;
	}
}