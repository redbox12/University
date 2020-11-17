
public class WorldCreator {

    public static Planet[] create(int n){
        Planet [] planets  = new Planet[n];

        for(int i=0; i<n; i++){
            double random = Math.random()*50 + 50; //50 до 100 масса
            planets[i]= new Planet(random);
        }
        return planets;
    }
}
