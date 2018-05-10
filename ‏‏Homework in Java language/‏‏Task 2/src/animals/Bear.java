package animals;

import diet.IDiet;
import diet.Omnivore;
import utilities.MessageUtility;
import food.EFoodType;
import mobility.Point;

/**
 *The class represent a bear.
 * @author Sahy miara
 * @version 1.1
 * @variable furColor
 * @date 17.4.17
 * @see AnimalThatRoars
 */
public class Bear extends AnimalThatRoars{

	private String furColor;
	
	/**
	 * Constructor to bear
	 * @param name, furColor
	 */
	public Bear(String name,String furColor) {
		super(name,new Point(100,5));
		MessageUtility.logConstractor("Bear", this.name);
		this.setWeight(308.2);
		this.setFurColor(furColor);
		IDiet d=this.getDiet();
		d=new Omnivore();
		this.setDiet(d);
		// TODO Auto-generated constructor stub
	}
	
	/**
	 * The function get furColor from Bear.
	 * @return furColor
	 */
	public String getFurColor() {
		return furColor;
	}

	/**
	 * The function set fur color to bear
	 * @param furColor
	 * @return  
	 */
	public boolean setFurColor(String furColor)
	{
		if (furColor!="GRAY" && furColor!="BLACK" && furColor!="WHITE")
		{
			this.furColor="GRAY";
			MessageUtility.logSetter(this.name, "setFurColor", furColor, false);
			return false;
		}
		else
		{
			this.furColor=furColor;	
			MessageUtility.logSetter(this.name, "setFurColor", furColor, true);
			return true;
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
	 * The function represent a roar of animal
	 */
	public void roar() {
		// TODO Auto-generated method stub
		MessageUtility.logSound(this.name,"Stands on its hind legs, roars and scratches its belly");
	}

	public String toString() {
		return "[" + this.getClass().getSimpleName() + "] "+this.name;
	}

}
