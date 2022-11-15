import java.util.ArrayList;

public class Main {

    public static double f(double x) {   ///метод, который считает функцию, которая дана из условия
        double f_x = 0;
        if(x == 0){
            f_x = 0.5;   ///0.5, так как этому равен предел функции при х -> 0; Олег Всеволодович сказал написать так
        }
        else{
            f_x = (Math.cosh(Math.sqrt(x)) - 1) / x;
        }
        return f_x;
    }

    public static double L(double x) {  ///метод, который считает многочлен Лагранжа;
                                       /// нужен х из отрезка, на котором рассматривается функция
        double[] x_i = new double[]{0, 1, 2, 3, 4};  ///в этих точках нужно посчитать многочлен по условию
        double[] y_i = new double[]{f(0), f(1), f(2), f(3), f(4)};  ///подсчёт значений функции в данных
                                                                  ///точках; нужно, чтобы построить график функции

        double result = 0;  ///значение многочлена Лагранжа
        //double li = 1;    ///далее по формулам из присланной лекции №5
        for (int i = 0; i < y_i.length; i++) {
            double li = 1;     ///базисный полином
            for (int j = 0; j < y_i.length; j++) {
                if (j == i) {
                    continue;
                } else {
                    li *= (x - x_i[j]) / (x_i[i] - x_i[j]);
                }
            }
            result += y_i[i] * li;
        }
        return result;
    }

     //Вычислим интегралл
    public static double fact(int n){ //факториал
        if(n<0)
            return 0;
        if(n == 0)
            return 1;
        int result = 1;
        for(int i=0; i<n; i++){
            result = result *(n - i);
        }

        return result;
    }

    public static ArrayList<Double> integral(){ //разложение интеграл в ряд
        ArrayList<Double> ryad = new ArrayList<>();
        double eps = 0.0001;
        double x = Math.PI;
        double x_n;

        for(int n =1; n< 10; n++){ //взяли примерно число 10
            x_n = Math.pow(x, n)/(n*fact(2*n));
            if(x_n < eps){  //когда эл-т ряда станет меньше eps, тогда запомнить этот эл-т и отправить
                ryad.add(Double.valueOf(n)); //эл-т с которого надо считать остаток
                break;
            }
        ryad.add(x_n);
        }

        return ryad;
    }

    public static ArrayList<Double> geomProgress(int lastElem){ //геометрическая прогрессия для оценивания остатка ряда
        ArrayList<Double> geomProg = new ArrayList<>();
        geomProg.add(2.0);
        double q = 0.2; //q = 1/5

        for(int i = 1; i < lastElem; i++){
            double b = 2/Math.pow(5.0, i);
            geomProg.add(b);
        }
        return geomProg;
    }

    public static double ostatok(int n){
        double q = 0.2;  //q = 1/5
        double ost = (2/Math.pow(5, n))/(1-q);
        return ost;
    }

    public static boolean ocenka(ArrayList<Double> x, ArrayList<Double> q, double n){
        for(int i = 0; i < n-1; i++) {
            if (x.get(i) > q.get(i)) {
                return false;
            }
        }
        return true;
    }

    public static void answer(){ //ответ 2 части задачи, чтобы не нагружать main
        ArrayList<Double> integ = integral();
        double lastEl = integ.get(integ.size() - 1);
        int lastElem = (int) lastEl;

        integ.remove(integ.size() - 1);
        System.out.println("\n////// Вычисление интегралла //////  \n\nИнтеграл: " + integ.toString());

        ArrayList<Double> geom = geomProgress(lastElem);
        System.out.println("Геометрическая прогрессия: " + geom.toString() + "\nоценка: " + ocenka(integ, geom, lastElem));

        double ost = ostatok(lastElem);
        System.out.printf("\nСумма остатка ряда:  %.4f %n", ost);

        double sumInt = 0;
        for(int i = 0; i < integ.size(); i++){
            sumInt += integ.get(i);
        }
        System.out.println("Приближенный ответ: " + sumInt);
    }

    public static void main(String[] args) {
        double eps = 0.0001;

        for(double x = 0; x <= 4.1; x += 0.1){   ///отрезок от 0 до 4
            System.out.printf("%f %f %f\n", x, f(x), L(x));  ///значения функции в точке и многочлена в точке совпадают
            ///так и должно быть; когда больше знаков после запятой, то видно небольшое различие
        }
        answer();

    }
}