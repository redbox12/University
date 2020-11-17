//Здесь главный файл
import java.util.Scanner;
public class Main {

public static void main(String args[])
{
    //Scanner reader = new Scanner(System.in);
    int n = 5;

    Planet universe[] = WorldCreator.create(n);
    Planet.printUniverse(universe);

    double totalWeight = Planet.getTotalWeight(universe);
    double avgWeight = Planet.getAverageWeight(universe, n);

    System.out.printf("Total weight=%f, Average weight=%f\n", totalWeight, avgWeight);



    System.out.println("");







}
}