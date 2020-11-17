public class StringArrayList
{
    String[] array;
    int userCount;

    StringArrayList(){
        array = new String[10];
    }

    void add(String wordValue)
    {
        if(userCount == array.length){
            realLocate(); //расширяет массив
        }
        array[userCount] = wordValue;
        userCount++;

    }
    void realLocate(){
        String[] newArray = new String[userCount+10];
        for(int i=0; i < array.length; i++){
            newArray[i] = array[i];
        }
        this.array = newArray;
    }

    String get(int i){
        if( i < userCount  && i >= 0 ){
            return array[i];
        }
        else
            return null;

    }

    int getLength(){

        return userCount;
    }

    boolean set(int i, String stringVar){
        if(i < userCount && i >= 0 ){
            array[i] = stringVar;
            return true;
        }
        else
            return false;

    }

    boolean  insert(int i, String stringVar2) {

        if (i >= 0 && i <= userCount) {
            if (array.length == userCount) {
                realLocate();
            }
            for (int j = userCount - 1; j >= i; j--) {
                array[j + 1] = array[j];
            }

            array[i] = stringVar2;
            userCount++;

            return true;
        }

        return false;
    }


    boolean remove(int i){
        if(i < userCount && i >= 0 ) {
            for(int j = i+1; j < userCount; j++){
                array[i] = array[j];
                i++;
            }
            array[userCount-1] = null;
            userCount--;
            return true;
        }

        return false;
    }

        void printArray(){
        for (int i = 0; i < userCount; i++){
            System.out.print("|"+array[i]+"|\t");
        }
    }
}
