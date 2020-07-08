#include <iostream>
using namespace std;


int reversed(int num){
  int reversed = 0;
while(num > 0){
    reversed = reversed*10 + num%10;        // take last digit of x, "appends" it to reversed
    num = num/10;                           // remove the digit after the decimal point
  }
return reversed;
}


int getLength(int n){
    unsigned int numDigits = 0;           //intial count  = 0;
    while(n){                             //while n exists as values (true) then apply the following conditon
      numDigits++;
      n = (n/10);                          //performing true division until n=false;
    }
    return numDigits;
  }


int exponent(int base, int exp){          //exponent function
   int c = 1;

   if(exp == 0){                            //corner case, anything number raised to the 0th degree is 1
     return 1;
   }

   for(int i = 1; i<=exp; i++){             //run through the number bounds
      c = c*base;                           //actual alogrithm
    }
    return c;
}



/*
int baseConverterAbove10(char x, char b){
  return 0;
}

*/



int baseConverterUnder10(int x, int b){

  int n = getLength(x);                 //retrieving size of input digits
  //cout<<"n(size): "<<n<<endl;         //debugging test case
  int s = 0;                            //running total

/* getting digits into an array */
  int digitsArray[50];                  //need to declare and initiitalize in same step
  int idx = n;                          //index of array starting from the last. top down
  digitsArray[idx]='\0';                //final null byte, know when to stop

  int userNumber = reversed(x);         //need to reverse nums



  while (userNumber>0){               //user input number
    int digit = (userNumber%10);      //retrieving the digit
    digitsArray[idx] = digit;         //setting the correct index to a digit (append operation)



    //formula
      n--;
      cout<<s<<endl;
      s+= ((digitsArray[idx])*exponent(b,n));
      cout<<s<<endl;
    idx--;                              //decrease the array index since i started from the top
    userNumber= (userNumber/10);        //take off the digit you just put in the array

      cout<<"digitsArray["<<idx<<"] = "<<digit<<endl;  //representation of array

  }

return s;

}


/* for base16+ support
int inputCoordinator(int x, int b){
  int num = 0; //set to zero so random memory is not already stored inside

  if ((b)>=16){
    cout<<"i"<<endl;
    //baseConverterAbove10(x,b);
  }
  else{
    num += baseConverterUnder10(x,b);
  }
return num;

}
*/

int main(){
  int usrNum;               
  int usrBase;

  cout<<"Enter a number to convert: "<<endl;
  cin>>usrNum;

  cout<<"Enter the base of the number: "<<endl;
  cin>>usrBase;

  cout<<baseConverterUnder10(usrNum,usrBase)<<endl;

  return 0;
}
