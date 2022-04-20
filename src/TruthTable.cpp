/*
    PROJETO 1 - RPLM 
    RESOLUÇÃO DE PROBLEMAS COM LOGICA MATEMATICA
    TABELA DA VERDADE
    NOME: Erick Lemmy dos Santos Oliveira
*/
#include "TruthTable.h"
#include <iostream>
#include <iomanip>

#define ONE 1
#define TWO 2
#define THREE 3

bool _OperationHelper(bool P, bool Q, Operation op) {
    switch(op) {
        case Operation::AND:
            return P & Q;
        case Operation::OR:
            return P | Q;
        case Operation::IMPLIES:
            return (!P | Q);
        case Operation::IFF:
            return P == Q;
        default:
            return !Q;
    } 
}

TruthTable::TruthTable() {
    choseOperations = {         
        {Operation::NOT, [](std::string bin, bool isThreeProps, Operation op) {
            bool p = bin.at(0) == '1' ? true: false;
            return !p ? 'V': 'F';
        }},
        {Operation::AND, [](std::string bin, bool isThreeProps, Operation op) {
            bool p = bin.at(0) == '1' ? true: false;
            bool q = bin.at(1) == '0' ? false: true;
            if (isThreeProps) {
                bool r = bin.at(2) == '1' ? true: false;
                return _OperationHelper((p & q), r, op) ? 'V': 'F';
            }
            return (p & q) ? 'V': 'F';
        }},
        {Operation::OR, [](std::string bin, bool isThreeProps, Operation op) {
            bool p = bin.at(0) == '1' ? true: false;
            bool q = bin.at(1) == '0' ? false: true;
            if (isThreeProps) {
                bool r = bin.at(2) == '1' ? true: false;
                return _OperationHelper((p | q), r, op) ? 'V': 'F';
            }
            return (p | q) ? 'V': 'F';
        }},
        {Operation::IMPLIES, [](std::string bin, bool isThreeProps, Operation op) {
            bool p = bin.at(0) == '1' ? true: false;
            bool q = bin.at(1) == '0' ? false: true;
            if (isThreeProps) {
                bool r = bin.at(2) == '1' ? true: false;
                return _OperationHelper((!p | q), r, op) ? 'V': 'F';
            }
            return (!p | q) ? 'V': 'F';              // ~p or q == p -> q
        }},
        {Operation::IFF, [](std::string bin, bool isThreeProps, Operation op) {    
            bool p = bin.at(0) == '1' ? true: false;
            bool q = bin.at(1) == '0' ? false: true;
            if (isThreeProps) {
                bool r = bin.at(2) == '0' ? false: true;
                return _OperationHelper((!p | q) & (!q | p), r, op) ? 'V': 'F';
            }
            return ((!p | q) & (!q | p)) ? 'V': 'F'; // (p -> q) ^ (q -> p) == p <-> q 
        }},
    };
}

int TruthTable::size() { 
    return props.size(); 
}

void TruthTable::push_props(std::string p) {
    props.push_back(p);
}

void TruthTable::pop_props() {
    props.pop_back();
}

void TruthTable::generateTableOneTwo(Operation op) {    
    for (int i = 0; i != (1 << props.size()); i++) {
        std::string binaryRep = (props.size() == 1) ? std::bitset<ONE>(i).to_string() : std::bitset<TWO>(i).to_string(); 
        auto pair = choseOperations.find(op);
        for (size_t j = 0; j < binaryRep.length(); j++) {
            char boolRep = binaryRep.at(j) == '1' ? 'V': 'F'; 
            if (pair != choseOperations.end())
                std::cout << "|\t" << boolRep << "\t";
        }
        std::cout << "|\t" << pair->second(binaryRep, false, op) << "\t\t\n";
    }
}

void TruthTable::show_table(Operation op) {
    const int total_width = STRING_SIZE * (props.size() + 1);
    const std::string line = "|" + std::string(total_width - 1, '=') + '|';
    
    std::cout << line << '\n';    
    for (size_t i = 0; i < props.size(); i++)
        std::cout << "|\t" << props[i] << "\t"; 

    if (op == Operation::NOT) 
        std::cout << "|\t" << Operation::NOT << props[0] << "\t\n";
    else std::cout << "|\t" << props[0] << " " << op << " " << props[1] << "\t\n";

    std::cout << line << '\n';    
    generateTableOneTwo(op);
    std::cout << line << '\n';    
}

void TruthTable::generateTableThree(Operation op, Operation op2) {    
     for (int i = 0; i != (1 << props.size()); i++) {
        std::string binaryRep = std::bitset<THREE>(i).to_string();
        auto pair = choseOperations.find(op);
        for (size_t j = 0; j < binaryRep.length(); j++) {
            char boolRep = binaryRep.at(j) == '1' ? 'V': 'F'; 
            if (pair != choseOperations.end())
                std::cout << "|\t" << boolRep << "\t";
        }
        std::cout << "|\t" << pair->second(binaryRep, false, op) << "\t";
        std::cout << "|\t" << pair->second(binaryRep, true, op2) << "\t\t\n";
    }
}

void TruthTable::show_tableThree(Operation op1, Operation op2) {
    const int total_width = STRING_SIZE * (props.size() + 1);
    const std::string line = "|" + std::string(total_width - 1, '=') + '|';
    
    std::cout << line << '\n';    
    for (size_t i = 0; i < props.size(); i++)
        std::cout << "|\t" << props[i] << "\t"; 

    std::cout << "|" << std::setw(5) 
                << "(" << props[0] 
                << " " << op1 
                << " " << props[1] 
                << ") " << op2 
                << " " << props[2] << std::setw(5)
                << "\t\t\n";  
    std::cout << line << '\n';    
    generateTableThree(op1, op2);
    std::cout << line << '\n';    
}
