
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

/*     A
      3  6  -5
      8 -3   2
      7  2   1   */

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        File file_matrix_a = new File("D:\\Универ\\3 курс\\6 семестр\\Вычисл. мет\\Lab1\\src\\matrix_a.txt");
        double[][] matrix_a = new double[3][3];

        File file_matrix_b = new File("D:\\Универ\\3 курс\\6 семестр\\Вычисл. мет\\Lab1\\src\\matrix_b.txt");
        double[][] matrix_b = new double[5][5];
        double[][] matrix_b_copy = new double[5][5]; //копия матрицы b для 2 задания

        File file_matrix_c = new File("D:\\Универ\\3 курс\\6 семестр\\Вычисл. мет\\Lab1\\src\\matrix_c.txt");
        double[][] matrix_c = new double[7][7];

        Matrix.readFile(file_matrix_a, matrix_a);
        Matrix.readFile(file_matrix_b, matrix_b);
        Matrix.readFile(file_matrix_c, matrix_c);

        Matrix.readFile(file_matrix_b, matrix_b_copy);


        Matrix a = new Matrix(matrix_a);
        Matrix b = new Matrix(matrix_b);
        Matrix c = new Matrix(matrix_c);

        a.determinant(); //расчет определителя + приведение матрицы к ступенчатому виду с 1 на диагонали
        a.print(); //вывод матрицы 

        b.determinant();
        b.print();

        c.determinant();
        c.print();


        //Поиск собственного значения матрицы В

        Matrix b_lambda1 = new Matrix(matrix_b_copy);
        Matrix b_lambda2 = new Matrix(matrix_b);
        Matrix b_middle_lambda = new Matrix(matrix_b);

        double lambda1 = 0;
        double lambda2= 3;
        double middle_lambda;
        double eps_lambda = 0.001;

        //алгоритм метода половинного деления
        if(b_lambda1.diag_minus_lambda(lambda1) * b_lambda2.diag_minus_lambda(lambda2) > 0){
            System.out.println("Корней нет!");
        }
        else {
            do {
                middle_lambda = (lambda1 + lambda2) / 2;

                if (b_lambda1.diag_minus_lambda(middle_lambda) * b_lambda2.diag_minus_lambda(lambda2) > 0)
                    lambda1 = middle_lambda;

                else lambda2 = middle_lambda;


            } while (lambda2 - lambda1 > eps_lambda);

            middle_lambda = (lambda1 + lambda2) / 2;

            System.out.println("Лябда: " + middle_lambda + " Опр-ль: " + b_middle_lambda.diag_minus_lambda(middle_lambda));
        }

    }

}
