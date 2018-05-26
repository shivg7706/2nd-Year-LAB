// Program description
// This program perfroms operations on linked lists

import java.util.Scanner;
import java.util.*;


public class Main{
	public static void main(String[] args){
		List l = new List();
		int position,data;
		Scanner in = new Scanner(System.in);
		while(true){
			System.out.printf("1.Display\n2.Insert\n3.Deletion\n4.Get the size of the List\n5.Print in reverse\n");
			int c=in.nextInt();
			switch(c){
				case 1:l.display();break;
				case 2:
				System.out.println("//0 is for head");
				System.out.println("Enter the data: ");
				data=in.nextInt();
				System.out.printf("Enter the valid position: ");
				position=in.nextInt();
				if (position>l.size){
					System.out.println("Invalid position");break;
				}
				l.insertatposition(data,position);
				System.out.println("List after Insert");
				l.display();
				break;
				case 3:
				System.out.println("//0 is for head");
				position=in.nextInt();
				if(position>l.size-1){
					System.out.println("Invalid position");break;
				}
				l.delete(position);
				System.out.println("List after Deletion");
				l.display();
				break;
				case 4:
				System.out.println("Size of the current Linked List");
				System.out.println(l.size);
				break;
				case 5:
				l.reverse(l.head);
				System.out.println();
				break;
				default:
				System.out.println("Wrong choice");
				return;
			}
		}
	}
}

