#include <iostream>
#include <string>

class MyRecursion{
private:
    std::string str;
public:
    int length;
    int Recursion(int, int);
    void read();
    void test(int,int );
};

void MyRecursion::read() {
    std::cin >> str;
    length = str.length()-1;
}


void MyRecursion::test(int leftBorder,int rightBorder){
    for(int i=leftBorder;i<=rightBorder;i++)
        std::cout << str[i];
    std::cout<<"\n";
}

int MyRecursion::Recursion(int leftBorder, int rightBorder) {

    test(leftBorder,rightBorder);

    if (leftBorder>=rightBorder)
    {
        std::cout<<"yes";
        return 0;
    }

    bool flag = true;
    int symbCount = 0;

    for (symbCount; symbCount < 3; symbCount++) {
        if (!isalpha(str[leftBorder+symbCount])) {
            flag = false;
        }
    }

    if (str[leftBorder+symbCount] != '=') {
        flag = false;
    }
    symbCount++;

    for (symbCount; symbCount < 6; symbCount++) {
        if (!isalnum(str[leftBorder+symbCount])) {
            flag = false;
        }
    }

    if (flag){
        if ((isalnum(str[leftBorder+6])!=0 || isalpha(str[leftBorder+6]!=0))){
            std::cout<<"no";
            return 0;
        }
        Recursion(leftBorder+((str[leftBorder+6] = ',')? 7:6),rightBorder);
        return 0;
    }

    flag = true;
    symbCount = 0;

    for (symbCount; symbCount < 3; symbCount++) {
        if (!isalpha(str[leftBorder+symbCount])) {
            flag = false;
        }
    }

    if ((!flag) || (str[leftBorder+3] != '=') || (str[leftBorder+4] != '(') || (str[rightBorder] != ')')){
        flag = false;
    }

    if (flag){
        Recursion(leftBorder+5,rightBorder-1);
        return 0;
    } else {
        std::cout<<"no";
        return 0;
    }
}



int main() {
    MyRecursion Text;
    std::cout<<"Enter string"<<"\n";
    Text.read();
    Text.Recursion(0,Text.length);
    return 0;
}
