#include "TruthTable.h"
#include "TruthTable.cpp"

#include <iostream>
#include <algorithm>
#include <sstream>

const std::string FIM = "FIM";

static void SHOW_RULES() {
    std::cout << "_________________________________________________________\n"
              << "|\t\tTRUTH TABLE GENERATOR\t\t\t|\n" 
              << "|-------------------------------------------------------|\n"
              << "|   OBS: \t\t\t\t\t\t|\n"  
              << "|   1. MAXIMO de TRES proposições\t\t\t|\n"
              << "|   2. Usar Letra MAISCULA na operação\t\t\t|\n"
              << "|   3. UMA proposição apenas a NEGAÇÃO sera apresentada\t|\n"
              << "|\tOPERAÇÕES ACEITAS: \t\t\t\t|\n"
              << "|\tSAIR:                           [FIM]\t\t|\n"
              << "|\tNEGAÇÃO:               [!],      [~],     [N]\t|\n"
              << "|\tCONJUNÇÃO:             [&],      [^],     [E]\t|\n"
              << "|\tDISJUNÇÃO:             [|],      [v],     [O]\t|\n"
              << "|\tIMPLICAÇÃO:            [>],      [-],     [I]\t|\n"
              << "|\tBICONDICIONAL:         [<],      [=],     [D]\t|\n"
              << "|-------------------------------------------------------|\n"
              << "Digite a PROPOSIÇÃO ou OPERAÇÃO: ";
}

int main() {
    TruthTable tt;
    std::string prop;
    std::deque<char> op;

    SHOW_RULES();
    
    std::getline(std::cin, prop);
    std::cout << prop << "\n";
    
    std::stringstream stream(prop);
    std::vector<std::string> vec_res;
    std::string tok;
    while (getline(stream, tok, ' ')) {
        if(tok != " " && tok != "!" && tok != "~" && tok != "N"
                      && tok != "^" && tok != "&" && tok != "E"
                      && tok != "V" && tok != "|" && tok != "O"
                      && tok != ">" && tok != "-" && tok != "I"
                      && tok != "<" && tok != "=" && tok != "D") 
        {
            std::cout << "string: " << tok << "\n";
            tt.push_props(tok);
        } 
        else {
            if (tok != " ") 
                op.push_back(tok[0]);
        }
    }
           
    std::transform(prop.begin(), prop.end(), prop.begin(), ::toupper);
    std::cout << op.front() << "\n";

    if (prop == FIM && tt.size() == 1)
        std::cout << "\n\t\tFIM DE EXECUÇÃO!"; 
    else {
        if (prop == FIM || tt.size() > 3) tt.pop_props();
        
        if (tt.size() == 1) tt.show_table(Operation::NOT); 

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
                    std::cerr << "\n\tOPERAÇÃO INVALIDA!!\n";
                    break;
            }
        }
    }
}