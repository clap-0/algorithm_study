import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Course[] courses = new Course[N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int number = Integer.parseInt(st.nextToken());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            courses[i] = new Course(number, start, end);
        }
        // 강의의 시작시간을 기준으로 오름차순 정렬한다.
        // 시작시간이 같다면 종료시간을 기준으로 오름차순 정렬한다.
        Arrays.sort(courses);

        // 우선순위큐에 현재 진행중인 강의들의 종료시간을 넣는다.
        Queue<Integer> pq = new PriorityQueue<>();
        pq.offer(0); // pq가 비어있는지 확인하는 코드 대신에 0을 먼저 삽입하도록 하였다.
        for (int i = 0; i < N; i++) {
            // 현재 진행중인 가장 빨리 끝나는 강의의 종료후에 i번째 강의가 시작한다면
            // 해당 강의의 강의실을 i번째 강의가 사용한다.
            if (pq.element() <= courses[i].start)
                pq.remove();
            // 새로운 강의실에서 i번째 강의를 진행한다.
            pq.offer(courses[i].end);
        }
        System.out.println(pq.size());
    }
}

class Course implements Comparable<Course> {
    int number, start, end;
    Course(int number, int start, int end) {
        this.number = number;
        this.start = start;
        this.end = end;
    }

    // 강의의 시작시간을 기준으로 오름차순 정렬한다.
    // 시작시간이 같다면 종료시간을 기준으로 오름차순 정렬한다.
    public int compareTo(Course c) {
        if (this.start != c.start)
            return Integer.compare(this.start, c.start);
        return Integer.compare(this.end, c.end);
    }
}
