package main;

public class MessageUtility {

	public static void logConstractor(String name) {
		String str = "[+] new animal\tname: " + name;
		System.out.println(str);
	}

	public static void logGetter(String name, String funcName, Object value) {
		String str = "[g] " + name + ":\t" + funcName + "() => " + value;
		System.out.println(str);
	}

	public static void logSetter(String name, String funcName, Object value, boolean isSuccess) {
		String str = "[s] " + name + ":\t" + funcName + "(" + value + ") => " + isSuccess;
		System.out.println(str);
	}

	public static String logString(String name, double distance, double weight) {
		return "[!] " + name + ":\ttotal distance: " + (int)distance + ", weight: " + Math.ceil(weight);
	}
}
