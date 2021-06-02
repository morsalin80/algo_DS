import java.math.BigInteger;
import java.util.Scanner;
public class Main{

	public static void main(String[] args){
		Scanner scn = new Scanner(System.in);
		BigInteger tot,temp;
		int n,a;
		while(scn.hasNextInt()){
			n=scn.nextInt();
			a=scn.nextInt();

			tot=new BigInteger("0");
			temp=BigInteger.valueOf(a);

			for(int i=1;i<=n;i++){
				tot=tot.add(BigInteger.valueOf(i).multiply(temp.pow(i)));
			}
			System.out.println(tot);
		} 
	}
}