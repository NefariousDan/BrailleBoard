#include <ezButton.h>
#include <Keyboard.h>

//Создаем переменные с пинами
const int button1Pin = 5;
const int button2Pin = 4;
const int button3Pin = 2;
const int button4Pin = 11;
const int button5Pin = 13;
const int button6Pin = 12;
//
//Создаем классы кнопок
ezButton button1(button1Pin);
ezButton button2(button2Pin);
ezButton button3(button3Pin);
ezButton button4(button4Pin);
ezButton button5(button5Pin);
ezButton button6(button6Pin);


//Переменная, для определения текущего языка
bool currentLanguage = false;
bool nummode = false;

//Создаем переменные, определяющие, нажата ли кнопка (1, HIGH), или нет(0, LOW)
int button1State = 0;
int button2State = 0;
int button3State = 0;
int button4State = 0;
int button5State = 0;
int button6State = 0;



//Слишком сложно(долго) обьяснять.  BBCCCCCCCCCCCCCCCCCCCDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC::::::::::,666ИЦФ6
  //Вкратсе, создаем алгоритм для определения
  //нажатой комбинации
  //
  //n - кнопка нажата
  //!n - кнопка не нажата

//Функция для печати на английском языке + цифры

void solenoidWrite(bool flag1, bool flag2, bool flag3, bool flag4, bool flag5, bool flag6){

  if (flag1){
    analogWrite(A0, 255);
  }
  if (flag2){
    analogWrite(A1, 255);
  }

  if (flag3){
    analogWrite(A2, 255);
  }
  if (flag4){
    analogWrite(A3, 255);
  }

  if (flag5){
    analogWrite(A4, 255);
  }
  if (flag6){
    analogWrite(A5, 255);
  }

}

void solenoidStop(){
  analogWrite(A0, 0);
  analogWrite(A1, 0);
  analogWrite(A2, 0);
  analogWrite(A3, 0);
  analogWrite(A4, 0);
  analogWrite(A5, 0);

}


