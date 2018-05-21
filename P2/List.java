import java.util.Scanner;

class List{
	Node head=null;
	int size=0;
	public List(){
		Node temp;
		Scanner in=new Scanner (System.in);
		System.out.printf("Enter the data: ");
		head=new Node(in.nextInt());
		temp=head;
		size++;
		while(true){
			System.out.printf("Do u wanna add more Nodes: ");
			char c=in.next().charAt(0);
			if(c=='Y' || c=='y') {
			System.out.printf("Enter the data: ");
			temp.next=new Node(in.nextInt());
			temp=temp.next;
			size++;
			}
		else break;
		}

	}
	public void display(){
    	Node tmp=head;
    	System.out.println("Current List:");
    	if(tmp==null){
    	   	System.out.println("List is Empty");
    	    return;
   	 	}
    	while(tmp!=null){
        	System.out.printf("%d ",tmp.data);
        	tmp=tmp.next;
    	}
    	System.out.println();
	}
	public void insertatposition(int data,int position){
		Node tmp=new Node(data);
		if (position==0){
			tmp.next=head;
			head=tmp;
		}else{
			Node temp=head;
			position=position-1;
			while(position>0){
				temp=temp.next;
				position--;
			}
			if(position==size-1){
				temp.next=tmp;
				return;
			}
			tmp.next=temp.next;
			temp.next=tmp;
		}
	}
	public void delete(int position){
		Node curr=head,prev=null;
		if(position==0){
			head=curr.next;
			curr.next=null;
		}else{
			while(position>0){
				prev=curr;
				curr=curr.next;
				position--;
			}
			prev.next=curr.next;
			curr.next=null;

		}
	}

	public void reverse(Node temp){
		if (temp==null)
			return;
		reverse(temp.next);
		System.out.printf("%d ",temp.data);

	}

}