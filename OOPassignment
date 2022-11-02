import java.util.Scanner;
class Donation {
    private String user;
    Scanner sc=new Scanner(System.in);
    Donation(){
        System.out.println("Enter your name:");
        user=sc.nextLine();
    }
}
class Sell extends Donation{
    int money(String data){
        int m;
        if(data.equals("rice")){
            m=20;
        }
        else if(data.equals("bread")){
            m=15;
        }
        else if(data.equals("soup")){
            m=15;
        }
        else{
            m=10;
        }
        return m;
    }
    void food(){
        System.out.println("Enter stop to end:");
        String x=" ";
        Boolean y=true;
        int price=0;
        while(y){
            x=sc.next();
            if(x.equals("stop")){
                y=false;
                break;
            }
            price+=money(x);
        }
        System.out.println("The total price is: "+price);
        System.out.println("Thank you for the donation! Your order will be picked");
    }
    void timeslot(){
        System.out.println("Enter the time from the given slots: ");
        System.out.println("8:00AM \n11:00AM \n2:00PM \n6:00PM \n8:00PM ");
        String time=sc.next();
        System.out.println("Your order will be picked at "+time);
        System.out.println("Money will be deposited soon");
    }
    Sell(){
        super();
        System.out.println("Enter food items from rice, bread and soup:");
        food();
        timeslot();
    }
}
class Donate extends Donation{
    Donate(){
        super();
        System.out.println("Enter food items from rice, bread and soup:");
        food();
        timeslot();
    }
    void food(){
        System.out.println("Enter stop to end:");
        Boolean y=true;
        String x=" ";
        String total="";
        while(y){
            x=sc.next();
            if(x.equals("stop")){
                y=false;
                break;
            }
            total=total+" "+x;
        }
        System.out.println("Thank you for the donation!You've Donated:"+total);
        System.out.println("Your order will be picked");
    }
    void timeslot(){
        System.out.println("Enter the time from the given slots: ");
        System.out.println("8:00AM \n11:00AM \n2:00PM \n6:00PM \n8:00PM ");
        String time=sc.next();
        System.out.println("Your order will be picked at "+time);
    }
}
class Location{
    Location(String loc){
        System.out.println("We've detected people of "+loc+" need food");
        loc();
    }
    void loc() {
        System.out.println("Thank you for donating! Your donated food has been used.");
    }

}
class DonationFinal{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter you choice: Sell or Donate");
        String ch=sc.next();
        if(ch.equals("Donate")){
            Donate d=new Donate();
        }
        else if(ch.equals("Sell")){
            Sell s=new Sell();
        }
        System.out.println("Your Order has been picked");
        System.out.println("Enter a location to park the food: ");
        ch=sc.next();
        Location l =new Location(ch);
    }
}
