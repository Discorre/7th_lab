import java.util.Arrays;

public class FirstZ {
    static final int INF = 1000000000; // Константа для представления бесконечности

    // Функция для нахождения кратчайшего гамильтонова цикла методом динамического программирования
    static int tsp(int pos, int mask, int[][] graph, int[][] dp, int[][] prev) {
        int n = graph.length; // Количество городов в графе

        if (mask == (1 << n) - 1)
            return 0; // Вернуть стоимость возврата в начальный город

        // Если уже рассчитано значение для данной позиции и маски, возвращаем его
        if (dp[pos][mask] != -1)
            return dp[pos][mask];

        int ans = INF; // Инициализация ответа как бесконечности
        int bestNext = -1; // Лучший следующий город для посещения

        // Перебираем все возможные следующие города
        for (int next = 0; next < n; ++next) {
            // Если город еще не посещен
            if ((mask & (1 << next)) == 0) {
                // Рекурсивно вызываем tsp для следующего города
                int newAns = graph[pos][next] + tsp(next, mask | (1 << next), graph, dp, prev);
                // Обновляем ответ, если новый путь короче
                if (newAns < ans) {
                    ans = newAns;
                    bestNext = next;
                }
            }
        }

        // Запоминаем лучшего следующего города для данной позиции и маски
        prev[pos][mask] = bestNext;
        // Запоминаем рассчитанное значение для данной позиции и маски
        return dp[pos][mask] = ans;
    }

    // Функция для вывода кратчайшего пути
    static void printPath(int pos, int mask, int[][] prev) {
        int n = prev.length;
        // Если все города уже посещены, выводим последний город и завершаем функцию
        if (mask == (1 << n) - 1) {
            System.out.print(pos + " ");
            return;
        }

        // Получаем следующий город по пути
        int next = prev[pos][mask];
        // Выводим текущий город
        System.out.print(pos + " ");
        // Рекурсивно вызываем функцию для следующего города
        printPath(next, mask | (1 << next), prev);
    }

    // Основная функция программы
    public static void main(String[] args) {
        // Инициализация весов рёбер графа
        int[][] graph = {
                {0, 40, 65, 2},
                {40, 0, 35, 25},
                {65, 35, 0, 30},
                {2, 25, 30, 0}
        };

        int n = graph.length; // Количество городов

        // Инициализация массивов для динамики и восстановления пути
        int[][] dp = new int[n][1 << n];
        int[][] prev = new int[n][1 << n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
            Arrays.fill(prev[i], -1);
        }

        // Вызываем функцию для нахождения кратчайшего гамильтонова цикла, начиная с города 0
        int ans = tsp(0, 1, graph, dp, prev);
        // Выводим минимальную стоимость обхода всех городов
        System.out.println("Минимальная стоимость обхода всех городов: " + ans);

        // Выводим минимальный путь
        System.out.print("Минимальный путь: ");
        printPath(0, 1, prev);
        System.out.println();
    }
}
