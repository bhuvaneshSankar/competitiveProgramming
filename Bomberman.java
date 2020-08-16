import java.util.Scanner;

public class Bomberman {
    static Scanner scan = new Scanner(System.in);
    static int minCount = 1000000;
    static boolean flag = false;

    public static void find(char[][] arr, int m, int n, int i, int j, int count, int[][] vis) {
        System.out.println(i + " " + j);
        if (vis[i][j] == 1) {
            return;
        }
        vis[i][j] = 1;
        if (arr[i][j] == 'B') {
            System.out.println("bom " + i + " " + j);
            if (count < minCount) {
                minCount = count;
                flag = true;
            }
            vis[i][j] = 0;
            return;
        }
        if (j < n - 1 && arr[i][j + 1] != 'W') {
            find(arr, m, n, i, j + 1, count + 1, vis); // move right
        }
        if (i < m - 1 && arr[i + 1][j] != 'W') {
            find(arr, m, n, i + 1, j, count + 1, vis); // move down
        }
        if (j > 0 && arr[i][j - 1] != 'W') {
            find(arr, m, n, i, j - 1, count + 1, vis); // move left
        }
        if (i > 0 && arr[i - 1][j] != 'W') {
            find(arr, m, n, i - 1, j, count + 1, vis); // move top
        }
        vis[i][j] = 0;
    }

    public static void printArr(int[][] arr, int m, int n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void resetArr(int[][] arr, int m, int n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = 0;
            }
        }
    }

    public static void solve() {
        int m, n;
        m = scan.nextInt();
        n = scan.nextInt();
        char[][] arr = new char[m][n];
        int[][] res = new int[m][n];
        int[][] visited = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = scan.next().charAt(0);
                visited[i][j] = 0;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 'O') {
                    find(arr, m, n, i, j, 0, visited);
                    if (flag == false) {
                        minCount = -1;
                    }
                    res[i][j] = minCount;
                    minCount = 1000000;
                    flag = false;
                    resetArr(visited, m, n);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 'B') {
                    res[i][j] = 0;
                } else if (arr[i][j] == 'W') {
                    res[i][j] = -1;
                }
            }
        }
        printArr(res, m, n);
        minCount = 1000000;
        flag = false;
        resetArr(visited, m, n);
    }

    public static void main(String[] args) {
        int t = scan.nextInt();
        while (t > 0) {
            --t;
            solve();
        }

    }
}