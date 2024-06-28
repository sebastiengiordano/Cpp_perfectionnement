#include <iostream>
#include <string>
#include <regex>

int main () {
    std::string str("This subject has a submarine as a subsequence !");
    std::smatch match;
    std::regex expreg("sub[^ ]*");

    std::cout << "Chaine de carateres : " << str << std::endl;
    std::cout << "Regex: /sub[^ ]*/" << std::endl;
    std::cout << "Resultat :" << std::endl;
    while (std::regex_search (str, match, expreg)) {
        std::cout << "  - " << match.str() << std::endl;
        str = match.suffix().str();
    }
    return 0;
}
