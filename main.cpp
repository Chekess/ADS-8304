#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

class MyRecursion{
private:
    std::string str;
public:
    int length;
    int recursion(int, int);
    void read(char* );
    void testWorkingDistance(int, int);
    void write(std::string);
MyRecursion();
MyRecursion(std::string&);
};

void MyRecursion::write(std::string result){
    std::cout << result << std::endl;
}

void MyRecursion::read(char* text) {
    str = text;
    length = str.length()-1;
}


void MyRecursion::testWorkingDistance(int leftBorder,int rightBorder){
    for(int i = leftBorder; i <= rightBorder; i++)
        std::cout << str[i];
    std::cout << std::endl;

}

MyRecursion::MyRecursion(std::string &string) {
    this->str = string;
    this->length = str.length()-1;
}

MyRecursion::MyRecursion() {
    this->str = "";
    this->length = 0;
}

int MyRecursion::recursion(int leftBorder, int rightBorder) {

    testWorkingDistance(leftBorder, rightBorder);

    if (leftBorder >= rightBorder)
    {
        write("it's a parameter list");
        return 0;
    }

    bool verification = true;
    int symbolCount = 0;

    for (symbolCount; symbolCount < 3; symbolCount++) {
        if (!isalpha(str[leftBorder + symbolCount])) {
            verification = false;
        }
    }

    if (str[leftBorder + symbolCount] != '=') {
        verification = false;
    }
    symbolCount++;

    for (symbolCount; symbolCount < 6; symbolCount++) {
        if (!isalnum(str[leftBorder + symbolCount])) {
            verification = false;
        }
    }

    if (verification){
        if ((isalnum(str[leftBorder + 6])!= 0 || isalpha(str[leftBorder + 6] != 0))){
            write("it's not a parameter list");
            return 0;
        }
        recursion(leftBorder + ((str[leftBorder + 6] = ',') ? 7:6), rightBorder);
        return 0;
    }

    verification = true;
    symbolCount = 0;

    for (symbolCount; symbolCount < 3; symbolCount++) {
        if (!isalpha(str[leftBorder + symbolCount])) {
            verification = false;
        }
    }

    bool notEqualSign = str[leftBorder + 3] != '=';
    bool notLeftBracket = str[leftBorder + 4] != '(';
    bool notRightBracket = str[rightBorder] != ')';

    if ((!verification) || notEqualSign || notLeftBracket || notRightBracket){
        verification = false;
    }

    if (verification){
        recursion(leftBorder + 5,rightBorder - 1);
    } else {
        write("it's not a parameter list");
    }
    return 0;
}



int main(int argc, char* argv[]) {

    if (argc == 1){
        std::cout << "argc: " << argc << std::endl;
        std::cout << "argv[0]: " << argv[0] << std::endl;
       // std::cout << "argv[1]:" << argv[1] << std::endl;
        std::cout << "enter" << std::endl;
        std::string line;
        std::ifstream in;
        in.open("D:\\study\\test.txt");
        if (in.is_open())
        {
            std::cout << "file opened" << std::endl;
            while (getline(in, line))
            {
                MyRecursion Text(line);
                Text.recursion(0, Text.length);
                std::cout<<std::endl;
            }
        }
        in.close();//закрываем файл
    }else{
        std::cout << argv[1] << std::endl;
        MyRecursion Text;//(argv[1]);
    //std::cout << "Enter string" << "\n";
        Text.read(argv[1]);
        Text.recursion(0, Text.length);

    }
    return 0;
}
