#include <iostream>
#include <vector>
#define MAX_SIZE_OF_RULES 100

std::vector<int> left_tape (1, 0);
std::vector<int> right_tape (1, 0);

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

void clear_tapes() {
	left_tape.clear();
	right_tape.clear();
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
int my_rules[MAX_SIZE_OF_RULES][2][3];

int time_run(int rules[][2][3], int maximum_time, bool verbose_mode) {
	int state = 0;
	int runtime = 0;
	do {
		runtime++;
		if (verbose_mode) {
			printf("%d ", runtime);
			// printf("runtime is %d, state is %d\n", runtime, state);
			// printf("currentSymbol is %d\n", left_tape[0]);
			// print_tapes();
		}

		int currentSymbol = left_tape[left_tape.size()-1];
		int newState = rules[state][currentSymbol][0];
		int newSymbol = rules[state][currentSymbol][1];
		int newDirection = rules[state][currentSymbol][2];

		state = newState;
		left_tape[left_tape.size()-1] = newSymbol;
		newDirection ? go_right() : go_left();
		if (state == -1) {
			return runtime;
		}
	} while (runtime < maximum_time);

	return -1;
}

void print_rules(int rules[][2][3], int num_of_rules);


void read_rules(int rules[][2][3]) {
	int number_of_states;
	scanf("%d", &number_of_states);

	if (number_of_states > 100) {
		printf("You asked for too many states!\n");
		exit(1);
	}

	int i;
	int* place;

	for(i=0; i<number_of_states; i++) {
		place = (int *) rules[i];
		scanf("%d %d %d %d %d %d", &place[0], &place[1], &place[2], &place[3], &place[4], &place[5]);
	}

	// print_rules(rules, number_of_states);
}

void generate_rules(int rules[][2][3], int number_of_states) {
	int i;
	int* place;

	for(i=0; i<number_of_states*2; i++) {
		place = (int *) rules[i];
		place[0] = (rand() % (number_of_states + 1)) - 1;
		place[1] = rand() % 2;
		place[2] = rand() % 2;
		place[3] = (rand() % (number_of_states + 1)) - 1;
		place[4] = rand() % 2;
		place[5] = rand() % 2;
	}

	// print_rules(rules, number_of_states);
}

void print_rules(int rules[][2][3], int num_of_rules) {
	printf("\t\t\tSymbol\nState | \t0\t\t\t1\n");
	printf("      | state  symbol direction | state symbol direction\n");
	printf("------------------------------------------------------\n");
	int i;
	for(i=0; i<num_of_rules; i++) {
		int *place = (int *) rules[i];
		printf("%d:    |\t%d\t%d\t%d\t  %d\t%d\t%d\n", i, place[0], place[1], place[2], place[3], place[4], place[5]);
	}
}


int main(int argc, char **argv) {
	if ((argc < 4 || argc > 5) && argc != 2) {
		printf("Usage: ./tm.cc number_of_trials number_of_states maximum_time\n");
		printf("./tm.cc --single\n");
		exit(0);
	}

	if (argc ==4 || argc == 5) {

		int number_of_trials;
		int number_of_states;
		int maximum_time;

		sscanf(argv[1], "%d", &number_of_trials);
		sscanf(argv[2], "%d", &number_of_states);
		sscanf(argv[3], "%d", &maximum_time);

		bool verbose_mode = false;
		bool print_machine = false;
		if (argc == 5) {
			if (strcmp(argv[4],"-v") == 0)
				verbose_mode = true;
			if (strcmp(argv[4],"-t") == 0)
				print_machine = true;
		}

		srand(time(NULL));
		int i;

		for(i=0; i<number_of_trials; i++) {
			generate_rules(my_rules, number_of_states);
			if (print_machine || verbose_mode) {
				print_rules(my_rules, number_of_states);
			}

			int num = time_run(my_rules, maximum_time, verbose_mode);
			if (num != -1 || verbose_mode)
				printf("%d ", num);
			if (verbose_mode || print_machine)
				printf("\n\n");
		}
	}
	else if (argc == 2) {
		read_rules(my_rules);

		printf("%d", time_run(my_rules, 100, true));

		return 0;
	}

}


	// if (false) {
	// 	bool verbose_mode = false;

	// 	// printf("%d\n", argc);

	// 	if (argc == 2) {
	// 		if (strcmp(argv[1], "-v") == 0) {
	// 			verbose_mode = true;
	// 		}
	// 	}

	// 	read_rules(my_rules);

	// 	printf("%d", time_run(my_rules, 100, verbose_mode));

	// 	return 0;
	// }

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