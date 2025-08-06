#include "main.h"
using std::string;
using std::array;
using std::function;

namespace math_functions {
    static float add(float a, float b) {
        std::cout << a << " + " << b << " = " << a + b << "\n";
        return a + b;
    }

    static float subtract(float a, float b) {
        std::cout << a << " - " << b << " = " << a - b << "\n";
        return a - b;
    }

    static float multiply(float a, float b) {
        std::cout << a << " * " << b << " = " << a * b << "\n";
        return a * b;
    }

    static float divide(float a, float b) {
        std::cout << a << " / " << b << " = " << a / b << "\n";
        return a / b;
    }

    static float modulo(float a, float b) {
        std::cout << static_cast<int>(a) << " % " << static_cast<int>(b) << " = " << static_cast<int>(a) % static_cast<int>(b) << "\n";
        return static_cast<int>(a) % static_cast<int>(b);
    }

    static float greaterThen(float a, float b) {
        std::cout << a << " > " << b << " = " << (a > b) << "\n";
        return a > b;
    }

    static float smallerThen(float a, float b) {
        std::cout << a << " < " << b << " = " << (a < b) << "\n";
        return a < b;
    }

    static float equals(float a, float b) {
        std::cout << a << " == " << b << " = " << (a == b) << "\n";
        return a == b;
    }

    static float unequals(float a, float b) {
        std::cout << a << " != " << b << " = " << (a != b) << "\n";
        return a != b;
    }
}

namespace calculator_functions {
    static const int size = 9;
    static const int calc_priority[size] = { 1,1,0,0,0,2,2,2,2 };
    static const char operators[size] = { '+', '-', '*', '/', '%', '>', '<', '=', '!' };
    static const array<function<float(float, float)>, size> operations = { math_functions::add, math_functions::subtract, math_functions::multiply, math_functions::divide, math_functions::modulo,  math_functions::greaterThen, math_functions::smallerThen, math_functions::equals, math_functions::unequals };

    static int getArrayPosition(const string a, const char* arr) {
        if (a.length() > 1)
            return -1;
        int i = 0;
        for (; i < sizeof(arr); i++) {
            if (a.at(0) == arr[i])
                return i;
        }
        return -1;
    }

    static int getArrayPosition(const char a, const char* arr) {
        int i = 0;
        for (; i < sizeof(arr); i++) {
            if (a == arr[i])
                return i;
        }
        return -1;
    }

    static std::string removeAllWhitespace(const std::string& str) {
        std::string result = str;
        result.erase(std::remove_if(result.begin(), result.end(), [](unsigned char c) {
            return std::isspace(c);
            }), result.end());
        return result;
    }

    static std::vector<string> tokenize(const string user_input) {
        string input = removeAllWhitespace(user_input);
        std::vector<string> tokens;
        int start = 0;
        for (int i = 0; i < input.length(); i++) {
            if (getArrayPosition(input[i], operators) >= 0) {
                string substring = input.substr(start, (i - start));
                if (substring.length() > 0) {
                    tokens.push_back(substring);
                    tokens.push_back(string() + input[i]);
                }
                start = i + 1;
            }
        }
        if (input.length() - start > 0)
            tokens.push_back(input.substr(start, input.length()));
        else
            tokens.pop_back();
        return tokens;
    }

    static void calculation_step(std::vector<string>* tokenized_input, int prio) {
        for (auto it = tokenized_input->begin(); it != tokenized_input->end();) {
            int pos = getArrayPosition(*it, operators);
            if (pos >= 0 && calc_priority[pos] == prio) {
                float result = operations[pos](std::stof(*(it - 1)), std::stof(*(it + 1)));
                *it = std::to_string(result);
                it = tokenized_input->erase(it - 1);
                it = tokenized_input->erase(it + 1);
            }
            else
                ++it;
        }
    }

    static string formatFloat(string value) {
        float fvalue = std::stof(value);
        return std::format("{:.2f}", fvalue);
    }

    static void calculate(std::vector<string>* tokenized_input) {
        calculation_step(tokenized_input, 0);
        calculation_step(tokenized_input, 1);
        calculation_step(tokenized_input, 2);
        std::cout <<"\033[33m" << formatFloat(tokenized_input->at(0)) << "\033[0m\n";
    }
}

int main()
{
    string userInput;
    std::cout << "This aaa is a simple programming calculator!\nPlease enter a simple equation only using the following operators:\n";
    for (char op : calculator_functions::operators) {
        std::cout << op << " ";
    }
    std::cout << "\n";
    std::getline(std::cin, userInput);
    std::vector<string> tokens = calculator_functions::tokenize(userInput);
    calculator_functions::calculate(&tokens);
}