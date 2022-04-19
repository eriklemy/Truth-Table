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

TruthTable::TruthTable() {
    choseOperations = {         
        {Operation::NOT, [](std::string bin) {
            bool p = bin.at(0) == '1' ? true: false;
            return !p ? 'V': 'F';
        }},
        {Operation::AND, [](std::string bin) {
            bool p = bin.at(0) == '1' ? true: false;
            bool q = bin.at(1) == '0' ? false: true;
            return (p & q) ? 'V': 'F';
        }},
        {Operation::OR, [](std::string bin) {
            bool p = bin.at(0) == '1' ? true: false;
            bool q = bin.at(1) == '0' ? false: true;
            return (p | q) ? 'V': 'F';
        }},
        {Operation::IMPLIES, [](std::string bin) {
            bool p = bin.at(0) == '1' ? true: false;
            bool q = bin.at(1) == '0' ? false: true;
            return (!p | q) ? 'V': 'F';              // ~p or q == p -> q
        }},
        {Operation::IFF, [](std::string bin) {    
            bool p = bin.at(0) == '1' ? true: false;
            bool q = bin.at(1) == '0' ? false: true;
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

void TruthTable::generateTable(Operation op) {    
     for (int i = 0; i != (1 << props.size()); i++) {
        std::string binaryRep;
        
        if (props.size() < 3)
            binaryRep = (props.size() == 1) ? std::bitset<ONE>(i).to_string() : std::bitset<TWO>(i).to_string();
        else binaryRep = std::bitset<THREE>(i).to_string();

        auto pair = choseOperations.find(op);
        for (size_t j = 0; j < binaryRep.length(); j++) {
            char boolRep = binaryRep.at(j) == '1' ? 'V': 'F'; 
            if (pair != choseOperations.end())
                std::cout << "|\t" << boolRep << "\t";
        }
        std::cout << "|\t" << pair->second(binaryRep) << "\t\t\n";
    }
}

void TruthTable::show_table(Operation op) {
    const int total_width = STRING_SIZE * (props.size() + 1);
    const std::string line = "|" + std::string(total_width - 1, '=') + '|';
    
    std::cout << line << '\n';    
    for (size_t i = 0; i < props.size(); i++)
        std::cout << "|\t" << props[i] << "\t"; 

    if(op == Operation::NOT)  
        std::cout << "|\t" << Operation::NOT << props[0] << "\t\n";   
    else if(props.size() == 2) 
        std::cout << "|\t" << props[0] << " " << op << " " << props[1] << "\t\n";
    else {
        std::cout << "|" << std::setw(10) << props[0] 
                  << " " << op 
                  << " " << props[1] 
                  << " " << op 
                  << " " << props[2] << std::setw(10)
                  << "\t\t\n";  
    }
    std::cout << line << '\n';    

    generateTable(op);
    std::cout << line << '\n';    

}

