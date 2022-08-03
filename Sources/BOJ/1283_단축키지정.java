import java.util.Scanner;

public class Main {
    static boolean[] shortcuts = new boolean[26];
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        outer:
        for (int i = 0; i < N; i++)
        {
            String option = scanner.nextLine();
            String[] words = option.split(" ");
            for(int j = 0; j < words.length; j++)
                if (canMakeShortcut(words[j], 0))
                {
                    printOption(words, j, 0);
                    continue outer;
                }
            for(int j = 0; j < words.length; j++)
                for(int k = 1; k < words[j].length(); k++)
                    if(canMakeShortcut(words[j], k))
                    {
                        printOption(words, j, k);
                        continue outer;
                    }
            System.out.println(option);
        }
    }

    static boolean canMakeShortcut(String word, int shortcut)
    {
        char ch = word.charAt(shortcut);
        int num = Character.isUpperCase(ch) ? ch - 'A' : ch - 'a';
        if(!shortcuts[num])
        {
            shortcuts[num] = true;
            return true;
        }
        return false;
    }

    static void printOption(String[] words, int idx, int shortcut)
    {
        for(int i = 0; i < idx; i++)
            System.out.print(words[i] + " ");
        System.out.printf("%s[%c]%s ", words[idx].substring(0, shortcut), words[idx].charAt(shortcut), words[idx].substring(shortcut + 1));
        for(int i = idx + 1; i < words.length; i++)
            System.out.print(words[i] + " ");
        System.out.println();
    }
}
