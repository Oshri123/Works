package utilities;
/**
 * Sets position on a two dimensional axis
 * @version 1.0 25/3/2017
 * @author Oshry Nachmani
 *
 */
public class Point {
	
	private int x,y;
	/**
	 * Constructor
	 * @param _x
	 * @param _y
	 */
	public Point(int x, int y)
	{
		if(!(setX(x)))
			this.x=0;
		if(!(setY(y)))
			this.y=0;
	}
	/**
	 * set x
	 * @param x
	 * @return True if success / false if not
	 */

	public boolean setX(int x)
	{
		if (x<0 || x>800)
		{
			return false;
		}
		else
		{
			this.x=x;
			return true;
		}
	}
	public int getX(){return this.x;}
	
	/**
	 * set y
	 * @param x
	 * @return True if success / false if not
	 */
	public boolean setY(int y)
	{
		if (y<0 || y>600)
		{
			return false;
		}
		else
		{
			this.y=y;
			return true;
		}
	}
	public int getY(){return this.y;}
	
	public String toString()
	{
		return ""+x+','+y;
	}
}


