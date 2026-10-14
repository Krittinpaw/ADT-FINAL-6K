#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));
    ofstream myfile("random.dat");
    myfile.is_open();
    if (myfile) {
        for (int i = 0; i < 3000000; i++) {
            int val = ((rand() << 15) | rand()) % 100000 + 1;
            myfile << val << " ";
        }
        cout << "Write data Success\n";
    } else {
        cout << "Unable to open file\n";
    }
    myfile.close();
    return 0;
}
