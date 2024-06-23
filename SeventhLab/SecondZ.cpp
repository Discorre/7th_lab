#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Структура для хранения результата выражения и самого выражения
struct ExpressionResult {
    int result; // Результат выражения
    string expression; // Само выражение
};

// Хэш-таблица для хранения ранее вычисленных результатов
unordered_map<string, vector<ExpressionResult>> memo;

// Функция для рекурсивного вычисления всех возможных вариантов выражения
static vector<ExpressionResult> diffWaysToComputeHelper(string expression) {
    // Проверяем, было ли вычислено данное выражение ранее
    if (memo.find(expression) != memo.end()) {
        return memo[expression]; // Если да, возвращаем результат из кэша
    }

    vector<ExpressionResult> result;
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        // Если символ оператора, разбиваем выражение на две части и рекурсивно вычисляем результаты
        if (c == '+' || c == '-' || c == '*') {
            vector<ExpressionResult> leftResults = diffWaysToComputeHelper(expression.substr(0, i));
            vector<ExpressionResult> rightResults = diffWaysToComputeHelper(expression.substr(static_cast<basic_string<char, char_traits<char>, allocator<char>>::size_type>(i) + 1));
            // Перебираем все результаты слева
            for (const auto& left : leftResults) {
                // Перебираем все результаты справа
                for (const auto& right : rightResults) {
                    int res; // Переменная для хранения результата вычисления
                    // Выполняем операцию в зависимости от символа оператора
                    if (c == '+') res = left.result + right.result;
                    else if (c == '-') res = left.result - right.result;
                    else if (c == '*') res = left.result * right.result;
                    // Формируем новое выражение, объединяя левое выражение, оператор и правое выражение
                    string exp = "(" + left.expression + c + right.expression + ")";
                    // Добавляем новый результат в итоговый список
                    result.push_back({ res, exp });
                }
            }
        }
    }
    // Если выражение состоит из одного числа, добавляем его в результат
    if (result.empty()) {
        int res = stoi(expression);
        result.push_back({ res, expression });
    }
    // Сохраняем результат в кэш
    memo[expression] = result;
    return result;
}

// Функция для вычисления всех возможных вариантов выражения
static vector<string> diffWaysToCompute(string expression) {
    // Получаем все результаты с помощью вспомогательной функции
    vector<ExpressionResult> results = diffWaysToComputeHelper(expression);
    vector<string> explanations;
    // Преобразуем результаты в строки для вывода
    for (const auto& res : results) {
        explanations.push_back(res.expression + " = " + to_string(res.result));
    }
    return explanations;
}

int main() {
    string expression1 = "2-1-1";
    string expression2 = "2*3-4*5";
    string expression3 = "5+6*9-12";

    // Вычисляем все возможные варианты выражений
    vector<string> explanations1 = diffWaysToCompute(expression1);
    vector<string> explanations2 = diffWaysToCompute(expression2);
    vector<string> explanations3 = diffWaysToCompute(expression3);

    // Выводим результаты на экран
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