void BrailleBoardEN(){
  switch(button1State){
     case HIGH: switch(button2State){      //1
      case HIGH: switch(button3State){     //1,2
        case HIGH: switch(button4State){    //1,2,3
          case HIGH: switch(button5State){   //1,2,3,4
            case HIGH: switch(button6State){    //1,2,3,4,5
              case HIGH: break;    //1,2,3,4,5,6
              case LOW: Keyboard.press('q'); solenoidWrite(1, 1, 1, 1, 1, 0); delay(100); break;  //1,2,3,4,5,!6
            } break;
            
            case LOW: switch(button6State){   //1,2,3,4,!5
              case HIGH: break;       //1,2,3,4,!5,6
              case LOW: Keyboard.press('p'); solenoidWrite(1, 1, 1, 1, 0, 0); delay(100); break; //1,2,3,4,!5,!6
            } break;
          } break;
        case LOW: switch(button5State){     //1,2,3,!4
            case HIGH: switch(button6State){    //1,2,3,!4,5
              case HIGH: break;     //1,2,3,!4,5,6
              case LOW: Keyboard.press('r'); solenoidWrite(1, 1, 1, 0, 1, 0); delay(100); break;   //1,2,3,!4,5,!6
            } break;
            case LOW: switch(button6State){     //1,2,3,!4,!5
              case HIGH: Keyboard.press('v'); solenoidWrite(1, 1, 1, 0, 0, 1); delay(100); break;   //1,2,3,!4,!5,6
              case LOW: Keyboard.press('l'); solenoidWrite(1, 1, 1, 0, 0, 0); delay(100); break;   //1,2,3,!4,!5,!6
            } break;
          } break;
        } break;
      case LOW: switch(button4State){       //1,2,!3
        case HIGH: switch(button5State) {        //1,2,!3,4
          case HIGH: switch(button6State) {     //1,2,!3,4,5
            case HIGH: break;                   //1,2,!3,4,5,6
            case LOW: if (nummode == false) { Keyboard.press('g'); solenoidWrite(1, 1, 0, 1, 1, 0); delay(100); }
                      else { Keyboard.press('7'); delay(100); }
                      break;                                        //1,2,!3,4,5,!6
          } break;
          case LOW: switch(button6State) {        //1,2,!3,4,!5
            case HIGH: break;                     //1,2,!3,4,!5,6
            case LOW: if (nummode == false) { Keyboard.press('f'); solenoidWrite(1, 1, 0, 1, 0, 0); delay(100);}
                      else { Keyboard.press('6'); delay(100); }
                      break;                                      //1,2,!3,4,!5,!6
          } break;
        } break;
        case LOW: switch(button5State){         //1,2,!3,!4
          case HIGH: switch(button6State){      //1,2,!3,!4,5
            case HIGH: break;         //1,2,!3,!4,5,6
            case LOW: if (nummode == false) { Keyboard.press('h'); solenoidWrite(1, 1, 0, 0, 1, 0); delay(100);}
                      else { Keyboard.press('8'); delay(100);} 
                      break;                                                //1,2,!3,!4,5,!6
          } break;
          case LOW: switch(button6State){             //1,2,!3,!4,!5
            case HIGH: break;                  //1,2,!3,!4,!5,6
            case LOW: if (nummode == false) { Keyboard.press('b'); solenoidWrite(1, 1, 0, 0, 0, 0); delay(100); }
                      else { Keyboard.press('2'); delay(100);}
                      break;                                                                    //1,2,!3,!4,!5,!6
          } break;
        } break;
      } break;
      ;} break;
      
    case LOW: switch(button3State){            //1,!2
      case HIGH: switch(button4State){        //1,!2,3
        case HIGH: switch(button5State){      //1,!2,3,4
          case HIGH: switch(button6State){    //1,!2,3,4,5
          case HIGH: break;
            case LOW: Keyboard.press('n'); solenoidWrite(1, 0, 1, 1, 1, 0); delay(100); break;                  //1,!2,3,4,5,!6
          } break;
          case LOW: switch(button6State){       //1,!2,3,4,!5
            case HIGH: Keyboard.press('x'); solenoidWrite(1, 0, 1, 1, 0, 1); delay(100); break;                   //1,!2,3,4,!5,6
            case LOW: Keyboard.press('m'); solenoidWrite(1, 0, 1, 1, 0, 0); delay(100); break;                   //1,!2,3,4,!5,!6
          } break;
        } break;
        case LOW: switch(button5State){       //1,!2,3,!4,
          case HIGH: switch(button6State){      //1,!2,3,!4,5
            case HIGH: Keyboard.press('z'); solenoidWrite(1, 0, 1, 0, 1, 1); delay(100); break;                //1,!2,3,!4,5,6
            case LOW: Keyboard.press('o'); solenoidWrite(1, 0, 1, 0, 1, 0); delay(100); break;         //1,!2,3,!4,5,!6
          } break;
          case LOW: switch(button6State){       //1,!2,3,!4,!5
            case HIGH: Keyboard.press('u'); solenoidWrite(1, 0, 1, 0, 0, 1); delay(100); break;                   //1,!2,3,!4,!5,6
            case LOW: Keyboard.press('k'); solenoidWrite(1, 0, 1, 0, 0, 0); delay(100); break;                    //1,!2,3,!4,!5,!6
          } break;
        } break;
      } break;
      case LOW: switch(button4State){             //1, !2, !3,
        case HIGH: switch(button5State){          //1,!2,!3,4
          case HIGH: switch(button6State){        //1,!2,!3,4,5
            case HIGH: break;                      //1,!2,!3,4,5,6a
            case LOW:if (nummode == false) { Keyboard.press('d'); solenoidWrite(1, 0, 0, 1, 1, 0); delay(100);}
                      else { Keyboard.press('4'); delay(100);}
                      break;                                                            //1,!2,!3,4,5,!6
          } break;
          case LOW: switch(button6State){         //1, !2, !3, 4, !5
            case HIGH: break;                    //1,!2,!3,4,!5,6
            case LOW: if (nummode == false) { Keyboard.press('c'); solenoidWrite(1, 0, 0, 1, 0, 0); delay(100); }
                      else { Keyboard.press('3'); delay(100);}
                      break;                                                          //1,!2,!3,4,!5,!6
          } break;
        } break;
        case LOW: switch(button5State){         //1,!2,!3,!4
          case HIGH: switch(button6State){        //1, !2,!3,!4,5
            case HIGH: break;                  //1,!2,!3,!4,5, 6
            case LOW: if (nummode == false) { Keyboard.press('e'); solenoidWrite(1, 0, 0, 0, 1, 0); delay(100); }
                      else { Keyboard.press('5'); delay(100); }
                      break;                                        //1,!2,!3,!4,5,!6
          } break;
          case LOW: switch(button6State){           //1,!2,!3,!4,!5
            case HIGH: break;                      //1,!2,!3,!4,!5,6
            case LOW: if (nummode == false) {Keyboard.press('a'); solenoidWrite(1, 0, 0, 0, 0, 0); delay(100); currentLanguage = 0;}               //1,!2,!3,!4,!5,!6
                      else {Keyboard.press('1'); delay(100); currentLanguage = 0;}
                      break;
          } break;
        } break;
      } break;
    } break;
    ;} break;






  case LOW: switch(button2State){      //!1
      case HIGH: switch(button3State){     //!1,2
        case HIGH: switch(button4State){    //!1,2,3
          case HIGH: switch(button5State){   //!1,2,3,4
            case HIGH: switch(button6State){    //!1,2,3,4,5
              case HIGH: break;    //!1,2,3,4,5,6
              case LOW: Keyboard.press('t'); solenoidWrite(0, 1, 1, 1, 1, 0); delay(100); break;  //!1,2,3,4,5,!6
            } break;
            
            case LOW: switch(button6State){   //!1,2,3,4,!5
              case HIGH: break;       //!1,2,3,4,!5,6
              case LOW: Keyboard.press('s'); solenoidWrite(0, 1, 1, 1, 0, 0); delay(100); break; //!1,2,3,4,!5,!6
            } break;
          } break;
        case LOW: switch(button5State){     //!1,2,3,!4
            case HIGH: switch(button6State){    //!1,2,3,!4,5
              case HIGH: break;     //!1,2,3,!4,5,6
              case LOW: Keyboard.press('!'); solenoidWrite(0, 1, 1, 0, 1, 0); delay(100); break;   //!1,2,3,!4,5,!6
            } break;
            case LOW: switch(button6State){     //!1,2,3,!4,!5
              case HIGH: Keyboard.press('?'); solenoidWrite(0, 1, 1, 0, 0, 1); delay(100);  break;   //!1,2,3,!4,!5,6
              case LOW: Keyboard.press(';'); solenoidWrite(0, 1, 1, 0, 0, 0); delay(100); break;   //!1,2,3,!4,!5,!6
            } break;
          } break;
        } break;
      case LOW: switch(button4State){       //!1,2,!3
        case HIGH: switch(button5State) {        //!1,2,!3,4
          case HIGH: switch(button6State) {     //!1,2,!3,4,5
            case HIGH: Keyboard.press('w'); solenoidWrite(0, 1, 0, 1, 1, 1); delay(100); break;                   //!1,2,!3,4,5,6
            case LOW: if (nummode == false) { Keyboard.press('j'); solenoidWrite(0, 1, 0, 1, 1, 0); delay(100); break; }
                      else { Keyboard.press('0'); delay(100); break; }    //!1,2,!3,4,5,!6
          } break;
          case LOW: switch(button6State) {        //!1,2,!3,4,!5
            case HIGH: break;                     //!1,2,!3,4,!5,6
            case LOW: if (nummode == false) { Keyboard.press('i'); solenoidWrite(0, 1, 0, 1, 0, 0); delay(100); }
                      else { Keyboard.press('9'); delay(100); }     //!1,2,!3,4,!5,!6
          } break;
        } break;
        case LOW: switch(button5State){         //!1,2,!3,!4
          case HIGH: switch(button6State){      //!1,2,!3,!4,5
            case HIGH: Keyboard.press('.'); solenoidWrite(0, 1, 0, 0, 1, 1); delay(100); break;         //!1,2,!3,!4,5,6
            case LOW: Keyboard.press(':'); solenoidWrite(0, 1, 0, 0, 1, 0); delay(100); break;      //!1,2,!3,!4,5,!6
          } break;
          case LOW: switch(button6State){             //!1,2,!3,!4,!5
            case HIGH: break;                 //!1,2,!3,!4,!5,6
            case LOW: Keyboard.press(','); solenoidWrite(0, 1, 0, 0, 0, 0); delay(100); break;         //!1,2,!3,!4,!5,!6
          } break;
        } break;
      } break;
      ;} break;
      
    case LOW: switch(button3State){            //!1,!2
      case HIGH: switch(button4State){        //!1,!2,3
        case HIGH: switch(button5State){      //!1,!2,3,4
          case HIGH: switch(button6State){    //!1,!2,3,4,5
            case HIGH: nummode = !nummode; delay(100); break;                //!1,!2,3,4,5,6
            case LOW: break;                 //!1,!2,3,4,5,!6
          } break;
          case LOW: switch(button6State){       //!1,!2,3,4,!5
            case HIGH: break;                   //!1,!2,3,4,!5,6
            case LOW: break;                    //!1,!2,3,4,!5,!6
          } break;
        } break;
        case LOW: switch(button5State){       //!1,!2,3,!4,
          case HIGH: switch(button6State){      //!1,!2,3,!4,5
            case HIGH: break;                //!1,!2,3,!4,5,6
            case LOW: break;         //!1,!2,3,!4,5,!6
          } break;
          case LOW: switch(button6State){       //!1,!2,3,!4,!5
            case HIGH: Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press(KEY_LEFT_ALT); currentLanguage = !currentLanguage; delay(100); break;                   //!1,!2,3,!4,!5,6
            case LOW: solenoidWrite(0, 0, 1, 0, 0, 0); break;                   //!1,!2,3,!4,!5,!6      //P.S. При смене языка, мы меняем значение текущего языка на обратное ему значение (true/false) 
          } break;
        } break;
      } break;
      case LOW: switch(button4State){             //!1, !2, !3,
        case HIGH: switch(button5State){          //!1,!2,!3,4
          case HIGH: switch(button6State){        //!1,!2,!3,4,5
            case HIGH: break;                      //!1,!2,!3,4,5,6
            case LOW: break;                      //!1,!2,!3,4,5,!6
          } break;
          case LOW: switch(button6State){         //!1, !2, !3, 4, !5
            case HIGH: Keyboard.press(KEY_CAPS_LOCK); break;                     //!1,!2,!3,4,!5,6
            case LOW: solenoidWrite(0, 0, 0, 1, 0, 0); Keyboard.press(KEY_BACKSPACE); break;                     //!1,!2,!3,4,!5,!6
          } break;
        } break;
        case LOW: switch(button5State){         //!1,!2,!3,!4
          case HIGH: switch(button6State){        //!1, !2,!3,!4,5
            case HIGH: break;                  //!1,!2,!3,!4,5, 6
            case LOW: solenoidWrite(0, 0, 0, 0, 1, 0); break;                 //!1,!2,!3,!4,5,!6
          } break;
          case LOW: switch(button6State){           //!1,!2,!3,!4,!5
            case HIGH: solenoidWrite(0, 0, 0, 0, 0, 1); Keyboard.press(' '); break;                      //!1,!2,!3,!4,!5,6
            case LOW: solenoidStop();  Keyboard.releaseAll(); break;                      //!1,!2,!3,!4,!5,!6      /P.S. если ни одна из кнопок не нажата, то мы отпускаем все кнопки клавиатуры
          } break;
        } break;
      } break;
    } break;
    ;} break;
  ;}

 
}




