import java.util.Scanner;
import java.util.*;
class node
{
	int data;
	node next;
	public node(int data)
	{
		this.data=data;
		this.next=null;
	}
	public node(int data,node next)
	{
		this.data=data;
		this.next=next;
	}

}
class list
{
	node head=null;
    int size=0;
	public list()
	{
		node temp;
		Scanner in=new Scanner (System.in);
		System.out.printf("Enter the data: ");
		head=new node(in.nextInt());
		temp=head;
		size++;
		while(true)
		{
		System.out.printf("Do u wanna add more nodes: ");
		char c=in.next().charAt(0);
		if(c=='Y' || c=='y')
		{
		System.out.printf("Enter the data: ");
		temp.next=new node(in.nextInt());
		temp=temp.next;
        last = temp;
		size++;
		}
		else break;
		}

	}
	public void display()
    {
    	node tmp=head;
    	System.out.println("Current List:");
    	if(tmp==null)
    	{
    	   	System.out.println("List is Empty");
    	    return;
   	 	}
    	while(tmp!=null)
    	{
        	System.out.printf("%d ",tmp.data);
        	tmp=tmp.next;
    	}
    	System.out.println();
	}
	public void insertatposition(int data,int position)
	{
		node tmp=new node(data);
		if (position==0)
		{
			tmp.next=head;
			head=tmp;
		}
		else
		{
			node temp=head;
			position=position-1;
			while(position>0)
			{
				temp=temp.next;
				position--;
			}
			if(position==size-1)
			{
				temp.next=tmp;
				return;
			}
			tmp.next=temp.next;
			temp.next=tmp;
		}
		size++;
	}
	public void delete(int position)
	{
		node curr=head,prev=null;
		if(position==0)
		{
			head=curr.next;
			curr.next=null;
		}
		else
		{
			while(position>0)
			{
				prev=curr;
				curr=curr.next;
				position--;
			}
			prev.next=curr.next;
			curr.next=null;

		}
		size--;

	}

	public void reverse(node temp)
	{
		if (temp==null)
			return;
		reverse(temp.next);
		System.out.printf("%d ",temp.data);

	}

}
public class st
{
	public static void main(String[] args)
	{
		list l=new list();
		int position,data;
		Scanner in = new Scanner(System.in);
		while(true)
		{
		System.out.printf("1.Display\n2.Insert at start\n3.Deletion at end\n4.Deletion at start\n5.");
		int c=in.nextInt();
		switch(c)
		{
			case 1:l.display();break;
			case 2:

			System.out.println("Enter the data: ");
			data=in.nextInt();

			position=0;
		
			l.insertatposition(data,position);
			System.out.println("List after Insert");
			l.display();
			break;
			case 3:
			
			l.delete(l.size-1);
			System.out.println("List after Deletion");
			l.display();
			break;
			case 4:
			l.delete(0);
			break;
			default:
			System.out.println("Wrong choice");
			return;
		}
		}

	}
}
