#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "RTClib.h"
LiquidCrystal_I2C lcd(0x27, 20, 4);
RTC_DS3231 rtc;
//relayDC
int relayDC = 8;
//define
#define button1  1
#define button2  2
#define button3  3
#define button4  4
#define buttonNone 0
//button
const int buttonPin1 = 4;
const int buttonPin2 = 5;
const int buttonPin3 = 6;
const int buttonPin4 = 7;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int prevButtonState1;
int prevButtonState2;
int prevButtonState3;
int prevButtonState4;
//menu
int buttonKey = 0;
int currentMenu = 1;
int numberClick = 0;
int isSelected = 0;
int applySetTime = 0;
int isHM = 0;
int isTimer = 0;
int isSetTime = 0;
//value status
int weightPerDay = 0;
int timePerDay = 0;
int timerSelected = 0;
//loadcell weight
int loadCellWeight = 0;
//weight in grams
int weightInGrams = 0;
//feeding
int isFeeding1 = 0;
int isFeeding2 = 0;
int isFeeding3 = 0;
int feedingStatus1 = 0;
int feedingStatus2 = 0;
int feedingStatus3 = 0;
//time value
int hours1 = 0;
int minutes1 = 0;
int seconds1 = 0;
int hours2 = 0;
int minutes2 = 0;
int seconds2 = 0;
int hours3 = 0;
int minutes3 = 0;
int seconds3 = 0;
//time now
//int nowDay = 0;
//int nowMonth = 0;
//int nowYear = 0;
int nowHour = 0;
int nowMinute = 0;
int nowSecond = 0;
//time set
int setDay = 0;
int setMonth = 0;
int setYear = 0;
int setHour = 0;
int setMinute = 0;
int setSecond = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
//    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  
  //delay
  pinMode(relayDC, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonKey = read_LCD_Button();
  switch (buttonKey) {
    case button1: {
        Serial.println("Button 1");
        if (currentMenu == 1) {
          Serial.println("Button 1 Menu 1");
          mainMenu();
          currentMenu = 2;
        } else if (currentMenu == 2) {
          Serial.println("Button 1 Menu 2");
          lcd.clear();
          statusMenu();
          currentMenu = 1;
        } else if (currentMenu == 3) {
          Serial.println("Button 1 Menu 3");
          if (numberClick == 0) {
            isHM = 1;
            numberClick += 1;
            setDayMonthYear(1);
          } else if (numberClick == 1) {
            isHM = 2;
            numberClick += 1;
            setDayMonthYear(2);
          } else if (numberClick == 2) {
            isHM = 3;
            numberClick += 1;
            setDayMonthYear(3);
          } else if (numberClick == 3) {
            isHM = 4;
            numberClick += 1;
            setDayMonthYear(4);
          } else if (numberClick == 4) {
            isHM = 5;
            numberClick += 1;
            setDayMonthYear(5);
          } else if (numberClick == 5) {
            isHM = 6;
            numberClick += 1;
            setDayMonthYear(6);
          } else {
            numberClick = 0;
            setDayMonthYear(7);
          }
        } else if (currentMenu == 4) {
          Serial.println("Button 1 Menu 4");
          lcd.clear();
          mainMenu();
          currentMenu = 2;
          numberClick = 0;
        } else if (currentMenu == 5) {
          Serial.println("Button 1 Menu 5");
          if (isSelected == 1) {
            if (numberClick == 0) {
              setHourMinute(1, 1);
              numberClick += 1;
              isHM = 1;
              isTimer = 1;
            } else if (numberClick == 1) {
              setHourMinute(1, 2);
              numberClick += 1;
              isHM = 2;
              isTimer = 1;
            } else {
              numberClick = 0;
              isHM = 0;
              lcd.setCursor(18, 1);
              lcd.print(" ");
            }
          } else if (isSelected == 2) {
            if (numberClick == 0) {
              setHourMinute(1, 1);
              numberClick += 1;
              isHM = 1;
              isTimer = 1;
            } else if (numberClick == 1) {
              setHourMinute(1, 2);
              numberClick += 1;
              isHM = 2;
              isTimer = 1;
            } else if (numberClick == 2) {
              setHourMinute(2, 1);
              numberClick += 1;
              isHM = 1;
              isTimer = 2;
            } else if (numberClick == 3) {
              setHourMinute(2, 2);
              numberClick += 1;
              isHM = 2;
              isTimer = 2;
            } else {
              numberClick = 0;
              isHM = 0;
              lcd.setCursor(18, 2);
              lcd.print(" ");
            }
          } else if (isSelected == 3) {
            if (numberClick == 0) {
              setHourMinute(1, 1);
              numberClick += 1;
              isHM = 1;
              isTimer = 1;
            } else if (numberClick == 1) {
              setHourMinute(1, 2);
              numberClick += 1;
              isHM = 2;
              isTimer = 1;
            } else if (numberClick == 2) {
              setHourMinute(2, 1);
              numberClick += 1;
              isHM = 1;
              isTimer = 2;
            } else if (numberClick == 3) {
              setHourMinute(2, 2);
              numberClick += 1;
              isHM = 2;
              isTimer = 2;
            } else if (numberClick == 4) {
              setHourMinute(3, 1);
              numberClick += 1;
              isHM = 1;
              isTimer = 3;
            } else if (numberClick == 5) {
              setHourMinute(3, 2);
              numberClick += 1;
              isHM = 2;
              isTimer = 3;
            } else {
              numberClick = 0;
              isHM = 0;
              lcd.setCursor(18, 3);
              lcd.print(" ");
            }
          }
        } else if (currentMenu == 6) {
          Serial.println("Button 1 Menu 6");
          lcd.clear();
          mainMenu();
          currentMenu = 2;
          numberClick = 0;
        }
        break;
      }
    case button2: {
        Serial.println("Button 2");
        if (currentMenu == 1) {
          Serial.println("Button 2 Menu 1");
          Serial.println("Dummy Status To Work");
          DateTime now = rtc.now();
          hours1 = now.hour();
//          minutes1 = now.minute();
          isSetTime = 1;
          timePerDay = 1;
          weightPerDay = 3;
        } else if (currentMenu == 2) {
          Serial.println("Button 2 Menu 2");
          if (numberClick == 0) {
            numberClick += 1;
            selectItem(19, 1);
            unSelectItem(19, 3);
            isSelected = numberClick;
          } else if (numberClick == 1) {
            numberClick += 1;
            selectItem(19, 2);
            unSelectItem(19, 1);
            isSelected = numberClick;
          } else if (numberClick == 2) {
            numberClick += 1;
            selectItem(19, 3);
            unSelectItem(19, 2);
            isSelected = numberClick;
          } else {
            numberClick = 0;
          }
        } else if (currentMenu == 3) {
          Serial.println("Button 2 Menu 3");
          //SetDate+1
//          menuSetDate()
          //setTime [setDay, setMonth, setYear, setHour, setMinute, setSecond]
          if(isHM == 1) {
            setYear += 1;
          } else if(isHM == 2) {
            if(setMonth >= 12) {
              setMonth = 1;
              menuSetDate();
            } else {
              setMonth += 1;
              menuSetDate();
            }
          } else if(isHM == 3) {
            if(setDay >= 30) {
              setDay = 1;
              menuSetDate();
            } else {
              setDay += 1;
              menuSetDate();
            }
          } else if(isHM == 4) {
            if(setHour >= 59) {
              setHour = 0;
              menuSetDate();
            } else {
              setHour += 1;
              menuSetDate();
            }
          } else if(isHM == 5) {
            if(setMinute >= 59) {
              setMinute = 0;
              menuSetDate();
            } else {
              setMinute += 1;
              menuSetDate();
            }
          } else if(isHM == 6) {
            if(setSecond >= 59) {
              setSecond = 0;
              menuSetDate();
            } else {
              setSecond += 1;
              menuSetDate();
            }
          }
        } else if (currentMenu == 4) {
          Serial.println("Button 2 Menu 4");
          if (numberClick == 0) {
            numberClick += 1;
            selectItem(19, 1);
            unSelectItem(19, 3);
            isSelected = numberClick;
            timePerDay = 1;
          } else if (numberClick == 1) {
            numberClick += 1;
            selectItem(19, 2);
            unSelectItem(19, 1);
            isSelected = numberClick;
            timePerDay = 2;
          } else if (numberClick == 2) {
            numberClick += 1;
            selectItem(19, 3);
            unSelectItem(19, 2);
            isSelected = numberClick;
            timePerDay = 3;
          } else {
            numberClick = 0;
          }
        } else if (currentMenu == 5) {
          Serial.println("Button 2 Menu 5");
          if (isHM != 0) {
            if (isTimer == 1) {
              if (isHM == 1) {
                menuSetTime1();
                if (hours1 >= 23) {
                  hours1 = 0;
                  menuSetTime1();
                } else {
                  hours1 += 1;
                  menuSetTime1();
                }
              } else if (isHM == 2) {
                menuSetTime1();
                if (minutes1 >= 59) {
                  minutes1 = 0;
                  menuSetTime1();
                } else {
                  minutes1 += 1;
                  menuSetTime1();
                }
              }
            } else if (isTimer == 2) {
              if (isHM == 1) {
                menuSetTime2();
                if (hours2 >= 23) {
                  hours2 = 0;
                  menuSetTime1();
                } else {
                  hours2 += 1;
                  menuSetTime2();
                }
              } else if (isHM == 2) {
                menuSetTime2();
                if (minutes2 >= 59) {
                  minutes2 = 0;
                  menuSetTime2();
                } else {
                  minutes2 += 1;
                  menuSetTime2();
                }
              }
            } else if (isTimer == 3) {
              if (isHM == 1) {
                menuSetTime3();
                if (hours3 >= 23) {
                  hours3 = 0;
                  menuSetTime3();
                } else {
                  hours3 += 1;
                  menuSetTime3();
                }
              } else if (isHM == 2) {
                menuSetTime3();
                if (minutes3 >= 59) {
                  minutes3 = 0;
                  menuSetTime3();
                } else {
                  minutes3 += 1;
                  menuSetTime3();
                }
              }
            }
          }
        } else if (currentMenu == 6) {
          Serial.println("Button 2 Menu 6");
          if (numberClick == 0) {
            numberClick += 1;
            selectItem(8, 1);
            unSelectItem(19, 3);
            weightPerDay = 1;
          } else if (numberClick == 1) {
            numberClick += 1;
            selectItem(8, 2);
            unSelectItem(8, 1);
            weightPerDay = 2;
          } else if (numberClick == 2) {
            numberClick += 1;
            selectItem(8, 3);
            unSelectItem(8, 2);
            weightPerDay = 3;
          } else if (numberClick == 3) {
            numberClick += 1;
            selectItem(19, 1);
            unSelectItem(8, 3);
            weightPerDay = 4;
          } else if (numberClick == 4) {
            numberClick += 1;
            selectItem(19, 2);
            unSelectItem(19, 1);
            weightPerDay = 5;
          } else if (numberClick == 5) {
            numberClick += 1;
            selectItem(19, 3);
            unSelectItem(19, 2);
            weightPerDay = 6;
          } else {
            numberClick = 0;
          }
        }
        break;
      }
    case button3: {
        Serial.println("Button 3");
        if (currentMenu == 1) {
          Serial.println("Button 3 Menu 1");
        } else if (currentMenu == 2) {
          Serial.println("Button 3 Menu 2");
          if (isSelected == 1) {
            lcd.clear();
            menuSetDate();
            currentMenu = 3;
            isSelected = 0;
            numberClick = 0;
            DateTime now = rtc.now();
            setDay = now.day();
            setMonth = now.month();
            setYear = now.year();
            setHour = now.hour();
            setMinute = now.minute();
            setSecond = now.second();
          } else if (isSelected == 2) {
            menuTimePerDay();
            currentMenu = 4;
            isSelected = 0;
            numberClick = 0;
          } else if (isSelected == 3) {
            menuWeightPerDay();
            currentMenu = 6;
            isSelected = 0;
            numberClick = 0;
          }
        } else if (currentMenu == 3) {
          Serial.println("Button 3 Menu 3");
          if (applySetTime == 1) {
            mainMenu();
            currentMenu = 2;
            isHM = 0;
            applySetTime = 0;
            //setTime [setDay, setMonth, setYear, setHour, setMinute, setSecond]
            //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
//            Serial.println("SetDay = ");
//            Serial.print(setDay);
            Serial.println("rtc.adjust = ");
            Serial.print(setYear);
            Serial.print("/");
            Serial.print(setMonth);
            Serial.print("/");
            Serial.print(setDay);
            Serial.print("/ ");
            Serial.print(setHour);
            Serial.print(":");
            Serial.print(setMinute);
            Serial.print(":");
            Serial.print(setSecond);
            rtc.adjust(DateTime(setYear, setMonth, setDay, setHour, setMinute, setSecond));
          } else {
//            Serial.println("ApplySetTime = 0");
            //SetDate-1
            if(isHM == 1) {
              setYear -= 1;
            } else if(isHM == 2) {
              if(setMonth <=  0) {
                setMonth = 12;
                menuSetDate();
              } else {
                setMonth -= 1;
                menuSetDate();
              }
            } else if(isHM == 3) {
              if(setDay <= 0) {
                setDay = 31;
                menuSetDate();
              } else {
                setDay -= 1;
                menuSetDate();
              }
            } else if(isHM == 4) {
              if(setHour <= 0) {
                setHour = 23;
                menuSetDate();
              } else {
                setHour -= 1;
                menuSetDate();
              }
            } else if(isHM == 5) {
              if(setMinute <= 0 ) {
                setHour = 59;
                menuSetDate();
              } else {
                setMinute -= 1;
                menuSetDate();
              }
            } else if(isHM == 6) {
              if(setSecond <= 0) {
                setSecond = 59;
                menuSetDate();
              } else {
                setSecond -= 1;
                menuSetDate();
              }
            }
          }
        } else if (currentMenu == 4) {
          Serial.println("Button 3 Menu 4");
          if (isSelected == 1) {
//            Serial.print("=========== 1 Time");
            currentMenu = 5;
            menuSetTimeX(1);
            numberClick = 0;
          } else if (isSelected == 2) {
//            Serial.print("=========== 2 Time");
            currentMenu = 5;
            menuSetTimeX(2);
            numberClick = 0;
          } else if (isSelected == 3) {
//            Serial.print("=========== 3 Time");
            currentMenu = 5;
            menuSetTimeX(3);
            numberClick = 0;
          }
        } else if (currentMenu == 5) {
          Serial.println("Button 3 Menu 5");
          if (applySetTime == 1) {
            mainMenu();
            currentMenu = 2;
            isHM = 0;
            applySetTime = 0;
            isSetTime = 1;
          } else {
          }
          if (isHM != 0) {
            if (isTimer == 1) {
              if (isHM == 1) {
                menuSetTime1();
                if (hours1 <= 0) {
                  hours1 = 23;
                  menuSetTime1();
                } else {
                  hours1 -= 1;
                  menuSetTime1();
                }
              } else if (isHM == 2) {
                menuSetTime1();
                if (minutes1 <= 0) {
                  minutes1 = 59;
                  menuSetTime1();
                } else {
                  minutes1 -= 1;
                  menuSetTime1();
                }
              }
            } else if (isTimer == 2) {
              if (isHM == 1) {
                menuSetTime2();
                if (hours2 <= 0) {
                  hours2 = 23;
                  menuSetTime1();
                } else {
                  hours2 -= 1;
                  menuSetTime2();
                }
              } else if (isHM == 2) {
                menuSetTime2();
                if (minutes2 <= 0) {
                  minutes2 = 59;
                  menuSetTime2();
                } else {
                  minutes2 -= 1;
                  menuSetTime2();
                }
              }
            } else if (isTimer == 3) {
              if (isHM == 1) {
                menuSetTime3();
                if (hours3 <= 0) {
                  hours3 = 23;
                  menuSetTime3();
                } else {
                  hours3 -= 1;
                  menuSetTime3();
                }
              } else if (isHM == 2) {
                menuSetTime3();
                if (minutes3 <= 0) {
                  minutes3 = 59;
                  menuSetTime3();
                } else {
                  minutes3 -= 1;
                  menuSetTime3();
                }
              }
            }
          }
        } else if (currentMenu == 6) {
          Serial.println("Button 3 Menu 6");
          Serial.println(weightPerDay);
          if (weightPerDay != 0) {
            numberClick = 0;
            mainMenu();
            currentMenu = 2;
          }
        }
        break;
      }
    case button4: {
        Serial.println("Button 4");
        if (currentMenu == 1) {
          Serial.println("Button 4 Menu 1");
        } else if (currentMenu == 2) {
          Serial.println("Button 4 Menu 2");
          lcd.clear();
          statusMenu();
          currentMenu = 1;
        } else if (currentMenu == 3) {
          Serial.println("Button 4 Menu 3");
          applyTime();
          if (applySetTime == 0) {
            applySetTime = 1;
          } else {
            Serial.println("BACK BACK");
            mainMenu();
            currentMenu = 2;
            numberClick = 0;
            applySetTime = 0;
          }
        } else if (currentMenu == 4) {
          Serial.println("Button 4 Menu 4");
          lcd.clear();
          mainMenu();
          currentMenu = 2;
          numberClick = 0;
        } else if (currentMenu == 5) {
          Serial.println("Button 4 Menu 5");
          applyTime();
          if (applySetTime == 0) {
            applySetTime = 1;
          } else {
            Serial.print("BACK BACK");
            menuTimePerDay();
            currentMenu = 4;
            numberClick = 0;
            applySetTime = 0;
            timerSelected = 0;
            isSetTime = 0;
            timePerDay = 0;
            hours1 = 0;
            minutes1 = 0;
            hours2 = 0;
            minutes2 = 0;
            hours3 = 0;
            minutes3 = 0;
            isHM = 0;
          }
        } else if (currentMenu == 6) {
          Serial.println("Button 4 Menu 6");
          weightPerDay = 0;
          lcd.clear();
          mainMenu();
          currentMenu = 2;
          numberClick = 0;
        }
        break;
      }
    case buttonNone: {
        //      Serial.println("ButtonNone");
        check24hr();
        if (currentMenu ==  1) {
          statusMenu();
        }
        if (isSetTime == 1  && timePerDay != 0 && weightPerDay != 0 && currentMenu == 1) {
          checkTimeToFeed();
        }
        break;
      }
  }
}
//boolean isLeapYear(int year) {
// if(setYear % 400 == 0) {
//   return(true);
// } else if(setYear % 100 == 0) {
//   return(false);
// } else if(setYear % 4 == 0) {
//   return(true);
// } else {
//   return(false);
// }
//}
//check day in month 30/31/28/29
//void checkDayInMonth() {
// if(setMonth == 1 && setMonth == 3 && setMonth == 5 && setMonth == 7 && setMonth == 8 && setMonth == 10 && setMonth == 12) {
//   //31day
//} else if(setMonth == 2 && isLeapYear(setYear)) {
//   //29day
//}
//}
//check time 24hr to reset isFeeding1 isFeeding2 isFeeding3 to 0
void check24hr() {
  DateTime now = rtc.now();
  if (now.hour() == 00 && now.minute() == 00 && now.second() == 00) {
    Serial.println("00:00:00");
    isFeeding1 = 0;
    feedingStatus1 = 0;
    isFeeding2 = 0;
    feedingStatus2 = 0;
    isFeeding3 = 0;
    feedingStatus3 = 0;
  }
}
//check time to feed
void checkTimeToFeed() {
  DateTime now = rtc.now();
  nowHour = now.hour();
  nowMinute = now.minute();
  nowSecond = now.second();
//  if (weightPerDay == 1) {
//      weightInGrams = 50;
//    } else if (weightPerDay == 2) {
//      weightInGrams = 100;
//    } else if (weightPerDay == 3) {
//      weightInGrams = 150;
//    } else if (weightPerDay == 4) {
//      weightInGrams = 200;
//    } else if (weightPerDay == 5) {
//      weightInGrams = 250;
//    } else if (weightPerDay == 6) {
//      weightInGrams = 300;
//    }
  if (hours1 == nowHour && minutes1 == nowMinute) {
  //    Serial.println("Feeding Time 1");
    if (feedingStatus1 == 0) {
      Serial.println("feedingStatus = 0");
      if (isFeeding1 == 0) {
        Serial.println("isFeeding1");
        if(loadCellWeight != weightInGrams) {
          //Relay ON
          digitalWrite(relayDC, HIGH);
        } else {
          //Relay OFF
          digitalWrite(relayDC, LOW);
          isFeeding1 = 1;
          feedingStatus1 = 1;
        }
//        while(loadCellWeight <= weightInGrams) {
//          digitalWrite(relayDC, HIGH);
//          delay(1000);
//          digitalWrite(relayDC, LOW);
//          delay(1000);
//          loadCellWeight += 50;
//        }
//        digitalWrite(delayDC, LOW);
        //Status to feed
//        isFeeding1 = 1;
//        feedingStatus1 = 1;
        //Status to feed
////        if (loadCellWeight != weightInGrams) {
//          // working
//          digitalWrite(relayDC, HIGH);
//          delay(1000);
//          //
//        } else {
//          //complete
//          digitalWrite(relayDC, LOW);
//          loadCellWeight++;
//          isFeeding1 = 1;
//          feedingStatus1 = 1;
//        }
      } else {
//        // Relay off
        digitalWrite(relayDC, LOW);
      }
    }
  } else if (hours2 == nowHour && minutes2 == nowMinute) {
    //    Serial.println("Feeding Time 2");
//    if (isFeeding2 == 0) {
//      Serial.println("isFeeding2");
//      isFeeding2 = 1;
//      digitalWrite(8, HIGH);
//      delay(2000);
//    } else {
//      digitalWrite(8, LOW);
//    }
  } else if (hours3 == nowHour && minutes3 == nowMinute) {
//    Serial.println("Feeding Time 3");
//    if (isFeeding3 == 0) {
//      Serial.println("isFeeding3");
//      isFeeding3 = 1;
//      digitalWrite(8, HIGH);
//      delay(2000);
//    } else {
//      digitalWrite(8, LOW);
//    }
  }
}

