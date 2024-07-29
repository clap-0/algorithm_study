class Solution {
    public String solution(String my_string, String overwrite_string, int s) {
        StringBuilder answer = new StringBuilder(my_string);

        /* StringBuilder : public StringBuilder replace​(int start, int end, String str)
         *
         * start - The beginning index, inclusive.
         * end - The ending index, exclusive.
         * str - String that will replace previous contents.
        */
        answer.replace(s, s + overwrite_string.length(), overwrite_string);
        
        return answer.toString();
    }
}
