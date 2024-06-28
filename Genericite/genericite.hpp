#include <iostream>
#include <typeinfo>
#include <unordered_map>
#include <vector>
#include <optional>


using namespace std;


template<typename T, typename U>
class Pair
{
protected:
    T t;
    U u;
public:
    Pair(T t, U u): t(t), u(u) {};
    virtual ~Pair() {};

    void display() const {
        cout << endl;
        cout << "T est de type : " << typeid(t).name() << " et vaut : " << t << endl;
        cout << "U est de type : " << typeid(u).name() << " et vaut : " << u << endl;
        cout << endl;
    }
};


template<typename T, typename U>
class LabeledPair: public Pair<T, U>
{
protected:
    string label;
public:
    LabeledPair(T t, U u, string label): Pair<T, U>(t, u) {
        this->label = label;
    };
    ~LabeledPair() {};

    void display() const {
        cout << endl;
        cout << "LabeledPair est  : " << label << endl;
        Pair<T, U>::display();
    }
};


template<typename T>
class HashTable
{
private:
    unordered_map<std::string, T> data;
public:
    HashTable() = default;
    // HashTable(vector<string, T> t): { 
    //     for(auto elem: t) {
    //         data
    //     }
    // };
    ~HashTable() { };

    void addElement(std::string key, T t) {
        data.insert_or_assign(key, t);
    }

     optional<T> operator[] (const string& key) const {
        if (key_exist(key)) {
            return data.at(key);
        }
        else {
            return nullopt;
        }
    }
    
    bool key_exist(const string& key) const{
        bool is_key_exist = true;
        if (data.find(key) == data.end())
            is_key_exist = false;

        return is_key_exist;
    }
};
