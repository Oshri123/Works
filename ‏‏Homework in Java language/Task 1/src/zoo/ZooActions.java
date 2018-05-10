package zoo;
//Oshry Nachmani 204566194
//Campus Beer Sheva
import animals.Bear;
import animals.Elephant;
import animals.Giraffe;
import animals.Lion;
import animals.Turtle;
import utilities.Food;
import utilities.Point;

/**Class number 3 with static functions
 * @version 1.0 25/3/2017
 * @author Oshry Nachmani
 *
 */

public class ZooActions {

	/**
	 * The function check if the type of food is OK with the the type of the animal
	 * and then update his new weight.
	 * @param obj animal
	 * @param obj food
	 * @return (true/false) if the animal eat
	 */

	public static boolean eat(Object animal,Food food)
	{
		boolean flag=false;
		if(animal instanceof Lion )
		{
			if(food.getType()==((Lion) animal).getType())
				flag = true;
			((Lion) animal).setWeight(1.10*((Lion) animal).getWeight());
		}
		else if(animal instanceof Bear )
		{
			if(food.getType()==((Bear) animal).getType())
				flag = true;
			((Bear) animal).setWeight(1.10*((Bear) animal).getWeight());
		}
		else if(animal instanceof Elephant )
		{
			if(food.getType()==((Elephant) animal).getType())
				flag = true;
			((Elephant) animal).setWeight(1.05*((Elephant) animal).getWeight());
		}
		else if(animal instanceof Turtle )
		{
			if(food.getType()==((Turtle) animal).getType())
				flag = true;
			((Turtle) animal).setWeight(1.05*((Turtle) animal).getWeight());
		}
		else if(animal instanceof Giraffe )
		{
			if(food.getType()==((Giraffe) animal).getType())
				flag = true;
			((Giraffe) animal).setWeight(1.05*((Giraffe) animal).getWeight());
		}
		return flag;
	}
	
	/**
	 * The function get point (x,y) and check if the point in range and go there by setting new location.
	 * if the animal moved the function updates his weight.
	 * @param animal
	 * @param point
	 * @return (true/false) if the animal eat
	 */
	public static boolean move(Object animal,Point point)
	{
		int x=point.getX(),y=point.getY();
		double dist=0,w=0;
		Point p;
		if ( x<0 || x>800 || y<0 || y>600 )
			return false;
		
		if(animal instanceof Lion )
		{
			p=((Lion) animal).getPosition();
			dist=((Lion) animal).getDistance();
			w=((Lion) animal).getWeight();
			((Lion) animal).setWeight(w-(Math.sqrt(Math.pow(x-p.getX(), 2)+Math.pow(y-p.getY(), 2))*w*0.001));
			((Lion) animal).setDistance(dist+Math.sqrt(Math.pow(x-p.getX(), 2)+Math.pow(y-p.getY(), 2)));
			((Lion) animal).setPosition(point);
		}
		else if(animal instanceof Bear )
		{
			p=((Bear) animal).getPosition();
			dist=((Bear) animal).getDistance();
			w=((Bear) animal).getWeight();
			((Bear) animal).setWeight(w-(Math.sqrt(Math.pow(x-p.getX(), 2)+Math.pow(y-p.getY(), 2))*w*0.001));
			((Bear) animal).setDistance(dist+Math.sqrt(Math.pow(x-p.getX(), 2)+Math.pow(y-p.getY(), 2)));
			((Bear) animal).setPosition(point);
		}
		else if(animal instanceof Elephant )
		{
			p=((Elephant) animal).getPosition();
			dist=((Elephant) animal).getDistance();
			w=((Elephant) animal).getWeight();
			((Elephant) animal).setWeight(w-(Math.sqrt(Math.pow(x-p.getX(), 2)+Math.pow(y-p.getY(), 2))*w*0.001));
			((Elephant) animal).setDistance(dist+Math.sqrt(Math.pow(x-p.getX(), 2)+Math.pow(y-p.getY(), 2)));
			((Elephant) animal).setPosition(point);
		}
		else if(animal instanceof Turtle )
		{
			p=((Turtle) animal).getPosition();
			dist=((Turtle) animal).getDistance();
			w=((Turtle) animal).getWeight();
			((Turtle) animal).setWeight(w-(Math.sqrt(Math.pow(x-p.getX(), 2)+Math.pow(y-p.getY(), 2))*w*0.001));
			((Turtle) animal).setDistance(dist+Math.sqrt(Math.pow(x-p.getX(), 2)+Math.pow(y-p.getY(), 2)));
			((Turtle) animal).setPosition(point);
		}
		else if(animal instanceof Giraffe )
		{
			p=((Giraffe) animal).getPosition();
			dist=((Giraffe) animal).getDistance();
			w=((Giraffe) animal).getWeight();
			((Giraffe) animal).setWeight(w-(Math.sqrt(Math.pow(x-p.getX(), 2)+Math.pow(y-p.getY(), 2))*w*0.001));
			((Giraffe) animal).setDistance(dist+Math.sqrt(Math.pow(x-p.getX(), 2)+Math.pow(y-p.getY(), 2)));
			((Giraffe) animal).setPosition(point);
		}
		
		return true;
	}
}
