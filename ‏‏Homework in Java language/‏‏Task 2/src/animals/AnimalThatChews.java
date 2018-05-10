package animals;


import mobility.Point;

/**
 *The class represent only animal that chews.
 * @version 1.1
 * @author snir
 * @date 17.07.2017
 * @see Animal
 */
public abstract class AnimalThatChews extends Animal {
	
	/**
	 * Constructor
	 * @param name
	 * @param p
	 */
	public AnimalThatChews(String name,Point p) {
		super(name,p);
		// TODO Auto-generated constructor stub
	}

	/**
	 * Abstract function
	 */
	public abstract void chew();
	
	/**
	 * The function turn on the sound of animal by type
	 */
	public void makeSound()
	{
		this.chew();
	}

}
