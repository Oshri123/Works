package main;
//Oshry Nachmani 204566194
//Campus Beer Sheva

import animals.Bear;
import animals.Elephant;
import animals.Giraffe;
import animals.Lion;
import animals.Turtle;
import utilities.Food;
import utilities.Point;
import zoo.ZooActions;
/**
 * main program
 * @author Oshry Nachmani
 * @version 1.0
 */
public class Program {

	public static void main(String[] args) {
		
		System.out.println("********************************************");
		System.out.println("Initilize");
		System.out.println("********************************************");
		Lion lion1 = new Lion("Simba");
		Bear bear1 = new Bear("Ted");
		Elephant elephant1 = new Elephant("Dumbo", new Point(10, 10));
		Giraffe giraffe1 = new Giraffe("Melman");
		Turtle turtle = new Turtle("Raphael");

		System.out.println("********************************************");
		System.out.println("Eat action");
		System.out.println("********************************************");
		ZooActions.eat(lion1, new Food("Meat", "predator"));
		ZooActions.eat(bear1, new Food("Meat", "predator"));
		ZooActions.eat(elephant1, new Food("Grass", "herbivorous"));
		ZooActions.eat(giraffe1, new Food("Grass", "herbivorous"));
		ZooActions.eat(turtle, new Food("Grass", "herbivorous"));
		
		System.out.println("********************************************");
		System.out.println("Move action");
		System.out.println("********************************************");
		ZooActions.move(lion1, new Point(10, 500));
		ZooActions.move(bear1, new Point(20, 400));
		ZooActions.move(elephant1,new Point(30, 300));
		ZooActions.move(giraffe1,new Point(40, 200));
		ZooActions.move(turtle,new Point(50, 100));
		
		System.out.println("********************************************");
		System.out.println("ToString");
		System.out.println("********************************************");
		System.out.println(lion1);
		System.out.println(bear1);
		System.out.println(elephant1);
		System.out.println(giraffe1);
		System.out.println(turtle);

	}

}

