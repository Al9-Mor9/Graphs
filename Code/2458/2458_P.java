import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    static int N, M, a, b;
    static boolean[][] floyd;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        floyd = new boolean[N + 1][N + 1];
        M = Integer.parseInt(st.nextToken());
        for (int i = 0; i < M; i++){
            String[] s = br.readLine().split(" ");
            a = Integer.parseInt(s[0]);
            b = Integer.parseInt(s[1]);
            floyd[b][a] = true;
        }
        for (int k = 1; k <= N; k++){
            for (int i = 1; i <= N; i++){
                for (int j = 1; j <= N; j++) {
                    if (floyd[i][k] && floyd[k][j]) floyd[i][j] = true;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= N; i++){
            int sum = 0;
            for (int j = 1; j <= N; j++) {
                sum += (floyd[i][j] ? 1 : 0) + (floyd[j][i] ? 1 : 0);
            }
            if (sum == N - 1) ans++;
        }
        System.out.println(ans);
    }
}
