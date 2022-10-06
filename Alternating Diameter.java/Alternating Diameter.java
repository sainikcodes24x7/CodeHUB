/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
	
		    Scanner sc=new Scanner(System.in);
		    int t=sc.nextInt();
		    while(t-->0){
		         int b=sc.nextInt();
		         int w=sc.nextInt();
		         solve(b,w);
		    }
		    
	
	}
	public static void solve(int b,int w){
	    if((b==0||w==0)&& (b+w>1)){
	        System.out.println(-1);
	    }
	    else{
	    int root=1;
	    if(w==1)root=w+b;
	    
	    for(int i=0;i<b;i++)
	     System.out.print("B");
	    
	    for(int i=0;i<w;i++)
	       System.out.print("W");
	    System.out.println();
	    
	    for(int i=1;i<=b+w;i++){
	        if(i!=root){
	        System.out.println(root+" "+i);
	        }
	    }
	    }
	    
	}
}
