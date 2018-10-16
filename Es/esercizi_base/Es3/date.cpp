#include "date.h"
#include <iostream>
int dMese(int n) {
  switch (n) {
    case (6,11,9,4) : n = 30;
    case (2) : n = 29;
    break;
    default : n = 31;
  }
  return n;
}

int date_difference(int year1, int month1, int day1,
                    int year2, int month2, int day2) {
                      int diffy = 0, diffm = 0, diffd = 0;
                      diffy = (year2 - year1) * 365;
                      std::cout << "diffm : " << diffm << std::endl;
                      if (month1 < month2) {
                        for (int i = month1 + 1; i < month2; i++)
                          diffm = diffm + dMese(i);
                        diffd = -(day1 + (dMese(month2) - day2));
                      }
                      if (month1 > month2) {
                        for (int i = month2 - 1; i > month1; i--)
                          diffm = diffm + dMese(i);
                        diffd = day2 + (dMese(month1) - day1);
                      }
                      if (month1 == month2) {
                        diffd = day2 - day1;
                      }


                      std::cout << "diffd : " << diffd << std::endl;
                      return diffy + diffm + diffd;

                    }
