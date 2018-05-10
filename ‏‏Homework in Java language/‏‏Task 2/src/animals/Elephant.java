package animals;

import diet.Herbivore;
import diet.IDiet;
import utilities.MessageUtility;
import food.EFoodType;
import mobility.Point;

/**
 *The class represent a elephant.
 * @author Oshry nahmani
 * @version 1.1
 * @variable trunkLength
 * @date 17.4.17
 * @see AnimalThatRoars
 */
public class Elephant extends AnimalThatChews {

	private double trunkLength;
	
	/**
	 * Constructor to elephant
	 * @param name, trunk
	 */
	public Elephant(String name,double trunkLength) {
		super(name,new Point(50,90));
		MessageUtility.logConstractor("Elephant", this.name);
		this.setWeight(500);
		this.settrunkLength(trunkLength);
		IDiet d=this.getDiet();
		d=new Herbivore();
		this.setDiet(d);
		// TODO Auto-generated constructor stub
	}
	
	/**
	 * The function get trunkLength from Elephant.
	 * @return trunkLength
	 */
	public double gettrunkLength() {
		return trunkLength;
	}

	/**
	 * The function set length of trunk to elephant
	 * @param trunk
	 * @return true if the value is legal 
	 */
	public boolean settrunkLength(double trunkLength) {
		if(trunkLength>=0.5 && trunkLength<=3)
		{
			this.trunkLength = trunkLength;
			MessageUtility.logSetter(this.name, "settrunkLength", trunkLength, true);
			return true;
		}
		else 
		{
			this.trunkLength=1;
			MessageUtility.logSetter(this.name, "settrunkLength", trunkLength, false);
			return false;
		}
	}

	/**
	 * The function return the foodType of animal.
	 * @return EFoodType
	 */
	public EFoodType getFoodtype() {
		// TODO Auto-generated method stub
		MessageUtility.logGetter(this.name, "getFoodtype", EFoodType.MEAT);
		return EFoodType.MEAT;
	}

	/**
	 * The function represent a chew of animal
	 */
	public void chew() {
		// TODO Auto-generated method stub
		MessageUtility.logSound(this.name,"Trumpets with joy while flapping its ears, then chews");
	}

	public String toString() {
		return "[" + this.getClass().getSimpleName() + "] "+this.name;
	}
}
