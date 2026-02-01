public class linkedList {
    static class Node {
        //node definition
        int data; //stores value
        Node next; //store refeference to the next node

        Node(int value) {
            data = value;
            next = null;
        }  
    }
    static Node head = null;

    // Insert at front
    static void insertFront(int value) {

        Node newNode = new Node(value);
        newNode.next = head;
        head = newNode;
    }

    // Delete from front
    static void deleteFront() {

        if (head == null) {
            System.out.println("List is empty");
            return;
        }

        head = head.next;
    }

    // Display the linked list
    static void display() {

        Node temp = head;

        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("NULL");
    }

    public static void main(String[] args) {
        insertFront(10);
        insertFront(20);
        insertFront(30);
        display();

        deleteFront();
        display();
    }


}
