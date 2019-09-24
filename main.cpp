#include <iostream>
#include <string>

class MyRecursion{
private:
    std::string str;
public:
    int length;
    int Recursion(int, int);
    void read();
    void write(std::string);
    void test(int ,int );
};

void MyRecursion::read() {
    std::cin >> str;
    length = str.length()-1;
}

void MyRecursion::write(std::string MyText) {
    std::cout << MyText << "\n";
}

void MyRecursion::test(int l,int r){
    for(int i=l;i<=r;i++)
        std::cout<<str[i];
    write("");
}

int MyRecursion::Recursion(int left, int right) {

    test(left,right);

    if (left>=right)
    {
        write("yes");
        return 0;
    }

    bool flag = true;
    int k = 0;

    for (k; k < 3; k++) {
        if (!isalpha(str[left+k])) {
            flag = false;
        }
    }

    if (str[left+k] != '=') {
        flag = false;
    }
    k++;

    for (k; k < 6; k++) {
        if (!isalnum(str[left+k])) {
            flag = false;
        }
    }

    if (flag){
        if ((isalnum(str[left+6])!=0 || isalpha(str[left+6]!=0))){
            write("no");
            return 0;
        }
        Recursion(left+((str[left+6] = ',')? 7:6),right);
        return 0;
    }

    flag = true;
    k = 0;

    for (k; k < 3; k++) {
        if (!isalpha(str[left+k])) {
            flag = false;
        }
    }

    if ((!flag) || (str[left+3] != '=') || (str[left+4] != '(') || (str[right] != ')')){
        flag = false;
    }

    if (flag){
        Recursion(left+5,right-1);
        return 0;
    } else {
        write("no");
        return 0;
    }
}



int main() {
    MyRecursion MySimple;
    MySimple.read();
    MySimple.Recursion(0,MySimple.length);
    return 0;
}
