package animals;

import mobility.Point;

/**
 *The class represent only animal that roars.
 * @author Oshri nahmani
 * @version 1.1
 * @date 17.07.2017
 * @see Animal
 */
public abstract class AnimalThatRoars extends Animal {

	/**
	 * Constructor
	 * @param name
	 * @param p
	 */
	public AnimalThatRoars(String name,Point p) {
		super(name,p);
		// TODO Auto-generated constructor stub
	}
	
	/**
	 * Abstract function
	 */
	public abstract void roar();
	
	/**
	 * The function turn on the sound of animal by type
	 */
	public void makeSound()
	{
		this.roar();
	}

}