void statusMenu() {
  DateTime now = rtc.now();
  lcd.setCursor(0, 0);
  lcd.print(now.day(), DEC);
  lcd.print("/");
  lcd.print(now.month(), DEC);
  lcd.print("/");
  lcd.print(now.year(), DEC);
  lcd.setCursor(12, 0);
  numberOfTime(now.hour(), 1);
  lcd.print(now.hour(), DEC);
  lcd.print(":");
  numberOfTime(now.minute(), 1);
  lcd.print(now.minute(), DEC);
  lcd.print(":");
  numberOfTime(now.second(), 1);
  lcd.print(now.second(), DEC);
  //
  lcd.setCursor(0, 3);
  lcd.print("Menu");
  //weight
  if (weightPerDay != 0) {
    lcd.setCursor(7, 3);
    lcd.print("Weight = ");
    if (weightPerDay == 1) {
      lcd.print("50g");
      weightInGrams = 50;
    } else if (weightPerDay == 2) {
      lcd.print("100g");
      weightInGrams = 100;
    } else if (weightPerDay == 3) {
      lcd.print("150g");
      weightInGrams = 150;
    } else if (weightPerDay == 4) {
      lcd.print("200g");
      weightInGrams = 200;
    } else if (weightPerDay == 5) {
      lcd.print("250g");
      weightInGrams = 250;
    } else if (weightPerDay == 6) {
      lcd.print("300g");
      weightInGrams = 300;
    }
  }
  //timeperday
  if (timePerDay != 0) {
    if (timePerDay == 1) {
      statusTime1();
    } else if (timePerDay == 2) {
      statusTime1();
      statusTime2();
    } else if (timePerDay == 3) {
      statusTime1();
      statusTime2();
      statusTime3();
    }
  }
  lcd.setCursor(0, 3);
  lcd.print("Menu");
}
void statusTime1() {
  lcd.setCursor(0, 1);
  lcd.print("T1=> ");
  if (hours1 <= 9) {
    lcd.print("0");
  }
  lcd.print(hours1);
  lcd.print(":");
  if (minutes1 <= 9) {
    lcd.print("0");
  }
  lcd.print(minutes1);
}
void statusTime2() {
  lcd.setCursor(10, 1);
  lcd.print("T2=> ");
  if (hours2 <= 9) {
    lcd.print("0");
  }
  lcd.print(hours2);
  lcd.print(":");
  if (minutes2 <= 9) {
    lcd.print("0");
  }
  lcd.print(minutes2);
}
void statusTime3() {
  lcd.setCursor(0, 2);
  lcd.print("T3=> ");
  if (hours3 <= 9) {
    lcd.print("0");
  }
  lcd.print(hours3);
  lcd.print(":");
  if (minutes3 <= 9) {
    lcd.print("0");
  }
  lcd.print(minutes1);
}
void mainMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("==== MAIN MENU ====");
  lcd.setCursor(0, 1);
  lcd.print("1. Set Date");
  lcd.setCursor(0, 2);
  lcd.print("2. Time Per Day");
  lcd.setCursor(0, 3);
  lcd.print("3. Weight Per Time");
}
void menuTimePerDay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time Per Day");
  lcd.setCursor(0, 1);
  lcd.print("1. 1 Time Per Day");
  lcd.setCursor(0, 2);
  lcd.print("2. 2 Time Per Day");
  lcd.setCursor(0, 3);
  lcd.print("3. 3 Time Per Day");
  applySetTime = 0;
}
void menuSetDate() {
  lcd.setCursor(0, 0);
  lcd.print("Set Date");
  // Fix 
//  DateTime now = rtc.now();
//  nowDay = now.day();
//  nowMonth = now.month();
//  nowYear = now.year();
//  nowHour = now.hour();
//  nowMinute = now.minute();
//  nowSecond = now.second();
  // Fix 
  lcd.setCursor(0, 1);
  lcd.print(setDay);
  lcd.print("/");
  lcd.print(setMonth);
  lcd.print("/");
  lcd.print(setYear);
  lcd.setCursor(10, 1);
  numberOfTime(setHour, 1);
  lcd.print(setHour);
  lcd.print(":");
  numberOfTime(setMinute, 1);
  lcd.print(setMinute);
  lcd.print(":");
  lcd.print(setSecond);
//  numberOfTime(nowSecond, 2);
}
void menuSetTimeX(int n) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Set Time ");
  lcd.print(n);
  timePerDay = n;
