#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void display(T t){
    for (auto i: t) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> myVector(15);
    vector<int> myVectorSorted;
    vector<int> myVectorSquarred;

    // First create an instance of an engine.
    random_device rnd_device;
    // Specify the engine and distribution.
    mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    uniform_int_distribution<int> dist {-156, 520};
    
    auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };

    generate(begin(myVector), end(myVector), gen);


    cout << endl << "display myVector" << endl;
    display<vector<int>>(myVector);


    myVectorSorted = myVector;
    sort(myVectorSorted.begin(), myVectorSorted.end());
    cout << endl << "display myVector Sorted" << endl;
    display<vector<int>>(myVectorSorted);


    myVectorSquarred = myVector;
    transform(myVectorSquarred.begin(), myVectorSquarred.end(), myVectorSquarred.begin(), [](auto i){ return i * i;});
    cout << endl << "display myVector Squarred" << endl;
    display<vector<int>>(myVectorSquarred);


    cout << endl << "display myVector sum" << endl;
    int result = accumulate(begin(myVector), end(myVector), 0);
    cout << result << endl;
    // cout << accumulate(begin(myVector), end(myVector), 0) << endl;

    myVectorSorted.insert(myVectorSquarred.begin(), myVectorSquarred.end());
    cout << endl << "display myVectorSorted merge with myVectorSquarred" << endl;
    display<vector<int>>(myVectorSorted);

    return 0;
}
