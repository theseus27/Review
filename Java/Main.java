import java.util.*;

public class Main {
    public static void main(String[] args) {
        Exceptions.outOfBounds();
        Staticky.main(new String[]{});
        
        Scope myScope = new Scope();
        Scope.inner in = myScope.new inner();
        in.print();

        EqualClass.main(new String[]{});

        Visiting myV = new Visiting();
        Visiting.Example ex = myV.new Example();
        myV.new Example().main(new String[]{});

    }
}

class Exceptions {
    static void outOfBounds() {
        int nums[] = {1,2,3};

        try {
            for (int i = 0; i < 10; i++)
                System.out.println(nums[i]);
        } catch (IndexOutOfBoundsException e) {
            System.out.println("Wow an exception");
        }
        System.out.println("Ok");

        try {
            for (int i = 0; i < 10; i++)
                System.out.println(nums[i]);
        } catch (IndexOutOfBoundsException e) { /*You can also do nothing on catch*/ }
    }
}

class Staticky {
    static int a = 0;
    public static void main(String[] args) {
        int b = 1;
        System.out.println(b);
        System.out.println(a);  //DOESN'T WORK UNLESS a IS STATIC
    }
}

class ArrayvsArrayList {
    public static void main(String[] args) {
        //Array - fixed size
        String[] friends = new String[4];   //Elements start as null
        String[] friends2 = {"Jimmy", "Luke", "Marco", "Felix"};

        //ArrayList - changes size
        ArrayList<String> friendsAL = new ArrayList<>();
        ArrayList<String> friendsAL2 = new ArrayList<>(Arrays.asList("Emma", "Fiona"));

        //Immutable List
        List<String> friendsAL3 = Arrays.asList("");
    }
}

class Scope {
    String name = "Theseus";
    
    class inner {
        String name = "Piplup";

        public void print() {
            System.out.println(name);               //Piplup
            System.out.println(this.name);          //Piplup
            System.out.println(Scope.this.name);    //Theseus
            //System.out.println(Scope.name);       //Can't make a static reference to a nonstatic field
        }
    }
}

class ADT {
    private int x;
    private int y;
    ADT(int x, int y) { this.x = x; this.y = y;}

    public ADT shift(int a, int b) {
        return new ADT(this.x+a, this.y+b);
    }
}

class EqualClass {
    public static void main(String[] args) {
        //Both are true
        String me = "Theseus";
        String hero = "Theseus";
        boolean physical = (me == hero);
        boolean structural = me.equals(hero);
        System.out.println("Physical: " + physical);
        System.out.println("Structural: " + structural);

        //Physical is false, structural is true
        List<String> l1 = new ArrayList<String>(Arrays.asList("Theseus"));
        List<String> l2 = new ArrayList<String>(Arrays.asList("Theseus"));
        boolean physicalL = (l1 == l2);
        boolean structuralL = l1.equals(l2);
        System.out.println("Physical: " + physicalL);
        System.out.println("Structural: " + structuralL);
    }
}

class Visiting {
    //Uses OOP style traversal, but only implements the traversal code once
    //An alternative to instanceOf

    abstract class Student {
        int iq;
        abstract int eval(Student score);
        abstract void accept(Visitor v);
    }

    class Genius extends Student {
        static int iq = 120;
        public int eval(Visiting.Student score) {
            return iq * score.iq;
        }
        public void accept(Visitor v) {
            v.visitGenius(this);
        }
    }

    class Average extends Student {
        static int iq = 100;
        public int eval(Visiting.Student score) {
            return iq * score.iq;
        }
        public void accept(Visitor v) {
            v.visitAverage(this);
        }
    }

    class Idiot extends Student {
        static int iq = 80;
        public int eval(Visiting.Student score) {
            return iq * score.iq;
        }
        public void accept(Visitor v) {
            v.visitIdiot(this);
        }
    }

    class Score extends Student {
        int iq;
        Score(int i) { iq = i; }
        public int eval(Visiting.Student score) {
            return iq;
        }
        public void accept(Visitor v) {
            v.visitScore(this);
        }
    }

    interface Visitor {
        void visitGenius(Genius g);
        void visitAverage(Average a);
        void visitIdiot(Idiot i);
        void visitScore(Score s);
    }

    public class Example {
        public void main(String[] args) {
            Visiting v = new Visiting();
            Student grade = v.new Score(80);
            Student theseus = v.new Genius();
            Student piplup = v.new Idiot();
            Student bob = v.new Average();
    System.out.println(grade.iq);
            List<Student> studs = new ArrayList<Student>(Arrays.asList(theseus, piplup, bob));
            for (Student s : studs) {
                System.out.println(s.eval(grade));
            }
        }
    }
}
