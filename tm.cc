#include <iostream>
#include <vector>

std::vector<char> left_tape (1, 0);
std::vector<char> right_tape (1, 0);

#define NUMBER_OF_STATES 2

void go_left () {
	if (left_tape.size()) {
		right_tape.push_back(left_tape.back());
		left_tape.pop_back();
	} else {
		right_tape.push_back(0);
	}
}

void go_right () {
	if (right_tape.size()) {
		left_tape.push_back(right_tape.back());
		right_tape.pop_back();
	} else {
		left_tape.push_back(0);
	}
}

void print_tapes() {
	printf("tapes: ");
	int i;
	for (i = left_tape.size(); i >= 0; --i) {
		printf("%d ", left_tape[i]);
	}
	printf("<| ");

	for (i = 0; i < right_tape.size(); i++) {
		printf("%d ", right_tape[i]);
	}
	printf("\n");
}

int main() {
	// left_tape
									//		 See 0     See 1
									//     newstate, newsymbol, go right 
	char rules[NUMBER_OF_STATES][2][3] = { { {1, 1, 1} , {1, 1, 1} },
											{ {-1, 1, 1} , {-1, 1, 1} } };

	char state = 0;
	int time = 0;
	do {
		printf("time is %d, state is %d\n", time++, state);
		printf("currentSymbol is %d\n", left_tape[0]);
		print_tapes();
		char currentSymbol = left_tape[0];
		char newState = rules[state][currentSymbol][0];
		char newSymbol = rules[state][currentSymbol][1];
		char newDirection = rules[state][currentSymbol][2];

		state = newState;
		left_tape[0] = newSymbol;
		newDirection ? go_right() : go_left();
	} while (state != -1);

	return 0;
}