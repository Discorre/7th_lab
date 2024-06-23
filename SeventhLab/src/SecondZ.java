import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class ExpressionResult {
    int result;
    String expression;

    public ExpressionResult(int result, String expression) {
        this.result = result;
        this.expression = expression;
    }
}

public class SecondZ {
    static Map<String, List<ExpressionResult>> memo = new HashMap<>();

    public static List<ExpressionResult> diffWaysToComputeHelper(String expression) {
        if (memo.containsKey(expression)) {
            return memo.get(expression);
        }

        List<ExpressionResult> result = new ArrayList<>();
        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                List<ExpressionResult> leftResults = diffWaysToComputeHelper(expression.substring(0, i));
                List<ExpressionResult> rightResults = diffWaysToComputeHelper(expression.substring(i + 1));
                for (ExpressionResult left : leftResults) {
                    for (ExpressionResult right : rightResults) {
                        int res;
                        if (c == '+') res = left.result + right.result;
                        else if (c == '-') res = left.result - right.result;
                        else res = left.result * right.result;
                        String exp = "(" + left.expression + c + right.expression + ")";
                        result.add(new ExpressionResult(res, exp));
                    }
                }
            }
        }
        if (result.isEmpty()) {
            int res = Integer.parseInt(expression);
            result.add(new ExpressionResult(res, expression));
        }
        memo.put(expression, result);
        return result;
    }

    public static List<String> diffWaysToCompute(String expression) {
        List<ExpressionResult> results = diffWaysToComputeHelper(expression);
        List<String> explanations = new ArrayList<>();
        for (ExpressionResult res : results) {
            explanations.add(res.expression + " = " + res.result);
        }
        return explanations;
    }

    public static void main(String[] args) {
        String expression1 = "2-1-1";
        String expression2 = "2*3-4*5";

        List<String> explanations1 = diffWaysToCompute(expression1);
        List<String> explanations2 = diffWaysToCompute(expression2);

        System.out.println("Output 1:");
        for (String exp : explanations1) {
            System.out.println(exp);
        }
        System.out.println();

        System.out.println("Output 2:");
        for (String exp : explanations2) {
            System.out.println(exp);
        }
    }
}
