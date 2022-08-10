import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) throws IOException {
        BigInteger[] cache = new BigInteger[251];
        cache[0] = new BigInteger("1");
        cache[1] = new BigInteger("1");
        for (int i = 2; i <= 250; i++) {
            cache[i] = cache[i - 1].add(cache[i - 2].multiply(BigInteger.valueOf(2L)));
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = null;
        while ((input = br.readLine()) != null) {
            int n = Integer.parseInt(input);
            System.out.println(cache[n]);
        }
    }
}
