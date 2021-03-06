import java.util.LinkedList;
import java.util.ListIterator;

public class LinkedListExample {

	public static void main(String args[]) {
		// create a linked list
		LinkedList list = new LinkedList();

		// add elements to the linked list
		list.add("One");
		list.add("Two");
		list.add("Three");
		list.add("Four");
		list.add("Five");

		// create a list iterator
		ListIterator lit = list.listIterator();
		System.out.println("Initial list: ");

		while (lit.hasNext()) {
			System.out.println(lit.next() + " ");
		}

		// add elements in the beginning and in the end of the list
		list.addFirst("Zero");
		list.addLast("Six");

		System.out
				.println("Updated List after insertion in the first and last position: ");
		lit = list.listIterator();
		while (lit.hasNext()) {
			System.out.println(lit.next() + " ");
		}

		System.out.println("Check if list contains the element Four: "
				+ list.contains("Four"));

		System.out.println("The position of the element \"One\" is: "
				+ list.indexOf("One"));

		System.out.println("Get the element in third position of the list: "
				+ list.get(2));

		int size = list.size();
		System.out.println("The size of list is: " + size);

		System.out.println("Iterate List in reverse order: ");
		lit = list.listIterator(size);
		while (lit.hasPrevious()) {
			System.out.println(lit.previous() + " ");
		}
		// remove elements from the linked list
		list.remove("Three");
		list.removeFirst();
		list.removeLast();
		System.out
				.println("Updated List after deletion of the first element, the last element and the element \"Three\": ");
		lit = list.listIterator();
		while (lit.hasNext()) {
			System.out.println(lit.next() + " ");
		}

	}

}
