package main;
import "fmt";
import "os";
const MAX = 999999999;
const MIN = -999999999;
func main() {
        input := 0;
        format := "";
        fmt.Println("Enter an integer.");
        fmt.Scan(&input);
        if input > MAX || input < MIN {
                os.Exit(1);
        }
        fmt.Println("Enter a format.");
        fmt.Scan(&format);
        translate(input, format);
}
func translate(in int, form string) {
        switch(form) {
        case "binary": fmt.Printf("%b\n", in);
        case "hexadecimal": fmt.Printf("%x\n", in);
        case "decimal": fmt.Printf("%d\n", in);
        default: os.Exit(2);
        }
}