//  Serial.println("TimePerDay = ");
//  Serial.print(timePerDay);
  if (n == 1) {
    menuSetTime1();
  } else if (n == 2) {
    menuSetTime1();
    menuSetTime2();
  } else if (n == 3) {
    menuSetTime1();
    menuSetTime2();
    menuSetTime3();
  }
}
void menuSetTime1() {
  lcd.setCursor(1, 1);
  lcd.print("Time=>1 = ");
  if (hours1 <= 9) {
    lcd.print("0");
  }
  lcd.print(hours1);
  lcd.print(":");
  if (minutes1 <= 9) {
    lcd.print("0");
    lcd.print(minutes1);
  } else {
    lcd.print(minutes1);
  }
}
void menuSetTime2() {
  lcd.setCursor(1, 2);
  lcd.print("Time=>2 = ");
  if (hours2 <= 9) {
    lcd.print("0");
  }
  lcd.print(hours2);
  lcd.print(":");
  if (minutes2 <= 9) {
    lcd.print("0");
    lcd.print(minutes2);
  } else {
    lcd.print(minutes2);
  }
}
void menuSetTime3() {
  lcd.setCursor(1, 3);
  lcd.print("Time=>3 = ");
  if (hours3 <= 9) {
    lcd.print("0");
  }
  lcd.print(hours3);
  lcd.print(":");
  if (minutes3 <= 9) {
    lcd.print("0");
    lcd.print(minutes3);
  } else {
    lcd.print(minutes3);
  }
}
void applyTime() {
  lcd.setCursor(15, 0);
  lcd.print("=> OK");
}
//void setDateTime(int t) {
//  if (t == 1) {
//    //dd
//    Serial.println("D");
//  } else if (t == 2) {
//    //mm
//    Serial.println("M");
//  } else if (t == 3) {
//    //yy
//    Serial.println("YYYY");
//  } else if (t == 4) {
//    //hh
//    Serial.println("HH");
//  } else if (t == 5) {
//    //mm
//    Serial.println("MM");
//  } else if (t == 6) {
//    //ss
//    Serial.println("SS");
//  } else {
//
//  }
//}
void setDayMonthYear(int t) {
  if (t == 1) {
    lcd.setCursor(0, 3);
    lcd.print("D");
  } else if (t == 2) {
    lcd.setCursor(0, 3);
    lcd.print(" ");
    lcd.setCursor(3, 3);
    lcd.print("M");
  } else if (t == 3) {
    lcd.setCursor(3, 3);
    lcd.print(" ");
    lcd.setCursor(6, 3);
    lcd.print("Y");
  } else if (t == 4) {
    lcd.setCursor(6, 3);
    lcd.print("  ");
    lcd.setCursor(11, 3);
    lcd.print("hh");
  } else if (t == 5) {
    lcd.setCursor(11, 3);
    lcd.print("  ");
    lcd.setCursor(14, 3);
    lcd.print("mm");
  } else if (t == 6) {
    lcd.setCursor(14, 3);
    lcd.print("  ");
    lcd.setCursor(16, 3);
    lcd.print("ss");
  } else {
    lcd.setCursor(16, 3);
    lcd.print("  ");
  }
}
void setHourMinute(int t, int hm) {
  if (t == 1) {
    lcd.setCursor(18, 3);
    lcd.print(" ");
    lcd.setCursor(18, 1);
    if (hm == 1) {
      lcd.print("H");
    } else if (hm == 2) {
      lcd.print("M");
    }
  } else if (t == 2) {
    lcd.setCursor(18, 1);
    lcd.print(" ");
    lcd.setCursor(18, 2);
    if (hm == 1) {
      lcd.print("H");
    } else if (hm == 2) {
      lcd.print("M");
    }
  } else if (t == 3) {
    lcd.setCursor(18, 2);
    lcd.print(" ");
    lcd.setCursor(18, 3);
    if (hm == 1) {
      lcd.print("H");
    } else if (hm == 2) {
      lcd.print("M");
    }
  }
}
void menuWeightPerDay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Weight Per Day");
  lcd.setCursor(0, 1);
  lcd.print("1. 50g");
  lcd.setCursor(0, 2);
  lcd.print("2. 100g");
  lcd.setCursor(0, 3);
  lcd.print("3. 150g");
  lcd.setCursor(10, 1);
  lcd.print("4. 200g");
  lcd.setCursor(10, 2);
  lcd.print("5. 250g");
  lcd.setCursor(10, 3);
  lcd.print("6. 300g");
}
void numberOfTime(int t, int o) {
  if (o == 1) {
    if (t <= 9) {
      lcd.print("0");
    }
  } else if (o == 2) {
    if (t <= 9) {
      lcd.print(" ");
    }
  }
}
//select
void selectItem(int r, int c) {
  lcd.setCursor(r, c);
  lcd.print("<");
}
void unSelectItem(int r, int c) {
  lcd.setCursor(r, c);
  lcd.print(" ");
}
//read button
int read_LCD_Button() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  if (buttonState1 == LOW && prevButtonState1 == HIGH) {
    prevButtonState1 = buttonState1;
    return button1;
  } else if (buttonState2 == LOW && prevButtonState2 == HIGH) {
    prevButtonState2 = buttonState2;
    return button2;
  } else if (buttonState3 == LOW && prevButtonState3 == HIGH) {
    prevButtonState3 = buttonState3;
    return button3;
  } else if (buttonState4 == LOW && prevButtonState4 == HIGH) {
    prevButtonState4 = buttonState4;
    return button4;
  } else {
    prevButtonState1 = buttonState1;
    prevButtonState2 = buttonState2;
    prevButtonState3 = buttonState3;
    prevButtonState4 = buttonState4;
    return buttonNone;
  }
}

