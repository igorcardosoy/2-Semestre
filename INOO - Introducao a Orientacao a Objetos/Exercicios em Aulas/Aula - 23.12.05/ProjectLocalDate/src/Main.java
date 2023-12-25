import java.time.Instant;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.Period;

public class Main {
  public static void main(String[] args) {
    Instant hehe = Instant.now();
    System.out.println(hehe);
    
    System.out.println("São Paulo: " + (hehe.plusSeconds(-(3 * 60 * 60))));
    System.out.println("Londres: " + hehe.plusSeconds(60 * 60));
    System.out.println("Moscou: " + hehe.plusSeconds(3 * 60 * 60));
    System.out.println("Tóquio: " + hehe.plusSeconds(9 * 60 * 60));
    System.out.println("Alasca: " + hehe.plusSeconds(- (8 *60 * 60)));
  }
}