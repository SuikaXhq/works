/*
 * Question source : Code Jam Kickstart - 2018 Round E - A
 */

package xhq.yogurt;

import java.util.*;

class YogurtSolver 
{
	private ArrayList<Long> aList = new ArrayList<Long>();
	private int k = 0;

	public void load(long[] ints,int k) {
		aList.clear();
		for (long i:ints)
			aList.add(i);
		Collections.sort(aList);
		this.k = k;
	}

	public int calc() {
		int i = 0;
		while (i < aList.size())
		{
			if (i < aList.size() && aList.get(i) * k >= i + 1)
				i++;
			else if (i < aList.size())
				aList.remove(i);
		}
		return aList.size();
	}
}