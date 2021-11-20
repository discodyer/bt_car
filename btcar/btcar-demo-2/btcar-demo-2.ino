//#include <Arduino_FreeRTOS.h>      //TODO：using freertos to realize multithreading 

#include "L298NX4.h"
#include "L298N.h"


//init ports of M1
const unsigned int IN_A1 = 4;
const unsigned int IN_A2 = 2;
const unsigned int EN_A  = 3;
//init ports of M2
const unsigned int IN_B1 = 11;
const unsigned int IN_B2 = 10;
const unsigned int EN_B  = 5;
//init ports of M3
const unsigned int IN_C1 = 8;
const unsigned int IN_C2 = 7;
const unsigned int EN_C  = 6;
//init ports of M4
const unsigned int IN_D1 = 13;
const unsigned int IN_D2 = 12;
const unsigned int EN_D  = 9;


/*
         ↑Front↑
      ┌----------┐
   A ▤│M1     M2│▤ B
      │          │
      │          │
      │          │
   C ▤│M3     M4│▤ D
      └----------┘
*/


L298NX4 motors( EN_A, IN_A1, IN_A2,
                EN_B, IN_B1, IN_B2, 
                EN_C, IN_C1, IN_C2, 
                EN_D, IN_D1, IN_D2);



//init two speed
unsigned short LOW_SPEED = 55;
unsigned short HIGH_SPEED = 255;


void setup() {
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.

  // Set initial speed for ALL motors
  
  }
  //motors.setSpeed(80);
}


void loop() 
{
   String inString = "";                        //获取一行输入信息
   while (Serial.available()>0)
   {
     char inChar = Serial.read();
     inString += (char)inChar;
     delay(5);
   }
   
   if (inString!="")                            //判断语句合法性，合法则执行语句
   {
     String cmd=inStringToCommand(inString);
     //Serial.println(cmd);
     if (cmd!="")                               //如果命令合法则执行
     {
         preruncmd(cmd);
     }
     
   }
//debugTestAll();
}


//Print some informations in Serial Monitor

//void printSomeInfo()
//{
//  Serial.print("Motor A is moving = ");
//  Serial.print(motors.isMovingA() ? "YES" : "NO");
//  Serial.print(" at speed = ");
//  Serial.println(motors.getSpeedA());
//  Serial.print("Motor B is moving = ");
//  Serial.print(motors.isMovingB() ? "YES" : "NO");
//  Serial.print(" at speed = ");
//  Serial.println(motors.getSpeedB());
//}





 void debugTestAll()        //test all motors
 {
//   // motors.setSpeed(80);
//   // motors.forward();
//   // printSomeInfo();
//   // delay(2000);
//   // motors.stop();
  
//   // motors.backward();
//   // printSomeInfo();
//   // delay(2000);
//   // motors.stop();

//   // motors.forwardA();
//   // delay(1000);
//   // motors.stop();
//   // motors.backwardA();
//   // delay(1000);
//   // motors.stop();

//   // motors.forwardB();
//   // delay(1000);
//   // motors.stop();
//   // motors.backwardB();
//   // delay(1000);
//   // motors.stop();

//   // motors.forwardC();
//   // delay(1000);
//   // motors.stop();
//   // motors.backwardC();
//   // delay(1000);
//   // motors.stop();
//
// motors.forwardD();
// delay(1000);
// motors.stop();
// motors.backwardD();
// delay(1000);
// motors.stop();

////   //半径约为1米逆时针前进
//   motors.setSpeedA(150);
//   motors.setSpeedC(150);
//   motors.setSpeedB(50);
//   motors.setSpeedD(50);
//   motors.forward();
//   
//   delay(2000);
//   motors.stop();
//   delay(2000);


//motors.setSpeed(130);
//motors.forwardA();
//motors.forwardC();
//delay(200);
//motors.stop();
//motors.backwardB();
//motors.backwardD();
//delay(200);
//motors.stop();

//!F*
motors.setSpeedA(80);
motors.setSpeedB(80);
motors.setSpeedC(80);
motors.setSpeedD(80);
motors.forward();
delay(200);
motors.stop();

}




//
//char* stringToChar(String instr)
//{
//     char* str = NULL;
//     const char* constc = NULL;
//     constc=instr.c_str();
//     str= const_cast<char*>(constc);
//     return str;
//}

                                                  
String inStringToCommand(String str)               //用来判断输入的命令的合法性
{
    String cmd = "";
    if (str[0] == '!'  && (str[str.length()-1] == '*'))
    {
       cmd = str;
       Serial.println("OK");
       return cmd;
    }
    else if (str=="dbg")                         //隐藏指令 dbg
   {
      debugTestAll();
   }
   else
    {
       Serial.println("E0");
       return cmd;
    }
}


int * getdot(String input)                      //获得一个命令里面的逗号所在位置，返回指针
{
   static int r[4];
   int a=0;
   for (int i=0;i<=(input.length()-1);i++)
   {
      if (input[i]==',')
      {
         r[a]=i;
         a++;
      }
   }
   return r;
}

String getnumstring(String fullcmd ,int whichnum)  //把给定的位置的字符串变成值
{
   int *dot=getdot(fullcmd);
   String anum="";
   for (int i=*(dot + whichnum-1);i<=(*(dot + whichnum));i++)
   {
      //if (fullcmd[i]>='0'&&fullcmd[i]<='9')
      
            anum+=fullcmd[i];

      
   }
   return anum;
}

