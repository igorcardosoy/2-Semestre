
public class USMoney {

    private int dollars;
    private int cents;

    public USMoney(int dollars, int cents) {
        this.dollars = dollars;
        this.cents = cents;

        if (this.cents < 0) {
            this.cents = 0;
        }

        if (this.dollars < 0) {
            this.dollars = 0;
        }

        if (this.cents > 99) {
            this.dollars += this.cents / 100;
            this.cents = this.cents % 100;
        }
    }

    public USMoney plus(USMoney money) {
        return new USMoney((money.dollars + this.dollars), (money.cents + this.cents));
    }

    public int getDollars() {
        return this.dollars;
    }

    public int getCents() {
        return this.cents;
    }

}