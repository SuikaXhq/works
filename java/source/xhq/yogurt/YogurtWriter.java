/*
 * Question source : Code Jam Kickstart - 2018 Round E - A
 */

package xhq.yogurt;

import java.io.*;

class YogurtWriter
{
	int numCurrent = 1;
	BufferedWriter fw;

	public YogurtWriter(File file) throws Exception {
		fw = new BufferedWriter(new FileWriter(file));
	}
	
	public void write(int i) {
		try
		{
			System.out.println(i);
			fw.write("Case #" + numCurrent + ": " + i + "\n");
			fw.flush();
			numCurrent++;
		}
		catch (Exception ex)
		{
			ex.printStackTrace();
		}
		
	}
}
