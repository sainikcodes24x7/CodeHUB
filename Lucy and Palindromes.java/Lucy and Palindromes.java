import java.io.*;

import java.math.BigDecimal;

import java.math.RoundingMode;

import java.util.*;



/*

Ночь, улица, фонарь, аптека,

Бессмысленный и тусклый свет.

Живи ещё хоть четверть века —

Всё будет так. Исхода нет.



Умрёшь — начнёшь опять сначала

И повторится всё, как встарь:

Ночь, ледяная рябь канала,

Аптека, улица, фонарь.



(Блок)

*/



public class Main {



    static FastReader in;

    static PrintWriter out;

    static Random rand = new Random();

    static final int INF = (int) (1e9);

    static final int MOD = (int) (1e9 + 7);

    static final int N = (int) (1e5 + 5);

    static long[] fact;



    static void precalc() {

        fact = new long[N];

        fact[0] = 1;

        for (int i = 1; i < N; i++) {

            fact[i] = fact[i - 1] * i;

            fact[i] %= MOD;

        }

    }



    static long binPow(long a, long b) {

        long res = 1;

        while (b > 0) {

            if ((b & 1) == 1) {

                res = (res * a) % MOD;

            }

            a = (a * a) % MOD;

            b >>= 1;

        }

        return res;

    }



    static class ImplicitTreap {

        static final int INF = (int) (1e9);

        static Random rand = new Random();

        Node root, m, l, r;



        class Node {

            int y;

            char ch;

            int[] chars;

            int rev;

            int cnt;

            Node l, r;



            Node(int y, char ch) {

                this.y = y;

                this.ch = ch;

                chars = new int['j' - 'a' + 1];

                chars[ch - 'a']++;

                rev = 0;

                cnt = 1;

                l = r = null;

            }

        }



        int cnt(Node t) {

            if (t != null) {

                return t.cnt;

            }

            return 0;

        }

        long calc(Node t) {

            if (t != null) {

                ArrayList<Integer> l = new ArrayList<>();

                int cntOdd = 0, sum = 0;

                for (int i = 0; i < t.chars.length; i++) {

                    if (t.chars[i] % 2 == 1) {

                        cntOdd++;

                    }

                    l.add(t.chars[i] / 2);

                    sum += t.chars[i] / 2;

                }

                if (cntOdd > 1) {

                    return 0;

                }

                long res = fact[sum];

                for (int ll : l) {

                    res *= binPow(fact[ll], MOD - 2);

                    res %= MOD;

                }

                return res;

            }

            return 0;

        }



        void push(Node t) {

            if (t.rev == 1) {

                if (t.l != null) {

                    t.l.rev ^= 1;

                }

                if (t.r != null) {

                    t.r.rev ^= 1;

                }

                Node t1 = t.l;

                t.l = t.r;

                t.r = t1;

                t.rev = 0;

            }

        }



        void recalc(Node t) {

            t.cnt = 1 + cnt(t.l) + cnt(t.r);

            Arrays.fill(t.chars, 0);

            t.chars[t.ch - 'a']++;

            if (t.l != null) {

                for (int i = 0; i < t.chars.length; i++) {

                    t.chars[i] += t.l.chars[i];

                }

            }

            if (t.r != null) {

                for (int i = 0; i < t.chars.length; i++) {

                    t.chars[i] += t.r.chars[i];

                }

            }

        }



        void merge(Node t1, Node t2) {

            if (t1 == null || t2 == null) {

                m = t1 == null ? t2 : t1;

                return;

            }

            if (t1.y >= t2.y) {

                push(t1);

                merge(t1.r, t2);

                t1.r = m;

                m = t1;

            } else {

                push(t2);

                merge(t1, t2.l);

                t2.l = m;

                m = t2;

            }

            recalc(m);

        }



        // [x1, x2] -> [x1, x] (x, x2]

        void split(Node t, int x) {

            if (t == null) {

                l = r = null;

                return;

            }

            push(t);

            int i = cnt(t.l) + 1;

            if (i <= x) {

                split(t.r, x - i);

                t.r = l;

                l = t;

                recalc(l);

            } else {

                split(t.l, x);

                t.l = r;

                r = t;

                recalc(r);

            }

        }



        void update(Node t) {

            if (t != null) {

                push(t);

                update(t.l);

                update(t.r);

                recalc(t);

            }

        }



        void print(Node t) {

            if (t != null) {

                print(t.l);

                out.print(t.ch);

                print(t.r);

            }

        }

        void print() {

            update(root);

            print(root);

            out.println();

        }





        void build(char[] vals) {

            Stack<Node> st = new Stack<>();

            for (int i = 0; i < vals.length; i++) {

                Node curr = new Node(rand.nextInt(), vals[i]);

                Node last = null;

                while (!st.empty() && st.peek().y < curr.y) {

                    last = st.pop();

                }

                curr.l = last;

                if (st.empty()) {

                    root = curr;

                } else {

                    st.peek().r = curr;

                }

                st.push(curr);

            }



            update(root);

        }



        // [i, j)

        long calcOn(int i, int j) {

            split(root, i);

            Node t = l;

            split(r, j - i);

            long res = calc(l);

            merge(t, l);

            merge(m, r);

            root = m;

            return res;

        }



        // [i, j)

        void revOn(int i, int j) {

            split(root, i);

            Node t = l;

            split(r, j - i);

            l.rev ^= 1;

            merge(t, l);

            merge(m, r);

            root = m;

        }

    }



    static void solve() {

        int n = in.nextInt();

        int m = in.nextInt();



        precalc();



        ImplicitTreap it = new ImplicitTreap();



        char[] s = in.next().toCharArray();

        it.build(s);



        for (int i = 0; i < m; i++) {

            int t = in.nextInt();

            if (t == 1) {

                int l = in.nextInt() - 1;

                int r = in.nextInt();

                it.revOn(l, r);

            } else {

                int l = in.nextInt() - 1;

                int r = in.nextInt();

                out.println(it.calcOn(l, r));

            }

        }

    }



    public static void main(String[] args) throws FileNotFoundException {

        in = new FastReader(System.in);

//        in = new FastReader(new FileInputStream("input.txt"));

        out = new PrintWriter(System.out);

//        out = new PrintWriter(new FileOutputStream("output.txt"));





        int q = 1;



        while (q-- > 0) {

            solve();

        }



        out.close();

    }



    static class FastReader {

        BufferedReader br;

        StringTokenizer st;



        FastReader(InputStream is) {

            br = new BufferedReader(new InputStreamReader(is));

        }



        Integer nextInt() {

            return Integer.parseInt(next());

        }



        Long nextLong() {

            return Long.parseLong(next());

        }



        Double nextDouble() {

            return Double.parseDouble(next());

        }



        String next() {

            while (st == null || !st.hasMoreTokens()) {

                st = new StringTokenizer(nextLine());

            }

            return st.nextToken();

        }



        String nextLine() {

            String s = "";

            try {

                s = br.readLine();

            } catch (IOException e) {

                e.printStackTrace();

            }

            return s;

        }

    }

}
