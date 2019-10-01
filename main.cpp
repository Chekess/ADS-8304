#include <iostream>
#include <string>

void TrySimplePar(std::string);

int main() {
    std::string str;
    std::cin >> str;

    TrySimplePar(str);
    //std::cout << "Не список параметров" << "\n";

    return 0;
}

void TrySimplePar(std::string str)
{
    int StartLengh = str.length();

    for (int i=0;i<str.length() - 6;i++) {
        bool flag = true;
        int k = 0;

        for (k; k < 3; k++) {
            if (!isalpha(str[i+k])) {
                flag = false;
            }
        }
        if (!flag) { continue;}

        if (str[i+k] != '=') {
            flag = false;
        }
        k++;
        if (!flag) { continue;}

        for (k; k < 7; k++) {
            if (!isalnum(str[i+k])) {
                flag = false;
            }
        }

        if (flag)
        {
            str.replace(i,7,"*");
        }
    }

    for (int i=0;i<str.length() - 2;i++) {
        if ((str[i] == '*') && (str[i+1] == ',') && (str[i+2] == '*')) {
            str.replace(i,3,"*");
        }
    }

    for (int i=0;i<str.length() - 6;i++) {

        bool flag = true;
        int k = 0;

        for (k; k < 3; k++) {
            if (!isalpha(str[i+k])) {
                flag = false;
            }
        }

        if ((flag) && (str[i+3] == '=') && (str[i+4] == '(') && (str[i+5] == '*') && (str[i+6] == ')'))
        {
            str.replace(i,7,"*");
        }
    }

    if (str.length() == StartLengh) {
        std::cout << "Не список параметров" << "\n";
    }else if ((str.length() == 1) && (str[0] == '*')){
        std::cout << "Cписок параметров" << "\n";
    }else{
        TrySimplePar(str);
    }

}
