
//Oshry Nachmani 204566194
//Campus Beer Sheva
package animals;
import java.util.Random;

import utilities.MessageUtility;
import food.EFoodType;
import food.IEdible;
import mobility.Point;
import diet.Carnivore;
import diet.IDiet;

/**
 *The class represent a Lion.
 * @author Shay miara
 * @version 1.1
 * @variable scarCount
 * @date 17.4.17
 * @see AnimalThatRoars
 */
public class Lion extends AnimalThatRoars{

	private int scarCount;

	/**
	 * Constructor to lion
	 * @param name
	 */
	public Lion(String name) {
		super(name,new Point(20,0));
		MessageUtility.logConstractor("Lion", this.name);
		this.setWeight(408.2);
		IDiet d=this.getDiet();
		d=new Carnivore();
		this.setDiet(d);
		scarCount=0;
		// TODO Auto-generated constructor stub
	}
	
	/**
	 * The function get scarCount from lion.
	 * @return scarCount
	 */
	public int getScarCount() {
		MessageUtility.logGetter(this.name, "getScarCount", scarCount);
		return scarCount;
	}

	/**
	 * The function set scarCount to lion.
	 * @return true or false
	 */
	public boolean setScars(int scarCount)
	{
		this.scarCount = scarCount;
		MessageUtility.logBooleanFunction(name, "setScars", scarCount, true);
		return true;
	}

	/**
	 * The function return the foodType of animal.
	 * @return EFoodType
	 */
	public EFoodType getFoodtype() {
		// TODO Auto-generated method stub
		MessageUtility.logGetter(this.name, "getFoodtype", EFoodType.NOTFOOD);
		return EFoodType.NOTFOOD;
	}
		
	/**
	 * The function represent a roar of animal
	 */
	public void roar() {
		// TODO Auto-generated method stub
		MessageUtility.logSound(this.name,"Roars, then stretches and shakes its mane");
	}

	@Override
	public boolean eat(IEdible food)
	{
		Random rand = new Random();
		if(this.getDiet().eat(this, food))
		{
			if(rand.nextBoolean())
				this.setScars(this.scarCount+1);
			return true;
		}
		return false;
	}
	
	public String toString() {
		return "[" + this.getClass().getSimpleName() + "] "+this.name;
	}

}
