#include <iostream>
#include <vector>
#define MAX_SIZE_OF_RULES 100

std::vector<char> left_tape (1, 0);
std::vector<char> right_tape (1, 0);

void go_left () {
	if (left_tape.size() > 1) {
		right_tape.push_back(left_tape.back());
		left_tape.pop_back();
	} else {
		right_tape.push_back(left_tape.back());
		left_tape[0] = 0;
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
	for (i = left_tape.size(); i>= 0; i--) {
		printf("%d ", left_tape[i]);
	}
	printf("<| ");

	for (i = right_tape.size() -1; i >= 0; i--) {
		printf("%d ", right_tape[i]);
	}
	printf("\n");
}
						// newState, newSymbol, newDirection
char my_rules[100][2][3];

int time_run(char rules[][2][3], int maximum_time, bool verbose_mode) {
	char state = 0;
	int time = 0;
	do {
		time++;
		if (verbose_mode) {
			printf("time is %d, state is %d\n", time, state);
			printf("currentSymbol is %d\n", left_tape[0]);
			print_tapes();
		}

		char currentSymbol = left_tape[left_tape.size()-1];
		char newState = rules[state][currentSymbol][0];
		char newSymbol = rules[state][currentSymbol][1];
		char newDirection = rules[state][currentSymbol][2];

		state = newState;
		left_tape[left_tape.size()-1] = newSymbol;
		newDirection ? go_right() : go_left();
		if (state == -1) {
			return time;
		}
	} while (time < maximum_time);

	return -1;
}

void read_rules(char rules[][2][3]) {
	int number_of_states;
	scanf("%d", &number_of_states);

	if (number_of_states > 100) {
		printf("You asked for too many states!\n");
		exit(1);
	}

	int i;
	char* place;

	for(i=0; i<number_of_states; i++) {
		place = (char *) rules[i];
		scanf("%c %c %c %c %c %c", &place[0], &place[1], &place[2], &place[3], &place[4], &place[5], &place[6]);
	}
};

// void print_rules(char rules[][2][3], int num_of_rules) {
// 	int i;
// 	for(i=0; i<num_of_rules; i++) {
// 		place = (char *) rules[i];
// 		printf()
// 	}
// }


int main(int argc, char **argv) {

	bool verbose_mode = false;

	// printf("%d\n", argc);

	if (argc == 2) {
		if (strcmp(argv[1], "-v") == 0) {
			verbose_mode = true;
		}
	}

	read_rules(my_rules);

	printf("%d", time_run(my_rules, 100, verbose_mode));

	return 0;
}




// 	int step = 0;
// //	printf("%d\n", time_run(my_rules, 10));
// 	int lol = 1;
// 	while (lol != 0) {
// 		step++;
// 		scanf("%d", &lol);
// 		left_tape[left_tape.size()-1] = step;
// 		if (lol == 1)
// 			go_left();
// 		if (lol == 2)
// 			go_right();
// 		print_tapes();
// 	}