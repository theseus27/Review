//Find and replace all "String DATA" w/ 'Type name'
//Find and replace all "DATA" w/ 'name'
import java.util.*;
interface Test { public void run(String DATA); };

//Copy and paste this
class TestExample implements Test { public void run(String DATA) {
    return;
}};

public class TestingTemplate {
    public static void main(String[] args) {
        List<Test> tests = Arrays.asList(new Test1(), new Test2(), new Test3());
        
        for (int i = 0; i < tests.size(); i++) {
            String word = "";
            tests.get(i).run(word);
        }
    }
};

class Test1 implements Test { public void run(String DATA) {
    System.out.println("Test 1 Finished");
}};

class Test2 implements Test { public void run(String DATA) { 
    System.out.println("Test 2 Finished");
}};

class Test3 implements Test { public void run(String DATA) {
    System.out.println("Test 3 Finished");
}};

