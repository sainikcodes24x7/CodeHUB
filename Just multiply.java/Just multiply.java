import java.io.*;

import java.util.*;

class p1{

          /* this function gives the resule of (a*b)%p where a,b and p are in rage of 10^18 */

       static long multiply(long a,long b,long p){   

                 

                 long div=1000000000l;

                 long a1=(a/div),a2=(a%div);

                 long b1=(b/div),b2=(b%div);

                 long ans=(a1*b1)%p;

                  

                for(int i=1;i<=9;i++)   

                    {

                       long x=ans;

                      for(int j=1;j<=9;j++)

                       ans=(ans+x)%p;

                    }

                  

                        ans=(ans+a1*b2+a2*b1)%p;

                 for(int i=1;i<=9;i++)   

                     {

                       long x=ans;

                        for(int j=1;j<=9;j++)

                           ans=(ans+x)%p;

                     }

                     ans=(ans+a2*b2)%p;

              

                return(ans);

         } 

   static long solve(long m,String s){



                           long ans=1;

                           int l =s.length();

                        for(int i=0;i<l;i++){

                                  int j=i;

                                  long A = 0;

                                  while(j<l&&(s.charAt(j)>='0'&&s.charAt(j)<='9')){

                                          A=(A*10+s.charAt(j)-'0')%m;

                                               j++;

                               

                                    }

                                  j++; j++;

                                    long mul=1;

                                 while(j<l&&(s.charAt(j)>='0'&&s.charAt(j)<='9')){

                                               long temp =1;

                                            for(int k=1;k<=10;k++)

                                                temp=multiply(temp,mul,m);

                                                 mul=temp;

                                           for(int k=1;k<=(s.charAt(j)-'0');k++)

                                                mul=multiply(mul,A,m);

                                              j++;

                                   

                                   }

                                ans= multiply(ans,mul,m);

                              i=j;

                       }

                           return(ans);

               }

   public static void main(String aegs[]){

                  Scanner sc = new Scanner(System.in);

                  PrintWriter out = new PrintWriter(System.out);

                     int t = sc.nextInt();

                    for(int h=1;h<=t;h++){                    

                            long m = sc.nextLong();

                            String s = sc.next();

                            out.println(solve(m,s));

                     }

                 out.flush();

         }

}
