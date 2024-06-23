#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// ��������� ��� �������� ���������� ��������� � ������ ���������
struct ExpressionResult {
    int result; // ��������� ���������
    string expression; // ���� ���������
};

// ���-������� ��� �������� ����� ����������� �����������
unordered_map<string, vector<ExpressionResult>> memo;

// ������� ��� ������������ ���������� ���� ��������� ��������� ���������
static vector<ExpressionResult> diffWaysToComputeHelper(string expression) {
    // ���������, ���� �� ��������� ������ ��������� �����
    if (memo.find(expression) != memo.end()) {
        return memo[expression]; // ���� ��, ���������� ��������� �� ����
    }

    vector<ExpressionResult> result;
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        // ���� ������ ���������, ��������� ��������� �� ��� ����� � ���������� ��������� ����������
        if (c == '+' || c == '-' || c == '*') {
            vector<ExpressionResult> leftResults = diffWaysToComputeHelper(expression.substr(0, i));
            vector<ExpressionResult> rightResults = diffWaysToComputeHelper(expression.substr(static_cast<basic_string<char, char_traits<char>, allocator<char>>::size_type>(i) + 1));
            // ���������� ��� ���������� �����
            for (const auto& left : leftResults) {
                // ���������� ��� ���������� ������
                for (const auto& right : rightResults) {
                    int res; // ���������� ��� �������� ���������� ����������
                    // ��������� �������� � ����������� �� ������� ���������
                    if (c == '+') res = left.result + right.result;
                    else if (c == '-') res = left.result - right.result;
                    else if (c == '*') res = left.result * right.result;
                    // ��������� ����� ���������, ��������� ����� ���������, �������� � ������ ���������
                    string exp = "(" + left.expression + c + right.expression + ")";
                    // ��������� ����� ��������� � �������� ������
                    result.push_back({ res, exp });
                }
            }
        }
    }
    // ���� ��������� ������� �� ������ �����, ��������� ��� � ���������
    if (result.empty()) {
        int res = stoi(expression);
        result.push_back({ res, expression });
    }
    // ��������� ��������� � ���
    memo[expression] = result;
    return result;
}

// ������� ��� ���������� ���� ��������� ��������� ���������
static vector<string> diffWaysToCompute(string expression) {
    // �������� ��� ���������� � ������� ��������������� �������
    vector<ExpressionResult> results = diffWaysToComputeHelper(expression);
    vector<string> explanations;
    // ����������� ���������� � ������ ��� ������
    for (const auto& res : results) {
        explanations.push_back(res.expression + " = " + to_string(res.result));
    }
    return explanations;
}

int main() {
    string expression1 = "2-1-1";
    string expression2 = "2*3-4*5";
    string expression3 = "5+6*9-12";

    // ��������� ��� ��������� �������� ���������
    vector<string> explanations1 = diffWaysToCompute(expression1);
    vector<string> explanations2 = diffWaysToCompute(expression2);
    vector<string> explanations3 = diffWaysToCompute(expression3);

    // ������� ���������� �� �����
    cout << "Output 1: " << endl;
    for (const auto& exp : explanations1) {
        cout << exp << endl;
    }
    cout << endl;

    cout << "Output 2: " << endl;
    for (const auto& exp : explanations2) {
        cout << exp << endl;
    }
    cout << endl;

    cout << "Output 3: " << endl;
    for (const auto& exp : explanations3) {
        cout << exp << endl;
    }
    cout << endl;

    return 0;
}