//Функция для печати на русском + казахском языке
void BrailleBoardKZ(){
  switch(button1State){
     case HIGH: switch(button2State){      //1
      case HIGH: switch(button3State){     //1,2
        case HIGH: switch(button4State){    //1,2,3
          case HIGH: switch(button5State){   //1,2,3,4
            case HIGH: switch(button6State){    //1,2,3,4,5
              case HIGH: break;    //1,2,3,4,5,6
              case LOW: Keyboard.press('x'); delay(100); break;  //1,2,3,4,5,!6
            } break;
            
            case LOW: switch(button6State){   //1,2,3,4,!5
              case HIGH: Keyboard.press('q'); delay(100); break;       //1,2,3,4,!5,6
              case LOW: Keyboard.press('g'); delay(100); break; //1,2,3,4,!5,!6
            } break;
          } break;
        case LOW: switch(button5State){     //1,2,3,!4
            case HIGH: switch(button6State){    //1,2,3,!4,5
              case HIGH: Keyboard.press(']'); delay(100); break;     //1,2,3,!4,5,6
              case LOW: Keyboard.press('h'); delay(100); break;   //1,2,3,!4,5,!6
            } break;
            case LOW: switch(button6State){     //1,2,3,!4,!5
              case HIGH: Keyboard.press('='); delay(100); break;   //1,2,3,!4,!5,6
              case LOW: Keyboard.press('k'); delay(100); break;   //1,2,3,!4,!5,!6
            } break;
          } break;
        } break;
      case LOW: switch(button4State){       //1,2,!3
        case HIGH: switch(button5State) {        //1,2,!3,4
          case HIGH: switch(button6State) {     //1,2,!3,4,5
            case HIGH: Keyboard.press('5'); delay(100); break;                   //1,2,!3,4,5,6
            case LOW: Keyboard.press('u'); delay(100); break;    //1,2,!3,4,5,!6
          } break;
          case LOW: switch(button6State) {        //1,2,!3,4,!5
            case HIGH: Keyboard.press('z'); delay(100); break;                     //1,2,!3,4,!5,6
            case LOW: Keyboard.press('a'); delay(100); break;     //1,2,!3,4,!5,!6
          } break;
        } break;
        case LOW: switch(button5State){         //1,2,!3,!4
          case HIGH: switch(button6State){      //1,2,!3,!4,5
            case HIGH: Keyboard.press('.'); delay(100); break;         //1,2,!3,!4,5,6
            case LOW: Keyboard.press('['); delay(100); break;      //1,2,!3,!4,5,!6
          } break;
          case LOW: switch(button6State){             //1,2,!3,!4,!5
            case HIGH: Keyboard.press('-'); delay(100); break;                 //1,2,!3,!4,!5,6
            case LOW: Keyboard.press(','); delay(100); break;         //1,2,!3,!4,!5,!6
          } break;
        } break;
      } break;
      ;} break;
      
    case LOW: switch(button3State){            //1,!2
      case HIGH: switch(button4State){        //1,!2,3
        case HIGH: switch(button5State){      //1,!2,3,4
          case HIGH: switch(button6State){    //1,!2,3,4,5
            case HIGH: Keyboard.press('3'); delay(100); break;                //1,!2,3,4,5,6
            case LOW: Keyboard.press('y'); delay(100); break;                  //1,!2,3,4,5,!6
          } break;
          case LOW: switch(button6State){       //1,!2,3,4,!5
            case HIGH: Keyboard.press('o'); delay(100); break;                   //1,!2,3,4,!5,6
            case LOW: Keyboard.press('v'); delay(100); break;                   //1,!2,3,4,!5,!6
          } break;
        } break;
        case LOW: switch(button5State){       //1,!2,3,!4,
          case HIGH: switch(button6State){      //1,!2,3,!4,5
            case HIGH: Keyboard.press('p'); delay(100); break;                //1,!2,3,!4,5,6
            case LOW: Keyboard.press('j'); delay(100); break;         //1,!2,3,!4,5,!6
          } break;
          case LOW: switch(button6State){       //1,!2,3,!4,!5
            case HIGH: Keyboard.press('e'); delay(100); break;                   //1,!2,3,!4,!5,6
            case LOW: Keyboard.press('r'); delay(100); break;                    //1,!2,3,!4,!5,!6
          } break;
        } break;
      } break;
      case LOW: switch(button4State){             //1, !2, !3,
        case HIGH: switch(button5State){          //1,!2,!3,4
          case HIGH: switch(button6State){        //1,!2,!3,4,5
            case HIGH: Keyboard.press('0'); delay(100); break;                      //1,!2,!3,4,5,6
            case LOW: Keyboard.press('l'); delay(100); break;                      //1,!2,!3,4,5,!6
          } break;
          case LOW: switch(button6State){         //1, !2, !3, 4, !5
            case HIGH: Keyboard.press('4'); delay(100); break;                     //1,!2,!3,4,!5,6
            case LOW: Keyboard.press('w'); delay(100); break;                     //1,!2,!3,4,!5,!6
          } break;
        } break;
        case LOW: switch(button5State){         //1,!2,!3,!4
          case HIGH: switch(button6State){        //1, !2,!3,!4,5
            case HIGH: Keyboard.press('i'); delay(100); break;                  //1,!2,!3,!4,5,6
            case LOW: Keyboard.press('t'); delay(100); break;                 //1,!2,!3,!4,5,!6
          } break;
          case LOW: switch(button6State){           //1,!2,!3,!4,!5
            case HIGH:  break;                      //1,!2,!3,!4,!5,6
            case LOW: Keyboard.press('f'); delay(100); break;                      //1,!2,!3,!4,!5,!6
          } break;
        } break;
      } break;
    } break;
    ;} break;





  case LOW: switch(button2State){      //!1
      case HIGH: switch(button3State){     //!1,2
        case HIGH: switch(button4State){    //!1,2,3
          case HIGH: switch(button5State){   //!1,2,3,4
            case HIGH: switch(button6State){    //!1,2,3,4,5
              case HIGH: Keyboard.press('m'); delay(100); break;    //!1,2,3,4,5,6
              case LOW: Keyboard.press('n'); delay(100); break;  //!1,2,3,4,5,!6
            } break;
            
            case LOW: switch(button6State){   //!1,2,3,4,!5
              case HIGH: Keyboard.press('s'); delay(100); break;       //!1,2,3,4,!5,6
              case LOW: Keyboard.press('c'); delay(100); break; //!1,2,3,4,!5,!6
            } break;
          } break;
        case LOW: switch(button5State){     //!1,2,3,!4
            case HIGH: switch(button6State){    //!1,2,3,!4,5
              case HIGH:     //!1,2,3,!4,5,6
              case LOW: Keyboard.press('!'); delay(100); break;   //!1,2,3,!4,5,!6
            } break;
            case LOW: switch(button6State){     //!1,2,3,!4,!5
              case HIGH: break;   //!1,2,3,!4,!5,6
              case LOW: break;   //!1,2,3,!4,!5,!6
            } break;
          } break;
        } break;
      case LOW: switch(button4State){       //!1,2,!3
        case HIGH: switch(button5State) {        //!1,2,!3,4
          case HIGH: switch(button6State) {     //!1,2,!3,4,5
            case HIGH: Keyboard.press('d'); delay(100); break;                   //!1,2,!3,4,5,6
            case LOW: Keyboard.press(';'); delay(100); break;    //!1,2,!3,4,5,!6
          } break;
          case LOW: switch(button6State) {        //!1,2,!3,4,!5
            case HIGH: Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press('"'); delay(100); break;                     //!1,2,!3,4,!5,6
            case LOW: Keyboard.press('b'); delay(100); break;     //!1,2,!3,4,!5,!6
          } break; 
        } break;
        case LOW: switch(button5State){         //!1,2,!3,!4
          case HIGH: switch(button6State){      //!1,2,!3,!4,5
            case HIGH: Keyboard.press('7'); delay(100); break;         //!1,2,!3,!4,5,6
            case LOW: break;         //!1,2,!3,!4,5,!6
          } break;
          case LOW: switch(button6State){             //!1,2,!3,!4,!5
            case HIGH:  Keyboard.press('?'); delay(100); break;                 //!1,2,!3,!4,!5,6
            case LOW:  Keyboard.press('6'); delay(100); break;         //!1,2,!3,!4,!5,!6
          } break;
        } break;
      } break;
      ;} break;
      
    case LOW: switch(button3State){            //!1,!2
      case HIGH: switch(button4State){        //!1,!2,3
        case HIGH: switch(button5State){      //!1,!2,3,4
          case HIGH: switch(button6State){    //!1,!2,3,4,5
            case HIGH: break;                //!1,!2,3,4,5,6
            case LOW: Keyboard.press('2'); delay(100); break;                  //!1,!2,3,4,5,!6
          } break;
          case LOW: switch(button6State){       //!1,!2,3,4,!5
            case HIGH: Keyboard.press('9'); delay(100); break;                   //!1,!2,3,4,!5,6
            case LOW:  Keyboard.press('8'); delay(100); break;                   //!1,!2,3,4,!5,!6
          } break;
        } break;
        case LOW: switch(button5State){       //!1,!2,3,!4,
          case HIGH: switch(button6State){      //!1,!2,3,!4,5
            case HIGH: break;                //!1,!2,3,!4,5,6       
            case LOW: break;         //!1,!2,3,!4,5,!6
          } break;
          case LOW: switch(button6State){       //!1,!2,3,!4,!5
            case HIGH: Keyboard.press(KEY_LEFT_SHIFT); Keyboard.press(KEY_LEFT_ALT); currentLanguage = !currentLanguage; delay(100); break;                   //!1,!2,3,!4,!5,6
            case LOW: break;                     //!1,!2,3,!4,!5,!6      //P.S. При смене языка, мы меняем значение текущего языка на обратное ему значение (true/false) 
          } break;
        } break;
      } break;
      case LOW: switch(button4State){             //!1, !2, !3,
        case HIGH: switch(button5State){          //!1,!2,!3,4
          case HIGH: switch(button6State){        //!1,!2,!3,4,5
            case HIGH: break;                      //!1,!2,!3,4,5,6
            case LOW: break;                      //!1,!2,!3,4,5,!6
          } break;
          case LOW: switch(button6State){         //!1, !2, !3, 4, !5
            case HIGH: Keyboard.press(KEY_CAPS_LOCK); break;                           //!1,!2,!3,4,!5,6
            case LOW: Keyboard.press(KEY_BACKSPACE); break;                     //!1,!2,!3,4,!5,!6
          } break;
        } break;
        case LOW: switch(button5State){         //!1,!2,!3,!4
          case HIGH: switch(button6State){        //!1, !2,!3,!4,5
            case HIGH: break;                  //!1,!2,!3,!4,5, 6
            case LOW: break;                 //!1,!2,!3,!4,5,!6
          } break;
          case LOW: switch(button6State){           //!1,!2,!3,!4,!5
            case HIGH: Keyboard.press(' '); break;                      //!1,!2,!3,!4,!5,6
            case LOW: Keyboard.releaseAll(); break;                      //!1,!2,!3,!4,!5,!6    //P.S. если ни одна из кнопок не нажата, то мы отпускаем все кнопки клавиатуры
          } break;
        } break;
      } break;
    } break;
    ;} break;
  ;}
}



void setup() {

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

    //pin-им пины ._. 
    pinMode(button1Pin, INPUT);
    pinMode(button2Pin, INPUT);
    pinMode(button3Pin, INPUT);
    pinMode(button4Pin, INPUT);
    pinMode(button5Pin, INPUT);
    pinMode(button6Pin, INPUT);

    
}



void loop() {

  //Функция loop() используется для постоянного обновления состояния кнопки. Функция loop() должна быть вызвана, перед тем как вызвать функцию getState()
  button1.loop(); 
  button2.loop();
  button3.loop();
  button4.loop();
  button5.loop();
  button6.loop();
  
  //Считываем значение кпопок(LOW или HIGH)
  delay(17);
  button1State = button1.getState();
  delay(17);
  button2State = button2.getState();
  delay(17);
  button3State = button3.getState();
  delay(17);
  button4State = button4.getState();
  delay(17);
  button5State = button5.getState();
  delay(17);
  button6State = button6.getState();
  delay(17);

  //Если текущий язык русский/казахский:     

      if(currentLanguage == 0){
        BrailleBoardEN();
      }
      else{

        BrailleBoardKZ();
        
      }

    
    
    
;}