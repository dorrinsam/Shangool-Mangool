#include <stdio.h>
#include <string.h>
#include <math.h>

int t, s[5000];
char Infix[5000], Postfix[5000];
int pop(), push(int sign);
int box(char sign), order(char sign);
int InfixtoPostfix();
int isEmpty();

int main(){

   t = -1;
   int c;
   char a;
     scanf("%s", Infix);
       InfixtoPostfix();
         printf("%s\n", Postfix);
           return 0;
                                  }

   int InfixtoPostfix(){
   int c, a = 0;
   char sign, b;

      for(c = 0; c < strlen(Infix); c++){
         sign = Infix[c];
           if(!box(sign)){

             switch(sign){

              case '(':
                push(sign);
                  break;

              case ')':
                 while((b = pop()) != '('){
                   Postfix[a++] = b;
                                             }
                  break;

              case '+':
              case '-':
              case '*':
              case '/':

                 while(!isEmpty() && order(s[t]) >= order(sign))
                    Postfix[a++] = pop();
                      push(sign);
                       break;

              default:
                Postfix[a++] = sign;
                                      }
                                         }
                                            }
                       while(!isEmpty()){
                          Postfix[a++] = pop();
                                                  }
                            Postfix[a] = '\0';
                                                      }
    int order(char sign){
      switch(sign){

        case '(':
          return 0;
        case '+':
        case '-':
          return 1;

        case '*':
        case '/':
          return 2;

        default:
          return 0;
                                       }
                                          }

    int box(char sign){
      if(sign == '\t' || sign == ' '){
         return 1;
                                            }
      else{
         return 0;
                                                }
                                                   }
    int push(int sign){
      if(t > 5000){
        return 1;
                                                        }
          t = t + 1;
          s[t] = sign;
                                                             }
    int isEmpty(){
      if(t == -1){
        return 1;
                                                                    }
      else{
        return 0;
                                                                           }
                                                                               }
    int pop(){
      if(isEmpty()){
        return 1;
                                                                                       }
          return(s[t--]);
                                                                                          }
