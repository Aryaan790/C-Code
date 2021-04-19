#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream finput;
    finput.open("inp.txt");
    ofstream file("out.ppm");
    file << "P3\n24 7 255\n"; // remember to change the dimensions
    char ch;
    while (finput.peek() != EOF)
    {
        finput.get(ch);
        if (ch == '3' || ch == '7' || ch == '8' || ch == '9')
        {
            file << "255 0 0 \n";
        }
        else if (ch == '0')
            file << "255 255 255\n";
    }
    file.close();
    finput.close();

    return 0;
}
