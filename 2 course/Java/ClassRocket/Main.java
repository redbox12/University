//ненужный комментрарий
import static  java.lang.System.out;
public class Main {

    public static void main(String[] args)
    {

        Rocket Union = new Rocket(500, 350);

        //вывод изначальных данных, Андрей Сергеевич, простите ну этот блок ну очень хочется вывести блоком, а не строчкой
        out.println("\nУ ракеты генерируется топлива от 0 до 300 л.");
        out.println("Общая масса ракеты: " + Union.getTotalWeight());
        out.println("Текущая кол-во топлива: " + Union.getFuelLevel());
        out.println();

        int count_operation = 1;
        for (int i = 0; i < count_operation; i++)
        {

            if (Union.getFuelLevel() > 100 ) //если объем топлива в ракете больше 100. Если это правда то выполняется расчет потраченного топлива
            {
                Union.spendFuel(100);
                out.println("Потрачено топлива: 100 л." + "\tОбщая масса ракеты: " + Union.getTotalWeight() + "\tКол-во топлива: " + Union.getFuelLevel());
                if(Union.getIsEngineRunning())
                    out.println("Двигатель запущен");
                count_operation++;

            }


            else
            {

                out.print("Потрачено топлива: " + Union.getFuelLevel());
                Union.spendFuel(Union.getFuelLevel());
                out.println(" Общая масса: " + Union.getTotalWeight()+ "\tТекущая кол-во топливо: " + Union.getFuelLevel());
                if(!Union.getIsEngineRunning())
                    out.println("Двигатель заглох   ");
            }

            out.println();

        }

    }
}
