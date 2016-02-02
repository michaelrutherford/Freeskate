/*
Copyright 2015 Michael Rutherford

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <stdio.h>

#define MAX 99999999
#define MIN -99999999

int ecode  = 0;
int hist = 0;
float history[50];

int main () 
{
        clear ()
        start:
        printf ("Enter an equation.\n")
        char* input = "";
        scanf ("%s", input);
        if (input != NULL) {
                ecode = 6;
                error (ecode);
        }
        input = in;
        if strings.Contains (input, "history") {
                for hval := 0; hval < hist; hval++ {
                        fmt.Println (history[hval]);
                }
        } else if (strings.Contains (input, "exit")) {
                os.Exit (0);
        } else {
                calc := solve (splice (input));
                if (hist >= 50) {
                        clear ();
                }
                history[hist] = calc;
                hist++;
                fmt.Print (calc, "\n");
        }
        goto start;
}
char* splice (char* a) 
{
        char *eqcoll;
        if (strings.Contains (a, "=") == true) {
                eqcoll = strings.Split (a, " ");
        } else {
                ecode = 2;
                error (ecode);
        }
        return eqcoll;
}
float solve (char* a) 
{
        float answer = 0;
        float opcount = 0;
        for (int t = 0; t < len (a); t++) {
                if (a[t] == "*") {
                        opcount++;
                }
                if (a[t] == "/") {
                        opcount++;
                }
                if (a[t] == "+") {
                        opcount++;
                }
                if (a[t] == "-") {
                        opcount++;
                }
                if (a[t] == "%") {
                        opcount++;
                }
                if (a[t] == "^") {
                        opcount++;
                }
                if (a[t] == "!") {
                        opcount++;
                }
        }
        opcount--;
        for (opcount >= 0) {
                exp:
                for (float i = 0; i < len (a); i++) {
                        float fdist = 1;
			float bdist = 1;
                        if (a[i] == "^") {
                                for (int y = i; y < len (a); y++) {
                                        if (a[i + fdist] == ".") {
                                                fdist++;
                                        }
                                }
                                for (float y = i; y >= 0; y--) {
                                        if a[i - bdist] == "." {
                                                bdist++
                                        }
                                }
                                one, err := strconv.ParseFloat (a[i - bdist], 64);
                                if (err != nil) {
                                        ecode = 6;
                                        error (ecode);
                                }
                                two, errtwo := strconv.ParseFloat (a[i + fdist], 64)
                                if (errtwo != nil) {
                                        ecode = 6;
                                        error (ecode);
                                }
                                two = exponent (one, two);
                                a[i] = ".";
                                a[i + fdist] = fmt.Sprintf ("%v", two);
                                a[i - bdist] = ".";
                                for (float y = len (a) - 1; y >= 0; y++) {
                                        if (a[y] != ".") {
                                                if (a[i + fdist + 1] == ".") {
                                                        a[i + fdist + 1] = "^";
                                                }
                                                break;
                                        }
                                }
                                answer = two;
                                opcount--;
                                fmt.Println (strings.Trim (fmt.Sprint(a), "[]"));
                                i = 0;
                        }
                }
                for (float i = 0; i < len (a); i++) {
                        float fdist = 1;
			float bdist = 1;
                        if (a[i] == "!") {
                                for (float y = i; y < len (a); y++) {
                                        if (a[y] == "^") {
                                                i = y;
                                                goto exp;
                                                break;
                                        } else if a[y] != "^" && y == len (a) {
                                                break;
                                        }
                                }
                                for y := i; y < len (a); y++ {
                                        if a[i + fdist] == "." {
                                                fdist++
                                        }
                                }
                                for y := i; y >= 0; y-- {
                                        if a[i - bdist] == "." {
                                                bdist++
                                        }
                                }
                                one, err := strconv.ParseFloat (a[i - bdist], 64)
                                if err != nil {
                                        ecode = 6
                                        error (ecode)
                                }
                                one = factorial (one)
                                a[i - bdist] = "."
                                a[i] = fmt.Sprintf ("%v", one);
                                answer = one
                                opcount--
                                fmt.Println (strings.Trim (fmt.Sprint(a), "[]"))
                                i = 0
                        }
                }
                mul:
                for i := 0; i < len (a); i++ {
                        fdist := 1
			bdist := 1
                        if a[i] == "*" {
                                for y := i; y < len (a); y++ {
                                        if a[y] == "^" {
                                                i = y
                                                goto exp
                                                break
                                        } else if a[y] != "^" && y == len (a) {
                                                break
                                        }
                                }
                                for y := i; y < len (a); y++ {
                                        if a[i + fdist] == "." {
                                                fdist++
                                        }
                                }
                                for y := i; y >= 0; y-- {
                                        if a[i - bdist] == "." {
                                                bdist++
                                        }
                                }
                                one, err := strconv.ParseFloat (a[i - bdist], 64)
                                if err != nil {
                                        ecode = 6
                                        error (ecode)
                                }
                                two, errtwo := strconv.ParseFloat (a[i + fdist], 64)
                                if errtwo != nil {
                                        ecode = 6
                                        error (ecode)
                                }
                                two = multiply (one, two)
                                a[i] = "."
                                a[i + fdist] = fmt.Sprintf ("%v", two);
                                a[i - bdist] = "."
                                answer = two
                                opcount--
                                fmt.Println (strings.Trim (fmt.Sprint(a), "[]"))
                                i = 0
                        }
                }
                div:
                for i := 0; i < len (a); i++ {
                        fdist := 1
			bdist := 1
                        if a[i] == "/" {
                                for y := i; y < len (a); y++ {
                                        if a[y] == "^" {
                                                i = y
                                                goto exp
                                                break
                                        } else if a[y] != "^" && y == len (a) {
                                                break
                                        }
                                }
                                for y := i; y < len (a); y++ {
                                        if a[i + fdist] == "." {
                                                fdist++
                                        }
                                }
                                for y := i; y >= 0; y-- {
                                        if a[i - bdist] == "." {
                                                bdist++
                                        }
                                }
                                one, err := strconv.ParseFloat (a[i - bdist], 64)
                                if err != nil {
                                        ecode = 6
                                        error (ecode)
                                }
                                two, errtwo := strconv.ParseFloat (a[i + fdist], 64)
                                if errtwo != nil {
                                        ecode = 6
                                        error (ecode)
                                }
                                two = divide (one, two)
                                a[i] = "."
                                a[i + fdist] = fmt.Sprintf ("%v", two);
                                a[i - bdist] = "."
                                answer = two
                                opcount--
                                fmt.Println (strings.Trim (fmt.Sprint(a), "[]"))
                                i = 0
                        }
                }
                for i := 0; i < len (a); i++ {
                        fdist := 1
			bdist := 1
                        if a[i] == "+" {
                                for y := i; y < len (a); y++ {
                                        if a[y] == "*" {
                                                i = y
                                                goto mul
                                                break
                                        } else if a[y] == "/" {
                                                i = y
                                                goto div
                                                break
                                        } else if a[y] == "^" {
                                               i = y
                                               goto exp
                                               break
                                        } else if a[y] == "\x25" {
                                               i = y
                                               goto mod
                                               break
                                        }
                                }
                                for y := i; y < len (a); y++ {
                                        if a[i + fdist] == "." {
                                                fdist++
                                        }
                                }
                                for y := i; y >= 0; y-- {
                                        if a[i - bdist] == "." {
                                                bdist++
                                        }
                                }
                                one, err := strconv.ParseFloat (a[i - bdist], 64)
                                if err != nil {
                                        ecode = 6
                                        error (ecode)
                                }
                                two, errtwo := strconv.ParseFloat (a[i + fdist], 64)
                                if errtwo != nil {
                                        ecode = 6
                                        error (ecode)
                                }
                                two = add (one, two)
                                a[i] = "."
                                a[i + fdist] = fmt.Sprintf ("%v", two);
                                a[i - bdist] = "."
                                for y := len (a) - 1; y >= 0; y++ {
                                        if a[y] != "." {
                                                if a[i + fdist + 1] == "." && a[i + fdist + 2] != "=" {
                                                        a[i + fdist + 1] = "+"
                                                }
                                                break
                                        }
                                }
                                answer = two
                                opcount--
                                fmt.Println (strings.Trim (fmt.Sprint(a), "[]"))
                                i = 0
                        }
                }
                for i := 0; i < len (a); i++ {
                        fdist := 1
			bdist := 1
                        if a[i] == "-" {
                                for y := i; y < len (a); y++ {
                                        if a[y] == "*" {
                                                i = y
                                                goto mul
                                                break
                                        } else if a[y] == "/" {
                                                i = y
                                                goto div
                                                break
                                        } else if a[y] == "^" {
                                               i = y
                                               goto exp
                                               break
                                        } else if a[y] == "\x25" {
                                               i = y
                                               goto mod
                                               break
                                        }
                                }
                                for y := i; y < len (a); y++ {
                                        if a[i + fdist] == "." {
                                                fdist++
                                        }
                                }
                                for y := i; y >= 0; y-- {
                                        if a[i - bdist] == "." {
                                                bdist++
                                        }
                                }
                                one, err := strconv.ParseFloat (a[i - bdist], 64)
                                if err != nil {
                                        ecode = 6
                                        error (ecode)
                                }
                                two, errtwo := strconv.ParseFloat (a[i + fdist], 64)
                                if errtwo != nil {
                                        ecode = 6
                                        error (ecode)
                                }
                                two = subtract (one, two)
                                a[i] = "."
                                a[i + fdist] = fmt.Sprintf ("%v", two);
                                a[i - 1] = "."
                                for y := len (a) - 1; y >= 0; y++ {
                                        if a[y] != "." {
                                                if a[i + fdist + 1] == "." {
                                                        a[i + fdist + 1] = "-"
                                                }
                                                break
                                        }
                                }
                                answer = two
                                opcount--
                                fmt.Println (strings.Trim (fmt.Sprint(a), "[]"))
                                i = 0
                        }
                }
                mod:
                for i := 0; i < len (a); i++ {
                        fdist := 1
			bdist := 1
                        if a[i] == "\x25" {
                                for y := i; y < len (a); y++ {
                                        if a[y] == "^" {
                                                i = y
                                                goto mul
                                                break
                                        }
                                }
                                for y := i; y < len (a); y++ {
                                        if a[i + fdist] == "." {
                                                fdist++
                                        }
                                }
                                for y := i; y < len (a); y++ {
                                        if a[i - bdist] == "." {
                                                bdist++
                                        }
                                }
                                one, err := strconv.ParseFloat (a[i - bdist], 64)
                                if err != nil {
                                        ecode = 6
                                        error (ecode)
                                }
                                two, errtwo := strconv.ParseFloat (a[i + fdist], 64)
                                if errtwo != nil {
                                        ecode = 6
                                        error (ecode)
                                }
                                two = modulus (one, two)
                                a[i] = "."
                                a[i + fdist] = fmt.Sprintf ("%v", two);
                                a[i - bdist] = "."
                                for y := len (a) - 1; y >= 0; y++ {
                                        if a[y] != "." {
                                                if a[i + fdist + 1] == "." {
                                                        a[i + fdist + 1] = "\x25"
                                                }
                                                break
                                        }
                                }
                                answer = two
                                opcount--
                                fmt.Println (strings.Trim (fmt.Sprint(a), "[]"))
                                i = 0
                        }
                }
        }
        return answer
}
func error (e int) {
        switch (e) {
        case 1:
                fmt.Println ("Error 1: Overflow.")
                os.Exit (1)
        case 2:
                fmt.Println ("Error 2: Invalid operation.")
                os.Exit (2)
        case 3:
                fmt.Println ("Error 3: Post-operation overflow.")
                os.Exit (3)
        case 4:
                fmt.Println ("Error 4: Divide by zero.")
                os.Exit (4)
        case 5:
                fmt.Println ("Error 5: Imaginary number.")
                os.Exit (5)
        case 6:
                fmt.Println ("Error 6: Error parsing.")
                os.Exit (6)
        default:
                fmt.Println ("Error 0: Generic error.")
                os.Exit (0)
        }
}
func clear () {
        for hval := 0; hval < len (history); hval++ {
                history[hval] = 0.0
        }
        hist = 0
}
func add (a, b float64) float64 {
        if a + b > MAX || a + b < MIN {
                ecode = 3
                error (ecode)
        }
        return a + b
}
func subtract (a, b float64) float64 {
        if a - b > MAX || a - b < MIN {
                ecode = 3
                error (ecode)
        }
        return a - b
}
func multiply (a, b float64) float64 {
        if a * b > MAX || a * b < MIN {
                ecode = 3
                error (ecode)
        }
        return a * b
}
func divide (a, b float64) float64 {
        if b == 0 {
                ecode = 4
                error (ecode)
        } else if a == 0 {
                return 0
        }
        if a / b > MAX || a / b < MIN {
                ecode = 3
                error (ecode)
        }
        return a / b
}
func modulus (a, b float64) float64 {
        if math.Mod (a, b) > MAX || math.Mod (a, b) < MIN {
                ecode = 3
                error (ecode)
        }
        return math.Mod (a, b)
}
func factorial (a float64) float64 {
        if a < 0 {
                ecode = 2
                error (ecode)
        }
        for track := a - 1; track > 0; track-- {
                a = a * track
        }
        if a > MAX || a < MIN {
                ecode = 3
                error (ecode)
        }
        return a
}
func squareroot (a float64) float64 {
        if math.Sqrt (a) > MAX || math.Sqrt (a) < MIN {
                ecode = 3
                error (ecode)
        }
        if a < 0 {
                ecode = 5
                error (ecode)
        }
        return math.Sqrt (a)
}
func sine (a float64) float64 {
        if math.Sin (a) > MAX || math.Sin (a) < MIN {
                ecode = 3
                error (ecode)
        }
        return math.Sin (a)
}
func cosine (a float64) float64 {
        if math.Cos (a) > MAX || math.Cos (a) < MIN {
                ecode = 3
                error (ecode)
        }
        return math.Cos (a)
}
func tangent (a float64) float64 {
        if math.Tan (a) > MAX || math.Tan (a) < MIN {
                ecode = 3
                error (ecode)
        }
        return math.Tan (a)
}
func absolute (a float64) float64 {
        if math.Abs (a) > MAX || math.Abs (a) < MIN {
                ecode = 3
                error (ecode)
        }
        return math.Abs (a)
}
func exponent (a, b float64) float64 {
        if math.Pow (a, b) > MAX || math.Pow (a, b) < MIN {
                ecode = 3
                error (ecode)
        }
        return math.Pow (a, b)
}