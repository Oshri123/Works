package animals;

import main.MessageUtility;
import utilities.Point;

public class Bear {

	String type;
	String name;
	double weight;
	Point position;
	double distance;
	
	public Bear(String name)
	{
		MessageUtility.logConstractor(name);
		setName(name);
		setType("predator");
		Point p=new Point(100,5);
		setPosition(p);
		setWeight(308.2);
		this.distance=0;
	}
	
	public Bear(String name,Point p)
	{	
		MessageUtility.logConstractor(name);
		setName(name);
		setType("predator");
		setPosition(p);
		setWeight(308.2);
		this.distance=0;
	}
	/**
	 * Function to set type predator or herbivorous
	 * @param type of the animal by String
	 * @return success or fail
	 */

	public boolean setType(String type)
	{
		boolean flag;
		if (type!="predator" && type!="herbivorous")
		{
			flag = false;
			MessageUtility.logSetter(this.name, "setType", type, flag);
		}
		else
		{
			flag=true;
			this.type=type;
			MessageUtility.logSetter(this.name, "setType", type, flag);
		}
		return flag;
	}
	
	/**
	 * Function to set name
	 * @param name of the animal by String
	 * @return success or fail
	 */

	public boolean setName(String name)
	{
		boolean flag;
		if (name==null)
		{
			flag = false;
			MessageUtility.logSetter("null", "setName", "null", flag);
		}
		else
		{
			flag=true;
			this.name=name;
			MessageUtility.logSetter(this.name, "setName", this.name, flag);
		}

		return flag;
	}
	
	/**
	 * @return the name of the instance
	 */
	public String getType()
	{
		MessageUtility.logGetter(this.name, "getType", this.type);
		return this.type;
	}
	
	/**
	 * @return the name of the instance
	 */
	public String getName()
	{
		MessageUtility.logGetter(this.name, "getName", this.name);
		return this.name;
	}
	/**
	 * Function to set weight of the animal
	 * @param w - for the weight change
	 * @return success / fail
	 */
	
	public boolean setWeight(double w)
	{
		boolean flag;
		if (w==0)
		{
			flag = false;
			MessageUtility.logSetter(this.name, "setWeight", w, flag);
		}
		else
		{
			flag=true;
			this.weight=w;
			MessageUtility.logSetter(this.name, "setWeight", w, flag);
		}

		return flag;		
	}

	/**
	 * @return the name of the instance
	 */

	public double getWeight()
	{
		MessageUtility.logGetter(this.name, "getWeight", this.weight);
		return this.weight;
	}
	/**
	 * Function to set a new position
	 * @param  - for the change position
	 * @return success / fail
	 */
	public boolean setPosition(Point p)
	{
		boolean flag;
		this.position=new Point(0,0);
		if (!(this.position.setX(p.getX()) && this.position.setY(p.getY())))
		{
			flag = false;
			MessageUtility.logSetter(this.name, "setPosition", this.position, flag);
		}
		else
		{
			flag=true;
			MessageUtility.logSetter(this.name, "setPosition", this.position, flag);
		}

		return flag;	
	}
	/**
	 * @return the name of the instance
	 */

	public Point getPosition()
	{
		MessageUtility.logGetter(this.name, "getPosition", this.position);
		return this.position;
	}
	
	/**
	 * Function to set distance of the animal.
	 * @param d - for the distance change
	 * @return success / fail
	 */
	
	public boolean setDistance(double d)
	{
		boolean flag;
		if (d<0)
		{
			flag = false;
			MessageUtility.logSetter(this.name, "setDistance", d, flag);
		}
		else
		{
			flag=true;
			this.distance=d;
			MessageUtility.logSetter(this.name, "setDistance", this.distance, flag);
		}

		return flag;	
	}
	/**
	 * @return the name of the instance
	 */

	public double getDistance()
	{
		MessageUtility.logGetter(this.name, "getDistance", this.distance);
		return this.distance;
	}
	
	public String toString()
	{
		return(MessageUtility.logString( getName(),getDistance(),getWeight() ));
	}
}
