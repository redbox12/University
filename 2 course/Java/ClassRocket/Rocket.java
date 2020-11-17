public class Rocket {
    double total_weight; //поле общая масса
    double fuel_weight; //кол-во топлива
    boolean engine;//состояния двигателя


    Rocket(double total_weight, double fuel_weight) {
        this.total_weight = total_weight;
        this.fuel_weight = fuel_weight;
        this.total_weight += this.fuel_weight;
    }

    boolean spendFuel(double count) {
        boolean var = true;

        if (fuel_weight < count) {
            var = false;


        }

        if (fuel_weight > count) //если объем топлива в ракете больше 100. Если это правда то выполняется расчет потраченного топлива
            {
                fuel_weight -= count;
                total_weight -= count;
                engine = true;

            }
        else
            {
                total_weight -= fuel_weight;
                fuel_weight = 0;
                engine = false;

            }

        return var;
    }

    double getTotalWeight() //общая масса
    {
        return total_weight;
    }


    double getFuelLevel() //текущие кол-во топлива
    {
        return fuel_weight;
    }


    boolean getIsEngineRunning() //работает ли двигатель
    {
        return  engine;
    }

}


