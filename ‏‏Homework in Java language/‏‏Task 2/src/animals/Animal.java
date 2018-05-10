package animals;

import utilities.MessageUtility;
import diet.IDiet;
import mobility.Mobile;
import mobility.Point;
import food.IEdible;

/**
 *The class represent some animal
 * @version 1.1
 * @author Oshry nahmani
 * @variable name, weight, diet 
 * @date 17/4/17
 * @see Mobile, IEdible
 */
public abstract class Animal extends Mobile implements IEdible{

	protected String name;
	private double weight;
	private IDiet diet;

	/**
	 * Ctor - define name
	 * @param name
	 * @param p
	 */
	public Animal(String name,Point p) {
		super(p);
		MessageUtility.logConstractor("Animal",name);
		setName(name);
		// TODO Auto-generated constructor stub
	}
	
	/**
	 * 
	 * @return the name of animal
	 */
	public String getName(){return this.name;}
	
	/**
	 * 
	 * @return weight of animal
	 */
	public double getWeight() {
		MessageUtility.logGetter(this.name, "getWeight", this.weight);
		return weight;
	}
	
	/**
	 * The func define a weight to the animal
	 * @param weight
	 * @return true if the value is legal
	 */
	public boolean setWeight(double weight)
	{
		if(weight<=0)
		{
			MessageUtility.logSetter(this.name, "setWeight", weight, false);
			return false;
		}
		this.weight = (weight);
		MessageUtility.logSetter(this.name, "setWeight", this.weight, true);
		return true;
	}
	
	public IDiet getDiet() {
		return this.diet;
	}
	
	/**
	 * The function set what kind of food some animal can eating
	 * @param diet
	 * @return boolean value
	 */
	public boolean setDiet(IDiet diet) {
		if(diet==null)
		{
			this.diet = null;
			MessageUtility.logSetter(this.name, "setDiet", diet, false);
			return false;
		}
		this.diet = diet;
		MessageUtility.logSetter(this.name, "setDiet", this.diet, true);
		return true;
	}
	
	/**
	 * The function define a name of animal
	 * @param name
	 * @return true if success
	 */
	public boolean setName(String name) {
		// TODO Auto-generated method stub
		if(name==null)
		{
			this.name = null;
			MessageUtility.logSetter(this.name, "setName", name, false);
			return false;
		}
		this.name=name;
		MessageUtility.logSetter(this.name, "setName", name, true);
		return true;
	}
	
	/**
	 * Abstract method 
	 * 
	 * @see class-Lion, class-Bear, class Elephant, class-giraffe, class-turtle
	 */
	public abstract void makeSound();
	
	/**
	 * the function represent eating of animal
	 * @param food
	 * @return boolean value
	 */
	public boolean eat(IEdible food)
	{
		return this.diet.eat(this, food);
	}

	/**
	 * the function represent a moving of animal
	 * @param Point p
	 * @return true or false and update the weight and the distance of the animal
	 */
	public double move(Point p)	{
		double w1,w2,dist;
		dist=this.calcDistance(p);
		if(dist==0)
		{
			MessageUtility.logBooleanFunction(this.name, "move", p, false);
			return 0;
		}
		w1=this.getWeight();
		w2=Math.round(w1-dist*w1*0.00025*100 / (double)100);
		this.setWeight(w2);
		MessageUtility.logBooleanFunction(this.name, "move", p, true);
		return dist;
		
	}

}
