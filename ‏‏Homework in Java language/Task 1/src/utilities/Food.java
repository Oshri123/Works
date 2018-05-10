package utilities;
/** Sets food
 * @version 1.0 25/3/2017
 * @author Oshry Nachmani
 *
 */

public class Food {
	private String name,type;
	
	public Food(String name,String type)
	{
		this.name=name;
		this.type=type;
	}
	
	/**
	 * Set to name
	 * @param name
	 * @return True if success / false if not
	 */
	public boolean setName(String name)
	{
		this.name=name;
		return true;
	}
	public String getName(){return this.name;}
	
	/**
	 * Set to type
	 * @param name
	 * @return True if success / false if not
	 */
	public boolean setType(String type)
	{
		this.type=type;
		return true;
	}
	public String getType(){return this.type;}

}
