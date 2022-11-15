// В файле input33.txt дана выборка случайной величины.
// Найти: 1. Объeм выборки,
// 2. выборочное среднее a (оценку матожидания),
// 3. среднеквадратичное отклонение сигмы,
// 4. 95%-доверительный интервал для матожидания.
// 5. По критерию согласия хи-квадрат (разбив отрезок на 10 неравных частей)
// проверить гипотезу, что распределение экспоненциальное с матожиданием a
// (число степеней свободы распределения хи-квадрат будет не 9, а 8, т.к. одна степень свободы израсходована на нахождение a).

import java.io.File;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = 0;
        Selection objRand = new Selection();
        double chiSquaredThreshold = 15.5; //квантиль уровень значимости 0.05 число степеней свобод 8

        while (n < 1 || n > 6) {

            System.out.println("Что Вы хотите сделать");
            System.out.println("0. Выход");
            System.out.println("1. Объем выборки;");
            System.out.println("2. Выборочное среднее а;");
            System.out.println("3. Среднеквадратичное отклонение");
            System.out.println("4. 95%-доверительный интервал для матожидания");
            System.out.println("5. Критерий согласий хи-квадрат ");

            n = scan.nextInt();
            switch (n) {
                case 0:
                    System.out.println("Программа завершена!");
                    return;
                case 1:
                    System.out.println("\tОбъем выборки:"+objRand.length());
                    break;
                case 2:
                    System.out.println("\tВыборочное среднее:"+objRand.averrage());
                    break;
                case 3:
                    System.out.println("\tСреднеквадратичное отклонение:"+objRand.dispersia());
                    break;
                case 4:
                    System.out.println("\t95 % доверительный интервал будет: ( -"+ objRand.confidence_interval() + "; " + objRand.confidence_interval()+")");
                    break;
                case 5:
                    System.out.println("\tЗначение Хи-квадрата пирсона: "+ objRand.chiSquared());
                    if(objRand.chiSquared()< chiSquaredThreshold)
                        System.out.println("\tГипотеза принята");
                    else
                        System.out.println("\tГипотеза отклонена");
                    break;
            }
            n=0;
        }
    }
}
