#include <iostream>
#include <time.h>
#include <unistd.h>
using namespace std;

/*  //77//   */
// Global 2-D Arrays
int **twoDarray = new int *[3];
int row = 3, col = 3, remainder_active = 0, count_flag = 0;

void input(); // Functions
void print();
void counter();
void deletion();

int main() // =============== MAIN ==================
{
  int flag = 0, input1, input2, user_count = 0;

  cout << "\t\t\t\b\b\b\bWait a minute  \n\n\t\t====GAME LOADING====   \n "
          "Thank you!!!\n\n";
  input();
  cout << "\n==================================================";
  cout << " \n1 = Live Enemy , 0 = Dead Enemy ";
  cout << "\n==================================================";
  print();
  counter();
  count_flag = remainder_active;

  while (flag != 1)
  {
    cout << "\n\nEnter row (1-3) : "; // INPUTS
    cin >> input1;
    cout << "\nEnter column (1-3) : ";
    cin >> input2;
    if (-1 < (input1 || input2) > 3) // CHECKER
    {
      user_count++;
      continue;
    }

    input1--;
    input2--;

    for (int i = 0; i < row; i++) // CHECKS IF IT HITS OR MISSES
    {
      for (int j = 0; j < col; j++)
      {
        if (i == input1 && j == input2)
        {
          if (twoDarray[i][j] == 1)
          {
            twoDarray[i][j] = 0;
            cout << "\n HIT !!! . Enemy Destroyed  :)";
            continue;
          }

          else if (twoDarray[i][j] == 0)
          {
            cout << "\n Missed !!!  Try Again  :( ";
          }
        }
      }
    }
    std::system("clear"); // LINUX OS                                // CLEARS
                          // TERMINAL SCREEN ( FOR BETTER VISUALS )
    std::system(
        "cls"); // WINDOWS OS                              // (( Uncomment and
                // comment on , depends on which OS you are using ))

    user_count++;
    cout << "\n";
    print();

    input1 = 0;
    input2 = 0;

    for (int i = 0; i < row; i++) // FLAG CHECKER ( IT CHECKS IF THERE ARE ANY
                                  // LIVE ENEMIES ARE REMAINING)
    {
      for (int j = 0; j < col; j++)
      {
        if (twoDarray[i][j] == 1)
        {
          flag = 0;
        }
        else if (i == row - 1 && j == col - 1)
        {
          counter();
          if (remainder_active > -1 && remainder_active < 1)
          {
            flag = 1;
          }
        }
      }
    }

    cin.ignore();
  }

  cout << "\n\nAll Enemies are destroyed !!!!!\n";
  cout << "Total Hits Required : " << count_flag;
  cout << "\nTotal Hits used : " << user_count;

  deletion(); // DELETION
  return 0;
}

void input() // Input Function
{

  for (int i = 0; i < 3; i++)
  {
    twoDarray[i] = new int[col];
  }

  for (int i = 0; i < row; i++) // GENERTAING RANDOM MATRIX NUMBER
  {

    for (int j = 0; j < col; j++)
    {
      int r;
      srand(time(0));
      r = rand() % 10;
      if (r % 2 == 0)
        r = 1;

      else if (r % 2 != 0)
        r = 0;
      sleep(1);
      twoDarray[i][j] = r;
    }
  }
}

void print() // Printing Function
{
  cout << "\n";
  for (int i = 0; i < row; i++)
  {
    cout << "\t\b\b";
    for (int j = 0; j < col; j++)
    {
      cout << twoDarray[i][j];
    }
    cout << "\n";
  }
}

void counter() // Counter Function
{
  remainder_active = 0;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (twoDarray[i][j] == 1)
      {
        remainder_active++;
      }
    }
  }

  cout << "\n\n Total Live Enemies : " << remainder_active;
}
void deletion() // Delete Function
{
  for (int i = 0; i < row; i++)
  {
    delete[] twoDarray[i];
  }
  delete[] twoDarray;
}
