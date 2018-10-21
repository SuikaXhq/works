/*
 * Question source : Code Jam Kickstart - 2018 Round E - A
 */

package xhq.yogurt;

import java.io.*;
import java.util.*;

class YogurtStarter 
{
	YogurtSolver ys = new YogurtSolver();
	int n;
	int k;
	long[] A_i;
	Scanner sc;
	YogurtWriter yr;

	public YogurtStarter() throws Exception {
		sc = new Scanner(new File(this.getClass().getResource("A-small-practice.in.txt").getPath()));
		yr = new YogurtWriter(new File(this.getClass().getResource("").getPath() + "small-output.txt"));
	}

	public static void main(String[] args) 
	{
		try
		{
			new YogurtStarter().start();
		}
		catch (Exception ex)
		{
			ex.printStackTrace();
		}
		
	}

	public void start() throws Exception {
		sc.nextInt();
		while (sc.hasNext())
		{
			n = sc.nextInt();
			k = sc.nextInt();
			System.out.println(n + " " + k);
			A_i = new long[n];
			for (int i = 0;i < n;i++)
				A_i[i] = sc.nextLong();
			ys.load(A_i,k);
			yr.write(ys.calc());
		}
		sc.close();
		yr.fw.close();
	}
}
