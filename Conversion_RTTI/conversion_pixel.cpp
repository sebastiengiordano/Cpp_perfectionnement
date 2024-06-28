#include "conversion_pixel.hpp"

using namespace std;


void changeColor(vector<Pixel*> myVector)
{
    for (auto aPixel: myVector) {
        swap(aPixel->blue, aPixel->red);
    }
}


int main() {
    


    cout << endl;

    return 0;
}
