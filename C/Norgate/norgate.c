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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 99999999
#define MIN -99999999

int ecode = 0;
int hist = 0;
float history[50];

int main (int argc, char *argv[]) 
{
        clear ();
        start:
        printf ("Enter an equation.\n")
        char input[50] = "";
        scanf ("%s", input);
        if (input != NULL) {
                ecode = 6;
                error (ecode);
        }
        if (strcmp (input, "history") == 0) {
                for (int hval = 0; hval < hist; hval++) {
                        printf ("%f\n", history[hval]);
                }
        } else if (strcmp (input, "exit") == 0) {
                exit (0);
        } else {
                char calc[50] = solve (splice (input));
                if (hist >= 50) {
                        clear ();
                }
                history[hist] = calc;
                hist++;
                printf ("%f\n", calc);
        }
        goto start;
}

char[50] splice (char[50] a) 
{
        char eqcoll[50];
        char *eqptr;
        int eqsign = '=';
        eqptr = strchr (a, eqsign);
        if (eqptr != NULL) {
                eqcoll = strings.Split (a, " ");
        } else {
                ecode = 2;
                error (ecode);
        }
        return eqcoll;
}

float solve (char a[50]) 
{
        float answer = 0;
        float opcount = 0;
        for (int t = 0; t < len (a); t++) {
                if (strcmp (a[t], "*") == 0) {
                        opcount++;
                }
                if (strcmp (a[t], "/") == 0) {
                        opcount++;
                }
                if (strcmp (a[t], "+") == 0) {
                        opcount++;
                }
                if (strcmp (a[t], "-") == 0) {
                        opcount++;
                }
                if (strcmp (a[t], "%") == 0) {
                        opcount++;
                }
                if (strcmp (a[t], "^") == 0) {
                        opcount++;
                }
                if (strcmp (a[t], "!") == 0) {
                        opcount++;
                }
        }
        opcount--;
        for (opcount >= 0) {
                exp:
                for (int i = 0; i < len (a); i++) {
                        float fdist = 1;
			float bdist = 1;
                        if (strcmp (a[i], "^") == 0) {
                                for (int y = i; y < len (a); y++) {
                                        if (strcmp (a[i + fdist], ".") == 0) {
                                                fdist++;
                                        }
                                }
                                for (int y = i; y >= 0; y--) {
                                        if (strcmp (a[i - bdist], ".") == 0) {
                                                bdist++;
                                        }
                                }
                                float one = atof (a[i - bdist]);
                                float two = atof (a[i + fdist]);
                                two = exponent (one, two);
                                a[i] = ".";
                                sprintf (a[i + fdist], "%f", two);
                                a[i - bdist] = ".";
                                for (int y = len (a) - 1; y >= 0; y++) {
                                        if (strcmp (a[y], ".") != 0) {
                                                if (strcmp (a[i + fdist + 1], ".") == 0) {
                                                        a[i + fdist + 1] = "^";
                                                }
                                                break;
                                        }
                                }
                                answer = two;
                                opcount--;
                                printf ("%s", a);
                                i = 0;
                        }
                }
                for (int i = 0; i < len (a); i++) {
                        float fdist = 1;
			float bdist = 1;
                        if (strcmp (a[i], "!") == 0) {
                                for (int y = i; y < len (a); y++) {
                                        if (strcmp (a[y], "^") == 0) {
                                                i = y;
                                                goto exp;
                                                break;
                                        } else if (strcmp (a[y], "^") != 0 && y == len (a)) {
                                                break;
                                        }
                                }
                                for (int y = i; y < len (a); y++) {
                                        if (strcmp (a[i + fdist], ".") == 0) {
                                                fdist++;
                                        }
                                }
                                for (int y = i; y >= 0; y--) {
                                        if (strcmp (a[i - bdist], ".") == 0) {
                                                bdist++;
                                        }
                                }
                                one = atof (a[i - bdist]);
                                one = factorial (one);
                                a[i - bdist] = ".";
                                sprintf (a[i], "%f", one);
                                answer = one;
                                opcount--;
                                printf ("%s", a);
                                i = 0;
                        }
                }
                mul:
                for (int i = 0; i < len (a); i++) {
                        float fdist = 1;
			float bdist = 1;
                        if (strcmp (a[i], "*") == 0) {
                                for (int y = i; y < len (a); y++) {
                                        if (strcmp (a[y], "^") == 0) {
                                                i = y;
                                                goto exp;
                                                break;
                                        } else if (strcmp (a[y], "^") != 0 && y == len (a)) {
                                                break;
                                        }
                                }
                                for (int y = i; y < len (a); y++) {
                                        if (strcmp (a[i + fdist], ".") == 0) {
                                                fdist++;
                                        }
                                }
                                for (int y = i; y >= 0; y--) {
                                        if (strcmp (a[i - bdist], ".") == 0) {
                                                bdist++;
                                        }
                                }
                                float one = atof (a[i - bdist]);
                                float two = atof (a[i + fdist]);
                                two = multiply (one, two);
                                a[i] = ".";
                                sprintf (a[i + fdist], "%f", two);
                                a[i - bdist] = "."
                                answer = two;
                                opcount--;
                                printf ("%s", a);
                                i = 0;
                        }
                }
                div:
                for (int i = 0; i < len (a); i++) {
                        float fdist = 1;
			float bdist = 1;
                        if (strcmp (a[i], "/") == 0) {
                                for (int y = i; y < len (a); y++) {
                                        if (strcmp (a[y], "^") == 0) {
                                                i = y;
                                                goto exp;
                                                break;
                                        } else if (strcmp (a[y], "^") != 0 && y == len (a)) {
                                                break;
                                        }
                                }
                                for (int y = i; y < len (a); y++) {
                                        if (strcmp (a[i + fdist], ".") == 0) {
                                                fdist++;
                                        }
                                }
                                for (int y = i; y >= 0; y--) {
                                        if (strcmp (a[i - bdist], ".") == 0) {
                                                bdist++;
                                        }
                                }
                                float one = atof (a[i - bdist]);
                                float two = atof (a[i + fdist]);
                                two = divide (one, two);
                                a[i] = ".";
                                sprintf (a[i + fdist], "%f", two);
                                a[i - bdist] = ".";
                                answer = two;
                                opcount--;
                                printf ("%s", a);
                                i = 0;
                        }
                }
                for (int i = 0; i < len (a); i++) {
                        float fdist = 1;
			float bdist = 1;
                        if (strcmp (a[i], "+") == 0) {
                                for (int y = i; y < len (a); y++) {
                                        if (strcmp (a[y], "*") == 0) {
                                                i = y;
                                                goto mul;
                                                break;
                                        } else if (strcmp (a[y], "/") == 0) {
                                                i = y;
                                                goto div;
                                                break;
                                        } else if (strcmp (a[y], "^") == 0) {
                                               i = y;
                                               goto exp;
                                               break;
                                        } else if (strcmp (a[y], "%") == 0) {
                                               i = y;
                                               goto mod;
                                               break;
                                        }
                                }
                                for (int y = i; y < len (a); y++) {
                                        if (strcmp (a[i + fdist], ".") == 0) {
                                                fdist++;
                                        }
                                }
                                for (int y = i; y >= 0; y--) {
                                        if (strcmp (a[i - bdist], ".") == 0) {
                                                bdist++;
                                        }
                                }
                                float one = atof (a[i - bdist]);
                                float two = atof (a[i + fdist]);
                                two = add (one, two);
                                a[i] = ".";
                                sprintf (a[i + fdist], "%f", two);
                                a[i - bdist] = ".";
                                for (int y = len (a) - 1; y >= 0; y++) {
                                        if (strcmp (a[y], ".") != 0) {
                                                if (strcmp (a[i + fdist + 1], ".") == 0 && strcmp (a[i + fdist + 2], "=") != 0) {
                                                        a[i + fdist + 1] = "+";
                                                }
                                                break;
                                        }
                                }
                                answer = two;
                                opcount--;
                                printf ("%s", a);
                                i = 0;
                        }
                }
                for (i = 0; i < len (a); i++) {
                        float fdist = 1;
			float bdist = 1;
                        if (strcmp (a[i], "-") == 0) {
                                for (int y = i; y < len (a); y++) {
                                        if (strcmp (a[y], "*") == 0) {
                                                i = y;
                                                goto mul;
                                                break;
                                        } else if (strcmp (a[y], "/") == 0) {
                                                i = y;
                                                goto div;
                                                break;
                                        } else if (strcmp (a[y], "^") == 0) {
                                               i = y;
                                               goto exp;
                                               break;
                                        } else if (strcmp (a[y], "%") == 0) {
                                               i = y;
                                               goto mod;
                                               break;
                                        }
                                }
                                for (int y = i; y < len (a); y++) {
                                        if (strcmp (a[i + fdist], ".") == 0) {
                                                fdist++;
                                        }
                                }
                                for (int y = i; y >= 0; y--) {
                                        if (strcmp (a[i - bdist] == ".") == 0) {
                                                bdist++;
                                        }
                                }
                                one = atof (a[i - bdist]);
                                two = atof (a[i + fdist]);
                                two = subtract (one, two);
                                a[i] = ".";
                                sprintf (a[i + fdist], "%f", two);
                                a[i - 1] = ".";
                                for (int y = len (a) - 1; y >= 0; y++ {
                                        if (strcmp (a[y], ".") != 0) {
                                                if (strcmp (a[i + fdist + 1], ".") == 0) {
                                                        a[i + fdist + 1] = "-";
                                                }
                                                break;
                                        }
                                }
                                answer = two;
                                opcount--;
                                printf ("%s", a);
                                i = 0;
                        }
                }
                mod:
                for (int i = 0; i < len (a); i++) {
                        float fdist = 1;
			float bdist = 1;
                        if (strcmp (a[i], "%") == 0) {
                                for (int y = i; y < len (a); y++) {
                                        if (strcmp (a[y], "^") == 0) {
                                                i = y;
                                                goto mul;
                                                break;
                                        }
                                }
                                for (int y = i; y < len (a); y++) {
                                        if (strcmp (a[i + fdist], ".") == 0) {
                                                fdist++;
                                        }
                                }
                                for (int y = i; y < len (a); y++) {
                                        if (strcmp (a[i - bdist], ".") == 0) {
                                                bdist++;
                                        }
                                }
                                float one = atof (a[i - bdist]);
                                float two = atof (a[i + fdist]);
                                two = modulus (one, two);
                                a[i] = ".";
                                sprintf (a[i + fdist], "%f", two);
                                a[i - bdist] = ".";
                                for (int y = len (a) - 1; y >= 0; y++) {
                                        if (strcmp (a[y], ".") != 0) {
                                                if (strcmp (a[i + fdist + 1], ".") == 0) {
                                                        a[i + fdist + 1] = "%";
                                                }
                                                break;
                                        }
                                }
                                answer = two;
                                opcount--;
                                printf ("%s", a);
                                i = 0;
                        }
                }
        }
        return answer;
}

void error (float e) 
{
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

void clear () 
{
        for (int hval = 0; hval < len (history); hval++) {
                history[hval] = 0.0;
        }
        hist = 0;
}

float add (float a, float b) 
{
        if ((a + b) > MAX || (a + b) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return a + b;
}

float subtract (float a, float b) 
{
        if ((a - b) > MAX || (a - b) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return a - b;
}

float multiply (float a, float b) 
{
        if ((a * b) > MAX || (a * b) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return a * b;
}

float divide (float a, float b) 
{
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

float modulus (float a, float b) 
{
        if ((a % b) > MAX || (a % b) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return a % b;
}

float factorial (float a) 
{
        if (a < 0) {
                ecode = 2;
                error (ecode);
        }
        for (int track = a - 1; track > 0; track--) {
                a = a * track;
        }
        if (a > MAX || a < MIN) {
                ecode = 3;
                error (ecode);
        }
        return a;
}

float squareroot (float a) 
{
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

float sine (float a) 
{
        if (sin (a) > MAX || sin (a) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return sin (a);
}

float arcsine (float a) 
{
        if (asin (a) > MAX || asin (a) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return asin (a);
}

float cosine (float a) 
{
        if (cos (a) > MAX || cos (a) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return cos (a);
}

float arccosine (float a) 
{
        if (acos (a) > MAX || acos (a) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return acos (a);
}

float tangent (float a) 
{
        if (tan (a) > MAX || tan (a) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return tan (a);
}

float arctangent (float a) 
{
        if (atan (a) > MAX || atan (a) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return atan (a);
}

float absolute (float a) 
{
        if (fabs (a) > MAX || fabs (a) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return fabs (a);
}

float exponent (float a, float b) 
{
        if (pow (a, b) > MAX || pow (a, b) < MIN) {
                ecode = 3;
                error (ecode);
        }
        return pow (a, b);
}
