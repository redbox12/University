import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Matrix {

    private double[][] matrix; //матрица
    private double determinant; //определитель


    Matrix(double[][] main_matrix) {
        this.matrix = main_matrix;
        this.determinant = 1;
    }


    public static void readFile(File file, double[][] matrix) throws FileNotFoundException { //чтение двумерного массива
        Scanner sc = new Scanner(file);
        while (sc.hasNextLine()) {
            for (int i = 0; i < matrix.length; i++) {
                String[] line = sc.nextLine().trim().split(" ");
                for (int j = 0; j < line.length; j++) {
                    matrix[i][j] = Double.parseDouble(line[j]);
                }
            }
        }
        sc.close();
    }

    public double determinant() {// расчет определителя
        int index_max_el = 0;
        for (int j = 0; j < matrix.length; j++) {
            index_max_el = index_main_el(j); //ищет индекс главного эл-та возвращает номер строки
            swap_line(index_max_el, j); //меняем местами
            multiply_line_const(j, matrix[j][j]); //умножение строку на число
            zanulit(j); //зануление нижних эл-ов
        }
    return determinant;
    }

    public int index_main_el(int column) { //нахождения главного эл-та
        int max_index = column;
        for (int i = column + 1; i < this.matrix.length; i++) {
            if (Math.abs(matrix[max_index][column]) < Math.abs(matrix[i][column])) {
                max_index = i;

            }
        }
        return max_index; //возвращает номер строки
    }


    void swap_line(int max_index, int j) //поменять местами строки
    {
        double[] remember_arr = matrix[max_index]; //массив который помнит, перемещаемую строку
        matrix[max_index] = matrix[j]; //перезаписываем строку с гл. эл-ом на вверх
        matrix[j] = remember_arr; //на место возвращаем стертую строку
        determinant *= -1;
    }

    void multiply_line_const(int index, double del_value) { //умножить сторку на константу

        for (int i = 0; i < matrix.length; i++) {
            matrix[index][i] /= del_value;
        }

        determinant *= del_value;
    }


    void zanulit(int index_max_el) {

        double[] up_arr = matrix[index_max_el]; //массив хранит все значения строки с главным эл-ом

        double remember_down_value_main = 0; // переменная, которая хранит эл-т ниже по столбцу главного эл-та
        for (int i = index_max_el + 1; i < matrix.length; i++) {
            remember_down_value_main = matrix[i][index_max_el];
            for (int j = index_max_el; j < matrix.length; j++) {
                matrix[i][j] -= up_arr[j] * remember_down_value_main;
            }
        }


    }

    public void print() { //выводим матрицу

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                System.out.print("\t|");
                System.out.printf("%.2f", matrix[i][j]);
                System.out.print("|\t");
            }
            System.out.println("");
        }

        System.out.println("Determinant: " + this.determinant+"\n");
    }




    public double diag_minus_lambda(double lambda){ //поиск собствен. значений
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                if(i==j){
                    matrix[i][j]-=lambda;
                }
            }
        }

        return determinant();
    }
}
