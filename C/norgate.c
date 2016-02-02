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
#include <math.h>
#include <stdlib.h>

#define MAX 99999999
#define MIN -99999999

int ecode = 0;
int hist = 0;
float history[50];

int main () 
{
        clear ();
        start:
        printf ("Enter an equation.\n")
        char[50] input = "";
        scanf ("%s", input);
        if (input != NULL) {
                ecode = 6;
                error (ecode);
        }
        input = in;
        if strings.Contains (input, "history") {
                for (float hval = 0; hval < hist; hval++) {
                        fmt.Println (history[hval]);
                }
        } else if (strings.Contains (input, "exit")) {
                exit (0);
        } else {
                char[50] calc = solve (splice (input));
                if (hist >= 50) {
                        clear ();
                }
                history[hist] = calc;
                hist++;
                fmt.Print (calc, "\n");
        }
        goto start;
}

char[50] splice (char[50] a) 
{
        char eqcoll[50];
        if (strings.Contains (a, "=") == true) {
                eqcoll = strings.Split (a, " ");
        } else {
                ecode = 2;
                error (ecode);
        }
        return eqcoll;
}

float solve (char[50] a) 
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
                                        if (a[i - bdist] == ".") {
                                                bdist++;
                                        }
                                }
                                one, err := strconv.ParseFloat (a[i - bdist], 64);
                                if (err != NULL) {
                                        ecode = 6;
                                        error (ecode);
                                }
                                two, errtwo := strconv.ParseFloat (a[i + fdist], 64);
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
                                        } else if (a[y] != "^" && y == len (a)) {
                                                break;
                                        }
                                }
                                for (float y = i; y < len (a); y++) {
                                        if (a[i + fdist] == ".") {
                                                fdist++;
                                        }
                                }
                                for (float y = i; y >= 0; y--) {
                                        if (a[i - bdist] == ".") {
                                                bdist++;
                                        }
                                }
                                one, err := strconv.ParseFloat (a[i - bdist], 64);
                                if (err != NULL) {
                                        ecode = 6;
                                        error (ecode);
                                }
                                one = factorial (one);
                                a[i - bdist] = ".";
                                a[i] = fmt.Sprintf ("%v", one);
                                answer = one;
                                opcount--;
                                fmt.Println (strings.Trim (fmt.Sprint(a), "[]"));
                                i = 0;
                        }
                }
                mul:
                for (float i = 0; i < len (a); i++) {
                        fdist := 1;
			bdist := 1;
                        if (a[i] == "*") {
                                for (float y = i; y < len (a); y++) {
                                        if (a[y] == "^") {
                                                i = y;
                                                goto exp;
                                                break;
                                        } else if (a[y] != "^" && y == len (a)) {
                                                break;
                                        }
                                }
                                for (float y = i; y < len (a); y++) {
                                        if (a[i + fdist] == ".") {
                                                fdist++;
                                        }
                                }
                                for (float y = i; y >= 0; y--) {
                                        if (a[i - bdist] == ".") {
                                                bdist++;
                                        }
                                }
                                one, err := strconv.ParseFloat (a[i - bdist], 64);
                                if (err != NULL) {
                                        ecode = 6;
                                        error (ecode);
                                }
                                two, errtwo := strconv.ParseFloat (a[i + fdist], 64);
                                if (errtwo != NULL) {
                                        ecode = 6;
                                        error (ecode);
                                }
                                two = multiply (one, two);
                                a[i] = ".";
                                a[i + fdist] = fmt.Sprintf ("%v", two);
                                a[i - bdist] = "."
                                answer = two;
                                opcount--;
                                fmt.Println (strings.Trim (fmt.Sprint(a), "[]"));
                                i = 0;
                        }
                }
                div:
                for (float i = 0; i < len (a); i++) {
                        fdist := 1;
			bdist := 1;
                        if (a[i] == "/") {
                                for (float y = i; y < len (a); y++) {
                                        if (a[y] == "^") {
                                                i = y;
                                                goto exp;
                                                break;
                                        } else if (a[y] != "^" && y == len (a)) {
                                                break;
                                        }
                                }
                                for (float y = i; y < len (a); y++) {
                                        if (a[i + fdist] == ".") {
                                                fdist++;
                                        }
                                }
                                for (float y = i; y >= 0; y--) {
                                        if (a[i - bdist] == ".") {
                                                bdist++;
                                        }
                                }
                                one, err := strconv.ParseFloat (a[i - bdist], 64);
                                if (err != NULL) {
                                        ecode = 6;
                                        error (ecode);
                                }
                                two, errtwo := strconv.ParseFloat (a[i + fdist], 64);
                                if (errtwo != NULL) {
                                        ecode = 6;
                                        error (ecode);
                                }
                                two = divide (one, two);
                                a[i] = ".";
                                a[i + fdist] = fmt.Sprintf ("%v", two);
                                a[i - bdist] = ".";
                                answer = two;
                                opcount--;
                                fmt.Println (strings.Trim (fmt.Sprint(a), "[]"));
                                i = 0;
                        }
                }
                for (float i = 0; i < len (a); i++) {
                        float fdist = 1;
			float bdist = 1;
                        if (a[i] == "+") {
                                for (float y = i; y < len (a); y++) {
                                        if (a[y] == "*") {
                                                i = y;
                                                goto mul;
                                                break;
                                        } else if (a[y] == "/") {
                                                i = y;
                                                goto div;
                                                break;
                                        } else if (a[y] == "^") {
                                               i = y;
                                               goto exp;
                                               break;
                                        } else if (a[y] == "%") {
                                               i = y;
                                               goto mod;
                                               break;
                                        }
                                }
                                for (float y = i; y < len (a); y++) {
                                        if (a[i + fdist] == ".") {
                                                fdist++;
                                        }
                                }
                                for (y := i; y >= 0; y--) {
                                        if (a[i - bdist] == ".") {
                                                bdist++;
                                        }
                                }
                                one, err := strconv.ParseFloat (a[i - bdist], 64);
                                if (err != NULL) {
                                        ecode = 6;
                                        error (ecode);
                                }
                                two, errtwo := strconv.ParseFloat (a[i + fdist], 64);
                                if (errtwo != NULL) {
                                        ecode = 6;
                                        error (ecode);
                                }
                                two = add (one, two);
                                a[i] = ".";
                                a[i + fdist] = fmt.Sprintf ("%v", two);
                                a[i - bdist] = ".";
                                for (float y = len (a) - 1; y >= 0; y++) {
                                        if (a[y] != ".") {
                                                if (a[i + fdist + 1] == "." && a[i + fdist + 2] != "=") {
                                                        a[i + fdist + 1] = "+";
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
                for (i = 0; i < len (a); i++) {
                        float fdist = 1;
			float bdist = 1;
                        if (a[i] == "-") {
                                for (float y = i; y < len (a); y++) {
                                        if (a[y] == "*") {
                                                i = y;
                                                goto mul;
                                                break;
                                        } else if a[y] == "/" {
                                                i = y;
                                                goto div;
                                                break;
                                        } else if a[y] == "^" {
                                               i = y;
                                               goto exp;
                                               break;
                                        } else if a[y] == "\x25" {
                                               i = y;
                                               goto mod;
                                               break;
                                        }
                                }
                                for (float y = i; y < len (a); y++) {
                                        if (a[i + fdist] == ".") {
                                                fdist++;
                                        }
                                }
                                for y := i; y >= 0; y-- {
                                        if (a[i - bdist] == ".") {
                                                bdist++;
                                        }
                                }
                                one, err := strconv.ParseFloat (a[i - bdist], 64);
                                if (err != NULL) {
                                        ecode = 6;
                                        error (ecode);
                                }
                                two, errtwo := strconv.ParseFloat (a[i + fdist], 64);
                                if (errtwo != NULL) {
                                        ecode = 6;
                                        error (ecode);
                                }
                                two = subtract (one, two);
                                a[i] = ".";
                                a[i + fdist] = fmt.Sprintf ("%v", two);
                                a[i - 1] = ".";
                                for y := len (a) - 1; y >= 0; y++ {
                                        if (a[y] != ".") {
                                                if (a[i + fdist + 1] == ".") {
                                                        a[i + fdist + 1] = "-";
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
                mod:
                for (float i = 0; i < len (a); i++) {
                        float fdist = 1;
			float bdist = 1;
                        if (a[i] == "%") {
                                for (float y = i; y < len (a); y++) {
                                        if (a[y] == "^") {
                                                i = y;
                                                goto mul;
                                                break;
                                        }
                                }
                                for (float y = i; y < len (a); y++) {
                                        if (a[i + fdist] == ".") {
                                                fdist++;
                                        }
                                }
                                for (float y = i; y < len (a); y++) {
                                        if (a[i - bdist] == ".") {
                                                bdist++;
                                        }
                                }
                                one, err := strconv.ParseFloat (a[i - bdist], 64);
                                if (err != NULL) {
                                        ecode = 6;
                                        error (ecode);
                                }
                                two, errtwo := strconv.ParseFloat (a[i + fdist], 64);
                                if (errtwo != NULL) {
                                        ecode = 6;
                                        error (ecode);
                                }
                                two = modulus (one, two);
                                a[i] = ".";
                                a[i + fdist] = fmt.Sprintf ("%v", two);
                                a[i - bdist] = ".";
                                for y := len (a) - 1; y >= 0; y++ {
                                        if a[y] != "." {
                                                if (a[i + fdist + 1] == ".") {
                                                        a[i + fdist + 1] = "%";
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
        }
        return answer
}

void error (float e) {
        switch (e) {
        case 1:
                printf ("Error 1: Overflow.");
                exit (1);
        case 2:
                printf ("Error 2: Invalid operation.");
                exit (2);
        case 3:
                printf ("Error 3: Post-operation overflow.");
                exit (3);
        case 4:
                printf ("Error 4: Divide by zero.");
                exit (4);
        case 5:
                printf ("Error 5: Imaginary number.");
                exit (5);
        case 6:
                printf ("Error 6: Error parsing.");
                exit (6);
        default:
                printf ("Error 0: Generic error.");
                exit (0);
        }
}

void clear () {
        for (float hval = 0; hval < len (history); hval++) {
                history[hval] = 0.0;
        }
        hist = 0;
}

float add (float a, float b) {
        if ((a + b) > MAX || (a + b) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return a + b;
}

float subtract (float a, float b) {
        if ((a - b) > MAX || (a - b) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return a - b;
}

float multiply (float a, float b) {
        if ((a * b) > MAX || (a * b) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return a * b;
}

float divide (float a, float b) {
        if (b == 0) {
                ecode = 4;
                error (ecode);
        } else if (a == 0) {
                return 0;
        }
        if ((a / b) > MAX || (a / b) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return a / b;
}

float modulus (float a, float b) {
        if ((a % b) > MAX || (a % b) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return a % b;
}

float factorial (float a) {
        if (a < 0) {
                ecode = 2;
                error (ecode);
        }
        for (float track = a - 1; track > 0; track--) {
                a = a * track;
        }
        if (a > MAX || a < MIN) {
                ecode = 3;
                error (ecode);
        }
        return a;
}

float squareroot (float a) {
        if (sqrt (a) > MAX || math.Sqrt (a) < MIN) {
                ecode = 3;
                error (ecode);
        }
        if (a < 0) {
                ecode = 5;
                error (ecode);
        }
        return sqrt (a);
}

float sine (float a) {
        if (sin (a) > MAX || sin (a) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return sin (a);
}

float cosine (float a) {
        if (cos (a) > MAX || cos (a) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return cos (a);
}

float tangent (float a) {
        if (tan (a) > MAX || tan (a) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return tan (a);
}

float absolute (float a) {
        if (abs (a) > MAX || abs (a) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return abs (a);
}

float exponent (float a, float b) {
        if (pow (a, b) > MAX || pow (a, b) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return pow (a, b);
}
