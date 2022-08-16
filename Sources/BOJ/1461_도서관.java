import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        List<Integer> bookPos = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            bookPos.add(Integer.parseInt(st.nextToken()));

        Collections.sort(bookPos);
        int ans = 0;
        int negativeNums = 0;
        List<Integer> negativePos = new ArrayList<>();
        while (negativeNums < N && bookPos.get(negativeNums) < 0) {
            negativePos.add(-bookPos.get(negativeNums));
            ++negativeNums;
        }
        Collections.reverse(negativePos);

        boolean isNegativeFurther = (negativeNums > 0 ? negativePos.get(negativeNums - 1) : 0) >
                (negativeNums < N ? bookPos.get(N - 1) : 0);

        ans = getSteps(M, isNegativeFurther, negativePos) + getSteps(M, !isNegativeFurther, bookPos.subList(negativeNums, N));
        System.out.println(ans);
    }

    static int getSteps(int M, boolean isFurther, List<Integer> bookPos) {
        int ret = 0;
        int books = bookPos.size();
        if (books == 0)
            return 0;
        int tmp = 0;
        bookPos.add(0, 0);
        if (M >= books)
            ret = bookPos.get(books);
        else {
            tmp = books % M;
            ret += (books / M) * bookPos.get(tmp) * 2 + bookPos.get(tmp);
            for (int i = tmp + M; i < books; i += M)
                ret += (bookPos.get(i) - bookPos.get(tmp)) * 2;
            ret += bookPos.get(books) - bookPos.get(tmp);
        }
        if (!isFurther)
            ret += bookPos.get(books);
        return ret;
    }
}