int stringtonum(String anum)
{
   return anum.toInt();
}

void preruncmd(String input)
{
   String cmd,num1,num2,num3,num4;
   int *dot=NULL,i=0;              //这里是用来将指令和参数分开的，默认指令1个，参数最多4个,dot是逗号出现的位置
      if (input[0]=='!')                  //如果是‘!’就分析指令，重置','的计数
      {
      
      switch (input[i+1])
      {
         case('F'):
         {
            if (input[i+2]=='*')          //!F*
            {
               motors.setSpeedA(80);
               motors.setSpeedB(80);
               motors.setSpeedC(80);
               motors.setSpeedD(80);
               motors.forward();
            }
            else if (input[i+2]==',')     //!F,@,@,@*
            {
               runcmd("F",input);
               break;
            }
            else 
            Serial.println("E2");
            break;

         }
         case('B'):
         {
            if (input[i+2]=='*')          //!B*
            {
               motors.setSpeedA(80);
               motors.setSpeedB(80);
               motors.setSpeedC(80);
               motors.setSpeedD(80);
               motors.backward();
            }
            else if (input[i+2]==',')     //!B,@,@,@*
            {
               runcmd("B",input);
               break;
            }
            else 
            Serial.println("E2");
            break;
         }
         case('K'):
         {
            if(input=="!KILL*")
            {
               motors.stop();
            }
            else
            Serial.println("E4");
            break;
         }
         //case('T'):
         //case('L'):
         //case('R'):
         //case('S'):
         default:
         {
            Serial.println("E5");
            break;
         }
         }
      }
//      if (input[i]=='*')
//      {
//         break;                           //读取到'*'终止
//      }
      else
      i++;  
}

void runcmd(String cmd,String fullcmd)    //执行命令的终极版，如果preruncmd()搞不定就交给它把
{
   
   switch (cmd[0])
   {
   case('F'):
   {
      int num2=80,num3=0;
      //int num2=stringtonum(getnumstring(fullcmd,2)),num3=stringtonum(getnumstring(fullcmd,3));
      String num1=getnumstring(fullcmd,1);
      if (getnumstring(fullcmd,3)=="@")
          num3=0;
      else
          num3=stringtonum(getnumstring(fullcmd,3));
      if (getnumstring(fullcmd,2)=="@")
         {
             num2=80;
         }
      else 
         {
             num2=stringtonum(getnumstring(fullcmd,2));
         }
      if (getnumstring(fullcmd,1)=="@")
            {
               motors.setSpeedA(num2);
               motors.setSpeedB(num2);
               motors.setSpeedC(num2);
               motors.setSpeedD(num2);
               motors.forward();
               if (num3!=0)
               {
                  delay(num3);
                  motors.stop();
               }
            }
         else
            {
               for (int i=0;i<(num1.length()-1);i++)
               {
               switch(num1[i])
               {
                  case ('A'):
                  {
                     motors.setSpeedA(num2);
                     motors.forwardA();
                  }
                  case ('B'):
                  {
                     motors.setSpeedB(num2);
                     motors.forwardB();
                  }
                  case ('C'):
                  {
                     motors.setSpeedC(num2);
                     motors.forwardC();
                  }
                  case ('D'):
                  {
                     motors.setSpeedD(num2);
                     motors.forwardD();
                  }
                  default:
                  Serial.println("E3");
               }
               }
               if (num3!=0)
                     {
                        delay(num3);
                        motors.stop();
                     }
            }
      
   }
   case('B'):
   {
      int num2=80,num3=0;
      //int num2=stringtonum(getnumstring(fullcmd,2)),num3=stringtonum(getnumstring(fullcmd,3));
      String num1=getnumstring(fullcmd,1);
      if (getnumstring(fullcmd,3)=="@")
          num3=0;
      else
          num3=stringtonum(getnumstring(fullcmd,3));
      if (getnumstring(fullcmd,2)=="@")
         {
             num2=80;
         }
      else 
         {
             num2=stringtonum(getnumstring(fullcmd,2));
         }
      if (getnumstring(fullcmd,1)=="@")
            {
               motors.setSpeedA(num2);
               motors.setSpeedB(num2);
               motors.setSpeedC(num2);
               motors.setSpeedD(num2);
               motors.backward();
               if (num3!=0)
               {
                  delay(num3);
                  motors.stop();
               }
            }
         else
            {
               for (int i=0;i<(num1.length()-1);i++)
               {
               switch(num1[i])
               {
                  case ('A'):
                  {
                     motors.setSpeedA(num2);
                     motors.backwardA();
                  }
                  case ('B'):
                  {
                     motors.setSpeedB(num2);
                     motors.backwardB();
                  }
                  case ('C'):
                  {
                     motors.setSpeedC(num2);
                     motors.backwardC();
                  }
                  case ('D'):
                  {
                     motors.setSpeedD(num2);
                     motors.backwardD();
                  }
                  default:
                  Serial.println("E3");
               }
               }
               if (num3!=0)
                     {
                        delay(num3);
                        motors.stop();
                     }
            }
      
   }
   
   }

}
