int choose_pointer_menu[3] = {15, 25};
int now_pointer_menu = 0;
void main_menu()
{
  lcd.Asc_String(15, 1, PSTR("MAIN MENU"), 1);
  if (analogRead(DOWN) > 500 && now_pointer_menu < 1)
  {
    now_pointer_menu += 1;
    delay(300);
  }
  if (analogRead(UP) > 500 && now_pointer_menu > 0)
  {
    now_pointer_menu -= 1;
    delay(300);
  }
  print_main_menu(now_pointer_menu);
  if (analogRead(OK) > 500)
  {
    status_computer = now_pointer_menu + 1;
    delay(300);
    lcd.Clear();
  }
  lcd.Display();
}
void print_main_menu(int input)
{
  bool a = 1, b = 1, c = 1;
  if (input == 0) a = 0;
  if (input == 1) b = 0;
  lcd.FillRect(9, choose_pointer_menu[0] - 1, 60, 10, !a);
  lcd.Asc_String(10, choose_pointer_menu[0], PSTR("Game"), a);
  lcd.FillRect(9, choose_pointer_menu[1] - 1, 60, 8, !b);
  lcd.Asc_String(10, choose_pointer_menu[1] - 1, PSTR("Calculator"), b);
  lcd.FillRect(9, 35 - 1, 60, 10, 0);
}
