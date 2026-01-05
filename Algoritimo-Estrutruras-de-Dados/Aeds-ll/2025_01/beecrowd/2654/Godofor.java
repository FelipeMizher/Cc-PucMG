import java.util.*;

public class Godofor{
    static class Character{
        String name;
        int powerLevel;
        int godsKilled;
        int deaths;

        Character(String name, int powerLevel, int godsKilled, int deaths){
            this.name = name;
            this.powerLevel = powerLevel;
            this.godsKilled = godsKilled;
            this.deaths = deaths;
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        Character chosen = new Character("", -1, -1, 101);

        for(int i = 0; i < N; i++){
            String name = sc.next();
            int power = sc.nextInt();
            int killed = sc.nextInt();
            int deaths = sc.nextInt();

            Character current = new Character(name, power, killed, deaths);

            if(current.powerLevel > chosen.powerLevel ||
                (current.powerLevel == chosen.powerLevel && current.godsKilled > chosen.godsKilled) ||
                (current.powerLevel == chosen.powerLevel && current.godsKilled == chosen.godsKilled && current.deaths < chosen.deaths) ||
                (current.powerLevel == chosen.powerLevel && current.godsKilled == chosen.godsKilled &&
                current.deaths == chosen.deaths && current.name.compareTo(chosen.name) < 0)){
                chosen = current;
            }
        }

        System.out.println(chosen.name);
        sc.close();
    }
}
