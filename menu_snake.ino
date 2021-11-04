int choose_pointer[3] = {15, 25, 35};
int now_pointer = 0;
void menu_snake()
{
  lcd.Asc_String(15, 1, PSTR("-Level-"), 1);
  if (analogRead(DOWN) > 500 && now_pointer < 2)
  {
    now_pointer += 1;
    delay(300);
  }
  if (analogRead(UP) > 500 && now_pointer > 0)
  {
    now_pointer -= 1;
    delay(300);
  }
  print_menu(now_pointer);
  if (analogRead(OK) > 500)
  {
    start_game = !start_game;
    level_of_difficult = now_pointer;
    delay(300);
    lcd.Clear();
  }
  lcd.Display();
}
void print_menu(int input)
{
  bool a = 1, b = 1, c = 1;
  if (input == 0) a = 0;
  if (input == 1) b = 0;
  if (input == 2) c = 0;
  lcd.FillRect(9, choose_pointer[0] - 1, 60, 10, !a);
  lcd.Asc_String(10, choose_pointer[0], PSTR("Easy"), a);
  lcd.FillRect(9, choose_pointer[1] - 1, 60, 8, !b);
  lcd.Asc_String(10, choose_pointer[1] - 1, PSTR("Medium"), b);
  lcd.FillRect(9, choose_pointer[2] - 1, 60, 10, !c);
  lcd.Asc_String(10, choose_pointer[2], PSTR("Difficult"), c);
}
