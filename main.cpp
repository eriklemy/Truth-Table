/*
    PROJETO 1 - RPLM 
    RESOLUÇÃO DE PROBLEMAS COM LOGICA MATEMATICA
    TABELA DA VERDADE
    NOME: Erick Lemmy dos Santos Oliveira
*/

#include "src\TruthTable.h"
#include "src\TruthTable.cpp"

#include <iostream>
#include <algorithm>
#include <sstream>

const std::string FIM = "FIM";
std::unordered_map<int, std::string> KEYS = {{0, "¬"}, {1, "∧"}, {2, "∨"}, {3, "➔"}, {4, "⇿ "}};

static void SHOW_RULES() {
    std::cout << "_________________________________________________________\n"
              << "|\t\tTRUTH TABLE GENERATOR\t\t\t|\n" 
              << "|-------------------------------------------------------|\n"
              << "|   OBS: \t\t\t\t\t\t|\n"  
              << "|   1. MAXIMO de TRES proposições\t\t\t|\n"
              << "|   2. Usar Letra MAISCULA entre ESPAÇOS na operação\t|\n"
              << "|      ex: P ^ Q; P V Q; P = Q\t\t\t\t|\n"
              << "|   3. UMA proposição apenas a NEGAÇÃO sera apresentada\t|\n"
              << "|   4. operação de NEGAÇÃO para DUAS ou MAIS proposições|\n"
              << "|     retorna apenas a negação da PRIMEIRA\t\t|\n"
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

int main() {
    TruthTable tt;
    std::string prop;
    std::deque<char> op;

    SHOW_RULES();
    
    std::getline(std::cin, prop);
    std::cout << prop << "\n";
    
    std::string tok;
    std::stringstream stream(prop);
    std::vector<std::string> vec_res;
    std::vector<std::string> v = {"!", "~", "N", "^", "&", "E", "V", "|", "O", ">", "-", "I", "<", "=", "D" };
 
    while (getline(stream, tok, ' ')) {
        if(std::find(v.begin(), v.end(), tok) != v.end())   
            op.push_back(tok[0]);
        else tt.push_props(tok);
    }
           
    std::transform(tok.begin(), tok.end(), tok.begin(), ::toupper);

    if (tok == FIM)
        std::cout << "PROGRAMA FINALIZADO! OBRIGADO!!\n";
    else {
        if (tt.size() > 3) tt.pop_props();
        else if (tt.size() == 1) tt.show_table(Operation::NOT); 
        else {
            switch (tolower(op.front())) {
                case '!':
                case '~':
                case 'n':
                    tt.show_table(Operation::NOT);
                    break;
                case '^':
                case '&':
                case 'e':
                    tt.show_table(Operation::AND);
                    break;
                case 'v':
                case '|':
                case 'o':
                    tt.show_table(Operation::OR);
                    break;
                case '>':
                case '-':
                case 'i':
                    tt.show_table(Operation::IMPLIES);
                    break;
                case '<':
                case '=':
                case 'd':
                    tt.show_table(Operation::IFF);
                    break;
                default:
                    std::cerr << "\nOPERAÇÃO INVALIDA!!";
                    break;
            }
        }
    }
}