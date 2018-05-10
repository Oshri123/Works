package mobility;
/**
 * Sets position on a two dimensional axis
 * @version 1.0 18/4/2017
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
		setX(x);
		setY(y);
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
			this.x=x;
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
			this.y=y;
			return false;
		}
		else
		{
			this.y=y;
			return true;
		}
	}
	public int getY(){return this.y;}
	
	public static boolean cheackBounderies(Point p)
	{
		if( (p.getX() >=0) && (p.getX() <=800) && (p.getY() >=0) && (p.getY() <=600) )
			return true;
		
		return false;
	}
	
	public String toString()
	{
		return ""+x+','+y;
	}
}


