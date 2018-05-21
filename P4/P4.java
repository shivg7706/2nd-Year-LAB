import java.util.*;
import java.util.Random;
class P4{
    public int randomPartition(int array[], int l, int h){
        Random rand= new Random();
        int i=l+rand.nextInt((h-l)+1);
        int temp;
        temp=array[h];
        array[h]=array[i];
        array[i]=temp;
        return partition(array,l,h);
    }

    public int partition(int array[], int l, int h){
        int pivot = array[h];
        int i = l - 1,temp;
        for (int j=l; j<h;j++){
            if (array[j] <= pivot){
                i++;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        temp = array[i + 1];
        array[i + 1] = array[h];
        array[h] = temp;
    return i+1;
    }

    public void sort(int array[], int l, int h){
        if (l < h){
            int pivot = randomPartition(array, l, h);
            sort(array, l, pivot - 1);
            sort(array, pivot + 1, h);
        }
    }
    
    public static void main(String[] args){
        int n;
        Scanner In = new Scanner(System.in);
        System.out.println("Enter the Size of the array");
        n=In.nextInt();
        int[] array=new int[n];
        System.out.println("Enter the elements of array");
        for(int i=0;i<array.length;i++)
              array[i]=In.nextInt();
        QuickSort Q=new QuickSort();
        Q.sort(array, 0 , n-1);
        System.out.println("Array after sorting :");
        for(int i=0;i<array.length;i++)
        System.out.printf("%d ",array[i]);
    }
}
