package animals;

import diet.Herbivore;
import diet.IDiet;
import diet.Omnivore;
import utilities.MessageUtility;
import food.EFoodType;
import food.IEdible;
import mobility.Point;

/**
* Turtle is one of the animals in our Zoo
* @date 17.4.17
* @author Shay miara
* @variable Age
* @version 1.1
*/
public class Turtle extends AnimalThatChews{

	private int Age;
	
	/**
	 * Constructor of Turtle
	 * @param name
	 */
	public Turtle(String name,int Age) {
		super(name,new Point(80,0));
		MessageUtility.logConstractor("Turtle", this.name);
		this.setWeight(1);
		this.setAge(Age);
		IDiet d=this.getDiet();
		d=new Herbivore();
		this.setDiet(d);
	}
		
	public int getAge() {
		return this.Age;
	}

	/**
	 * The function set Age to turtle.
	 * @return True or false and update the age
	 */
	public boolean setAge(int age) {
		if(age >=1 && age <=500)
		{
			this.Age = age;
			MessageUtility.logSetter(this.name, "setAge", age, true);
			return true;
		}
		else 
		{
			this.Age=1;
			MessageUtility.logSetter(this.name, "setAge", age, false);
			return false;
		}
	}

	/**
	 * The function return the foodType of animal.
	 * @return EFoodType
	 */
	public EFoodType getFoodtype() {
		MessageUtility.logGetter(this.name, "getFoodtype", EFoodType.MEAT);
		return EFoodType.MEAT;
	}

	/**
	 * The function represent a chew of animal
	 */
	public void chew() {
		// TODO Auto-generated method stub
		MessageUtility.logSound(this.name,"Retracts its head in then eats quietly");
	}
	
	public String toString() {
		return "[" + this.getClass().getSimpleName() + "] "+this.name;
	}
	
}
