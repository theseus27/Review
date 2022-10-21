import java.util.*;
import java.lang.reflect.*;

// interface TestSetInterface<H> extends Test{ 
//     List<Test> tests = Arrays.asList(); 
//     void runAll(); }
interface Test<G> { public <G> void run(G obj); }

public class TestingGeneric {
    public static void main(String[] args) {
        TestSet<Integer> intTests = new TestSet<Integer>();
        Method[] methods = intTests.getClass().getDeclaredMethods();
        for (Method m : methods) {
            List<Integer> nums = new ArrayList<Integer>(Arrays.asList(1,2,3));
        }
    }
}

class TestSet<X> {
    X testObj = new ArrayList(Arrays.asList(1, 2, 3));
    List<Test<X>> tests = Arrays.asList(new Test1<X>(), new Test2<X>(), new Test3<X>());;

    void runAll() {
        for (Test test : tests) {
            test.run(l);
        }

    }

    class Test1<T> implements Test<T> {
        public <T> void run(T obj) {
            System.out.println("Test 1");
            for (T arg : args) {
                System.out.println(arg);
            }
        }
    }
        
    class Test2<T> implements Test<T> {
        public <T> void run(T obj) {
            System.out.println("Test 2");
            for (T arg : args) {
                System.out.println(arg);
            }
        }
    }

    class Test3<T> implements Test<T> {
        public <T> void run(T obj) {
            System.out.println("Test 3");
            for (T arg : args) {
                System.out.println(arg);
            }
        }
    }
}

// Method[] methods = this.getClass().getDeclaredMethods();