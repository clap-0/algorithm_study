import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        List<String> primes = getPrimes(a, b);
        for (String prime : primes) {
            boolean isPalindrome = true;
            int left = 0, right = prime.length() - 1;
            while (left < right) {
                if (prime.charAt(left) != prime.charAt(right)) {
                    isPalindrome = false;
                    break;
                }
                left++; right--;
            }
            if (isPalindrome)
                System.out.println(prime);
        }
        System.out.println(-1);
    }

    static List<String> getPrimes(int a, int b) {
        b = Math.min(b, 10000000);
        boolean[] isPrime = new boolean[b + 1];
        Arrays.fill(isPrime, true);
        List<String> primes = new ArrayList<>(1250);
        for (int i = 3; i <= b; i += 2)
            if (isPrime[i]) {
                for (long j = (long)i * i; j <= b; j += i * 2L)
                    isPrime[(int)j] = false;
                if (i >= a)
                    primes.add(String.valueOf(i));
            }
        return primes;
    }
}
