# ONP_calculator_C

Author: Karolina Glaza ( https://github.com/kequel )

Made as an Algorithms and Data Structure Project for my 2 semester on Gdansk University of Technology.

Version 1.0. 

Version 2.0 includes Html, JavaScript and WebAssembly. You can find it here: //TO DO// 

1. Programm asks for the number of equations that you want to do.
2. Programm shows the Reversed Polish Notation (ONP) conversion, counting process and result.
3. You can only use positive integners
4. Available operations:
   - a + b
   - a - b
   - a * b
   - a / b
   - Na -> negation (ex. N3 = -3)
   - IF ( a , b , c ) -> if a>0 return b, otherwise c
   - MIN ( a , b , c )
   - MAX ( a , b , c )
   - ( ... ) -> parentheses
5. The formula must end with a "."
6. If the programm finds division by 0, it will write ERROR

How to use, example:
    NUMBER OF EQUATIONS:
4
    EQUATION 1:
MIN ( 100 , MAX ( 1 , 34 , 2 ) , 80 ,  MIN ( 66 , 36  , 35 , 77 ) , 50 , 60 ) .
    CONVERTED TO ONP:
100 1 34 2 MAX3 80 66 36 35 77 MIN4 50 60 MIN6
    COUNTING PROCESS:
MAX3 2 34 1 100
MIN4 77 35 36 66 80 34 100
MIN6 60 50 35 80 34 100
    RESULT:
34

    EQUATION 2:
2 + MIN ( 100 , MAX ( 1 , 6 * 5 + 2 , 2 ) , 80 ,  MIN ( 66 , 36  , 35 , 77 ) , 50 , 60 ) * 3 .
    CONVERTED TO ONP:
2 100 1 6 5 * 2 + 2 MAX3 80 66 36 35 77 MIN4 50 60 MIN6 3 * +
    COUNTING PROCESS:
* 5 6 1 100 2
+ 2 30 1 100 2
MAX3 2 32 1 100 2
MIN4 77 35 36 66 80 32 100 2
MIN6 60 50 35 80 32 100 2
* 3 32 2
+ 96 2
    RESULT:
98

    EQUATION 3:
MIN ( MIN ( IF ( 0 , 8 , 2 ) ) , MAX ( MIN ( 9 ) , 4 + 9 ) , ( IF ( 3 , 9 , 9 ) / MIN ( 7 , 0 , 6 , 2 , 1 ) ) , N ( 3 + 4 ) , 1 * 1 + IF ( 1 , 9 , 2 ) ) .
    CONVERTED TO ONP:
0 8 2 IF MIN1 9 MIN1 4 9 + MAX2 3 9 9 IF 7 0 6 2 1 MIN5 / 3 4 + N 1 1 * 1 9 2 IF + MIN5
    COUNTING PROCESS:
IF 2 8 0
MIN1 2
MIN1 9 2
+ 9 4 9 2
MAX2 13 9 2
IF 9 9 3 13 2
MIN5 1 2 6 0 7 9 13 2
/ 0 9 13 2
ERROR
    EQUATION 4:
MIN ( 3 - 9 * 2 / 7 , IF ( 2 + 7 , 0 - 6 , 8 + 0 ) , IF ( 6 * 5 , ( 5 / 8 ) , N ( 6 ) ) , MAX ( 4 , 4 , 4 , 1 ) / 7 * 1 , MIN ( MIN ( 7 , 6 , 0 , 0 , 6 ) , ( 0 * 3 ) , ( 6 * 1 ) , ( 8 + 1 ) ) , ( 7 - 5 + N 4 ) ) .
    CONVERTED TO ONP:
3 9 2 * 7 / - 2 7 + 0 6 - 8 0 + IF 6 5 * 5 8 / 6 N IF 4 4 4 1 MAX4 7 / 1 * 7 6 0 0 6 MIN5 0 3 * 6 1 * 8 1 + MIN4 7 5 - 4
 N + MIN6
    COUNTING PROCESS:
* 2 9 3
/ 7 18 3
- 2 3
+ 7 2 1
- 6 0 9 1
+ 0 8 -6 9 1
IF 8 -6 9 1
* 5 6 -6 1
/ 8 5 30 -6 1
N 6 0 30 -6 1
IF -6 0 30 -6 1
MAX4 1 4 4 4 0 -6 1
/ 7 4 0 -6 1
* 1 0 0 -6 1
MIN5 6 0 0 6 7 0 0 -6 1
* 3 0 0 0 0 -6 1
* 1 6 0 0 0 0 -6 1
+ 1 8 6 0 0 0 0 -6 1
MIN4 9 6 0 0 0 0 -6 1
- 5 7 0 0 0 -6 1
N 4 2 0 0 0 -6 1
+ -4 2 0 0 0 -6 1
MIN6 -2 0 0 0 -6 1
    RESULT:
-6

Process finished with exit code 0

