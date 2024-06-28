#include "genericite.hpp"


int main() {

    Pair<int, int> pair(2, 6);
    LabeledPair<int, int> int_int_labeledpair(2, 6, "Des entiers");
    LabeledPair<string, string> str_str_labeledpair("Première chaine", "Heu... en recherche d'idée", "Des chaines de caractère");
    LabeledPair<int, string> mix_labeledpair(42, "Le chiffre 42 est mythique !", "Un mix des deux...");

    pair.display();
    int_int_labeledpair.display();
    str_str_labeledpair.display();
    mix_labeledpair.display();

    HashTable<int> hashtable;
    hashtable.addElement("key", 12);
    hashtable["Un"] = 1;
    std::optional<int> result = hashtable["Un"];
    // cout << result << endl;

    return 0;
}
