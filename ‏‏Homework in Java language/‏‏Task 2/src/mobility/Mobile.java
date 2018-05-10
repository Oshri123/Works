package mobility;

/**
 *Abstract class - represent functionality of moving
 * @author Oshry nahmani
 * @param Point location, double totalDistance
 * @date 18.4.17
 * @see Mobile, ILocatable
 */
public abstract class Mobile implements ILocatable {
	
	private Point location;// Current location
	private double totalDistance;// Distance the object traveled

	/**
	 * Constructor
	 * @param _p
	 */
	public Mobile(Point p)
	{
		setLocation(p);
		this.totalDistance=0;
	}
	
	/**
	 * The function return location of animal
	 * @return Point location
	 */
	public Point getLocation(){
		return this.location;
	}
	public boolean setLocation(Point p)
	{
		this.location=p;
		return false;
	}

	/**
	 * The function return total distance of animal
	 * @return double totalDistance
	 */
	public double getTotalDistance() {
		return totalDistance;
	}

	public void setTotalDistance(double totalDistance) {
		this.totalDistance = totalDistance;
	}
	
	/**
	 * The function adding new distance to total distance that some animal moved
	 * @param double d
	 */
	public void addTotalDistance(double dist){
		this.totalDistance+=dist;
	}
	
	/**
	 * The function calculate distance between tow points
	 * @param obj point
	 * @return distance
	 */
	public double calcDistance(Point p){
		int x=p.getX(),y=p.getY();
		if ( x<0 || x>800 || y<0 || y>600 )
			return 0;
		
		else
			return Math.sqrt(Math.pow(x-location.getX(), 2)+Math.pow(y-location.getY(), 2));
	}
	
	/**
	 * the method is abstract 
	 * @param obj point
	 * @see Calss Animal - implement of the function
	 */
	public abstract double move(Point p);

}
