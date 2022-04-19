/*
    PROJETO 1 - RPLM 
    RESOLUÇÃO DE PROBLEMAS COM LOGICA MATEMATICA
    TABELA DA VERDADE
    NOME: Erick Lemmy dos Santos Oliveira
*/
#ifndef TRUTH_TABLE_H
#define TRUTH_TABLE_H

#include <iostream>
#include <string>
#include <bitset>
#include <queue>
#include <functional>
#include <unordered_map>

constexpr int STRING_SIZE = 20;

enum class Operation { NOT, AND, OR, IMPLIES, IFF };

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
#endif // !TRUTH_TABLE_H