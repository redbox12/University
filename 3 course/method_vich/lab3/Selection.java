import java.io.FileReader;
import java.util.Scanner;

import static java.lang.Math.exp;

public class Selection {
    private double[] randValue; // случайные величины из выборки

    // выборка
    Selection() {
        // заполняем из файла randValue
        String[] dataFromFile = getDataFromFile("C:\\Users\\Ivan\\Documents\\programm_method_vich\\lab3\\src\\input33.txt");
        randValue = new double[dataFromFile.length];
        for(int i=0; i<dataFromFile.length; i++){
            randValue[i] = Double.parseDouble(dataFromFile[i]);
        }
    }

    // размер массива (объем выборки)
    public int length() {
        return randValue.length;
    }

    // получить строки из файла
    private static String[] getDataFromFile(String filename) {
        // создаем массив строк по кол-ву строк файла
        String[] arr = new String[getSize(filename)];
        try{
            // читаем из файла
            FileReader reader = new FileReader(filename);
            Scanner scanner = new Scanner(reader);
            // строки из файла записываем в массив
            for(int i = 0; i < arr.length; i++){
                arr[i] = scanner.nextLine();
            }
            reader.close();
        }
        catch (Exception e){
            System.out.println(e);
        }
        return arr;
    }

    // получить кол-во строк из файла
    private static int getSize(String filename){
        int counter = 0;
        try{
            FileReader reader = new FileReader(filename);
            Scanner scanner = new Scanner(reader);
            while(scanner.hasNextLine()){
                scanner.nextLine();
                counter++;
            }
            reader.close();
        }
        catch (Exception e){
            System.out.println(e);
        }
        return counter;
    }

    // выборочное среднее
    public double averrage() {
        double sum = 0;
        for(int i=0; i<length(); i++ ){
            sum += randValue[i];
        }
        double averrage = sum/length();
        return averrage;
    }

    // среднеквадратичное отклонение
    public double dispersia() {
        double sum = 0;
        for(int i=0; i<length(); i++ ){
            sum += Math.pow(randValue[i] - averrage(), 2);
        }
        double dispersia = sum/length();

        return Math.sqrt(dispersia);
    }

    // 95% доверительный интервал
    public double confidence_interval(){
        double interval;
        interval = 2*dispersia()/Math.sqrt(length());
        return interval;
    }

    //ф-я экспоненциального распределения
    private double exponentialDistribution( double x){
        double lambda = 1/ averrage();
        return  1 - Math.exp(-lambda*x);
    }

    // критерий Хи-квадрат
    public double chiSquared(){
        //min = 0; max = 2.5
        double[] k = {0, 0.3, 0.6, 0.9, 1, 1.2, 1.5, 1.75, 2, 2.3, 2.5}; //интервал
        double[] p_k = new double[k.length - 1]; //вероятность попадания
        double[] n_k = new double[k.length - 1]; //число n_i выборочных значений, попавших в i-й интервал

        for(int i =0; i < k.length-1; i++){ // считываем вероятность попадания в интервал
            p_k[i] = exponentialDistribution(k[i+1]) - exponentialDistribution(k[i]);
            n_k[i] = 0;
        }

        for(int i = 0; i < randValue.length; i++){ //число n_i выборочных значений, попавших в i-й интервал
            for(int j = 1; j < k.length; j++ ){
                if (randValue[i] <= k[j]){
                    n_k[j-1] +=1;
                    break;
                }
            }
        }

        double chiSquared = 0; //Значение Хи-квадрат Пирсона:

        for (int i=0; i < p_k.length; i++){ //подсчет значения Хи-квадрата Пирсона
            chiSquared += Math.pow(n_k[i] - length()*p_k[i],2)/(length()*p_k[i]);
        }

        return chiSquared;
    }

}
