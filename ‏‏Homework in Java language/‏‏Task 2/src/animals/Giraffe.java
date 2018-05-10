package animals;

import diet.Herbivore;
import diet.IDiet;
import utilities.MessageUtility;
import food.EFoodType;
import mobility.Point;

/**
 *The class represent a Giraffe.
 * @author Oshry nahmani
 * @version 1.1
 * @variable neckLength
 * @date 17.4.17
 * @see AnimalThatRoars
 */
public class Giraffe extends AnimalThatChews{

	private double neckLength;
	
	/**
	 * Constructor to giraffe
	 * @param name, neck lenght
	 */
	public Giraffe(String name,double neckLength) {
		super(name,new Point(50,0));
		MessageUtility.logConstractor("Giraffe", this.name);
		this.setWeight(450);
		this.setNeckLength(neckLength);
		IDiet d=this.getDiet();
		d=new Herbivore();
		this.setDiet(d);
	}
	
	/**
	 * The function get neckLength from Giraffe.
	 * @return neckLength
	 */
	public double getNeckLength() {
		return neckLength;
	}

	/**
	 * The function set length of neck to giraffe
	 * @param neck
	 * @return true if the value is legal 
	 */
	public boolean setNeckLength(double neckLength) {
		if(neckLength >=1 && neckLength <=2.5)
		{
			this.neckLength = neckLength;
			MessageUtility.logSetter(this.name, "setNeckLength", neckLength, true);
			return true;
		}
		else 
		{
			this.neckLength=1.5;
			MessageUtility.logSetter(this.name, "setNeckLength", neckLength, false);
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
		MessageUtility.logSound(this.name,"Bleats and Stomps its legs, then chews");
	}
	
	public String toString() {
		return "[" + this.getClass().getSimpleName() + "] "+this.name;
	}
	
}
