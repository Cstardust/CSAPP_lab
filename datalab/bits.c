/* 
 * CS:APP Data Lab 
 * 
 * Shc 200110732
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif

/*
bits.c??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
btest.c?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
dlc??????????????????????????????????????????????????????gcc???????????????????????????????????????????????????????????????lab???????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
driver.pl???????????????????????????????????????????????????????????????
fshow.c&ishow.c?????????????????????????????????????????????????????????????????????????????????????????????????????????float??????integer????????????????????????????????????????????????????????????????????????

??????bits.c??????????????????
?????????
???????????????./dlc -e bits.c?????????????????????????????????????????????????????????????????????
??????make clean && make btest????????????
??????./btest???????????????????????????
return 1 ??????????????????
????????????./driver.pl????????????
*/

//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1  
 *   Legal ops: ~ &             ????????????
 *   Max ops: 14                ??????????????????
 *   Rating: 1                  ??????????????????
 * ???:
 *  x^y?????????x???y??????????????????????????????1???????????????0
 *  t1 = x&y???x???y?????????1??????(t)???0
 *  t2 = ~x&~y???x???y?????????0??????(t)???0
 * ~t1???x???y????????????1??????(t)???1
 * ~t2???x???y????????????0??????(t)???1
 * ~t1 & ~t2???x???y??????????????????1????????????????????????0??? ??? ???1
 */

