public class array {
    static final int MAX = 10;

    static class List {
        int[] data = new int[MAX]; //stores the element
        int size;
    }

     // Initialize the list
    static void initialize(List L) {
        L.size = 0;//makes the list empty
    }

     // Insert at a given position
    static void insert(List L, int pos, int value) {

        if (L.size == MAX) {
            System.out.println("List is full");
            return;
        }

        if (pos < 0 || pos > L.size) {
            System.out.println("Invalid position");
            return;
        }

        // Shift elements to the right
        for (int i = L.size; i > pos; i--) {
            L.data[i] = L.data[i - 1];
        }
          L.data[pos] = value;
        L.size++;
    }

    // Delete an element from a given position
    static void delete(List L, int pos) {

        if (pos < 0 || pos >= L.size) {
            System.out.println("Invalid position");
            return;
        }

        // Shift elements to the left
        for (int i = pos; i < L.size - 1; i++) {
            L.data[i] = L.data[i + 1];
        }

        L.size--;
    }

    // Display the list
    static void display(List L) {

        if (L.size == 0) {
            System.out.println("List is empty");
            return;
        }

        for (int i = 0; i < L.size; i++) {
            System.out.print(L.data[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args){
      List L = new List();
        initialize(L);

        insert(L, 0, 10);
        insert(L, 1, 20);
        insert(L, 2, 30);
        display(L);

        delete(L, 1);
        display(L);  
    }
}
