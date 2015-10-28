import java.util.*;
public class Guess {
    public static void main(String[] args) {
        Scanner kbd = new Scanner(System.in);
        Random rnd = new Random();
        int trk = 0;
        int hgh = 0;
        int ans = 0;
        short lct = 1;
        short act = 1;
        while (act != 0) {
            switch(lct) {
                case 1:
                	System.out.println("GUESS A VALUE BETWEEN 0 AND 255");
                    short agn = 1;
                    int gss = 0;
                    trk = 0;
                    ans = rnd.nextInt(255);
                    lct = 2;
                    break;
                case 2:
                        gss = kbd.nextInt();
                        if (gss == ans) {
                            System.out.println("CORRECT. IT TOOK YOU" + " " + trk + " " + "ATTEMPTS.");
                            if (hgh == 0) {
                                hgh = trk;
                            } else if (hgh > trk) {
                                System.out.println("< < NEW HIGH SCORE > >");
                                hgh = trk;
                            }
                            System.out.println("HIGH SCORE ::" + " " + hgh);
                            System.out.println("PLAY AGAIN? (0 = N/1 = Y)");
                            agn = kbd.nextShort();
                                if (agn == 1) {
                                    lct = 1;
                                    break;
                                } else if (agn == 0) {
                                		act = 0;
                                		System.exit(0);
                                  } else {
									System.out.println("INVALID RESPONSE.");
										act = 0;
										System.exit(0);
                            		 }
                        } else {
                            if (gss > ans) {
                                System.out.println("TOO HIGH. GUESS AGAIN.");
                                trk++;
                            } else if (gss < ans) {
                                System.out.println("TOO LOW. GUESS AGAIN.");
                                trk++; 
                    }  
                } 
                    default:
            }
        }    
    }
}
