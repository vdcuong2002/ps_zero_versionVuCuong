int num[4][4][3] = {{{0, 11, 1}, {20, 11, 2}, {40, 11, 3}, {62, 11, 13}},
                    {{0, 20, 4}, {20, 20, 5}, {40, 20, 6}, {62, 20, 14}},
                    {{0, 29, 7}, {20, 29, 8}, {40, 29, 9}, {62, 29, 15}},
                    {{0, 38, 17}, {20, 38, 0}, {40, 38, 12}, {62, 38, 16}}
                    };
int col = 0, row = 0;
int cal_a = 0, cal_b = 0;
bool get = false, equal = false; //get = false -> cal_a;  get = true-> cal_b
int calculation = 0; // 1->+  2->-   3->x   4->:
float div_ans;
void calculator() 
{
  for (int i = 0; i<4; i++)
  {
    for (int j = 0; j<4; j++)
    {
      lcd.FillRect(num[i][j][0], num[i][j][1], 21, 10, 0);
      if (num[i][j][2] < 10)
      {
        lcd.Number_Long(num[i][j][0] + 7, num[i][j][1] + 2, num[i][j][2], 0, 1);
      }
      if(num[i][j][2] == 12) lcd.Asc_String(num[i][j][0] + 7, num[i][j][1] + 2, PSTR("="), 1);
      if(num[i][j][2] == 13) lcd.Asc_String(num[i][j][0] + 7, num[i][j][1] + 2, PSTR("+"), 1);
      if(num[i][j][2] == 14) lcd.Asc_String(num[i][j][0] + 7, num[i][j][1] + 2, PSTR("-"), 1);
      if(num[i][j][2] == 15) lcd.Asc_String(num[i][j][0] + 7, num[i][j][1] + 2, PSTR("x"), 1);
      if(num[i][j][2] == 16) lcd.Asc_String(num[i][j][0] + 7, num[i][j][1] + 2, PSTR(":"), 1);
      if(num[i][j][2] == 17) lcd.Asc_String(num[i][j][0] + 7, num[i][j][1] + 2, PSTR("C"), 1);
    }
  }
  int pointer[3] = {num[col][row][0], num[col][row][1], num[col][row][2]};
  lcd.FillRect(pointer[0], pointer[1], 21, 10, 1);
  if (pointer[2] < 10)
  {
    lcd.Number_Long(pointer[0] + 7, pointer[1] + 2, pointer[2], 0, 0);
  }
  if(pointer[2] == 12) lcd.Asc_String(pointer[0] + 7, pointer[1] + 2, PSTR("="), 0);
  if(pointer[2] == 13) lcd.Asc_String(pointer[0] + 7, pointer[1] + 2, PSTR("+"), 0);
  if(pointer[2] == 14) lcd.Asc_String(pointer[0] + 7, pointer[1] + 2, PSTR("-"), 0);
  if(pointer[2] == 15) lcd.Asc_String(pointer[0] + 7, pointer[1] + 2, PSTR("x"), 0);
  if(pointer[2] == 16) lcd.Asc_String(pointer[0] + 7, pointer[1] + 2, PSTR(":"), 0);
  if(pointer[2] == 17) lcd.Asc_String(pointer[0] + 7, pointer[1] + 2, PSTR("C"), 0);
  
  int u = analogRead(UP);
  int d = analogRead(DOWN);
  int r = analogRead(RIGHT);
  int l = analogRead(LEFT);
  int ok = analogRead(OK);

  if (u > 500) 
  {
    if(col >0) col--;
    delay(100);
  }
  if (d > 500) 
  {
    if (col < 3) col++;
    delay(100);
  }
  if (r > 500) 
  {
    if(row < 3) row++;
    delay(100);
  }
  if (l > 500) 
  {
    if(row > 0) row--;
    delay(100);
  }
  if (ok > 500)
  {
    if (pointer[2] < 10 && not get) cal_a = 10*cal_a + pointer[2];
    if (pointer[2] < 10 && get) cal_b = 10*cal_b + pointer[2];
    if(equal)
    {
      cal_a = pointer[2];
      cal_b = 0;
      equal = !equal;
    }
    if (pointer[2] > 12)
    {
      calculation = pointer[2] - 12;
      get = !get;
    }
    if (pointer[2] == 12)
    {
      if (calculation == 1) cal_a += cal_b;
      if (calculation == 2) cal_a -= cal_b;
      if (calculation == 3) cal_a *= cal_b;
      if (calculation == 4) 
      {
        div_ans = (float)cal_a/(float)cal_b;
      }
      get = !get;
      equal = true;
      cal_b = 0;
    }
    delay(200);
    if (pointer[2] == 17) //clear
    {
      get = false;
      cal_b = 0;
      cal_a = 0;
    }
  }
  
  lcd.FillRect(0, 0, 84, 10, 1);
  lcd.DrawLine(61, 0, 61, 10, 0);
  if (not get && calculation != 4) lcd.Number_Long(2, 2, cal_a, 0, 0);
  if (not get && calculation == 4) lcd.Number_Float(2, 2, div_ans, 3, 0, 0);
  if (get) lcd.Number_Long(2, 2, cal_b, 0, 0);
  if (calculation == 1) lcd.Asc_String(70, 1, PSTR("+"), 0);
  if (calculation == 2) lcd.Asc_String(70, 1, PSTR("-"), 0);
  if (calculation == 3) lcd.Asc_String(70, 1, PSTR("x"), 0);
  if (calculation == 4) lcd.Asc_String(70, 1, PSTR(":"), 0);
  
  lcd.Display();
}
