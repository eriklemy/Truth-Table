#ifndef TRUTH_TABLE_H
#define TRUTH_TABLE_H

#include <iostream>
#include <string>
#include <bitset>
#include <unordered_map>
#include <queue>
#include <functional>

constexpr int ONE = 1;
constexpr int TWO = 2;
constexpr int THREE = 3;
constexpr int STRING_SIZE = 16;

enum class Operation {
	NOT,
	AND,
	OR,
	IMPLIES,
	IFF
};

std::ostream &operator<<(std::ostream &stream, Operation op) {
	switch (op) {
		case Operation::NOT:      stream << "¬";   break;
		case Operation::AND:      stream << "∧";   break;
		case Operation::OR:       stream << "∨";   break;
		case Operation::IMPLIES:  stream << "➔ "; break;
		case Operation::IFF:      stream << "⇿ "; break;
	}
	return stream;
}

class TruthTable {
	public:
		TruthTable();
		int size(); 
		void push_props(std::string p);
		void show_table(Operation op);
		void pop_props();
	private:
		std::deque<std::string> props;
		std::unordered_map<int, std::string> operations = {{0, "¬"}, {1, "∧"}, {2, "∨"}, {3, "➔"}, {4, "⇿ "}};
		std::unordered_map<Operation, std::function<char(std::string)>> choseOperations;

		void generateTable(Operation op);
		void generateTableThree(Operation op);
};

#endif // !TRUTH_TABLE_H