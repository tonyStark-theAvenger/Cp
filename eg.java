
/**
 * eg
 */

/*
                    test
*/

/*
                     Emploee
*/

class Employee {
    public static void walk() {
        System.out.println("Walking");
    }
}

class danceEmp extends Employee {
    void walk() {
        System.out.println("Dancing and Walking");
    }

    void walk(int a) {
        System.out.println(a);
    }
}

public class eg {

    public static void main(String[] args) {

        danceEmp t = new danceEmp();
        t.walk();
        t.walk(3);

    }
}