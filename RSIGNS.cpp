import java.util.*;
class am
{
static long modulo(long  k, long a)
{
long  m=1000000007;
if(k==0)
{
return 1;
}
if(k%2!=0)
{
return (a*modulo((k-1)/2,((a*a)%m)))%m;
}
return modulo(k/2,((a*a)%m));
}
public static void main(String[]args)
{
    long  t,k,m=1000000007;
    Scanner sc=new Scanner(System.in);
    t=sc.nextLong();
    while(t-->0)
    {
    	k=sc.nextLong();
    	long  a = modulo(k-1,2);
    	a=a*10;
    	a=a%m;
    	System.out.println(a);
    }
}
}
