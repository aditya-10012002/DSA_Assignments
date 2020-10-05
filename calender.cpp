#include<iostream>
using namespace std;

int first_day_formula(int day, int month, int year) {
  // I had to get this formula through the net.
  int odd_days[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  year -= month < 3;
  return (year + year / 4 - year / 100 + year / 400 + odd_days[month - 1] + day) % 7;
}

bool checkYear(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

string months[] =  {"january", "february", "march", "april", "may", "june", "july",
"august", "september", "october", "november", "december"};

void print_hor(int month, int cal[6][7]) {

  cout << "\t\t" << months[month] << endl;
  cout << "Sun\tMon\tTue\tWed\tThu\tFri\tSat" << '\n';

  for(int j=0;j<6;j++) {
    for(int g=0;g<7;g++) {
      if(cal[j][g] == 0)
      cout << "\t";
      else
      cout << cal[j][g] << "\t";
    }
    cout << endl;
  }
}

void print_ver(int month, int cal[6][7]) {

  cout << "\t\t" << months[month] << endl;
  //cout << "Sun\tMon\tTue\tWed\tThu\tFri\tSat" << '\n';

  cout << "Sun\t";
  for(int i=0;i<6;i++)
  if(cal[i][0] != 0) {
    cout << cal[i][0] << "\t";
  } else {
    cout << "\t";
  }
  cout << endl;

  cout << "Mon\t";
  for(int i=0;i<6;i++)
  if(cal[i][1] != 0) {
    cout << cal[i][1] << "\t";
  } else {
    cout << "\t";
  }
  cout << endl;

  cout << "Tues\t";
  for(int i=0;i<6;i++)
  if(cal[i][2] != 0) {
    cout << cal[i][2] << "\t";
  } else {
    cout << "\t";
  }
  cout << endl;

  cout << "Wed\t";
  for(int i=0;i<6;i++)
  if(cal[i][3] != 0) {
    cout << cal[i][3] << "\t";
  } else {
    cout << "\t";
  }
  cout << endl;

  cout << "Thu\t";
  for(int i=0;i<6;i++)
  if(cal[i][4] != 0) {
    cout << cal[i][4] << "\t";
  } else {
    cout << "\t";
  }
  cout << endl;

  cout << "Fri\t";
  for(int i=0;i<6;i++)
  if(cal[i][5] != 0) {
    cout << cal[i][5] << "\t";
  } else {
    cout << "\t";
  }
  cout << endl;

  cout << "Sat\t";
  for(int i=0;i<6;i++)
  if(cal[i][6] != 0) {
    cout << cal[i][6] << "\t";
  } else {
    cout << "\t";
  }
  cout << endl;
}

void func(int month, int year) {
  int days;
  int cal[6][7];
  switch(month) {

    case 0: {
      days = 31;
      for(int j=0;j<6;j++)
      for(int g=0;g<7;g++)
      cal[j][g] = 0;

      int k = first_day_formula(1, 1, year);
      int i=1, n=0;
      while(i <= days) {
        cal[n][k%7] = i++;
        k++;
        n = k/7;
      }
      print_hor(0, cal);
      print_ver(0, cal);
    }

    case 1: {
      days = checkYear(year)?29:28;
      for(int j=0;j<6;j++)
      for(int g=0;g<7;g++)
      cal[j][g] = 0;

      int k = first_day_formula(1, 2, year);
      int i=1, n=0;
      while(i <= days) {
        cal[n][k%7] = i++;
        k++;
        n = k/7;
      }
      print_hor(1, cal);
      print_ver(1, cal);
    }

    case 2: {
      days = 31;
      for(int j=0;j<6;j++)
      for(int g=0;g<7;g++)
      cal[j][g] = 0;

      int k = first_day_formula(1, 3, year);
      int i=1, n=0;
      while(i <= days) {
        cal[n][k%7] = i++;
        k++;
        n = k/7;
      }
      print_hor(2, cal);
      print_ver(2, cal);
    }

    case 3: {
      days = 30;
      for(int j=0;j<6;j++)
      for(int g=0;g<7;g++)
      cal[j][g] = 0;

      int k = first_day_formula(1, 4, year);
      int i=1, n=0;
      while(i <= days) {
        cal[n][k%7] = i++;
        k++;
        n = k/7;
      }
      print_hor(3, cal);
      print_ver(3, cal);
    }

    case 4: {
      days = 31;
      for(int j=0;j<6;j++)
      for(int g=0;g<7;g++)
      cal[j][g] = 0;

      int k = first_day_formula(1, 5, year);
      int i=1, n=0;
      while(i <= days) {
        cal[n][k%7] = i++;
        k++;
        n = k/7;
      }
      print_hor(4, cal);
      print_ver(4, cal);
    }

    case 5: {
      days = 30;
      for(int j=0;j<6;j++)
      for(int g=0;g<7;g++)
      cal[j][g] = 0;

      int k = first_day_formula(1, 6, year);
      int i=1, n=0;
      while(i <= days) {
        cal[n][k%7] = i++;
        k++;
        n = k/7;
      }
      print_hor(5, cal);
      print_ver(5, cal);
    }

    case 6: {
      days = 31;
      for(int j=0;j<6;j++)
      for(int g=0;g<7;g++)
      cal[j][g] = 0;

      int k = first_day_formula(1, 7, year);
      int i=1, n=0;
      while(i <= days) {
        cal[n][k%7] = i++;
        k++;
        n = k/7;
      }
      print_hor(6, cal);
      print_ver(6, cal);
    }

    case 7: {
      days = 31;
      for(int j=0;j<6;j++)
      for(int g=0;g<7;g++)
      cal[j][g] = 0;

      int k = first_day_formula(1, 8, year);
      int i=1, n=0;
      while(i <= days) {
        cal[n][k%7] = i++;
        k++;
        n = k/7;
      }
      print_hor(7, cal);
      print_ver(7, cal);
    }

    case 8: {
      days = 30;
      for(int j=0;j<6;j++)
      for(int g=0;g<7;g++)
      cal[j][g] = 0;

      int k = first_day_formula(1, 9, year);
      int i=1, n=0;
      while(i <= days) {
        cal[n][k%7] = i++;
        k++;
        n = k/7;
      }
      print_hor(8, cal);
      print_ver(8, cal);
    }

    case 9: {
      days = 31;
      for(int j=0;j<6;j++)
      for(int g=0;g<7;g++)
      cal[j][g] = 0;

      int k = first_day_formula(1, 10, year);
      int i=1, n=0;
      while(i <= days) {
        cal[n][k%7] = i++;
        k++;
        n = k/7;
      }
      print_hor(9, cal);
      print_ver(9, cal);
    }

    case 10: {
      days = 30;
      for(int j=0;j<6;j++)
      for(int g=0;g<7;g++)
      cal[j][g] = 0;

      int k = first_day_formula(1, 11, year);
      int i=1, n=0;
      while(i <= days) {
        cal[n][k%7] = i++;
        k++;
        n = k/7;
      }
      print_hor(10, cal);
      print_ver(10, cal);
    }

    case 11: {
      days = 31;
      for(int j=0;j<6;j++)
      for(int g=0;g<7;g++)
      cal[j][g] = 0;

      int k = first_day_formula(1, 12, year);
      int i=1, n=0;
      while(i <= days) {
        cal[n][k%7] = i++;
        k++;
        n = k/7;
      }
      print_hor(11, cal);
      print_ver(11, cal);
    }

  }
}

int main() {
  cout << "Enter the year" << '\n';
  int year;
  cin >> year;

  cout << "Enter the number of month" << '\n';
  int month;
  cin >> month;
  func(month-1, year);
  return 0;
}
