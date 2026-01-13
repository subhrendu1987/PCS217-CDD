import java.util.Scanner;

public class ExpressionApp {

    static {
        // Loads libexprengine.so / exprengine.dll
        System.loadLibrary("exprengine");
    }

    // Native method implemented in C++ (JNI)
    private native double evaluate(String expression);

    /**
     * Automated test suite to verify all features
     */
    private void runPredefinedTests() {
        String[] tests = {
            "3+4",
            "10-5",
            "6*7",
            "20/4",
            "10/3",
            "5/0",        // division by zero
            "100*0",
            "8-12"
        };

        System.out.println("=== Running Predefined Tests ===");
        for (String expr : tests) {
            try {
                double result = evaluate(expr);
                System.out.println(expr + " = " + result);
            } catch (Exception e) {
                System.out.println(expr + " -> ERROR: " + e.getMessage());
            }
        }
        System.out.println();
    }

    /**
     * Interactive mode for user-driven testing
     */
    private void interactiveMode() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("=== Interactive Expression Evaluation ===");
        System.out.println("Enter expressions like 3+4, 6*7, 8/2");
        System.out.println("Type 'exit' to quit");

        while (true) {
            System.out.print(">> ");
            String input = scanner.nextLine();

            if (input.equalsIgnoreCase("exit")) {
                break;
            }

            try {
                double result = evaluate(input);
                System.out.println("Result = " + result);
            } catch (Exception e) {
                System.out.println("ERROR: " + e.getMessage());
            }
        }

        scanner.close();
    }

    public static void main(String[] args) {
        ExpressionApp app = new ExpressionApp();

        System.out.println("=== Expression Evaluation Engine ===");
        System.out.println("Java → JNI → C++ → C Integration Test\n");

        // 1. Automated tests
        app.runPredefinedTests();

        // 2. Interactive testing
        app.interactiveMode();

        System.out.println("\nApplication terminated.");
    }
}
