import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
            Scanner in = new Scanner(System.in);

        StringArrayList stringArray = new StringArrayList();
        System.out.print("Программа: \"Удобная работа с динамическим массивом строк\"\nМоя программа умеет:\n" +
                "1)В конец добавить новый элемент\n2)Возращает i-й эл-т\n3)Возращает текущее кол-во эл-ов" +
                "\n4)Переписывает значение i-го элемента массива\n5)Вставляет элемент на i-е место\n6)Удаляет i-й элемент массива\n" +
                "0 если хотите закрыть программу"+"\n\nВведите число: ");
        int switchVar;


        do {
            switchVar = in.nextInt();
            switch (switchVar) {
                case 1: // в конец добавляется новый элемент.
                    System.out.print("Введите символ, который хотите добавить в конец: ");
                    in.nextLine();
                    String wordValue  = in.nextLine();
                    stringArray.add(wordValue);

                    break;

                case 2: // возвращает i-й элемент либо null
                    System.out.print("Введите номер позиции символа в массиве: ");
                    int numberSymbol = in.nextInt();
                    System.out.print("Ваш эл-т массива: "+stringArray.get(numberSymbol)+"\n");
                    break;

                case 3: // возвращает текущее количество элементов
                    System.out.println(stringArray.getLength());
                    break;

                case 4: //переписывает значение i-го элемента массива

                    System.out.print("Введите номер позиции символа в массиве: ");
                    int i = in.nextInt();

                    if(i< 0){
                        System.out.println(stringArray.set(i, null));
                    }
                    else{
                        System.out.print("Введите слово: ");
                        in.nextLine();
                        String stringVar = in.nextLine();
                        stringArray.set(i, stringVar);
                    }


                    break;

                case 5: // вставляет элемент value на i-е место
                    System.out.print("Введите номер позиции символа в массиве: ");
                    int numberPosition2 = in.nextInt();

                    if(numberPosition2 < 0){
                        System.out.println(stringArray.insert(numberPosition2, null));
                    }
                    else {
                        System.out.print("Введите слово: ");
                        in.nextLine();
                        String stringVar2 = in.nextLine();
                        stringArray.insert(numberPosition2, stringVar2);
                    }

                    break;

                case 6: //удаляет i-й элемент массива
                    System.out.print("Введите номер позиции символа в массиве: ");
                    int numberPosition3 = in.nextInt();

                    if(numberPosition3 < 0){
                        System.out.println(stringArray.remove(numberPosition3));
                    }
                    else
                    stringArray.remove(numberPosition3);
                    break;



                default:
            }
            stringArray.printArray();
            System.out.print("\n\nЧто вы хотите сделать: ");

        } while (switchVar != 0);
    }
}