int bitXor(int x, int y) {
  int t1 = x&y;
  int t2 = (~x)&(~y);
  return (~t1) & (~t2);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1<<31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 * 
 * ????????????x?????????0??????????????????????????????????????????Tmax????????????-1 0xffffffff???
 */
int isTmax(int x) {
  int t = x+1;      //  Tmax->Tmin 10000...000
  x = ~(x+t);       //  x <-- 0
  return !(x+!t) ;  //  +!t?????????????????????x???-1?????????
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int m = 0xaa;
  m = m<<8 | 0xaa; //  0xaa
  m = m<<8 | 0xaa; //  0xaaaa
  m = m<<8 | 0xaa; //  0xaaaaaa
  m = m<<8 | 0xaa; //  0xaaaaaaaa
  return !((x&m)^m);    //  ??????x???????????????m??? x&m ??????????????? ^m ?????????????????????
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
//  ???????????????(a-b?????????????????????)?????????a>=b???,???????????????????????????????????????????????? a-b>=0 -> a+(~b+1)>=0 -> a+(~b+1)????????????0
//  ??????????????????a<0,b>0 ???a<b???a>0,b<0??????a>b
//  ????????????(?????????????????????)?????????a<b????????????<?????????a-b<0 -> a+(~b+1)<0 -> a+(~b+1)????????????1
//  ??????x??????[0x30,0x39]
int isAsciiDigit(int x) {
  int t1 = x+(~0x30+1);     //  x>=0x30
  int t2 = 0x39 + (~x+1);   //  x<=0x39
  return (!(t1>>31)) & (!(t2>>31));
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 * ?????????x???bool?????????!!x;
 *    x=0,???!!x=0
 *    x!=0,???!!x=1
 */
int conditional(int x, int y, int z) {
  x = !!x;
  x = ~x+1;   //  0->0???00...00->00...00  ??? 1->-1???00...001 -> 111...1111
  return (x&y) | ((~x)&z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 * ???????????????????????????????????????????????????????????????;  !((y+(~x)+1)>>31) 
 * ???????????????????????????????????????x????????????      
 */
int isLessOrEqual(int x,int y) {
  //  ?????????????????? ??????????????????&1???????????????????????????????????????????????????
  int sub_sign = (y+(~x+1))>>31&1;  //  y-x
  // sub_sign = (sub_sign>>31)&1;  //  ??????y-x?????????????????????????????????0???
  int x_sign = (x>>31)&1;     //  ??????x?????????????????????????????????0???
  int y_sign = (y>>31)&1;     //  ??????y?????????????????????????????????0???
  int sign_xor = x_sign ^ y_sign; //  x???y????????????????????? ?????????0????????????1???
  return ((!sign_xor)&(!sub_sign)) | (sign_xor&x_sign) ;
  /*
  * x???y??????????????????sign_xor=0????????????y-x>=0,???sub_sign=0x0???????????????x<=y?????????1
  * x???y??????????????????sign_xor=1; ?????????x???????????????x_sign=0x1????????????x<=y?????????1
  */  
 return 0;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 * 
 *   ???????????????
 *    -x = ~x+1;
 *      x==0??????-x=x=0???
 *      x==Tmin???,-x=x
 *      ?????????,x!=-x
 *  
 */
int logicalNeg(int x) {
  int s = x | (~x+1); 
  return ((s>>31) + 1); 
  // ??????>> ???????????????????????????
  // x>0||x<0??????s???????????????1,>>31????????????111...1111??? +1??????000000...000
  // x==0,s?????????=0???>>31????????????00000...000   	;   +1??????1
}

/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 * ???????????????????????????????????????1??????????????????????????????0???????????????
 * ???????????????????????????????????????0??????????????????????????????1???????????????
 * ???????????????????????????bool???: !!x
 * ?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????1?????????????????????
 */
int howManyBits(int x) {
  int b16,b8,b4,b2,b1,b0;
  int sign = x>>31;           //  >=0 ???sign=0x0??? <=0 ???sign=0xffffffff
  x = (sign&~x)|(~sign&x);    //  x>=0,x=x?????????x<0,???x=~x
  b16 = (!(!(x>>16)))<<4; //  ?????????16??????1?????????b16=16?????????b16=0
  x = x>>b16;                 //  ?????????16???????????????????????????????????????
  b8 = (!(!(x>>8)))<<3;       //  ??????x???[31,8]???1???????????????????????????[7,0]????????????[31,8]?????????????????????????????????8????????????1?????????????????????
  x = x>>b8;
  b4 = (!(!(x>>4)))<<2;
  x = x>>b4;
  b2 = (!(!(x>>2)))<<1;
  x = x>>b2;
  b1 = !(!(x>>1));
  x = x>>b1;
  b0 = x;
  //  b16 + b8 ... + b0 ?????????????????????1????????????0????????????
  return b16 + b8 + b4 + b2 + b1 + b0 + 1;    //  ??????+?????????1??????????????????????????????????????????
}

//float
/* 
 *   floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 * NUM:
 *   s exp frac
 *   arg:
 *    NAN???exp=11..11 ; frac!=0
 *    ?????????s=0/1 ;exp=111..111;frac=0
 *    0:exp=0 ; frac=0  
 *   ??????????????????????????????????????????????????????
 */
unsigned floatScale2(unsigned uf) { 
  int s = (uf>>31)&0x1;             //  s
  int exp = (uf&0x7f800000)>>23;    //  exp??????
  int frac = uf&0x007fffff;         //  frac
  if(exp==255)                      //  NAN / ?????????
    return uf;           
  if(exp==0)                       //  ?????????????????????E = 1-bias; ????????????E=e-bias?????????????????????????????????????????????????????????????????????????????????
    return (s<<31) | (uf<<1);    
  if(++exp==255)                    // exp++?????????*2???????????????????????????bias????????????????????????????????????????????? *2 ???????????????????????????NAN???????????????NAN??????????????????
  {
    return exp<<23 | s<<31 ;    //  0x7t800000 | s<<31
  }
  return s<<31 | exp<<23 | frac;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 * float -> int
 * |float| = 0  -> int =0 
 * |float| < 1  -> int = 0;
 * E = e-bias
 * E >= 31  -> ??????int(?????????float : 2^E * M(M=1+f))
 * 0 < E < 31 ??????frac
 * 0 < E < 23 ??????frac?????????
 * 23 <= E < 31 ?????????frac????????? 
 */
int floatFloat2Int(unsigned uf) {
  int E,M;
  int bias,s,exp,frac;
  bias = 127;
  s = (uf>>31)&0x1;
  exp = (uf&0x7f800000)>>23;
  E = exp-bias;         //  ??????E
  frac = uf&0x007fffff;
  M = frac + (1<<23);   //  ??????M??????????????????1
  //  ??????E???M
  if(E<0)
  {
    return 0;
  }
  else if(E>=31)
  {
    return 0x80000000u; 
  }
  else if(E>=0&&E<23)
  {
    M >>= (23-E);
  }
  else if(E>23)
  {
    M <<= (E-23);
  }
  if(s) return -M;  //  ?????? -M = ~M + 1??????????????????????????????????????????1???
  else return M;
}

/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 * 
      * ??????????????????0???

      2^-150?????????????????????0|00000000|00000000000000000000000

      ??????????????????0:
      -------------------------------------------------------------------
      2^-149?????????????????????0|00000000|00000000000000000000001
      2^-148?????????????????????0|00000000|00000000000000000000010
      2^-147?????????????????????0|00000000|00000000000000000000100
      ??????
      2^-129?????????????????????0|00000000|00100000000000000000000
      2^-128?????????????????????0|00000000|01000000000000000000000
      2^-127?????????????????????0|00000000|10000000000000000000000

      ?????????????????????0???
      -------------------------------------------------------------------
      2^-126?????????????????????0|00000001|00000000000000000000000
      2^-125?????????????????????0|00000010|00000000000000000000000
      2^-124?????????????????????0|00000011|00000000000000000000000
      ??????
      2^0 ?????????????????????0|01111111|00000000000000000000000
      2^1 ?????????????????????0|10000000|00000000000000000000000
      ??????
      2^127 ?????????????????????0|11111110|00000000000000000000000

      ????????????????????????
      -----------------------------------------------------------------
      2^128 ?????????????????????0|11111111|00000000000000000000000
      2^129 ?????????????????????0|11111111|00000000000000000000000
 *  ???????????????
 *    E = 1-bias = 1-127 = -126
 *    frac = 2^-24 ...  2^-1
 *  V = 2^E * frac
 * ?????????????????????2??????????????? ??? 2^-150 --- 2^-127
 *  ????????????
 *    E = e-bias = e-127 
 * 2???????????????-126-127
 */
//  ???????????????????????????2.0^x
unsigned floatPower2(int x) {
    //  ??????????????????????????????return 0
    if(x<=-127){
      return 0;
    }else if(x>=-126&&x<=127){
      return (x+127)<<23; //  frac?????????0 E = e-bias??????e = E+bias
    }else if(x>127){
      return 0x7f800000u;   //  ???+INF ???0xff<<23 8+23=31??? ??????????????????????????????0 ???32??????
    }    
    return 0;
}
