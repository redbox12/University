import static java.lang.Math.*;
public class Planet
{
    private double mass;
    private static int numPlanets;


    public Planet(double mass){
        this.mass = mass;
        incrementNumPlanets();
    }

    private static void incrementNumPlanets(){
        numPlanets++;
    }

    public double getMass(){
        return  mass;
    }

    public double setMass(double mass){
        this.mass = mass;
        return  mass;
    }

    public int getNumPlanets(){
        return  this.numPlanets;
    }


    public static double getTotalWeight(Planet [] planets){

        double Mass=0; //общая масса
        for (int i=0; i<planets.length; i++)
        {
            Mass += planets[i].mass;
        }

        return Mass;
    }

    public static double getAverageWeight(Planet [] planets, int n)
    {
        double Sred_Massa = 0;
        double Mass=0; //общая масса
        for (int i=0; i<planets.length; i++)
        {
            Mass += planets[i].mass;
        }

        Sred_Massa = Mass/n;
        return  Sred_Massa;
    }

    public static void printUniverse(Planet [] planets)
    {
        for(int i = 0; i< planets.length; i++)
        {
            System.out.println("Планета масса: " + planets[i].mass);

        }

        System.out.println("Кол-во планет: " + numPlanets);
    }


}
