#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

class ProxyArray
{
private:
    vector<int> *my_proxy_array;
public:
    ProxyArray() = default;
    ProxyArray(vector<int>* my_int): my_proxy_array(my_int) {
        for (auto elem: my_int){
            my_proxy_array->push_back(elem);
        }
    };
    ~ProxyArray() { };

    void print_array() const {
        cout << "print array" << endl;
        for (auto elem: *my_proxy_array) {
            cout << "\t" << elem << endl;
        }
    }

    size_t getSize() const {return my_proxy_array->size();}

    std::vector<int>* getAddress() {return my_proxy_array;}

    bool operator== (const ProxyArray& proxyarray) const {
        return this->getSize() == proxyarray.getSize();
    }

    bool operator!= (const ProxyArray& proxyarray) const {
        return this->getSize() != proxyarray.getSize();
    }

    int operator[] (const int i) {
        vector<int>& proxy_array = dynamic_cast<vector<int>&> (my_proxy_array);
        // return (static_cast<vector<int>&> *my_proxy_array)[i];
        return my_proxy_array[i];
    }

};


int main() {
    vector<int> an_array = {1,2,3,4,5};
    vector<int> another_array(7);
    std::iota(another_array.begin(), another_array.end(), 20);

    ProxyArray proxyarray(&an_array);
    ProxyArray anotherproxyarray(&another_array);

    proxyarray.print_array();
    cout << endl << "Taille du tableau :\t" << proxyarray.getSize() << endl;
    cout << endl << "Adresse du tableau :\t" << proxyarray.getAddress() << endl;

    string result = (proxyarray != anotherproxyarray) ? "Oui" : "Non";
    cout << endl <<
        "Comparaison de mes array, sont-elles bien différente :\t" <<
        result << endl;

    cout << endl <<
        "an_array[2] :\t" <<
        proxyarray[2] << endl;

    return 0;
}