/*    PROJETO 1 - RPLM 
     RESOLUÇÃO DE PROBLEMAS COM LOGICA MATEMATICA
     TABELA DA VERDADE
     NOME: Erick Lemmy dos Santos Oliveira  */
#include "src\TruthTable.h"
#include "src\TruthTable.cpp"

#include <iostream>
#include <algorithm>
#include <sstream>

void SHOW_RULES();
Operation switchKeys(char op);

int main() {
    TruthTable tt;
    std::string tokken;
    std::string prop;
    std::deque<char> op;

    SHOW_RULES();
    
    std::getline(std::cin, prop);    
    std::stringstream stream(prop); 
    while (getline(stream, tokken, ' ')) {
        if(std::find(tt.all_operators.begin(), tt.all_operators.end(), tokken) != tt.all_operators.end())   
            op.push_back(tokken[0]);
        else tt.push_props(tokken);
    }
        
    std::vector<Operation> oper;
    std::transform(tokken.begin(), tokken.end(), tokken.begin(), ::toupper);
    if (tt.size() > 3) tt.pop_props();
    
    if (tokken == "FIM" || tt.size() == 1) {
        tt.show_table(Operation::NOT);
        std::cout << "\n     PROGRAMA FINALIZADO! OBRIGADO!!\n";
    } else if (tt.size() == 3) {
        tt.show_tableThree(switchKeys(op.front()), switchKeys(op.back()));
    } else tt.show_table(switchKeys(op.front()));
};

void SHOW_RULES() {
    std::cout << "_________________________________________________________\n"
              << "|\t\tTRUTH TABLE GENERATOR\t\t\t|\n" 
              << "|-------------------------------------------------------|\n"
              << "|   OBS: \t\t\t\t\t\t|\n"  
              << "|   1. MAXIMO de TRES proposições\t\t\t|\n"
              << "|   2. Usar Letra MAISCULA entre ESPAÇOS na operação\t|\n"
              << "|      ex: P ^ Q; P V Q; P = Q;\t\t\t\t|\n"
              << "|   3. UMA proposição apenas a NEGAÇÃO sera apresentada\t|\n"
              << "|   4. operação de NEGAÇÃO para DUAS ou MAIS proposições|\n"
              << "|      retorna apenas a negação da PRIMEIRA\t\t|\n"
              << "|   5. Não usar ACENTUAÇÃO nas proposições\t\t|\n"
              << "|\tOPERAÇÕES ACEITAS: \t\t\t\t|\n"
              << "|\tSAIR:                           [FIM]\t\t|\n"
              << "|\tNEGAÇÃO:               [!],      [~],     [N]\t|\n"
              << "|\tCONJUNÇÃO:             [&],      [^],     [E]\t|\n"
              << "|\tDISJUNÇÃO:             [|],      [v],     [O]\t|\n"
              << "|\tIMPLICAÇÃO:            [>],      [-],     [I]\t|\n"
              << "|\tBICONDICIONAL:         [<],      [=],     [D]\t|\n"
              << "|-------------------------------------------------------|\n"
              << "Digite as PROPOSIÇÃO com a/as OPERAÇÕES: ";
}

Operation switchKeys(char op) {
    switch (op) {
        case '!': case '~': case 'N':
            return Operation::NOT;
        case '^': case '&': case 'E':
            return Operation::AND;
        case 'v': case '|': case 'O':
            return Operation::OR;
        case '>': case '-': case 'I':
            return Operation::IMPLIES;
        case '<': case '=': case 'D':
            return Operation::IFF;
        default:
            std::cerr << "\nOPERAÇÃO INVALIDA!!\n";
            return Operation::INVALID;
    }
}