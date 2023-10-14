// java program to display calendar for this month
import java.time.LocalDate;
import java.util.Scanner;

public class Demo {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        
        // get month and year input from user
        System.out.println("Add month and year to view calendar for that particular month");

        System.out.print("Month: ");
        int month = in.nextInt();
        System.out.print("Year: ");
        int year = in.nextInt();

        LocalDate firstDay = LocalDate.of(year, month, 1); // date of 1st day of month
        int dayIndex = firstDay.getDayOfWeek().getValue() - 1; // index of day on firstDay

        // Month and year
        System.out.printf("\n\t%s, %d\n", firstDay.getMonth(), firstDay.getYear());

        // week days
        System.out.println(" Mon Tue Wed Thu Fri Sat Sun");

        // print spaces before firstDay
        System.out.printf("%" + dayIndex * 4 + "c", ' ');

        int dayNum = 1;
        while (dayNum <= firstDay.lengthOfMonth()) {
            dayIndex++;

            System.out.printf("% 4d", dayNum);
            dayNum++;

            // go to new line when week ends
            if (dayIndex % 7 == 0) { System.out.println(); }
        }

        System.out.println();
        in.close();
    }
}
